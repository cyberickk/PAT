 ///
 /// @file    1056_组合数的和.cpp
 /// @author  kk(blingblingda@hotmail.com)
 /// @date    2020-02-05 15:53:42
 ///
 
#include <iostream>
using namespace std;
 
int main()
{
    int n,sum = 0;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        sum += (n - 1) * num;
        sum += (n - 1) * num * 10;
    }
    cout << sum << endl;
    return 0; 
}
