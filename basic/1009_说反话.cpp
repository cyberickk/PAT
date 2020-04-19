 ///
 /// @file    1009_inverse.cpp
 /// @author  kk(blingblingda@hotmail.com)
 /// @date    2020-01-15 22:57:39
 ///
 

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<string> inverse;
vector<string>::reverse_iterator it ;

int main()
{
    string s,word;
    getline(cin,s);
    istringstream iss(s);
    while(iss >> word)
    {
        inverse.push_back(word);
    }
    for(it = inverse.rbegin(); it != inverse.rend()-1; ++it)
    {
        cout << *it << " ";
    }
    cout << inverse[0] << endl;
}
