# 1121 Damn Single

"Damn Single (单身狗)" is the Chinese nickname for someone who is being single. You are supposed to find those who are alone in a big party, so they can be taken care of.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (≤ 50,000), the total number of couples. Then N lines of the couples follow, each gives a couple of ID's which are 5-digit numbers (i.e. from 00000 to 99999). After the list of couples, there is a positive integer M (≤ 10,000) followed by M ID's of the party guests. The numbers are separated by spaces. It is guaranteed that nobody is having bigamous marriage (重婚) or dangling with more than one companion.

### Output Specification:

First print in a line the total number of lonely guests. Then in the next line, print their ID's in increasing order. The numbers must be separated by exactly 1 space, and there must be no extra space at the end of the line.

### Sample Input:

```in
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
```

### Sample Output:

```out
5
10000 23333 44444 55555 88888
```



用 `int v[100010] = {-1}` 存储每个宾客的 couple，`bool guest[100010] = {0}` 存储出席的并且有 couple 的宾客， `vector<int> ans` 存储没有 couple 或者有 couple 但只身一人出席的宾客。

读取出席宾客时，如果没有 couple，直接存入 `ans`，否则把 `guest` 置为 1 表示出席。遍历 `guest` ，出席者判定他的 `couple`  是否出席，没有则放入 `ans` 。最后对 `ans` 进行排序，输出时注意格式控制，用 0 填补空缺的5位整数。

读取 couple 的时间复杂度  O(n)，读取宾客的时间复杂度 O(n)，进行判定的时间复杂度 O(n)，排序的时间复杂度 O(nlogn)，总的时间复杂度 O(nlogn)；空间复杂度 O(n)

```c++
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
```



| 测试点 | 结果     | 耗时  | 内存    |
| ------ | -------- | ----- | ------- |
| 0      | 答案正确 | 4 ms  | 804 KB  |
| 1      | 答案正确 | 4 ms  | 768 KB  |
| 2      | 答案正确 | 4 ms  | 768 KB  |
| 3      | 答案正确 | 26 ms | 1024 KB |
| 4      | 答案正确 | 24 ms | 896 KB  |



也可以用 `set` 存放最终结果，插入时自动完成排序。但因为每次插入都有排序操作，整体运行时间以及占用空间都比 `vector` 要高一些。记录出现的宾客一定要用数组，进行检查时随机存取效率高，用 `set` 记录的话每次 `count` 的时间太长，有一个测试用例会超时。

```c++
#include <iostream>
#include <vector>
#include <set>

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
	set<int> ans;
	for(int i = 0; i < k; ++i) {
		scanf("%d", &a);	
		if(v[a] == -1)	ans.insert(a);
		else guest[a] = 1;
	}
	for(int i = 0; i < 100010; ++i) {
		if(guest[i] == 1) {
			if(guest[v[i]] == 0)	ans.insert(i);
		}		
	}
	printf("%d\n", ans.size());
	for(auto it = ans.begin(); it != ans.end(); ++it) {
		if(it != ans.begin()) printf(" ");
		printf("%05d",*it); 
	}
	return 0;
}
```



| 测试点 | 结果     | 耗时  | 内存    |
| ------ | -------- | ----- | ------- |
| 0      | 答案正确 | 5 ms  | 868 KB  |
| 1      | 答案正确 | 5 ms  | 940 KB  |
| 2      | 答案正确 | 5 ms  | 896 KB  |
| 3      | 答案正确 | 27 ms | 1448 KB |
| 4      | 答案正确 | 26 ms | 1408 KB |