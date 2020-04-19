#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)	{ return a > b;}


int main()
{
	int r;
	cin >> r;
	vector<int> v(r);
	map<int, int> di;
	for(int i = 0; i < r; ++i)
		cin >> v[i];
	sort(v.begin(), v.end(), cmp);
	int m = r, n = 1, mi = r - 1;
	for(int i = 1; i * i <= r; ++i)
	{
		if(r % i == 0)
		{			
			if((r / i - i) < mi)
			{
				m = r / i;
				n = i;
				mi = m - n;
			}			
		}
		//cout << m << " " << n << endl;
	}	
	int a[m][n], vp = 0;
	int level = m / 2 + m % 2;
	for(int i = 0; i < level; ++i)
	{
		for(int j = i; j <= n - 1 - i && vp <= r - 1; ++j)
		a[i][j] = v[vp++];
		for(int j = i + 1; j <= m - 2 - i && vp <= r - 1; ++j)
		a[j][n - 1 - i] = v[vp++];
		for(int j = n - 1 - i; j >= i && vp <= r - 1; --j)
		a[m - 1 - i][j] = v[vp++];
		for(int j = m - 2 - i; j >= i + 1 && vp <= r - 1; --j)
		a[j][i] = v[vp++];		
	}
	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			printf("%d", a[i][j]);
			if(j != n - 1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
