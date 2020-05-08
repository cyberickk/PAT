# 1149 Dangerous Goods Packaging

When shipping goods with containers, we have to be careful not to pack some incompatible goods into the same container, or we might get ourselves in serious trouble. For example, oxidizing agent （氧化剂） must not be packed with flammable liquid （易燃液体）, or it can cause explosion.

Now you are given a long list of incompatible goods, and several lists of goods to be shipped. You are supposed to tell if all the goods in a list can be packed into the same container.

### Input Specification:

Each input file contains one test case. For each case, the first line gives two positive integers: *N* (≤104), the number of pairs of incompatible goods, and *M* (≤100), the number of lists of goods to be shipped.

Then two blocks follow. The first block contains N pairs of incompatible goods, each pair occupies a line; and the second one contains M lists of goods to be shipped, each list occupies a line in the following format:

```
K G[1] G[2] ... G[K]    
```

where `K` (≤1,000) is the number of goods and `G[i]`'s are the IDs of the goods. To make it simple, each good is represented by a 5-digit ID number. All the numbers in a line are separated by spaces.

### Output Specification:

For each shipping list, print in a line `Yes` if there are no incompatible goods in the list, or `No` if not.

### Sample Input:

```in
6 3
20001 20002
20003 20004
20005 20006
20003 20001
20005 20004
20004 20006
4 00001 20004 00002 20003
5 98823 20002 20003 20006 10010
3 12345 67890 23333    
```

### Sample Output:

```out
No
Yes
Yes
```



用 `unordered_map<int, vector<int>> ma` 来存储每种货物所有不相容的其他货物，对每一批货物进行检验时，用数组 `a[100000] = {0}` 来指示该编号的货物是否存在于这一批次中，遍历每个货物的 `ma` 来检查不相容的货物编号是否为 `1`，遍历结束输出 `Yes or No` 即可。

存放不相容的编号主要涉及 `map` 与 `vector` 的插入，平均时间复杂度 O(nlogn)， 检查货物时存放所有货物编号的时间复杂度 O(n)，检查 `ma` 的时间复杂度 O(n)， 总的时间复杂度 O(n^2 + nlogn)；空间上使用 `map` 与数组，空间复杂度 O(n)

```c++
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
```



