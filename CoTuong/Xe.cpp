#include "Xe.h"
#include <iostream>
using namespace std;

Xe::Xe() {}
Xe::~Xe() {}

void Xe::nhap() {
    QuanCo::nhap();
}
void Xe::xuat() {
    QuanCo::xuat();
    cout << "Quan co nay la: Xe" << endl;
}
void Xe::cachDi() {
    cout << "Cach di Xe: Di thang hoac di ngang khong duoc di cheo, khong han che o.\n";
}
