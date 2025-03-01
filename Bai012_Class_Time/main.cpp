#include <iostream>
#include <iomanip>
using namespace std;

// Lớp Thời Gian
class ThoiGian {
private:
    int gio, phut, giay;
public:
    ThoiGian();
    ThoiGian(int gio, int phut, int giay);
    void Nhap();
    void NhapGio(int &conggio);
    void NhapPhut(int &congphut);
    void NhapGiay(int &conggiay);
    void Xuat();
    void ChuanHoa();
    ThoiGian Cong(int conggio, int congphut, int conggiay);
};

// Định nghĩa constructor
ThoiGian::ThoiGian() : gio(0), phut(0), giay(0) {}
ThoiGian::ThoiGian(int gio, int phut, int giay) {
    this->gio = gio;
    this->phut = phut;
    this->giay = giay;
}

void ThoiGian::Nhap() {
    cout << "Nhập giờ: ";
    cin >> this->gio;
    cout << "Nhập phút: ";
    cin >> this->phut;
    cout << "Nhập giây: ";
    cin >> this->giay;
}

void ThoiGian::NhapGio(int &conggio) {
    cout << "Nhập số giờ cần cộng thêm: ";
    cin >> conggio;
}

void ThoiGian::NhapPhut(int &congphut) {
    cout << "Nhập số phút cần cộng thêm: ";
    cin >> congphut;
}

void ThoiGian::NhapGiay(int &conggiay) {
    cout << "Nhập số giây cần cộng thêm: ";
    cin >> conggiay;
}

void ThoiGian::Xuat() {
    cout << setw(2) << setfill('0') << this->gio << ":";
    cout << setw(2) << setfill('0') << this->phut << ":";
    cout << setw(2) << setfill('0') << this->giay << endl;
}

void ThoiGian::ChuanHoa() {
    if (this->giay >= 60) {
        this->phut += this->giay / 60;
        this->giay %= 60;
    }
    if (this->giay < 0) {
        this->phut -= 1;
        this->giay += 60;
    }
    if (this->phut >= 60) {
        this->gio += this->phut / 60;
        this->phut %= 60;
    }
    if (this->phut < 0) {
        this->gio -= 1;
        this->phut += 60;
    }
    if (this->gio >= 24) {
        this->gio %= 24;
    }
    if (this->gio < 0) {
        this->gio += 24;
    }
}

ThoiGian ThoiGian::Cong(int conggio, int congphut, int conggiay) {
    ThoiGian tg(this->gio + conggio, this->phut + congphut, this->giay + conggiay);
    tg.ChuanHoa();
    return tg;
}

int main() {
    ThoiGian hientai, ketqua;
    int conggio, congphut, conggiay;
    
    cout << "Nhập thời gian hiện tại:" << endl;
    hientai.Nhap();
    
    cout << "Nhập thời gian cần cộng thêm:" << endl;
    hientai.NhapGio(conggio);
    hientai.NhapPhut(congphut);
    hientai.NhapGiay(conggiay);
    
    ketqua = hientai.Cong(conggio, congphut, conggiay);
    
    cout << "Thời gian sau khi cộng thêm: ";
    ketqua.Xuat();
    
    return 0;
}
