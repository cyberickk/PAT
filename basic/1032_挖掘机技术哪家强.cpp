#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, max = 0, team;
	cin >> n;
	vector<int> a(n+1);
	for(int i = 0; i < n; ++i)
	{
		int t, s;
		cin >> t >> s;
		a[t] += s;
		if(a[t] > max)
		{
			max = a[t]; team = t;
		}
	}
	cout << team << " " << max;
	
	return 0;
} 
