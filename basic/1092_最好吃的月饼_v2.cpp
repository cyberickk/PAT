#include <iostream>
using namespace std;

int main()
{
	int n, m, maxn = 0, cnt = 0;
	cin >> n >> m;
	int a[m][n] = {0}, sales[n] = {0};
	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
			sales[j] += a[i][j];
			maxn = max(maxn, sales[j]);
		}
	}
	cout << maxn << endl; 
	for(int i = 0; i < n; ++i)
	{		
		if(sales[i] == maxn) 
		{
			if( cnt != 0) cout << " ";
			cout << i+1; cnt++;
		}	
	}
	return 0;
}
