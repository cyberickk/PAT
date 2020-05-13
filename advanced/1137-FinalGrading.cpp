#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

struct scores {
	int gp, mid, final, total;
};
struct stu {
	string id;
	int gp, mid, final, total;
};

bool cmp(const stu& a, const stu& b) {
	if(a.total != b.total)
		return a.total > b.total;
	else
		return a.id < b.id;
 
}

int main() {
	int p, m, n, tmp, total;
	unordered_map<string, scores> ma;
	vector<stu> v;
	string id;
	scanf("%d %d %d", &p, &m, &n);
	for(int i = 0; i < p; ++i) {
		cin >> id >> tmp;
		if(tmp >= 200) {
			ma[id].gp = tmp;
			ma[id].mid = -1;
			ma[id].final = -1;
			total = 0;
		}	
		
	}
	for(int i = 0; i < m; ++i) {
		cin >> id >> tmp;
		if(ma.count(id)) {
			ma[id].mid = tmp;
		}	
	}
	for(int i = 0; i < n; ++i) {
		cin >> id >> tmp;
		if(ma.count(id))	{
			ma[id].final = tmp;
		}
	}
	for(auto it:ma) {
		id = it.first;
		if(ma[id].final >= 0) {
			if(ma[id].mid < ma[id].final)
				total = ma[id].final;
			else
				total = (int)(ma[id].mid * 0.4 + ma[id].final * 0.6 + 0.5);
			if(total >= 60) {
				v.push_back({id, ma[id].gp, ma[id].mid, ma[id].final, total});	
			}
				
		}
	}
	sort(v.begin(), v.end(), cmp);
	for(auto it:v) {
		printf("%s %d %d %d %d\n", it.id.c_str(), it.gp, it.mid, it.final, it.total);
	}
	return 0;
}
