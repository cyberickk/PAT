#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	unordered_map<int, vector<int>> ma;
	for(int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		ma[a].push_back(b);
		ma[b].push_back(a);
	}
	while(m--) {
		int cnt, a[100000] = {0}, flag = 1;
		cin >> cnt;
		vector<int> v(cnt);
		for(int i = 0; i < cnt; ++i) {
			cin >> v[i];
			a[v[i]] = 1;
		}
		for(int i = 0; i < cnt; ++i) {
			for(int j = 0; j < ma[v[i]].size(); ++j) {
				if(a[ma[v[i]][j]] == 1) {
					flag = 0;
					break;
				}
			}
		}
		if(flag) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
