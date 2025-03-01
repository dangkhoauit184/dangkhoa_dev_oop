#include<iostream>
using namespace std;

class PhanSo {
private:
    int tuso;
    int mauso;

public:
    double DecimalValue();
    PhanSo();
    void Nhap();
    void Xuat();
    int GCD(int a, int b);
    void RutGon();
    PhanSo Sum(PhanSo& ps);
    PhanSo Difference(PhanSo& ps);
    PhanSo Product(PhanSo& ps);
    PhanSo Quotient(PhanSo& ps);
};

PhanSo::PhanSo() {}

void PhanSo::Nhap() {
    cout << "Nhập tử số: ";
    cin >> this->tuso;
    cout << "Nhập mẫu số: ";
    cin >> this->mauso;
    while (this->mauso == 0) {
        cout << "Mẫu số phải khác 0, vui lòng nhập lại: ";
        cin >> this->mauso;
    }
    if (this->mauso < 0) {
        this->tuso = -this->tuso;
        this->mauso = -this->mauso;
    }
}

void PhanSo::Xuat() {
    cout << this->tuso << "/" << this->mauso;
}

int PhanSo::GCD(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return abs(a);
}

void PhanSo::RutGon() {
    int gcd = this->GCD(this->tuso, this->mauso);
    this->tuso /= gcd;
    this->mauso /= gcd;
    if (this->mauso < 0) {
        this->tuso = -this->tuso;
        this->mauso = -this->mauso;
    }
}

PhanSo PhanSo::Sum(PhanSo& ps) {
    PhanSo Result;
    Result.tuso = this->tuso * ps.mauso + ps.tuso * this->mauso;
    Result.mauso = this->mauso * ps.mauso;
    Result.RutGon();
    return Result;
}

PhanSo PhanSo::Difference(PhanSo& ps) {
    PhanSo Result;
    Result.tuso = this->tuso * ps.mauso - ps.tuso * this->mauso;
    Result.mauso = this->mauso * ps.mauso;
    Result.RutGon();
    return Result;
}

PhanSo PhanSo::Product(PhanSo& ps) {
    PhanSo Result;
    Result.tuso = this->tuso * ps.tuso;
    Result.mauso = this->mauso * ps.mauso;
    Result.RutGon();
    return Result;
}

PhanSo PhanSo::Quotient(PhanSo& ps) {
    if (ps.tuso == 0) {
        cout << "Không thể chia cho phân số có tử số bằng 0!" << endl;
        return PhanSo();
    }
    PhanSo Result;
    Result.tuso = this->tuso * ps.mauso;
    Result.mauso = this->mauso * ps.tuso;
    Result.RutGon();
    return Result;
}

double PhanSo::DecimalValue() {
    if (this->mauso == 0) {
        cout << "Mẫu số bằng 0, không thể tính giá trị thập phân!" << endl;
        return 0;
    }
    return (double)this->tuso / this->mauso;
}

int main() {
    PhanSo ps1, ps2;
    cout << "Nhập phân số thứ nhất:" << endl;
    ps1.Nhap();
    cout << "Nhập phân số thứ hai:" << endl;
    ps2.Nhap();

    cout << "Hai phân số vừa nhập là:" << endl;
    cout << "Phân số thứ nhất: "; ps1.Xuat(); cout << endl;
    cout << "Phân số thứ hai: "; ps2.Xuat(); cout << endl;

    ps1.RutGon();
    ps2.RutGon();
    cout << "Rút gọn phân số thứ nhất: "; ps1.Xuat(); cout << endl;
    cout << "Rút gọn phân số thứ hai: "; ps2.Xuat(); cout << endl;

    cout << "Tổng của hai phân số là: "; (ps1.Sum(ps2)).Xuat(); cout << endl;
    cout << "Giá trị thập phân của tổng: " << (ps1.Sum(ps2)).DecimalValue() << endl;
    cout << "Hiệu của hai phân số là: "; (ps1.Difference(ps2)).Xuat(); cout << endl;
    cout << "Giá trị thập phân của hiệu: " << (ps1.Difference(ps2)).DecimalValue() << endl;
    cout << "Tích của hai phân số là: "; (ps1.Product(ps2)).Xuat(); cout << endl;
    cout << "Giá trị thập phân của tích: " << (ps1.Product(ps2)).DecimalValue() << endl;
    cout << "Thương của hai phân số là: "; (ps1.Quotient(ps2)).Xuat(); cout << endl;
    cout << "Giá trị thập phân của thương: " << (ps1.Quotient(ps2)).DecimalValue() << endl;

    return 0;
}
