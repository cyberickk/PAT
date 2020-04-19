 ///
 /// @file    1091_自守数.cpp
 /// @author  kk(blingblingda@hotmail.com)
 /// @date    2020-02-05 13:41:32
 ///
 
#include <iostream>
using namespace std;
 
 
 
int main()
{
    int m;
    cin >> m;
    
    for(int i = 0; i < m; ++i)
    {
        int j,num;
        cin >> num;
        for(j = 1; j < 10; ++j)
        {
            string s, snum, mulend;
            long long mul;
            mul = j * num * num;
            s = to_string(mul);
            snum = to_string(num);
            mulend = s.substr(s.length() - snum.length());

            if(mulend == snum)
            {
                cout << j << " " << mul << endl;
                break;
            }
        }
        if(j >= 10) 
            cout << "No" << endl;

    }
    return 0; 
}
