#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct stu{
	int id, de, cai;
};

bool cmp(const stu& a, const stu& b)
{
	return (a.de + a.cai) == (b.de + b.cai) ? (a.de == b.de ? a.id < b.id : a.de > b.de) : (a.de + a.cai) > (b.de + b.cai);
}
int main()
{
	int n, l, h, cnt = 0;
	cin >> n >> l >> h;
	vector<stu> v[4];
	for(int i = 0; i < n; ++i)
	{
		int id, d, c;
		cin >> id >> d >> c;
		if(d >= l && c >= l)
		{
			if(d >= h && c >= h) v[0].push_back(stu{id, d, c});
			else if(d >= h && c < h) v[1].push_back(stu{id, d, c});
			else if(d < h && c < h && d >= c) v[2].push_back(stu{id, d, c});
			else v[3].push_back(stu{id, d, c});
			cnt++;
		}		 
	}
	for(int i = 0; i < 4; ++i)
		sort(v[i].begin(), v[i].end(),cmp);
	cout << cnt << endl;
	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < v[i].size(); ++j)
		printf("%08d %d %d\n", v[i][j].id, v[i][j].de, v[i][j].cai);	
	}
		
	return 0;
}
