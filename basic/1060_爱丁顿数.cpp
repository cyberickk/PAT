#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

bool cmp(int a, int b) { return a > b;}

int main()
{
	int n, flag = 0;
	cin >> n;
	vector<int> v(100000);
	for(int i = 1; i <= n; ++i)
	cin >> v[i];	
	sort(v.begin() + 1, v.end(), cmp);
	int ans = 0, p = 1;
	while(ans <= n && v[p] > p)
	{
		ans++;
		p++;
	}
	cout << ans;
	return 0;
}
