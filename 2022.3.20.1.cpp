#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int months[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int Getday(int y, int m, int d) {
    //Äê
    int days1 = y * 365 + y / 4 - y / 100 + y / 400;
    //ÔÂ
    int days2 = 0;
    for (int i = 1; i < m; i++) {
        days2 += months[i];
    }
    //ÈòÄê
    if (m > 2 &&
        (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
    {
        days2++;
    }return days1 + days2 + d;
}

int main() {
    int year1, month1, day1;
    int year2, month2, day2;
    scanf("%4d%2d%2d", &year1, &month1, &day1);
    scanf("%4d%2d%2d", &year2, &month2, &day2);
    int d1 = Getday(year1, month1, day1);
    int d2 = Getday(year2, month2, day2);
    cout << abs(d1 - d2) << endl;
    return 0;
}

