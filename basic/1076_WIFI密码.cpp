 ///
 /// @file    1076_WIFI密码.cpp
 /// @author  kk(blingblingda@hotmail.com)
 /// @date    2020-01-31 23:07:31
 ///
 
#include <iostream>
#include <vector>
using namespace std;
 
 
 
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    
    string s;
    vector<int> psw;
    for(int i = 0; i < n; ++i)
    {
        getline(cin, s);
        int size = s.size();
        for(int j = 0; j < size; ++j)
        {
            if(s[j+1] == 'T')
            {
                psw.push_back(s[j-1] - 'A' +1);
                break;
            }            
        }
    }
    
    vector<int>::iterator it;
    for(it = psw.begin(); it != psw.end(); ++it)
        cout << *it;
    cout << endl;
    return 0; 
}
