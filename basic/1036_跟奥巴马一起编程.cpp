 ///
 /// @file    1036_跟奥巴马一起编程.cpp
 /// @author  kk(blingblingda@hotmail.com)
 /// @date    2020-02-06 13:00:19
 ///
 
#include <iostream>
using namespace std; 
 
int main()
{
    int n,line;
    char c;
    cin >> n >> c;
    line = n / 2 + n % 2 - 2;
    for(int i = 0; i < n; ++i)
        cout << c;
    cout << endl;
    for(int i = 0; i < line; ++i)
    {
        cout << c;
        for(int j = 0; j < n-2; ++j)
            cout << " ";
        cout << c << endl;

    }
    for(int i = 0; i < n; ++i)
        cout << c;
    cout << endl;
    return 0; 
}
