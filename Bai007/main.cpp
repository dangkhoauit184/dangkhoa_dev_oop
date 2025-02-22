// SỐ PHỨC (COMPLEX NUMBERS)
#include<bits/stdc++.h>
using namespace std;
//Khai báo struct số phức gồm phần thực và phần ảo
struct complexNumbers{ 
	int real;
	int imag;
};
//Hàm nhập hai số phức
void Nhập(complexNumbers &sp){
	cout<<"Nhập phần thực ";
	cin>>sp.real;
	cout<<"Nhập phần ảo ";
	cin>>sp.imag;
}
//Hàm xuất hai số phức
void Xuất(complexNumbers sp){ //Hàm xuất số phức
	if(sp.imag < 0 ){
		cout<<sp.real<<"-"<<-sp.imag<<"i"<<endl;
	}
	else 
	cout<<sp.real<<" + "<<sp.imag<<"i"<<endl;
}
//Hàm xuất hai số phức trước khi cộng
void xuất(complexNumbers sp1, complexNumbers sp2){ 
	cout<<"Số phức thứ nhất là:";
	Xuất(sp1);
	cout<<"Số phức thứ hai là:";
	Xuất(sp2);
}
//Hàm cộng hai số phức
complexNumbers Plus(complexNumbers sp1, complexNumbers sp2){
	complexNumbers ketQua;
	ketQua.real = sp1.real + sp2.real;
	ketQua.imag = sp1.imag + sp2.imag;
	return ketQua;
}
//Hàm trừ hai số phức
complexNumbers Minus(complexNumbers sp1, complexNumbers sp2){ 
	complexNumbers ketQua;
	ketQua.real = sp1.real - sp2.real;
	ketQua.imag = sp1.imag - sp2.imag;
	return ketQua;
}
int main()
{
	complexNumbers sp1, sp2, Kq;
	cout<<"Nhập số phức thứ nhất "<<endl;
	Nhập(sp1);
	cout<<"Nhập số phức thứ hai"<<endl;
	Nhập(sp2);
	cout<<"Hai số phức vừa nhập là:"<<endl;
	xuất(sp1, sp2);
	Kq = Plus(sp1, sp2);
	cout<<"Kết quả cộng hai số phức là:";
	Xuất(Kq);
	Kq = Minus(sp1, sp2);
	cout<<"Kết quả trừ hai số phức là:";
	Xuất(Kq);
	return 0;
}
