#include "TuongJ.h"
#include <iostream>
using namespace std;

TuongJ::TuongJ() {}
TuongJ::~TuongJ() {}

void TuongJ::nhap() {
    QuanCo::nhap();
}
void TuongJ::xuat() {
    QuanCo::xuat();
    cout << "Quan co nay la: TuongJ" << endl;
}
void TuongJ::cachDi() {
    cout << "Cach di TuongJ: Di cheo 2 o, duoc phep ra khoi o cung va khong duoc qua song\n";
}
#pragma once
