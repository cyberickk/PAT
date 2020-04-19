#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm> 
using namespace std;

struct sco{
	string id;
	int gp, gm, gf, g;
};

bool cmp(const sco& a, const sco& b)
{
	return a.g == b.g ? a.id < b.id : a.g > b.g;
}

int main()
{
	int p, m, n;
	cin >> p >> m >> n;
	unordered_map<string, int> prog, gm, gf;
	for(int i = 0; i < p; ++i)
	{
		string s;
		int t;
		cin >> s >> t;
		prog[s] = t;
	}
	for(int i = 0; i < m; ++i)
	{
		string s;
		int t;
		cin >> s >> t;
		gm[s] = t;
	}
	for(int i = 0; i < n; ++i)
	{
		string s;
		int t;
		cin >> s >> t;
		gf[s] = t;
	}
	vector<sco> ans;
	for(auto it = prog.begin(); it != prog.end(); ++it)
	{
		string s = it->first;
		if(it->second < 200) continue;
		if(gf.count(s) == 0) continue;
		int g;
		if(gm.count(s) == 0  || gm[s] < gf[s])
			g = gf[s];
		else
			g = (int)(gm[s] * 0.4 + gf[s] * 0.6 + 0.5);
		if(g < 60) continue;
		else
		{ 
			if(gm.count(s) == 0)
				ans.push_back(sco{s, prog[s], -1, gf[s], g});
			else
				ans.push_back(sco{s, prog[s], gm[s], gf[s], g});
		}	
	}
	sort(ans.begin(), ans.end(), cmp);
	for(int i = 0; i < ans.size(); ++i)
	printf("%s %d %d %d %d\n", ans[i].id.c_str(), ans[i].gp, ans[i].gm, ans[i].gf, ans[i].g);
	return 0;
}
 
