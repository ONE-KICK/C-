#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>days = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int year1, month1, day1;
	int year2, month2, day2;
	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
	{
		int account=0;
		--day1;
		while (year1 < year2 || month1 < month2)
		{
			account += (((month1 == 2 && ((year1 % 4 == 0 && year1 % 100 != 0) || year1 % 400 == 0)) ? 29 : days[month1]) - day1) * ((month1 == 2 || month1 == 3 || month1 == 5 || month1 == 7 || month1 == 11) ? 1 : 2);

			day1 = 0;

			if (++month1 > 12)
			{
				month1 = 1;
				year1++;
			}
		}
		cout << account + (day2 - day1) * ((month1 == 2 || month1 == 3 || month1 == 5 || month1 == 7 || month1 == 11) ? 1 : 2) << endl;
	}
	return 0;
}