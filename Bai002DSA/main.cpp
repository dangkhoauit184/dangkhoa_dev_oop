#include <iostream>
#include <stdexcept>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;
    int size;
    string name;

public:
    Stack(string stackName) {
        top = nullptr;
        size = 0;
        name = stackName;
    }
    
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
    
    bool isEmpty() {
        return top == nullptr;
    }
    
    int peek() {
        if (isEmpty()) {
            throw runtime_error("Cột rỗng, không thể xem đỉnh!");
        }
        return top->data;
    }
    
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
    }
    
    int pop() {
        if (isEmpty()) {
            throw runtime_error("Cột rỗng, không thể lấy phần tử!");
        }
        Node* temp = top;
        int value = temp->data;
        top = top->next;
        delete temp;
        size--;
        return value;
    }
    
    int getSize() {
        return size;
    }
    
    string getName() {
        return name;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Cột " << name << ": (rỗng)" << endl;
            return;
        }
        
        cout << "Cột " << name << ": ";
        
        int* tempArray = new int[size];
        Node* current = top;
        int index = 0;
        
        while (current != nullptr) {
            tempArray[index++] = current->data;
            current = current->next;
        }
        
        for (int i = size - 1; i >= 0; i--) {
            cout << tempArray[i];
            if (i > 0) {
                cout << ", ";
            }
        }
        
        cout << " (đỉnh: " << top->data << ")" << endl;
        
        delete[] tempArray;
    }
};

class TowerOfHanoi {
private:
    Stack *sourceStack;
    Stack *auxiliaryStack;
    Stack *destinationStack;
    int numDisks;
    int moves;

public:
    TowerOfHanoi(int n) {
        sourceStack = new Stack("A");
        auxiliaryStack = new Stack("B");
        destinationStack = new Stack("C");
        numDisks = n;
        moves = 0;
        
        for (int i = n; i >= 1; i--) {
            sourceStack->push(i);
        }
    }
    
    ~TowerOfHanoi() {
        delete sourceStack;
        delete auxiliaryStack;
        delete destinationStack;
    }
    
    void resetStacks() {
        delete sourceStack;
        delete auxiliaryStack;
        delete destinationStack;
        sourceStack = new Stack("A");
        auxiliaryStack = new Stack("B");
        destinationStack = new Stack("C");
        moves = 0;
        for (int i = numDisks; i >= 1; i--) {
            sourceStack->push(i);
        }
    }
    
    void displayState() {
        cout << "\n--- Trạng thái hiện tại (sau " << moves << " bước) ---" << endl;
        sourceStack->display();
        auxiliaryStack->display();
        destinationStack->display();
        cout << "-------------------------------\n" << endl;
    }
    
    void moveDisk(Stack* source, Stack* destination) {
        try {
            int sourceDisk = source->peek();
            if (!destination->isEmpty() && sourceDisk > destination->peek()) {
                cout << "Lỗi: Không thể đặt đĩa lớn hơn lên đĩa nhỏ hơn!" << endl;
                return;
            }
            int disk = source->pop();
            destination->push(disk);
            moves++;
            cout << "Di chuyển đĩa " << disk << " từ cột " << source->getName()
                 << " sang cột " << destination->getName() << endl;
        } catch (const runtime_error& e) {
            cout << "Lỗi: " << e.what() << endl;
        }
    }
    
    void solve() {
        cout << "Bắt đầu giải bài toán Tháp Hà Nội với " << numDisks << " đĩa:" << endl;
        displayState();
        
        solveRecursive(numDisks, sourceStack, destinationStack, auxiliaryStack);
        
        cout << "\nĐã giải xong bài toán Tháp Hà Nội trong " << moves << " bước!" << endl;
        displayState();
    }
    
    void solveRecursive(int n, Stack* source, Stack* destination, Stack* auxiliary) {
        if (n == 1) {
            moveDisk(source, destination);
            displayState();
            return;
        }
        
        solveRecursive(n-1, source, auxiliary, destination);
        moveDisk(source, destination);
        displayState();
        solveRecursive(n-1, auxiliary, destination, source);
    }
    
