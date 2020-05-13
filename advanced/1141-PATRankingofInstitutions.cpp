#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct scores {
	double sum;
	int cnt;
};

struct insti {
	string school;
	int sum, cnt;
};

bool cmp(const insti& a, const insti& b) {
	if(a.sum != b.sum)
		return a.sum > b.sum;
 	else if(a.cnt != b.cnt) 
	 	return a.cnt < b.cnt;
	else
		return a.school < b.school; 	
}

int main() {
	int n, prescore = -1, prerank = 0;
	double score;
	string id, school;
	unordered_map<string, scores> ma;
	vector<insti> v;
	scanf("%d", &n);	
	for(int i = 0; i < n; ++i) {
		cin.ignore();
		cin >> id >> score >> school;
		if(id[0] == 'B') score /= 1.5;
		if(id[0] == 'T') score *= 1.5;
		transform(school.begin(), school.end(), school.begin(), ::tolower);
		ma[school].sum += score;
		ma[school].cnt++;		
	}
	for(auto it:ma) {
		v.push_back({it.first, (int)it.second.sum, it.second.cnt});
	}
	sort(v.begin(), v.end(), cmp);
	printf("%d\n", v.size());
	for(int i = 0; i < v.size(); ++i) {
		if(v[i].sum == prescore) 
			printf("%d %s %d %d\n", prerank, v[i].school.c_str(), v[i].sum, v[i].cnt);
		else {
			printf("%d %s %d %d\n", i+1, v[i].school.c_str(), v[i].sum, v[i].cnt);
			prerank = i+1;
		}
		prescore = v[i].sum;			
	}
	return 0;
}
