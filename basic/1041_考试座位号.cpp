 ///
 /// @file    1041_考试座位号.cpp
 /// @author  kk(blingblingda@hotmail.com)
 /// @date    2020-02-05 16:42:14
 ///
 
#include <iostream>
#include <map>
using namespace std;
 
struct seatInfo
{
    string _examrg;
    int _examnum;
};

map<int,seatInfo> query;
 
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        string s;
        int test,exam;
        cin >> s >> test >> exam;
        query[test]._examrg = s;
        query[test]._examnum = exam;
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i)
    {
        int testquery;
        cin >> testquery;
        if(query.count(testquery))
            cout << query[testquery]._examrg << " " << query[testquery]._examnum << endl;
    }

    return 0; 
}
