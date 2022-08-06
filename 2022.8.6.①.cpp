#define _CRT_SECURE_NO_WARNINGS  //Äê»á³é½± Å£¿Í
#include<math.h>
#include<iostream>
using namespace std;
int main()
{
	int n;
	long long ftable[21] = { 0,0,1 };
	long long alltable[21] = { 0,1,2 };
	for (int i = 3; i < 21; ++i)
	{
		ftable[i] = (i - 1) * (ftable[i - 1] + ftable[i - 2]);
		alltable[i] = i * alltable[i - 1];
	}
	while (scanf("%d", &n) != -1)
	{
		printf("%4.2lf%%\n", 100 * double(ftable[n]) / alltable[n]);
	}
	return 0;
}