#include <bits/stdc++.h>//STRUCT CỘNG THÊM 30 NGÀY
using namespace std;
struct Date {
	int day;
	int month;
	int year;
};
bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int daysInMonth(int month, int year) {
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    default:
        return 0;
    }
}
Date getNextDay(Date current) {
    Date nextDate = current;
    nextDate.day +=30;

    if (nextDate.day > daysInMonth(current.month, current.year)) {
        nextDate.day -=daysInMonth(nextDate.month, nextDate.year);
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

    cout << "Nhập ngày (dd mm yyyy): ";
    cin >> today.day >> today.month >> today.year;

    if (today.month < 1 || today.month > 12 || today.day < 1 || today.day > daysInMonth(today.month, today.year)) {
        cout << "Ngày không hợp lệ" << endl;
        return 1;
    }

    Date nextDay = getNextDay(today);

    cout << "30 ngày tiếp theo là: " << nextDay.day << "/" << nextDay.month << "/" << nextDay.year << endl;

    return 0;
}
