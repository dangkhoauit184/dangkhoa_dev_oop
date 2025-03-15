#include "Tot.h"
#include <iostream>
using namespace std;

Tot::Tot() {}
Tot::~Tot() {}

void Tot::nhap() {
    QuanCo::nhap();
}
void Tot::xuat() {
    QuanCo::xuat();
    cout << "Quan co nay la: Tot" << endl;
}
void Tot::cachDi() {
    cout << "Cach di Tot: Di thang moi lan chi duoc di chuyen 1 o, sau khi qua song co the vua di ngang vua di thang.\n";
}
