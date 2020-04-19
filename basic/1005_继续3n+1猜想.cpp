#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int a[10000] = {0};

bool cmp(int a, int b)  { return a > b;}
int main()
{
	int k,flag = 0;
	cin >> k;
	vector<int> v(k);
	for(int i = 0; i < k; ++i)
	{
		int t;
		cin >> t;
		v[i] = t;
		while(t != 0)
		{
			if(t % 2 == 1) t = 3 * t + 1;
			t = t / 2;
			if(a[t] == 1) break;
			a[t] = 1;		
		}
	}
	sort(v.begin(), v.end(), cmp);
	for(int i = 0; i < v.size(); ++i)
	{
		if(a[v[i]] == 0)
		{
			if(flag) cout << " ";
			cout << v[i];
			flag = 1;
		}
	}
	return 0;
}
