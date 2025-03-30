#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct SinhVien {
    string maSo;
    string hoTen;
    float diemTB;
    SinhVien* tiepTheo;
};
// Tổng hợp các hàm cần thiết cho chương trình quản lý sinh viên
void themSinhVien(SinhVien*& danhSach, string ms, string ht, float dtb);
void nhapDanhSach(SinhVien*& danhSach);
void hienThiSV(SinhVien* sv);
void hienThiDanhSach(SinhVien* danhSach);
SinhVien* timSV(SinhVien* danhSach, string ms);
void xoaSV(SinhVien*& danhSach, string ms);
void lietKeSVKha(SinhVien* danhSach);
string xepLoai(float diem);
void sapXepTheoDiem(SinhVien*& danhSach);
void chenSV(SinhVien*& danhSach, string ms, string ht, float dtb);
void xoaDanhSach(SinhVien*& danhSach);

//Hàm thêm sinh viên vào đầu danh sách
void themSinhVien(SinhVien*& danhSach, string ms, string ht, float dtb) {
    SinhVien* svMoi = new SinhVien{ ms, ht, dtb, danhSach };
    danhSach = svMoi;
}
// Nhập danh sách sinh viên từ bàn phímDS
void nhapDanhSach(SinhVien*& danhSach) {
    string ms, ht;
    float dtb;

    cout << "\nNHAP DANH SACH SINH VIEN (nhap ten la khoang trang de ket thuc)\n"; //Kết thúc nhập danh sách sinh viên

    while (true) {
        cout << "\nNhap thong tin sinh vien:\n";

        cout << "Ho ten: ";
        getline(cin, ht);
        if (ht == " ") {
            cout << "Da ket thuc nhap danh sach.\n";
            break;
        }

        cout << "Ma so: ";
        getline(cin, ms);

        cout << "Diem TB: ";
        cin >> dtb;
        cin.ignore();

        themSinhVien(danhSach, ms, ht, dtb);
    }
}
// Hiển thị thông tin sinh viên
void hienThiSV(SinhVien* sv) {
    if (!sv) return;
    cout << sv->maSo << " - " << sv->hoTen << " - "
        << fixed << setprecision(2) << sv->diemTB
        << " - " << xepLoai(sv->diemTB) << endl;
}
// Hiển thị danh sách sinh viên    
void hienThiDanhSach(SinhVien* danhSach) {
    cout << "\nDANH SACH SINH VIEN:\n";
    SinhVien* hienTai = danhSach;
    while (hienTai) {
        hienThiSV(hienTai);
        hienTai = hienTai->tiepTheo;
    }
}
// Tìm kiếm sinh viên trong lớp học theo mã số
SinhVien* timSV(SinhVien* danhSach, string ms) {
    SinhVien* hienTai = danhSach;
    while (hienTai) {
        if (hienTai->maSo == ms) return hienTai;
        hienTai = hienTai->tiepTheo;
    }
    return nullptr;
}
// Xóa sinh viên theo mã số
void xoaSV(SinhVien*& danhSach, string ms) {
    if (!danhSach) return;

    SinhVien* truoc = nullptr;
    SinhVien* hienTai = danhSach;

    while (hienTai && hienTai->maSo != ms) {
        truoc = hienTai;
        hienTai = hienTai->tiepTheo;
    }

    if (!hienTai) {
        cout << "Khong tim thay SV!\n";
        return;
    }

    if (!truoc) {
        danhSach = hienTai->tiepTheo;
    }
    else {
        truoc->tiepTheo = hienTai->tiepTheo;
    }

    delete hienTai;
    cout << "Da xoa SV!\n";
}
// Xếp loại sinh viên theo điểm
string xepLoai(float diem) {
    if (diem >= 9) return "Xuat sac";
    if (diem >= 8) return "Gioi";
    if (diem >= 7) return "Kha";
    if (diem >= 6.5) return "TB Kha";
    if (diem >= 5) return "Trung binh";
    if (diem >= 3.6) return "Yeu";
    return "Kem";
}

