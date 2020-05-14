#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k, a, b;
	scanf("%d", &n);
	int v[100010] = {-1};
	bool guest[100010] = {0};
	for(int i = 0; i < n; ++i) {
		scanf("%d %d", &a, &b);
		v[a] = b;
		v[b] = a;
	}
	scanf("%d", &k);
	vector<int> ans;
	for(int i = 0; i < k; ++i) {
		scanf("%d", &a);	
		if(v[a] == -1)	ans.push_back(a);
		else guest[a] = 1;
	}
	for(int i = 0; i < 100010; ++i) {
		if(guest[i] == 1) {
			if(guest[v[i]] == 0)	ans.push_back(i);
		}		
	}
	printf("%d\n", ans.size());
	sort(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); ++i) {
		if(i != 0) printf(" ");
		printf("%05d", ans[i]); 
	}
	return 0;
}
