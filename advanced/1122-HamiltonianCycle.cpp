#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	int n, m, k, a, b, e[210][210];
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		e[a][b] = e[b][a] = 1;
	}
	scanf("%d", &k);
	for(int i = 0; i < k; ++i) {
		int t;
		bool flag = 1;		
		scanf("%d", &t);
		vector<int> v(t);
		set<int> s;
		for(int j = 0; j < t; ++j)	{
			scanf("%d", &v[j]);
			s.insert(v[j]);
			if(j != 0)
				if(e[v[j]][v[j-1]] != 1)	flag = 0;
		}
		if(v[0] != v[t-1] || s.size() != n || v.size() != n+1)	flag = 0;
		if(flag)	printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
