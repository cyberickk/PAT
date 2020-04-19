#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

struct sch{
	int sum;
	int cnt;
	string id;
};

bool cmp(const sch& a, const sch& b)
{
	return a.sum == b.sum ? (a.cnt == b.cnt ? a.id < b.id : a.cnt < b.cnt) : a.sum > b.sum; 
}

int main()
{
	int n;
	cin >> n;
	unordered_map<string, int> cnt;  //分两个map存储，如果把cnt sum组成结构体用一个map存储，开销大 
	unordered_map<string, float> sum;
	vector<sch> ans;
	for(int i = 0; i < n; ++i)
	{
		string s1, s2, s;
		int t;
		cin >> s1 >> t >> s2;
		for(int j = 0; j < s2.size(); ++j)
			s += tolower(s2[j]);
		float sco;
		if(s1[0] == 'B') sco = t / 1.5;
		else if(s1[0] == 'A') sco = t;
		else if(s1[0] == 'T') sco = t * 1.5; 
		sum[s] += sco;
		cnt[s]++;	
	}
	for(auto it = cnt.begin(); it != cnt.end(); ++it)
		ans.push_back(sch{(int)sum[it->first], cnt[it->first], it->first});
	sort(ans.begin(), ans.end(), cmp);
	printf("%d\n", (int)ans.size());
	int rank = 0, pres = -1;
	for(int i = 0; i < ans.size(); ++i)
	{
		if(ans[i].sum != pres) rank = i + 1;
		pres = ans[i].sum;
		printf("%d ", rank);
		cout << ans[i].id;
		printf(" %d %d\n",ans[i].sum, ans[i].cnt); 	
	}
	
	return 0;
}
