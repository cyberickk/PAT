#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		
		int cnt;
		cin >> cnt;
		vector<int> v(cnt);
		bool flag = 1;
		for(int j = 0;j < cnt; ++j) {
			cin >> v[j];
			for(int k = 0; k < j; ++k) {
				if(v[k] == v[j] || abs(v[k] - v[j]) == (j-k)) {
					flag = 0;
					break;
				}
			}
		}
		cout << (flag == 1 ? "YES\n" : "NO\n" );
		
	}
	return 0;
}
