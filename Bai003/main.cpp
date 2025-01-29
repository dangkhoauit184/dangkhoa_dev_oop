#include<bits/stdc++.h>//STRUCT CHIA HAI PHÂN SỐ
using namespace std;
struct Phanso
{
    int tuso;
    int mauso;
};
void nhap(Phanso &x)
{
    cout<<"Nhập tử số: ";
    cin>>x.tuso;
    cout<<"Nhập mẫu số: ";
    cin>>x.mauso;
}
void xuat(Phanso x)
{
    cout<< x.tuso<<"/"<<x.mauso; 
}
int ucln(int a, int b)
{
    while(b!=0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return abs(a);
}
void rutgon(Phanso &Ps)
{
    int gcd=ucln(Ps.tuso,Ps.mauso);
    Ps.tuso/=gcd;
    Ps.mauso/=gcd;
    if(Ps.mauso<0)
    {
        Ps.tuso=-Ps.tuso;
        Ps.mauso=-Ps.mauso;
    }
}
Phanso ThuongPhanSo (Phanso ps1 ,  Phanso ps2)
{
    Phanso PhanSoThuong ;
    PhanSoThuong.tuso=ps1.tuso*ps2.mauso;
    PhanSoThuong.mauso=ps1.mauso*ps2.tuso;
    rutgon(PhanSoThuong);
    return PhanSoThuong;
}
int main()
{
    Phanso ps1, ps2;
    cout<<"Nhập phân số thứ nhất"<<endl;
    nhap(ps1);
    cout<<"Nhập phân số thứ hai"<<endl;
    nhap(ps2);
    cout<<"Hai phân số vừa nhập là: "<<endl;
    xuat(ps1);cout<<endl;    
    xuat(ps2);cout<<endl;
    cout<<"Rút gọn phân số thứ nhất: ";
    rutgon(ps1);
    xuat(ps1); cout<<endl;
    cout<<"Rút gọn phân số thứ hai: ";
    rutgon(ps2);
    xuat(ps2); cout<<endl;
    cout<<"Thương hai phân số là: ";
    Phanso PhanSoThuong = ThuongPhanSo(ps1,ps2);
    xuat(PhanSoThuong);
    return 0;
}