// Liệt kê sinh viên có điểm >= 5
void lietKeSVKha(SinhVien* danhSach) {
    cout << "\nSINH VIEN DAT (>=5):\n";
    bool timThay = false;

    SinhVien* hienTai = danhSach;
    while (hienTai) {
        if (hienTai->diemTB >= 5) {
            hienThiSV(hienTai);
            timThay = true;
        }
        hienTai = hienTai->tiepTheo;
    }

    if (!timThay) cout << "Khong co SV nao!\n";
}

// Sắp xếp danh sách sinh viên theo điểm trung bình
void sapXepTheoDiem(SinhVien*& danhSach) {
    if (!danhSach || !danhSach->tiepTheo) return;

    bool daSapXep;
    do {
        daSapXep = true;
        SinhVien* truoc = nullptr;
        SinhVien* hienTai = danhSach;

        while (hienTai->tiepTheo) {
            if (hienTai->diemTB > hienTai->tiepTheo->diemTB) {
                swap(hienTai->maSo, hienTai->tiepTheo->maSo);
                swap(hienTai->hoTen, hienTai->tiepTheo->hoTen);
                swap(hienTai->diemTB, hienTai->tiepTheo->diemTB);
                daSapXep = false;
            }
            hienTai = hienTai->tiepTheo;
        }
    } while (!daSapXep);
}
// Chèn sinh viên vào danh sách đã sắp xếp theo điểm
void chenSV(SinhVien*& danhSach, string ms, string ht, float dtb) {
    sapXepTheoDiem(danhSach);

    SinhVien* svMoi = new SinhVien{ ms, ht, dtb, nullptr };

    if (!danhSach || dtb <= danhSach->diemTB) {
        svMoi->tiepTheo = danhSach;
        danhSach = svMoi;
        return;
    }

    SinhVien* hienTai = danhSach;
    while (hienTai->tiepTheo && hienTai->tiepTheo->diemTB < dtb) {
        hienTai = hienTai->tiepTheo;
    }

    svMoi->tiepTheo = hienTai->tiepTheo;
    hienTai->tiepTheo = svMoi;
}
// Xóa toàn bộ danh sách sinh viên
void xoaDanhSach(SinhVien*& danhSach) {
    while (danhSach) {
        SinhVien* temp = danhSach;
        danhSach = danhSach->tiepTheo;
        delete temp;
    }
}
// Hàm main
int main() {
    SinhVien* danhSach = nullptr;
    int luaChon;

    do {
        cout << "\n===== QUAN LY SINH VIEN =====\n";
        cout << "1. Nhap danh sach\n";
        cout << "2. Hien thi danh sach\n";
        cout << "3. Tim sinh vien\n";
        cout << "4. Xoa sinh vien\n";
        cout << "5. Liet ke SV co diem >=5\n";
        cout << "6. Sap xep theo diem\n";
        cout << "7. Chen SV (da sap xep)\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> luaChon;
        cin.ignore();

        switch (luaChon) {
        case 1:
            nhapDanhSach(danhSach);
            break;
        case 2:
            hienThiDanhSach(danhSach);
            break;
        case 3: {
            string ms;
            cout << "Nhap ma so: ";
            getline(cin, ms);
            SinhVien* sv = timSV(danhSach, ms);
            if (sv) {
                cout << "Tim thay: ";
                hienThiSV(sv);
            }
            else {
                cout << "Khong tim thay!\n";
            }
            break;
        }
        case 4: {
            string ms;
            cout << "Nhap ma so can xoa: ";
            getline(cin, ms);
            xoaSV(danhSach, ms);
            break;
        }
        case 5:
            lietKeSVKha(danhSach);
            break;
        case 6:
            sapXepTheoDiem(danhSach);
            cout << "Da sap xep!\n";
            break;
        case 7: {
            string ms, ht;
            float dtb;
            cout << "Nhap ma so: "; getline(cin, ms);
            cout << "Nhap ten: "; getline(cin, ht);
            cout << "Nhap diem: "; cin >> dtb;
            cin.ignore();
            chenSV(danhSach, ms, ht, dtb);
            break;
        }
        }
    } while (luaChon != 0);

    xoaDanhSach(danhSach);
    return 0;
}
