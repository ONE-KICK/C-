#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

bool Isleap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    return false;
}

int Getday(int year, int month, int day, int n) 
{
    int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    while (n+day > days[month])
    {
        days[2] = 28;
        if (Isleap(year))
        {
            days[2] = 29;
        }
        n -= days[month];
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }day += n;
    printf("%4d-%02d-%02d", year, month, day);
    cout << endl;
    return 0;
}



int main() {
    int year = 0;
    int month = 0;
    int day = 0;
    int n = 0;
    int m = 0;
    scanf("%d", &m);
   
    for(int i=0;i<m;i++)
    {
        scanf("%4d %d %d %d", &year, &month, &day, &n);
        Getday(year, month, day, n); 
    }
  
    return 0;
}