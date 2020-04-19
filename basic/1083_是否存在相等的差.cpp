#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int b[10000] = {0};
	for(int i = 1; i <= n; ++i)
	{
		int j;
		cin >> j;
		b[abs(j-i)]++;
	}
	for(int i = 9999; i >= 0; --i)
	{
		if(b[i] >= 2)
				cout << i << " " << b[i] << endl;
	}
	return 0;
}
