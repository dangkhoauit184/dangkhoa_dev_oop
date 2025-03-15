#include <iostream>
#include "Tuong.h"
#include "Si.h"
#include "TuongJ.h"
#include "Xe.h"
#include "Ma.h"
#include "Phao.h"
#include "Tot.h"

using namespace std;

int main() {
    cout << "Chon loai quan co tuong de nhap:\n";
    cout << "1. Tuong\n";
    cout << "2. Si\n";
    cout << "3. TuongJ\n";
    cout << "4. Xe\n";
    cout << "5. Ma\n";
    cout << "6. Phao\n";
    cout << "7. Tot\n";

    int loai;
    cin >> loai;
    cin.ignore();

    if (loai == 1) {
        Tuong t;
        t.nhap();
        cout << "\n--- Thong tin quan co ---\n";
        t.xuat();
        cout << "--- Cach di ---\n";
        t.cachDi();

    }
    else if (loai == 2) {
        Si s;
        s.nhap();
        cout << "\n--- Thong tin quan co ---\n";
        s.xuat();
        cout << "--- Cach di ---\n";
        s.cachDi();

    }
    else if (loai == 3) {
        TuongJ tb;
        tb.nhap();
        cout << "\n--- Thong tin quan co ---\n";
        tb.xuat();
        cout << "--- Cach di ---\n";
        tb.cachDi();

    }
    else if (loai == 4) {
        Xe x;
        x.nhap();
        cout << "\n--- Thong tin quan co ---\n";
        x.xuat();
        cout << "--- Cach di ---\n";
        x.cachDi();

    }
    else if (loai == 5) {
        Ma m;
        m.nhap();
        cout << "\n--- Thong tin quan co ---\n";
        m.xuat();
        cout << "--- Cach di ---\n";
        m.cachDi();

    }
    else if (loai == 6) {
        Phao p;
        p.nhap();
        cout << "\n--- Thong tin quan co ---\n";
        p.xuat();
        cout << "--- Cach di ---\n";
        p.cachDi();

    }
    else if (loai == 7) {
        Tot t;
        t.nhap();
        cout << "\n--- Thong tin quan co ---\n";
        t.xuat();
        cout << "--- Cach di ---\n";
        t.cachDi();

    }
    else {
        cout << "Lua chon khong hop le!\n";
    }
    return 0;
}
