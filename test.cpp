#include<iostream>
#include<vector>

using namespace std;

int main() {
	int year;
	int month;
	int day;
	vector <int>months = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	while (cin >> year >> month >> day) {
		int datecount = day;
		if (month == 2) {
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
				months[2] = 29;
			}
		}
		for (int i = 1; i < month; i++) {
			datecount += months[i];
		}cout << datecount << endl;
	} return 0;
}


//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//    int year = 0;
//    int month = 0;
//    int day = 0;
//    vector<int> months = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//
//    while (cin >> year >> month >> day)
//    {
//        int dateCount = day;
//
//        if (year % 4 == 0 && year % 100 != 0)
//        {
//            months[2] = 29;
//        }
//        else if (year % 100 == 0 && year % 400 == 0)
//        {
//            months[2] = 29;
//        }
//        else
//            months[2] = 28;
//        for (int i = 1; i < month; i++)
//        {
//            dateCount += months[i];
//        }
//        cout << dateCount << endl;
//    }
//    return 0;
//}