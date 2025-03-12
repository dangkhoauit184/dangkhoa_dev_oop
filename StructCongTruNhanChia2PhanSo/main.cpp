#include <iostream>
using namespace std;

struct PhanSo {
    int tuso;
    int mauso;
};

void Nhap(PhanSo &x){
    cout << "Nhập tử số: ";
    cin >> x.tuso;
    cout << "Nhập mẫu số: ";
    cin >> x.mauso;
    while(x.mauso == 0){
        cout << "Mẫu số khác không, vui lòng nhập lại mẫu số!\n";
        cout << "Nhập mẫu số: ";
        cin >> x.mauso;
    }
}

void Xuat(PhanSo x){
    if (x.mauso < 0){
        x.tuso = -x.tuso;
        x.mauso = -x.mauso;
    }
    if (x.mauso == 1){
        cout << x.tuso; 
    } else {
        cout << x.tuso << "/" << x.mauso;
    }
}

int UCLN(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return abs(a);
}

void RutGon(PhanSo &ps){
    int gcd = UCLN(ps.tuso, ps.mauso);
    ps.tuso /= gcd;
    ps.mauso /= gcd;
    // Đảm bảo mẫu số dương sau khi rút gọn
    if(ps.mauso < 0){
        ps.tuso = -ps.tuso;
        ps.mauso = -ps.mauso;
    }
}

double GiaTriThapPhan(PhanSo ps){
    return static_cast<double>(ps.tuso) / ps.mauso;
}

PhanSo TongPhanSo(PhanSo ps1, PhanSo ps2){
    PhanSo result;
    result.tuso = ps1.tuso * ps2.mauso + ps2.tuso * ps1.mauso;
    result.mauso = ps1.mauso * ps2.mauso;
    RutGon(result);
    return result;
}

PhanSo HieuPhanSo(PhanSo ps1, PhanSo ps2){
    PhanSo result;
    result.tuso = ps1.tuso * ps2.mauso - ps2.tuso * ps1.mauso;
    result.mauso = ps1.mauso * ps2.mauso;
    RutGon(result);
    return result;
}

PhanSo TichPhanSo(PhanSo ps1, PhanSo ps2){
    PhanSo result;
    result.tuso = ps1.tuso * ps2.tuso;
    result.mauso = ps1.mauso * ps2.mauso;
    RutGon(result);
    return result;
}

PhanSo ThuongPhanSo(PhanSo ps1, PhanSo ps2){
    PhanSo result;
    result.tuso = ps1.tuso * ps2.mauso;
    result.mauso = ps1.mauso * ps2.tuso;
    RutGon(result);
    return result;
}

int main(){
    PhanSo ps1, ps2;
    
    cout << "Nhập phân số thứ nhất:\n";
    Nhap(ps1);
    
    cout << "Nhập phân số thứ hai:\n";
    Nhap(ps2);

    // Rút gọn trước khi tính
    RutGon(ps1);
    RutGon(ps2);

    cout << "\nPhân số thứ nhất sau khi rút gọn: ";
    Xuat(ps1);
    cout << "\nPhân số thứ hai sau khi rút gọn: ";
    Xuat(ps2);

    // Tính tất cả các phép toán
    PhanSo psTong = TongPhanSo(ps1, ps2);
    PhanSo psHieu = HieuPhanSo(ps1, ps2);
    PhanSo psTich = TichPhanSo(ps1, ps2);
    PhanSo psThuong = ThuongPhanSo(ps1, ps2);

    // Xuất kết quả
    cout << "\n\n===== Kết quả 4 phép tính =====\n";

    cout << "Tổng: ";
    Xuat(psTong);
    cout << " = " << GiaTriThapPhan(psTong) << endl;
    
    cout << "Hiệu: ";
    Xuat(psHieu);
    cout << " = " << GiaTriThapPhan(psHieu) << endl;
    
    cout << "Tích: ";
    Xuat(psTich);
    cout << " = " << GiaTriThapPhan(psTich) << endl;
    
    cout << "Thương: ";
    Xuat(psThuong);
    cout << " = " << GiaTriThapPhan(psThuong) << endl;

    return 0;
}
