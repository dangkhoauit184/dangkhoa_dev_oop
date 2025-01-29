    #include<bits/stdc++.h>//STRUCT CỘNG GIỜ PHÚT GIÂY
    using namespace std;
    struct ThoiGian{
        int gio, phut, giay;
    };
    void Nhapthoigian(ThoiGian &t)
    {
        cout<<"giờ phút giây";
        cin>>t.gio;
        cin>>t.phut;
        cin>>t.giay;
    }
    void XuatThoiGian(ThoiGian t)
    {
        cout<<setw(2)<<setfill('0')<<t.gio<<":";
        cout<<setw(2)<<setfill('0')<<t.phut<<":";
        cout<<setw(2)<<setfill('0')<<t.giay<<endl;
    }
    void ChuanHoaThoiGian(ThoiGian &t)
    {
        if(t.giay>=60){
            t.phut+=t.giay/60;
            t.giay=t.giay%60;
        }
        if(t.giay<0){
            t.phut-=1;
            t.giay+=60;
        }
        if(t.phut>=60){
            t.gio+=t.phut/60;
            t.phut=t.phut%60;
        }
        if(t.phut<0){
            t.gio-=1;
            t.phut+=60;
        }
        if(t.gio>=24){
            t.gio=t.gio%24;
        }
        if(t.gio<0){
            t.gio+=24;
        }
    }
    ThoiGian CongThoiGian(ThoiGian t, int conggio, int congphut, int conggiay){
        t.gio+=conggio;
        t.phut+=congphut;
        t.giay+=conggiay;
        ChuanHoaThoiGian(t);
        return t;
    }
    int main()
    {
        ThoiGian hientai, congthem,ketqua;
        int conggio, congphut, conggiay;
        cout<<"Nhập thời gian hiện tại:";
        Nhapthoigian(hientai);
        cout<<"Nhập thời gian cần thêm:";
        cin>>conggio>>congphut>>conggiay;
        ketqua=CongThoiGian(hientai, conggio, congphut, conggiay);
        cout<<"Thời gian sau khi cộng thêm: ";
        XuatThoiGian(ketqua);
        return 0;

    }
//Chúc sư phụ năm mới vui vẻ
