#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	map<int, vector<int>> incom;
	for(int i = 0; i < n; ++i)
	{
		int t1, t2;
		cin >> t1 >> t2;
		incom[t1].push_back(t2);
		incom[t2].push_back(t1);
	}
	while(m--)
	{
		int cnt, j, flag = 0, a[100000] = {0}; 
		cin >> cnt;
		vector<int> v(cnt);
		for(int i = 0; i < cnt; ++i)
		{
			cin >> v[i];
			a[v[i]] = 1;
		}
			
		for(int i = 0; i < v.size(); ++i)
		{
			for(int j = 0; j < incom[v[i]].size(); ++j)	
				if(a[incom[v[i]][j]] == 1)	flag = 1;
		}
		printf("%s\n", flag ? "No" : "Yes");
	}
	
	return 0;
}
