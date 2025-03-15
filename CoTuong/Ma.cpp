#include "Ma.h"
#include <iostream>
using namespace std;

Ma::Ma() {}
Ma::~Ma() {}

void Ma::nhap() {
    QuanCo::nhap();
}
void Ma::xuat() {
    QuanCo::xuat();
    cout << "Quan co nay la: Ma" << endl;
}
void Ma::cachDi() {
    cout << "Cach di Ma: Di hinh chu L(2 o x 1 o) dac biet la khong bi can chan.\n";
}
