#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m, k, e[210][210], ans = 99999999, ansid;

void check(int index) {
	int cnt, sum = 0, flag = 1;
	cin >> cnt;
	set<int> s;
	vector<int> v(cnt);
	for(int i = 0; i < cnt; ++i) {
		cin >> v[i];
		s.insert(v[i]);
	}
	for(int i = 0; i < cnt-1; ++i) {
		if(e[v[i]][v[i+1]] == 0) {
	      	flag = 0;
	      	break;
	    }
		sum += e[v[i]][v[i+1]];
	}
	if(flag == 0) 
		printf("Path %d: NA (Not a TS cycle)\n", index);
	else if(v[cnt-1] != v[0] || s.size() != n)
		printf("Path %d: %d (Not a TS cycle)\n", index, sum);
	else if(cnt != n+1) {
		printf("Path %d: %d (TS cycle)\n", index, sum);
		if (sum < ans) {
		ans = sum;
		ansid = index;
		}
	}
	else {
		printf("Path %d: %d (TS simple cycle)\n", index, sum);
		if (sum < ans) {
		ans = sum;
		ansid = index;
		}
	}		 
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int a, b, d;
		cin >> a >> b >> d;
		e[a][b] = e[b][a] = d;
	}
	cin >> k;
	for(int i = 1; i <= k; ++i) {
		check(i);
	}
	printf("Shortest Dist(%d) = %d", ansid, ans);
	return 0;
} 
