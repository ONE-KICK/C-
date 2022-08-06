#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		vector<long long>v(91, 0);
		v[1] = 1;
		v[2] = 1;
		for (int i = 3; i <= 90; ++i)
		{
			v[i] = v[i - 2] + v[i - 1];
		}
		cout << v[n] << endl;
	}return 0;
}