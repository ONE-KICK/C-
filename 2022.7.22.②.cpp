#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    while (getline(cin, str))
    {
        int a[256] = { 0 };
        bool flag = false;
        for (int i = 0; i < str.size(); ++i)
            ++a[str[i]];
        for (int i = 0; i < str.size(); ++i)
            if (a[str[i]] == 1)
            {
                cout << str[i] << endl;
                flag = true;
                break;
            }
        if (flag == false)
            cout << "-1" << endl;
    }
    return 0;
}