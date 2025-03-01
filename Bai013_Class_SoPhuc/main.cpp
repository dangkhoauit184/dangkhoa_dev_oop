#include <iostream>
using namespace std;

// Lớp Số Phức
class SoPhuc {
private:
    int thuc, ao;
public:
    SoPhuc();
    SoPhuc(int thuc, int ao);
    void Nhap();
    void Xuat();
    SoPhuc Cong(SoPhuc &sp2);
    SoPhuc Tru(SoPhuc &sp2);
};
// Định nghĩa constructor
SoPhuc::SoPhuc() : thuc(0), ao(0) {}
SoPhuc::SoPhuc(int thuc, int ao) {
    this->thuc = thuc;
    this->ao = ao;
}
// Hàm Nhập 2 số phức
void SoPhuc::Nhap() {
    cout << "Nhập phần thực: ";
    cin >> this->thuc;
    cout << "Nhập phần ảo: ";
    cin >> this->ao;
}

void SoPhuc::Xuat() {
    if (this->ao < 0) {
        cout << this->thuc << " - " << -this->ao << "i" << endl;
    } else {
        cout << this->thuc << " + " << this->ao << "i" << endl;
    }
}

SoPhuc SoPhuc::Cong(SoPhuc &sp2) {
    return SoPhuc(this->thuc + sp2.thuc, this->ao + sp2.ao);
}

SoPhuc SoPhuc::Tru(SoPhuc &sp2) {
    return SoPhuc(this->thuc - sp2.thuc, this->ao - sp2.ao);
}

int main() {
    SoPhuc sp1, sp2, kq;
    
    cout << "Nhập số phức thứ nhất: " << endl;
    sp1.Nhap();
    cout << "Nhập số phức thứ hai: " << endl;
    sp2.Nhap();
    
    cout << "Hai số phức vừa nhập là: " << endl;
    cout << "Số phức thứ nhất: "; sp1.Xuat();
    cout << "Số phức thứ hai: "; sp2.Xuat();
    
    kq = sp1.Cong(sp2);
    cout << "Kết quả cộng hai số phức là: "; kq.Xuat();
    
    kq = sp1.Tru(sp2);
    cout << "Kết quả trừ hai số phức là: "; kq.Xuat();
    
    return 0;
}
