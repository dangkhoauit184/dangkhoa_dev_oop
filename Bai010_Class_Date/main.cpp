#include <iostream>
using namespace std;

// Class Date
class Date {
private:
    int day;
    int month;
    int year;
public:
    void Input();
    void Output();
    bool isLeapYear();
    int daysInMonth() const;
    Date getNextDay();

    // Thêm getter cho day, month, year
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
};

// Hàm nhập Date
void Date::Input() {
    cout << "Nhap ngay (dd mm yyyy): ";
    cin >> this->day >> this->month >> this->year;
}

// Hàm xuất Date
void Date::Output() {
    cout << this->day << "/" << this->month << "/" << this->year << endl;
}

// Kiểm tra năm nhuận
bool Date::isLeapYear() {
    return (this->year % 4 == 0 && this->year % 100 != 0) || (this->year % 400 == 0);
}

// Trả về số ngày trong tháng
int Date::daysInMonth() const {
    switch (this->month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return ((this->year % 4 == 0 && this->year % 100 != 0) || (this->year % 400 == 0)) ? 29 : 28;
    default:
        return 0;
    }
}

// Trả về ngày tiếp theo
Date Date::getNextDay() {
    Date nextDate = *this;
    nextDate.day++;
    
    if (nextDate.day > nextDate.daysInMonth()) {
        nextDate.day = 1;
        nextDate.month++;
        
        if (nextDate.month > 12) {
            nextDate.month = 1;
            nextDate.year++;
        }
    }
    return nextDate;
}

int main() {
    Date today;
    today.Input();
    
    // Sử dụng getter thay vì truy cập trực tiếp thành viên private
    if (today.getMonth() < 1 || today.getMonth() > 12 || today.getDay() < 1 || today.getDay() > today.daysInMonth()) {
        cout << "Ngay khong hop le" << endl;
        return 1;
    }
    
    cout << "Ngay vua nhap: ";
    today.Output();
    
    Date nextDay = today.getNextDay();
    cout << "Ngay tiep theo la: ";
    nextDay.Output();
    
    return 0;
}
