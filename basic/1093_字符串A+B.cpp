 ///
 /// @file    1093_stringA+B.cpp
 /// @author  kk(blingblingda@hotmail.com)
 /// @date    2020-01-15 22:00:36
 ///

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::string;

string catstring(string & s1, string & s2)
{
    string s;
    int flag = 0;
    for(size_t idx = 0; idx != s1.size(); ++idx)
    {
        for(size_t idx1 = 0; idx1 != s.size(); ++idx1)
        {
            if( s[idx1] == s1[idx]) 
            {
                flag = 1;
            }
        }
        if(!flag)
            s.push_back(s1[idx]);
        flag=0;
    }

    for(size_t idx = 0; idx != s2.size(); ++idx)
    {
        for(size_t idx1 = 0; idx1 != s.size(); ++idx1)
        {
            if( s[idx1] == s2[idx])
            {
                flag = 1;
            }
        }
        if(!flag)
            s.push_back(s2[idx]);
        flag=0;
    }
    return s;
}

int main()
{
    string s1,s2,ss;
    getline(cin,s1);
    getline(cin,s2);
    ss = catstring(s1,s2);
    cout << ss << endl;
}
