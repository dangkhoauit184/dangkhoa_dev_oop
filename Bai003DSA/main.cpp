#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
using namespace std;

struct Bracket
{
    char type;
    int position;
};

struct Stack
{
    Bracket *data;
    int top;
    int capacity;

    void initialize(int size)
    {
        data = new Bracket[size];
        top = -1;
        capacity = size;
    }

    void push(Bracket bracket)
    {
        if (top >= capacity - 1)
        {
            throw runtime_error("Ngăn xếp đầy, không thể thêm dấu ngoặc!");
        }
        data[++top] = bracket;
    }

    Bracket pop()
    {
        if (top >= 0)
        {
            return data[top--];
        }
        return {' ', -1};
    }

    Bracket peek()
    {
        if (top >= 0)
        {
            return data[top];
        }
        return {' ', -1};
    }

    bool isEmpty()
    {
        return top < 0;
    }

    void cleanup()
    {
        delete[] data;
    }
};

struct PairArray
{
    int *open;
    int *close;
    int size;
    int capacity;

    void initialize(int maxSize)
    {
        open = new int[maxSize];
        close = new int[maxSize];
        size = 0;
        capacity = maxSize;
    }

    void add(int openPos, int closePos)
    {
        if (size >= capacity)
        {
            throw runtime_error("Mảng cặp đầy, không thể thêm cặp dấu ngoặc!");
        }
        open[size] = openPos;
        close[size] = closePos;
        size++;
    }

    void cleanup()
    {
        delete[] open;
        delete[] close;
    }
};

bool areBracketsMatching(char opening, char closing)
{
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

bool isOpenBracket(char c)
{
    return c == '(' || c == '[' || c == '{';
}

bool isCloseBracket(char c)
{
    return c == ')' || c == ']' || c == '}';
}

void findMatchingBrackets(char *code, int length)
{
    Stack openingBrackets;
    openingBrackets.initialize(length);

    PairArray matchedPairs;
    matchedPairs.initialize(length);

    int *unmatchedClosing = new int[length];
    int unmatchedClosingCount = 0;

    bool inSingleLineComment = false;
    bool inMultiLineComment = false;
    bool inStringLiteral = false;
    bool inCharLiteral = false;

    for (int i = 0; i < length; i++)
    {
        char current = code[i];
        char next = (i + 1 < length) ? code[i + 1] : '\0';

        if (inSingleLineComment && current == '\n')
        {
            inSingleLineComment = false;
            continue;
        }

        if (inMultiLineComment && current == '*' && next == '/')
        {
            inMultiLineComment = false;
            i++;
            continue;
        }

        if (inStringLiteral && current == '"' && (i == 0 || code[i - 1] != '\\'))
        {
            inStringLiteral = false;
            continue;
        }

        if (inCharLiteral && current == '\'' && (i == 0 || code[i - 1] != '\\'))
        {
            inCharLiteral = false;
            continue;
        }

        if (!inSingleLineComment && !inMultiLineComment && !inStringLiteral && !inCharLiteral)
        {
            if (current == '/' && next == '/')
            {
                inSingleLineComment = true;
                i++;
                continue;
            }

            if (current == '/' && next == '*')
            {
                inMultiLineComment = true;
                i++;
                continue;
            }

            if (current == '"')
            {
                inStringLiteral = true;
                continue;
            }

            if (current == '\'')
            {
                inCharLiteral = true;
                continue;
            }

            if (isOpenBracket(current))
            {
                Bracket bracket = {current, i};
                try
                {
                    openingBrackets.push(bracket);
                }
                catch (const runtime_error &e)
                {
                    cerr << e.what() << "\n";
                    break;
                }
            }
            else if (isCloseBracket(current))
            {
                if (openingBrackets.isEmpty())
                {
                    unmatchedClosing[unmatchedClosingCount++] = i;
                }
                else if (areBracketsMatching(openingBrackets.peek().type, current))
                {
                    try
                    {
                        matchedPairs.add(openingBrackets.peek().position, i);
                        openingBrackets.pop();
                    }
                    catch (const runtime_error &e)
                    {
                        cerr << e.what() << "\n";
                        break;
                    }
                }
                else
                {
                    unmatchedClosing[unmatchedClosingCount++] = i;
                }
            }
        }
    }

    string message = string("Tìm thấy ") + to_string(matchedPairs.size) + string(" cặp dấu ngoặc tương ứng:\n");
    cout << message;
    for (int i = 0; i < matchedPairs.size; i++)
    {
        message = string("Dấu ngoặc mở tại vị trí ") + to_string(matchedPairs.open[i]) +
                  string(" tương ứng với dấu ngoặc đóng tại vị trí ") + to_string(matchedPairs.close[i]) + string("\n");
        cout << message;
    }

    if (!openingBrackets.isEmpty())
    {
        cout << "\nCác dấu ngoặc mở không có cặp tương ứng:\n";
        while (!openingBrackets.isEmpty())
        {
            Bracket b = openingBrackets.pop();
            message = string("Dấu ngoặc mở '") + b.type +
                      string("' tại vị trí ") + to_string(b.position) +
                      string(" không có cặp đóng tương ứng\n");
            cout << message;
        }
    }

    if (unmatchedClosingCount > 0)
    {
        cout << "\nCác dấu ngoặc đóng không có cặp tương ứng:\n";
        for (int i = 0; i < unmatchedClosingCount; i++)
        {
            message = string("Dấu ngoặc đóng '") + code[unmatchedClosing[i]] +
                      string("' tại vị trí ") + to_string(unmatchedClosing[i]) +
                      string(" không có cặp mở tương ứng\n");
            cout << message;
        }
    }

    delete[] unmatchedClosing;
    matchedPairs.cleanup();
    openingBrackets.cleanup();
}

int main()
{
    string filename;
    cout << "Nhập tên file mã nguồn : ";
    getline(cin, filename);

    ifstream file(filename, ios::binary);
    if (!file.is_open())
    {
        cerr << "Không thể mở file: " << filename << "\n";
        return 1;
    }

    file.seekg(0, ios::end);
    streampos fileSize = file.tellg();
    if (fileSize <= 0)
    {
        cerr << "File rỗng hoặc không thể đọc!\n";
        file.close();
        return 1;
    }

    file.seekg(0, ios::beg);
    char *buffer = new char[static_cast<size_t>(fileSize) + 1];
    file.read(buffer, fileSize);
    buffer[static_cast<size_t>(fileSize)] = '\0';

    findMatchingBrackets(buffer, static_cast<int>(fileSize));

    delete[] buffer;
    file.close();
    return 0;
}
