 ///
 /// @file    1081_检查密码.cpp
 /// @author  kk(blingblingda@hotmail.com)
 /// @date    2020-01-29 21:47:19
 ///
 
#include <iostream>
#include <string>
using namespace std;

bool lengthCheck(const string & s)
{
    int len;
    len = s.size();
    if(len < 6)
    {
        cout << "Your password is tai duan le." << endl;
        return 0;
    }
    else 
        return 1;
}



bool validCheck(const string & s)
{
    int num = 0, alpha = 0;
    for(auto idx = 0; idx != s.size(); ++idx)
    {
        if(isdigit(s[idx]))
            ++num;
        else if(isalpha(s[idx]))
            ++alpha;
        else if(s[idx] != '.')
        {
            cout << "Your password is tai luan le." << endl;
            return 0;
        }    
        else ;
    }
    if(num && alpha)
        return 1;
    else if(!num)
    {
        cout << "Your password needs shu zi." << endl;
        return 0;
    }
    else if(!alpha)
    {
        cout << "Your password needs zi mu." << endl;
        return 0;
    }
    else
        return 0;
}
 
int main()
{
    int lcheck = 0, vcheck = 0, n = 0;
    string s[100];
    cin >> n;
    cin.ignore();
    
    for (int i = 0; i < n; ++i)
    {
        getline(cin, s[i]);
    }
    for( int i =0; i < n; ++i )
    {
        lcheck = lengthCheck(s[i]);
        if(!lcheck)
            continue;
        vcheck = validCheck(s[i]);
        if(lcheck && vcheck)
            cout << "Your password is wan mei." << endl;
    }
    return 0; 
}
