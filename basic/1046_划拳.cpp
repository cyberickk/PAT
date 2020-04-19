 ///
 /// @file    1046_划拳.cpp
 /// @author  kk(blingblingda@hotmail.com)
 /// @date    2020-02-01 10:50:09
 ///
 
#include <iostream>
using namespace std;
 
 
 
int main()
{
    int n,jhe = 0,yhe = 0;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int jhan,jhua,yhan,yhua;
        cin >> jhan >> jhua >> yhan >> yhua;
        if(jhua == jhan + yhan && jhua != yhua)
            ++yhe;
        else if(yhua == jhan + yhan && jhua != yhua)
            ++jhe;
        else ;
    }
    cout << jhe << " " << yhe << endl;

    return 0; 
}
