#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct mem{
	string n;
	int h;
};

bool cmp(const mem& a, const mem& b)
{
	return a.h == b.h ? a.n < b.n : a.h > b.h ;
}

int main()
{
	int n, k; 
	cin >> n >> k;
	vector<mem> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i].n >> v[i].h;
	sort(v.begin(), v.end(), cmp);
	int m, t = 0, row = k;	
	while(row)
	{
		if(row == k) m = n - n / k * (k - 1);
		else m = n / k;
		vector<string> ans(m);
		ans[m / 2] = v[t].n;
		int j = m / 2 - 1;
		for(int i = t + 1; i < t + m; i += 2)
			ans[j--] = v[i].n;
		j = m / 2 + 1;
		for(int i = t + 2; i < t + m; i += 2)
			ans[j++] = v[i].n;
		cout << ans[0];
		for(int i = 1; i < m; ++i)
			cout << " " << ans[i];
		cout << endl;
		t = t + m;
		--row;
	}
	
	return 0;
}
