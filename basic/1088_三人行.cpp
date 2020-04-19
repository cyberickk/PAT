#include <iostream>
#include <cmath>
using namespace std;

int m,x,y;
double i = 0, j = 0, k = 0;	
void print(double n)
{
	if(n == m) cout << " Ping";
	else if(n > m) cout << " Cong";
	else cout << " Gai";
}

int main()
{
	cin >> m >> x >> y;
	for(int i = 99; i >= 10; --i)
	{
		j = i % 10 * 10 + i / 10;
		k = abs(i - j) * 1.0 / x;
		if(k * y == j)
		{
			cout << i;
			print(i); print(j); print(k);
			return 0;
		}
	}
	cout << "No Solution" << endl;
	return 0;
}
