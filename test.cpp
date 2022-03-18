#include<iostream>
using namespace std;

class Date {
public:int GetMonthDay(int year, int month);//获取每个月天数的方法
	  bool IsLeap(int year);
	  friend ostream& operator<<(ostream & out, const Date & d);
	  //构造函数
	  Date (int year=2000,int month=1,int day=1) {
		  _year = year;
		  _month = month;
		  _day = day;
	  }
	  //拷贝构造函数
	  Date (const Date& d) {
		  _year = d._year;
		  _month = d._month;
		  _day = d._day;
	  }
	  //赋值运算符重载
	  Date& operator=(const Date& d) {
		  _year = d._year;
		  _month = d._month;
		  _day = d._day;
	  }
	  //析构函数
	  ~Date() {};
	  // 日期-=天数
	  Date& operator-=(int n) {
		  int days = 1;
		  while (n >= _day) {
			  _month--;
			  if (_month == 0) {
				  _year--;
				  _month = 12;
				  _day = 31;
			  }
			  days = GetMonthDay(_year, _month);
			  n -= _day;
			  _day = days;
		  }
		  _day -= n;
		  return *this;
	  }
	  // 日期-天数
	  Date operator-(int n){
		  int year = _year;
		  int month = _month;
		  int day = _day;
		  int days = 1;
		  while (n >= day) {
			  month--;
			  if (month == 0) {
				  year--;
				  month = 12;
				  day = 31;
			  }
			  days = GetMonthDay(year, month);
			  n -= day;
			  day = days; 
					  		  }
		  day -= n;
		  return Date(year,month,day);
	  }
	  // --日期
	  Date& operator--() {
		  *this -= 1;
		  return *this;
	  }
	  // 日期--
	  Date& operator--(int) {
		  Date tmp = *this;
		  *this -= 1;
		  return tmp;
	  }
	  // 日期++
	  Date& operator++(int) {
		  Date tmp = *this;
		  *this += 1;
		  return tmp;
	 }
	  // ++日期
	  Date& operator++() {
		  *this += 1;
		  return *this;
	  }
	  // 日期+=天数
	   Date& operator+=(int n) {
	  int days = GetMonthDay(_year, _month);
	  while (_day + n > days) {
		  _month++;
		  if (_month > 12) {
			  _year++;
			  _month = 1;
		  }n -= days;
		  days = GetMonthDay(_year, _month);
	  }
	  _day += n;
	  return *this;
}
	  // 日期+天数
	  Date operator+(int n) {
		  int year = _year;
		  int month = _month;
		  int day = _day;
		  int days = GetMonthDay(_year,_month);
		  while (day + n > days) {
			  month++;
			  if (month > 12) {
				  year++;
				  month = 1;
			  }n -= days;
			  days = GetMonthDay(year,month);
		  }
		  day += n;
		  return Date(year, month, day);
	  }
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream & out, const Date & d) {
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}

//获取每个月天数的方法
bool Date::IsLeap(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	return false;
}

int Date::GetMonthDay(int year, int month) {
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int day = days[month];
	if (month == 2) {
		if (IsLeap(year)) {
			day=29;
		}
	}return day;
}

int main() {
	Date dt1(2021, 5, 10);
	cout << "dt1=" << dt1 << endl;
	Date dt2 = dt1--;
	//Date dt = dt1 + 100;
	cout << "dt1=" << dt1 << endl;
	cout << "dt2=" << dt2 << endl;
}