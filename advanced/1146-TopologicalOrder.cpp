#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, a, b, k, in[1010] = {0}, cnt = 0;
	scanf("%d %d", &n, &m);
	vector<int> v[1010];
	for(int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		in[b]++;
	}
	cin >> k;
	for(int i = 0; i < k; ++i) {
		bool flag = 1;
		vector<int> tin(in, in+n+1);
		for(int j = 0; j < n; ++j) {
			scanf("%d", &a);
			if(tin[a] != 0) flag = 0;
			for(auto it: v[a]) tin[it]--;
		}
		if(flag == 1) continue;
		if(cnt) printf(" ");
		printf("%d", i);
		cnt++;
	}
	return 0;
} 
