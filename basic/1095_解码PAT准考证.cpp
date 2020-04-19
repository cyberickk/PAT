#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct stu	//
{
	string id;
	int sco;
};

struct room	//
{
	string rid;
	int num;
};

bool cmpsc(const stu& s1, const stu& s2)
{
	return s1.sco == s2.sco ? s1.id < s2.id : s1.sco > s2.sco;	//
}

bool cmpnum(const room& r1, const room& r2)
{
	return r1.num == r2.num ? r1.rid < r2.rid : r1.num > r2.num; 	//
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<stu> v(n);
	vector<stu>::iterator it;
	for(int i = 0; i < n; ++i)
		cin >> v[i].id>> v[i].sco;
	for(int i = 1; i <= m; ++i)	//
	{
		int order;
		scanf("%d", &order);
		if(order == 1)
		{
			char c; cin >> c;
			printf("Case %d: %d %c\n", i, order, c);
			vector<stu> level;			
			for(it = v.begin(); it != v.end(); ++it)
				if((*it).id[0] == c) level.push_back(*it);
			sort(level.begin(), level.end(), cmpsc);	//
			for(it = level.begin(); it != level.end(); ++it)
			printf("%s %d\n", (*it).id.c_str(), (*it).sco);	//
			if(level.size() == 0) cout << "NA" << endl;
		}
		else if(order == 2)
		{
			string r;
			cin >> r;
			printf("Case %d: %d %s\n", i, order, r.c_str());
			int cnt = 0, sum = 0;
			for(it = v.begin(); it != v.end(); ++it)
			{
				string s = (*it).id.substr(1, 3);	//
				if(s == r)
				{
					cnt++; sum += (*it).sco; 
				}
			}
			if(cnt == 0) cout << "NA" << endl;	//
			else cout << cnt << " " << sum << endl;
		}
		else if(order == 3)
		{
			string d;
			cin >> d;
			printf("Case %d: %d %s\n", i, order, d.c_str());
			vector<room> date;				//
			vector<room>::iterator it1;		//
			unordered_map<string, int> m;
			for(it = v.begin(); it != v.end(); ++it)
			{
				if((*it).id.substr(4, 6) == d)		//
				{
					string s = (*it).id.substr(1, 3);	
					m[s]++;					//
				}
			}
			for(auto it: m)					//
				date.push_back({it.first, it.second});	//
			sort(date.begin(), date.end(), cmpnum);
			for(it1 = date.begin(); it1 != date.end(); ++it1)
				printf("%s %d\n", (*it1).rid.c_str(), (*it1).num);
			if(date.size() == 0) cout << "NA" << endl;	//
		}
	}
	
	return 0;
} 
