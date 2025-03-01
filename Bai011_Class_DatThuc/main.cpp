#include <iostream>
using namespace std;

// Lớp Đa thức bậc hai
class DaThuc {
private:
    double a, b, c;
public:
    DaThuc();
    DaThuc(double a, double b, double c);
    void Nhap();
    void Xuat();
    DaThuc Cong(const DaThuc &other);
    DaThuc Tru(const DaThuc &other);
    DaThuc Nhan(const DaThuc &other, double &newD, double &newE);
    double GiaTriF0();
};

// Định nghĩa constructor
DaThuc::DaThuc() : a(0), b(0), c(0) {}
DaThuc::DaThuc(double a, double b, double c) : a(a), b(b), c(c) {}

void DaThuc::Nhap() {
    cout << "Nhập hệ số a: ";
    cin >> a;
    cout << "Nhập hệ số b: ";
    cin >> b;
    cout << "Nhập hệ số c: ";
    cin >> c;
}

void DaThuc::Xuat() {
    cout << a << "x^2 + " << b << "x + " << c << endl;
}

DaThuc DaThuc::Cong(const DaThuc &other) {
    return DaThuc(a + other.a, b + other.b, c + other.c);
}

DaThuc DaThuc::Tru(const DaThuc &other) {
    return DaThuc(a - other.a, b - other.b, c - other.c);
}

DaThuc DaThuc::Nhan(const DaThuc &other, double &newD, double &newE) {
    double newA = a * other.a;
    double newB = a * other.b + b * other.a;
    double newC = a * other.c + b * other.b + c * other.a;
    newD = b * other.c + c * other.b;
    newE = c * other.c;
    return DaThuc(newA, newB, newC);
}

// Trả về hệ số tự do của đa thức
double DaThuc::GiaTriF0() {
    return c;
}

int main() {
    DaThuc dt1, dt2;
    cout << "Nhập đa thức thứ nhất:" << endl;
    dt1.Nhap();
    cout << "Nhập đa thức thứ hai:" << endl;
    dt2.Nhap();
    
    cout << "Đa thức thứ nhất: "; dt1.Xuat();
    cout << "Đa thức thứ hai: "; dt2.Xuat();
    
    DaThuc tong = dt1.Cong(dt2);
    cout << "Tổng hai đa thức: "; tong.Xuat();
    
    DaThuc hieu = dt1.Tru(dt2);
    cout << "Hiệu hai đa thức: "; hieu.Xuat();
    
    double newD, newE;
    DaThuc tich = dt1.Nhan(dt2, newD, newE);
    cout << "Tích hai đa thức: "; tich.Xuat();
    cout << " + " << newD << "x + " << newE << endl;
    
    cout << "Giá trị của biểu thức tại x = 0: " << dt1.GiaTriF0() * dt2.GiaTriF0() << endl;
    return 0;
}
