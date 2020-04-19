 ///
 /// @file    1071_小赌怡情.cpp
 /// @author  kk(blingblingda@hotmail.com)
 /// @date    2020-02-05 14:04:13
 ///
 
#include <iostream>
using namespace std;
 
 
 
int main()
{
    int token,k;
    cin >> token >> k;
    for(int i = 0; i < k; ++i)
    {
        int n1,b,t,n2;
        cin >> n1 >> b >> t >> n2;
        if(t > token)
        {
            printf("Not enough tokens.  Total = %d.\n", token);
            continue;
        }
        else if((n1 < n2 && b == 1) || (n1 > n2 && b == 0))
        {
            token += t;
            printf("Win %d!  Total = %d.\n", t,token);
        }
        else if((n1 < n2 && b == 0) || (n1 > n2 && b == 1))
        {
            token -= t;
            printf("Lose %d.  Total = %d.\n", t,token);     
        }
        if(token == 0)
        {
            cout << "Game Over." << endl;
            return 0;
        }

    }

    return 0; 
}
