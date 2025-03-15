#include "Si.h"
#include <iostream>
using namespace std;

Si::Si() {}
Si::~Si() {}

void Si::nhap() {
    QuanCo::nhap();
}
void Si::xuat() {
    QuanCo::xuat();
    cout << "Quan co nay la: Sĩ" << endl;
}
void Si::cachDi() {
    cout << "Cach di Sĩ: Di chéo 1 ô trong phạm vi cung.\n";
}
