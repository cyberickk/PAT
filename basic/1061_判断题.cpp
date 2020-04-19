 ///
 /// @file    1061_判断题.cpp
 /// @author  kk(blingblingda@hotmail.com)
 /// @date    2020-02-05 15:28:04
 ///
 
#include <iostream>
using namespace std;
 
 
int main()
{
    int stunum,testnum;
    cin >> stunum >> testnum;
    int score[testnum],ans[testnum];
    for(int i = 0; i < testnum; ++i)
        cin >> score[i];
    for(int i = 0; i < testnum; ++i)
        cin >> ans[i];
    for(int i = 0; i < stunum; ++i)
    {
        int stuscore = 0, stuans;
        for(int j = 0; j < testnum; ++j)
        {
            cin >> stuans;
            if(stuans == ans[j])
                stuscore += score[j];            
        }
        cout << stuscore << endl;
    }

    return 0; 
}
