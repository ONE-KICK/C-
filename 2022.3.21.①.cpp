#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class String {
public:
	friend ostream& operator<<(ostream& out, const String& s);
	String(const char* str="")
	{
		m_data = new char[strlen(str)+1];
		strcpy(m_data, str);
	}
	String(const String& s)
	{
		m_data = new char[strlen(s.m_data)+1];
		strcpy(m_data, s.m_data);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			delete[] m_data;
			m_data = new char[strlen(s.m_data) + 1];
			strcpy(m_data, s.m_data);
		}
		return *this;
	}
	~String() 
	{
		delete[] m_data;
		m_data = nullptr;
	}
private:
	char* m_data;
};

ostream& operator<<(ostream& out, const String& s) 
{
	out << s.m_data;
	return out;
}

int main()
{
	String s("abc");
	String s1 = s;
	cout << "s=" << s << endl;
	cout << "s1=" << s1 << endl;
	return 0;
}