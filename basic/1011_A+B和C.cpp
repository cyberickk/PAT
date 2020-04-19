 ///
 /// @file    1011_A+B和C.cpp
 /// @author  kk(blingblingda@hotmail.com)
 /// @date    2020-02-01 10:37:43
 ///
 
#include <iostream>
using namespace std;
 
 
 
int main()
{
    int n;
    cin >> n;

    long long  n1,n2,n3;
    int result[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> n1 >> n2 >> n3;
        if(n1 + n2 <= n3)
            result[i] = 0;
        else
            result[i] = 1;
    }
    for(int i = 0; i < n ; ++i)
    {
        if(result[i])
            cout << "Case #" << i+1 << ": " << "true" << endl;
        else 
            cout << "Case #" << i+1 << ": " << "false" << endl;            
    }
    return 0; 
}
