#include<bits/stdc++.h>//STRUCT NHÂN HAI ĐA THỨC
using namespace std;
struct DaThuc{
    double a;
    double b;
    double c;
};
void NhapDaThuc(DaThuc &x)
{
    cout<<"Nhập hệ số a của đa thức: ";
    cin>>x.a;
    cout<<"Nhập hệ số b của đa thức: ";
    cin>>x.b;
    cout<<"Nhập hệ số c cho đa thức: ";
    cin>>x.c;
}
void XuatDaThuc1(DaThuc x)
{
    cout<< x.a <<"x^2 + "<<x.b <<"x + "<<x.c<<endl;
}
void XuatDaThuc2(double a, double b, double c, double d, double e)//ĐÙNG ĐỂ XUẤT ĐA THỨC NHÂN
{
    cout<<a<<"x^4 + "<<b<<"x^3 + "<<c<<"x^2 + "<<d<<"x + "<<e<<endl;
}
DaThuc TongDaThuc(DaThuc dt1, DaThuc dt2)
{
    DaThuc Ketqua;
    Ketqua.a = dt1.a + dt2.a;
    Ketqua.b = dt1.b + dt2.b;
    Ketqua.c = dt1.c + dt2.c;
    return Ketqua;
}
DaThuc HieuDaThuc(DaThuc dt1, DaThuc dt2)
{
    DaThuc Ketqua;
    Ketqua.a = dt1.a - dt2.a;
    Ketqua.b = dt1.b - dt2.b;
    Ketqua.c = dt1.c - dt2.c;
    return Ketqua;
}
void TichDaThuc(DaThuc dt1 , DaThuc dt2 , double &a, double &b, double &c, double &d, double &e)
{
    a= dt1.a * dt2.a;
    b= dt1.a * dt2.b + dt1.b * dt2.a;
    c= dt1.a * dt2.c + dt1.b * dt2.b + dt1.c * dt2.a;
    d= dt1.b * dt2.c + dt1.c * dt2.b;
    e= dt1.c * dt2.c;
}
double GiaTriTaiF0(double e)
{
    return e;
}
int main()
{
    DaThuc dt1, dt2;
    cout<<"Nhập đa thức thứ nhất"<<endl;
    NhapDaThuc(dt1);
    cout<<"Nhập đa thức thứ hai"<<endl;
    NhapDaThuc(dt2);
    cout<<"Đa thức thứ nhất là: "; 
    XuatDaThuc1(dt1); 
    cout<<"Đa thức thứ hai là: ";
    XuatDaThuc1(dt2); 
    DaThuc tong = TongDaThuc(dt1, dt2);
    cout<<"Tổng hai đa thức là: ";
    XuatDaThuc1(tong);
    DaThuc hieu = HieuDaThuc(dt1,dt2);
    cout<<"Hiệu hai đa thức là: ";
    XuatDaThuc1(hieu);
    double a, b ,c , d, e;
    TichDaThuc(dt1,dt2,a,b,c,d,e);
    cout<<"Tích hai đa thức là: ";
    XuatDaThuc2(a,b,c,d,e);
    double giatri=GiaTriTaiF0(e);
    cout<<"Giá trị của biểu thức tại x bằng 0 là: "<<giatri;
    return 0;
}
