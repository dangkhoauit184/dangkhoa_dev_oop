#include "QuanCo.h"
#include <iostream>
using namespace std;

QuanCo::QuanCo() {}
QuanCo::~QuanCo() {}

void QuanCo::nhap() {
    cout << "Nhap ten quan co: ";
    getline(cin, ten);

    cout << "Nhap mau (Trang hoac Den): ";
    getline(cin, mau);
}

void QuanCo::xuat() {
    cout << "Ten quan co: " << ten << endl;
    cout << "Mau quan co: " << mau << endl;
}
