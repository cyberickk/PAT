#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isprime(int n) {
	if(n == 1) return 0;
	for(int i = 2; i * i <= n; ++i) {
		if(n % i == 0) return 0;
	}
	return 1;
}

int main() {
	int ms, n, m;
	cin >> ms >> n >> m;
	//resize
	while(!isprime(ms)) {
		ms++;
	}
	vector<int> v(ms);
	for(int i = 0; i < n; ++i) {
		int d, cnt = 0;
		bool flag = 0;
		cin >> d;
		while(cnt < ms) {
			int pos = (d + cnt * cnt) % ms;
			if(v[pos] > 0) cnt++;
			else {
				v[pos] = d;
				flag = 1;
				break;
			}
		}
		if(!flag) printf("%d cannot be inserted.\n", d);
	}
	int d, ans = 0;
	for(int i = 0; i < m; ++i) {		
		cin >> d;
		for(int cnt = 0; cnt <= ms; cnt++) {
			ans++;
			int pos = (d + cnt * cnt) % ms;
			if(v[pos] == d || v[pos] == 0) break;
		}
	}
	printf("%.1f\n", ans * 1.0 / m);
	return 0;
}
