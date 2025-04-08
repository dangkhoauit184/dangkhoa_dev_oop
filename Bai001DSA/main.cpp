#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class BigNumber {
private:
    string number;
    bool isNegative;

    void removeLeadingZeros() {
        int i = 0;
        while (i < number.size() - 1 && number[i] == '0') {
            i++;
        }
        number = number.substr(i);
    }

public:
    BigNumber() {
        number = "0";
        isNegative = false;
    }

    BigNumber(string str) {
        if (str.empty()) {
            number = "0";
            isNegative = false;
            return;
        }

        isNegative = (str[0] == '-');
        if (isNegative) {
            str = str.substr(1);
        }

        for (char c : str) {
            if (c < '0' || c > '9') {
                number = "0";
                isNegative = false;
                return;
            }
        }

        number = str;
        removeLeadingZeros();

        if (number == "0") {
            isNegative = false;
        }
    }

    BigNumber(const BigNumber& other) {
        number = other.number;
        isNegative = other.isNegative;
    }

    int compareAbsValue(const BigNumber& other) const {
        if (number.length() > other.number.length()) {
            return 1;
        } else if (number.length() < other.number.length()) {
            return -1;
        }

        for (size_t i = 0; i < number.length(); i++) {
            if (number[i] > other.number[i]) {
                return 1;
            } else if (number[i] < other.number[i]) {
                return -1;
            }
        }
        return 0;
    }

    BigNumber add(const BigNumber& other) const {
        if (isNegative && !other.isNegative) {
            BigNumber temp = *this;
            temp.isNegative = false;
            return other.subtract(temp);
        }
        if (!isNegative && other.isNegative) {
            BigNumber temp = other;
            temp.isNegative = false;
            return subtract(temp);
        }

        string result;
        string num1 = number;
        string num2 = other.number;
        int carry = 0;

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        if (num1.length() < num2.length()) {
            swap(num1, num2);
        }

        for (size_t i = 0; i < num1.length(); i++) {
            int digit1 = num1[i] - '0';
            int digit2 = (i < num2.length()) ? (num2[i] - '0') : 0;
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            result.push_back(sum % 10 + '0');
        }

        if (carry > 0) {
            result.push_back(carry + '0');
        }

        reverse(result.begin(), result.end());

        BigNumber resultNum(result);
        resultNum.isNegative = isNegative;
        return resultNum;
    }

    BigNumber subtract(const BigNumber& other) const {
        if (isNegative && !other.isNegative) {
            BigNumber temp = *this;
            temp.isNegative = false;
            BigNumber res = temp.add(other);
            res.isNegative = true;
            return res;
        }
        if (!isNegative && other.isNegative) {
            BigNumber temp = other;
            temp.isNegative = false;
            return add(temp);
        }

        int cmp = compareAbsValue(other);
        if (cmp == 0) {
            return BigNumber("0");
        }

        string a, b;
        bool resultNegative;

        if (cmp > 0) {
            a = number;
            b = other.number;
            resultNegative = isNegative;
        } else {
            a = other.number;
            b = number;
            resultNegative = !isNegative;
        }

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string result;
        int borrow = 0;

        for (size_t i = 0; i < a.length(); i++) {
            int digit1 = a[i] - '0';
            int digit2 = (i < b.length()) ? (b[i] - '0') : 0;
            int diff = digit1 - digit2 - borrow;

            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }

            result.push_back(diff + '0');
        }

        reverse(result.begin(), result.end());
        BigNumber resultNum(result);
        resultNum.isNegative = resultNegative;
        return resultNum;
    }

    BigNumber multiply(const BigNumber& other) const {
        if (number == "0" || other.number == "0") {
            return BigNumber("0");
        }

        vector<int> result(number.length() + other.number.length(), 0);

        for (int i = number.length() - 1; i >= 0; i--) {
            for (int j = other.number.length() - 1; j >= 0; j--) {
                int n1 = number[i] - '0';
                int n2 = other.number[j] - '0';
                int sum = n1 * n2 + result[i + j + 1];

                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        string resultStr;
        for (size_t i = 0; i < result.size(); i++) {
            resultStr.push_back(result[i] + '0');
        }

        size_t i = 0;
        while (i < resultStr.size() - 1 && resultStr[i] == '0') {
            i++;
        }
        resultStr = resultStr.substr(i);

        BigNumber resultNum(resultStr);
        resultNum.isNegative = (isNegative != other.isNegative);
        return resultNum;
    }

    pair<BigNumber, BigNumber> divide(const BigNumber& divisor) const {
        if (divisor.number == "0") {
            throw runtime_error("Không thể chia cho 0");
        }

        if (compareAbsValue(divisor) < 0) {
            return {BigNumber("0"), *this};
        }

        if (divisor.number == "1") {
            BigNumber result = *this;
            result.isNegative = (isNegative != divisor.isNegative);
            return {result, BigNumber("0")};
        }

        BigNumber remainder("0");
        BigNumber quotient("0");
        BigNumber absDivisor = divisor;
        absDivisor.isNegative = false;
        BigNumber absDividend = *this;
        absDividend.isNegative = false;

        string quotientStr;
        for (size_t i = 0; i < absDividend.number.length(); i++) {
            remainder.number.push_back(absDividend.number[i]);
            remainder.removeLeadingZeros();

            int count = 0;
            while (remainder.compareAbsValue(absDivisor) >= 0) {
                remainder = remainder.subtract(absDivisor);
                count++;
            }

            quotientStr.push_back(count + '0');
        }

        size_t i = 0;
        while (i < quotientStr.size() - 1 && quotientStr[i] == '0') {
            i++;
        }
        quotientStr = quotientStr.substr(i);

        BigNumber quotientResult(quotientStr);
        quotientResult.isNegative = (isNegative != divisor.isNegative);
        remainder.isNegative = isNegative;

        return {quotientResult, remainder};
    }

    string toString() const {
        if (isNegative && number != "0") {
            return "-" + number;
        }
        return number;
    }
};

class Calculator {
private:
    BigNumber memory;
    vector<BigNumber> numStack;
    vector<char> opStack;

    int precedence(char op) {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        return 0;
    }

    BigNumber applyOperation(BigNumber a, BigNumber b, char op) {
        switch (op) {
            case '+': return a.add(b);
            case '-': return a.subtract(b);
            case '*': return a.multiply(b);
            case '/': {
                pair<BigNumber, BigNumber> result = a.divide(b);
                return result.first;
            }
            default: return BigNumber("0");
        }
    }

public:
    Calculator() {
        memory = BigNumber("0");
    }

    BigNumber calculate(const string& expression) {
        numStack.clear();
        opStack.clear();

        string num;
        bool expectingOperand = true;
        bool isNegative = false;

        for (size_t i = 0; i < expression.length(); i++) {
            char c = expression[i];

            if (c == ' ') {
                continue;
            } else if (c == '(') {
                opStack.push_back(c);
                expectingOperand = true;
            } else if (isdigit(c)) {
                num = "";
                while (i < expression.length() && isdigit(expression[i])) {
                    num.push_back(expression[i++]);
                }
                i--;

                if (isNegative) {
                    num = "-" + num;
                    isNegative = false;
                }

                numStack.push_back(BigNumber(num));
                expectingOperand = false;
            } else if (c == ')') {
                while (!opStack.empty() && opStack.back() != '(') {
                    char op = opStack.back();
                    opStack.pop_back();

                    BigNumber b = numStack.back();
                    numStack.pop_back();

                    BigNumber a = numStack.back();
                    numStack.pop_back();

                    numStack.push_back(applyOperation(a, b, op));
                }

                if (!opStack.empty() && opStack.back() == '(') {
                    opStack.pop_back();
                }
                expectingOperand = false;
            } else if (c == '+' || c == '-' || c == '*' || c == '/') {
                if (expectingOperand && c == '-') {
                    isNegative = true;
                    continue;
                }

                while (!opStack.empty() && precedence(opStack.back()) >= precedence(c)) {
                    char op = opStack.back();
                    opStack.pop_back();

                    BigNumber b = numStack.back();
                    numStack.pop_back();

                    BigNumber a = numStack.back();
                    numStack.pop_back();

                    numStack.push_back(applyOperation(a, b, op));
                }
                opStack.push_back(c);
                expectingOperand = true;
            }
        }

        while (!opStack.empty()) {
            char op = opStack.back();
            opStack.pop_back();

            BigNumber b = numStack.back();
            numStack.pop_back();

            BigNumber a = numStack.back();
            numStack.pop_back();

            numStack.push_back(applyOperation(a, b, op));
        }

        return numStack.back();
    }

    void memoryAdd(const BigNumber& num) {
        memory = memory.add(num);
    }

    void memorySubtract(const BigNumber& num) {
        memory = memory.subtract(num);
    }

    void memoryClear() {
        memory = BigNumber("0");
    }

    BigNumber memoryRecall() {
        return memory;
    }
};

int main() {
    Calculator calc;
    string input;
    BigNumber currentResult("0");

    cout << "Máy tính số lớn (tối đa 30 chữ số)" << endl;
    cout << "Các lệnh: \n";
    cout << "- Nhập biểu thức để tính\n";
    cout << "- M+ để cộng kết quả hiện tại vào bộ nhớ\n";
    cout << "- M- để trừ kết quả hiện tại khỏi bộ nhớ\n";
    cout << "- MR để hiển thị giá trị trong bộ nhớ\n";
    cout << "- MC để xóa bộ nhớ\n";
    cout << "- 'exit' để thoát\n\n";

    while (true) {
        cout << "> ";
        getline(cin, input);

        if (input == "exit") {
            break;
        } else if (input == "M+") {
            calc.memoryAdd(currentResult);
            cout << "Đã cộng vào bộ nhớ" << endl;
        } else if (input == "M-") {
            calc.memorySubtract(currentResult);
            cout << "Đã trừ khỏi bộ nhớ" << endl;
        } else if (input == "MR") {
            cout << "Giá trị trong bộ nhớ: " << calc.memoryRecall().toString() << endl;
        } else if (input == "MC") {
            calc.memoryClear();
            cout << "Đã xóa bộ nhớ" << endl;
        } else {
            try {
                currentResult = calc.calculate(input);
                cout << "Kết quả: " << currentResult.toString() << endl;
            } catch (const exception& e) {
                cout << "Lỗi: " << e.what() << endl;
            }
        }
    }

    return 0;
}
