#include <iostream>
using namespace std;

int suspect(int num, int &step)
{
    if ( num == 1)
        return step;
    else if ( num % 2 == 0)
        suspect(num/2, ++step);
    else if( num % 2 == 1)
        suspect((3*num + 1) / 2, ++step);
}

int main()
{
    int num=0,step=0;
    cin >> num;
    step = suspect(num, step);
    cout << step << endl; 
    return step;
}
