#include <iostream>
#include<iomanip>
using namespace std;
class SinhVien {
private:
    string MaSV;
    string HoTen;
    int Tuoi;
    float DiemToan;
    float DiemVan;
    float DiemAnh;
    float DiemTB;
public:
    void Nhap();   
    void Xuat(); 
    void TinhDiemTB();     
    float DiemTBMon();  
};
void SinhVien::Nhap() {
    cout << "Nhập mã sinh viên: ";
    cin >> MaSV;
    cin.ignore(); 

    cout << "Nhập họ và tên sinh viên: ";
    getline(cin, HoTen);

    cout << "Nhập tuổi sinh viên: ";
    cin >> Tuoi;

    cout << "Nhập điểm Toán: ";
    cin >> DiemToan;

    cout << "Nhập điểm Văn: ";
    cin >> DiemVan;

    cout << "Nhập điểm Anh: ";
    cin >> DiemAnh;

    TinhDiemTB();
}
void SinhVien::TinhDiemTB() {
    DiemTB = ((DiemToan * 2) + (DiemVan * 2) + (DiemAnh * 1)) / 5;
}
void SinhVien::Xuat() {
    cout << "Mã sinh viên: " << MaSV << endl;
    cout << "Họ và tên: " << HoTen << endl;
    cout << "Tuổi: " << Tuoi << endl;
    cout << "Điểm Toán: " << DiemToan << endl;
    cout << "Điểm Văn: " << DiemVan << endl;
    cout << "Điểm Anh: " << DiemAnh << endl;
    cout << "Điểm trung bình: " << fixed << setprecision(2) << DiemTB << endl;
}
float SinhVien::DiemTBMon() {
    return DiemTB;
}
int main() {
    int n;
    cout << "Nhập số lượng sinh viên: ";
    cin >> n;

    SinhVien dssv[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhập thông tin sinh viên thứ " << i + 1 << endl;
        dssv[i].Nhap();
    }

    cout << endl;
    cout << "Danh sách sinh viên:" << endl;
    for (int i = 0; i < n; i++) {
        dssv[i].Xuat();
    }
    
    SinhVien MaxSV = dssv[0];
    for (int i = 1; i < n; i++) {
        if (dssv[i].DiemTBMon() > MaxSV.DiemTBMon()) {
            MaxSV = dssv[i];
        }
    }
    cout << endl;
    cout << "Sinh viên có điểm trung bình cao nhất:" << endl;
    MaxSV.Xuat();
    cout << "Nguyễn Minh Nhựt trùm oop";
    return 0;
}
