 ///
 /// @file    1066_图像过滤.cpp
 /// @author  kk(blingblingda@hotmail.com)
 /// @date    2020-02-01 11:09:13
 ///
 
#include <iostream>
using namespace std;
 
int main()
{
    int m, n, a, b, f;
    cin >> m >> n >> a >> b >> f;
    int image[m][n];
    for(int i = 0; i < m ; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> image[i][j];
            if(image[i][j] <= b && image[i][j] >= a)
                image[i][j] = f;
        }   
    }
    for(int i = 0; i < m; ++i)
    {
        int j;
        for(j = 0; j < n-1; ++j)
            printf("%03d ", image[i][j]);
        printf("%03d\n", image[i][j]);
    }

    return 0; 
}