    void solveIterative() {
        cout << "Bắt đầu giải bài toán Tháp Hà Nội với " << numDisks << " đĩa (giải thuật lặp):" << endl;
        displayState();
        
        int totalMoves = (1 << numDisks) - 1;
        
        Stack* auxStack = auxiliaryStack;
        Stack* destStack = destinationStack;
        
        // Nếu số đĩa là chẵn, hoán đổi vai trò của cột phụ và cột đích
        if (numDisks % 2 == 0) {
            auxStack = destinationStack;
            destStack = auxiliaryStack;
        }
        
        for (int i = 1; i <= totalMoves; i++) {
            if (i % 3 == 1) {
                if (sourceStack->isEmpty() || (!destStack->isEmpty() && sourceStack->peek() > destStack->peek())) {
                    moveDisk(destStack, sourceStack);
                } else {
                    moveDisk(sourceStack, destStack);
                }
            } else if (i % 3 == 2) {
                if (sourceStack->isEmpty() || (!auxStack->isEmpty() && sourceStack->peek() > auxStack->peek())) {
                    moveDisk(auxStack, sourceStack);
                } else {
                    moveDisk(sourceStack, auxStack);
                }
            } else if (i % 3 == 0) {
                if (auxStack->isEmpty() || (!destStack->isEmpty() && auxStack->peek() > destStack->peek())) {
                    moveDisk(destStack, auxStack);
                } else {
                    moveDisk(auxStack, destStack);
                }
            }
            displayState();
        }
        
        cout << "\nĐã giải xong bài toán Tháp Hà Nội trong " << moves << " bước!" << endl;
    }
    
    void interactive() {
        int choice = 0;
        bool solved = false;
        
        cout << "Mô phỏng bài toán Tháp Hà Nội với " << numDisks << " đĩa:" << endl;
        displayState();
        
        while (!solved) {
            cout << "Chọn hành động:" << endl;
            cout << "1. Di chuyển đĩa" << endl;
            cout << "2. Hiển thị trạng thái hiện tại" << endl;
            cout << "3. Giải tự động (đệ quy)" << endl;
            cout << "4. Giải tự động (lặp)" << endl;
            cout << "5. Thoát" << endl;
            cout << "Lựa chọn của bạn: ";
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Lựa chọn không hợp lệ! Vui lòng nhập số." << endl;
                continue;
            }
            
            switch (choice) {
                case 1: {
                    // Bao bọc các biến trong một khối để tránh lỗi "jump to case label"
                    int source, destination;
                    cout << "Nhập cột nguồn (1=A, 2=B, 3=C): ";
                    if (!(cin >> source)) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Cột nguồn không hợp lệ!" << endl;
                        break;
                    }
                    cout << "Nhập cột đích (1=A, 2=B, 3=C): ";
                    if (!(cin >> destination)) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Cột đích không hợp lệ!" << endl;
                        break;
                    }
                    
                    if (source < 1 || source > 3 || destination < 1 || destination > 3 || source == destination) {
                        cout << "Lựa chọn không hợp lệ!" << endl;
                        break;
                    }
                    
                    Stack* sourcePtr = (source == 1) ? sourceStack : (source == 2) ? auxiliaryStack : destinationStack;
                    Stack* destPtr = (destination == 1) ? sourceStack : (destination == 2) ? auxiliaryStack : destinationStack;
                    
                    moveDisk(sourcePtr, destPtr);
                    displayState();
                    
                    if (destinationStack->getSize() == numDisks) {
                        cout << "Chúc mừng! Bạn đã giải xong bài toán trong " << moves << " bước!" << endl;
                        solved = true;
                    }
                    break;
                }
                    
                case 2:
                    displayState();
                    break;
                    
                case 3:
                    resetStacks();
                    solve();
                    solved = true;
                    break;
                    
                case 4:
                    resetStacks();
                    solveIterative();
                    solved = true;
                    break;
                    
                case 5:
                    cout << "Thoát khỏi chương trình!" << endl;
                    return;
                    
                default:
                    cout << "Lựa chọn không hợp lệ!" << endl;
            }
        }
    }
};

int main() {
    int n;
    cout << "Nhập số đĩa cho bài toán Tháp Hà Nội: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Số đĩa phải là số nguyên dương!" << endl;
        return 1;
    }
    
    TowerOfHanoi tower(n);
    
    int choice;
    cout << "Chọn chế độ:" << endl;
    cout << "1. Tự động giải (đệ quy)" << endl;
    cout << "2. Tự động giải (lặp)" << endl;
    cout << "3. Mô phỏng tương tác" << endl;
    cout << "Lựa chọn của bạn: ";
    if (!(cin >> choice)) {
        cout << "Lựa chọn không hợp lệ! Vui lòng nhập số." << endl;
        return 1;
    }
    
    switch (choice) {
        case 1:
            tower.solve();
            break;
        case 2:
            tower.solveIterative();
            break;
        case 3:
            tower.interactive();
            break;
        default:
            cout << "Lựa chọn không hợp lệ!" << endl;
    }
    
    return 0;
}
