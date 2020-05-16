#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, e = 0;
	scanf("%d", &n);
	vector<int> v(n);
	for(int i = 0; i < n; ++i) 
		scanf("%d", &v[i]);
	sort(v.rbegin(), v.rend());
	while(e < n && v[e] > e+1) e++;
	printf("%d", e); 
	return 0;
}
