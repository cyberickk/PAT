#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int n, m, k, a, b;
	scanf("%d %d", &n, &m);
	vector<int> va, vb;
	for(int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		va.push_back(a);
		vb.push_back(b);
	}
	scanf("%d", &k);	
	for(int i = 0; i < k; ++i) {
		set<int> check;
		bool flag = 1;
		scanf("%d", &a);
		while(a--) {
			scanf("%d", &b);
			check.insert(b);
		}
		for(int j = 0; j < m; ++j) {
			if(check.count(va[j]) == 0 && check.count(vb[j]) == 0) {
				flag = 0;
				break;
			}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}
