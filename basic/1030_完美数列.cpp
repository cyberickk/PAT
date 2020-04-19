#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main()
{
	int n, cnt = 0, tmp = 0;
	long long p;
	cin >> n >> p;
	vector<int> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	for(int i = 0; i < n; ++i)
	{
		for(int j = i + cnt; j < n; ++j)
		{
			if(v[j] > v[i] * p) break;
			tmp = j - i + 1;
			if(tmp > cnt) cnt = tmp;
		}
	}
	cout <<cnt;
	return 0;
}
