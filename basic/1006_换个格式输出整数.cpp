 ///
 /// @file    1006_outputinte.cpp
 /// @author  kk(blingblingda@hotmail.com)
 /// @date    2020-01-15 23:24:58
 ///

#include <iostream>
#include <string>
using namespace std;

void printout(const string & s)
{
    int i,l,num;
    l = s.length();
    switch(l)
    { 
        case 1:
            num = s[0]-'0'; 
            for(i =1; i <= num; ++i )
                cout << i;
            break;
        case 2:
            for(i = 0; i < s[0]-'0'; ++i)
            {
                cout << "S";
            }
            for(i = 1; i <= s[1]-'0'; ++i)
            {
                cout << i;
            }
            break;
        case 3:
            for(i = 0; i < s[0]-'0'; ++i)
            {
                cout << "B";
            }
            for(i = 0; i < s[1]-'0'; ++i)
            {
                cout << "S";
            }
            for(i = 1; i <= s[2]-'0'; ++i)
            {
                cout << i;
            }
            break;
        default:
            break;
    }
    cout << endl;
}

int main()
{
    string s;
    cin >> s;
    printout(s);

    return 0;
}
