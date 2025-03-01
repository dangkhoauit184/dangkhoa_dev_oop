#include <iostream>
#include <cmath>
using namespace std;

// Class Điểm trong không gian
class Point {
private:
    double x, y;
public:
    void Input();
    void Output();
    void Move(double dx, double dy);
    double Distance(const Point& p);
};

// Hàm nhập Điểm trong không gian
void Point::Input() {
    cout << "Nhập tọa độ x: ";
    cin >> this->x;
    cout << "Nhập tọa độ y: ";
    cin >> this->y;
}

// Hàm xuất Điểm
void Point::Output() {
    cout << "(" << this->x << ", " << this->y << ")";
}

// Hàm di chuyển điểm bằng cách cộng thêm lượng x y
void Point::Move(double dx, double dy) {
    this->x += dx;
    this->y += dy;
}

// Hàm tính khoảng cách giữa 2 điểm
double Point::Distance(const Point& p) {
    return sqrt(pow(this->x - p.x, 2) + pow(this->y - p.y, 2));
}

int main() {
    Point p1, p2;
    cout << "Nhập tọa độ điểm ban đầu:" << endl;
    p1.Input();
    
    cout << "Điểm vừa nhập: ";
    p1.Output();
    cout << endl;
    
    double dx, dy;
    cout << "Nhập độ dời dx: ";
    cin >> dx;
    cout << "Nhập độ dời dy: ";
    cin >> dy;
    
    p2 = p1; // Sao chép điểm ban đầu
    p2.Move(dx, dy);
    
    cout << "Điểm sau khi di chuyển: ";
    p2.Output();
    cout << endl;
    
    cout << "Khoảng cách giữa điểm ban đầu và điểm mới là: " << p1.Distance(p2) << endl;
    
    return 0;
}
