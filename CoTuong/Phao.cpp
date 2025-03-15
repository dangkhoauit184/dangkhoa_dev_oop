#include "Phao.h"
#include <iostream>
using namespace std;

Phao::Phao() {}
Phao::~Phao() {}

void Phao::nhap() {
    QuanCo::nhap();
}
void Phao::xuat() {
    QuanCo::xuat();
    cout << "Quan co nay la: Phao" << endl;
}
void Phao::cachDi() {
    cout << "Cach di Phao: Di nhu Xe, muon an quan thi phai nhay qua dung 1 quan can.\n";
}
