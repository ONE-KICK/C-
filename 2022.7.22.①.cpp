#include<iostream>
#include<vector>
using namespace std;

int measure(int x, int y)
{
	int z = y;
	while (x % y != 0)
	{
		z = x % y;
		x = y;
		y = z;
	}
	return z;
}

void BeatMonster(int& a, int bi)
{
	if (a >= bi)
		a += bi;
	else if (bi > a)
	{
		int ret = measure(bi, a);
		a += ret;
	}
}

int main()
{
	int n, a, b=0;
	vector<int>bn;
	while (cin >> n >> a)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> b;
			bn.push_back(b);
		}
		for (int i = 0; i < n; i++)
		{
			BeatMonster(a, bn[i]);
		}
		cout << a << endl;
		bn.clear();
	}

}