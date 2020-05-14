#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v; 
vector<bool> visit;
int cnt = 0;

void dfs(int index) {
	visit[index] = 1;
	cnt++;
	for(int i = 0; i < v[index].size(); ++i)
		if(visit[v[index][i]] == 0)
			dfs(v[index][i]);
}

int main() {
	int n, m, a, b, odd = 0;
	scanf("%d %d", &n, &m);
	v.resize(n+1);
	visit.resize(n+1);
	for(int i = 1; i <= m; ++i) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a); 
	}	
	for(int i = 1; i <= n; ++i) {
		if(i != 1) printf(" ");
		printf("%d", v[i].size());
		if(v[i].size() % 2 == 1)	odd++;
	}
	dfs(1);
	if(odd == 0 && cnt == n) printf("\nEulerian\n");
	else if(odd == 2 && cnt == n) printf("\nSemi-Eulerian\n");
	else printf("\nNon-Eulerian\n");
	return 0;
} 
