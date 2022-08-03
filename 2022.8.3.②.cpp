#include <iostream>
#include <vector>
using namespace std;
int main() 
{
    vector<int> F(100001, 0);
    F[0] = 1;
    F[1] = 1;
    for (int i = 2; i <= 100000; ++i) 
    {
        F[i] = F[i - 2] + F[i - 1];
        F[i] = F[i] % 1000000;
    }
    int n;
    while (cin >> n) 
    {
        if (n < 29) 
        {
            printf("%d\n", F[n]);
        }
        else 
        {
            printf("%06d\n", F[n]);
        }
    }
    return 0;
}
