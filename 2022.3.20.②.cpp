#include<iostream>

using namespace std;

int GetDate(int year, int day)
{
    int months[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int i = 1;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        months[2] = 29;
    }
    while (day > months[i]) {
        day -= months[i];
        ++i;
    }
    printf("%04d-%02d-%02d", year, i, day);
    return 1;
}

int main() {
    int year = 0;
    int day = 0;
    while (cin >> year >> day)
    {
        GetDate(year, day);
        cout << endl;
    }
    return 0;
}

