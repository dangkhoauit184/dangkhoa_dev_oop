#include "Tuong.h"
#include <iostream>
using namespace std;

Tuong::Tuong() {}
Tuong::~Tuong() {}

void Tuong::nhap() {
    QuanCo::nhap();
}

void Tuong::xuat() {
    QuanCo::xuat();
    cout << "Quan co nay la: Tuong" << endl;
}

void Tuong::cachDi() {
    cout << "Cach di Tuong: Di 1 ô ngang hoac doc trong o cung (cot 4 5 6, hang 1 2 3 hoac 8 9 10).\n";
}
