#include <iostream>
#include <vector>
#include <set>

using namespace std;
struct node {
	int t1, t2;
};

int main() {
	int n, m, k;
	cin >> n >> m;
	vector<node> v(n);
	for(int i = 0; i < m; ++i) {
		cin >> v[i].t1 >> v[i].t2;
	}
	cin >> k;
	while(k--) {
		int a[10010] = {0};
		bool flag = 1;
		set<int> s;
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
			s.insert(a[i]);
		}
		for(int i = 0; i < m; ++i) {
			if(a[v[i].t1] == a[v[i].t2]) {
				flag = 0;
				break;
			}
		}
		if(flag) printf("%d-coloring\n", s.size());
		else printf("No\n");
	}
	return 0;
}
