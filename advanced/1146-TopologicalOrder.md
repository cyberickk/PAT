# 1146 Topological Order

This is a problem given in the Graduate Entrance Exam in 2018: Which of the following is NOT a topological order obtained from the given directed graph? Now you are supposed to write a program to test each of the options.

![gre.jpg](https://images.ptausercontent.com/5d35ed2a-4d19-4f13-bf3f-35ed59cebf05.jpg)

### Input Specification:

Each input file contains one test case. For each case, the first line gives two positive integers N (≤ 1,000), the number of vertices in the graph, and M (≤ 10,000), the number of directed edges. Then M lines follow, each gives the start and the end vertices of an edge. The vertices are numbered from 1 to N. After the graph, there is another positive integer K (≤ 100). Then K lines of query follow, each gives a permutation of all the vertices. All the numbers in a line are separated by a space.

### Output Specification:

Print in a line all the indices of queries which correspond to "NOT a topological order". The indices start from zero. All the numbers are separated by a space, and there must no extra space at the beginning or the end of the line. It is graranteed that there is at least one answer.

### Sample Input:

```in
6 8
1 2
1 3
5 2
5 4
2 3
2 6
3 4
6 4
5
1 5 2 3 6 4
5 1 2 6 3 4
5 1 2 3 6 4
5 2 1 6 3 4
1 2 3 4 5 6   
```

### Sample Output:

```out
3 4
```



结点之间的拓扑关系用 `map<int, vector<int>> ma` 来存放，每个结点记录它的所有前驱结点。读取每个拓扑序列时，用 `set<int> pre` 存放前面已经遍历过的结点，针对每一个输入的结点，遍历 `map ma` 中该点对应的所有前驱结点是否已经存在于 `set pre` 中，如果没有出现则表示拓扑序列判定失败，将序列编号放入 `vector<int> ans` 中； 但不能 `break` 仍然要读完这轮序列剩余的结点，否则影响下一轮序列的判定。 最后遍历 `ans` 输出编号，除了输出第一个值，其余都先输出空格再输出编号，符合题目的格式要求。

存取图的时间复杂度 O(nlogn)，判定序列时针对每一个输入的结点都要查询并遍历 `map` ，总的时间复杂度大约在 O(nlogn)；用到的辅助空间比较多，平均的空间复杂度 O(n)

```c++
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m;
	map<int, vector<int>> ma;
	vector<int> ans;		//存放不是拓扑序列的序列编号
	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		ma[b].push_back(a);
	}
	cin >> k;
	for(int i = 0; i < k; ++i) {
		set<int> pre;
		bool flag = 1;		//判定是否是拓扑序列
		for(int j = 0; j < n; ++j) {
			int d;
			cin >> d;
			if(ma.count(d)) {
				for(auto it:ma[d]) {
					if(pre.count(it) == 0) {
						flag = 0;
					}
				}
			}
			pre.insert(d);
		}
		if(!flag) {
			ans.push_back(i);
		}
	}
	for(int i = 0; i < ans.size(); ++i) {
		if(i) cout << " ";
		cout << ans[i];
	}
	return 0;
} 
```



测评结果可以看到数据量比较大的时候耗时和内存都有显著增高。

| 测试点 | 结果     | 耗时   | 内存   |
| ------ | -------- | ------ | ------ |
| 0      | 答案正确 | 3 ms   | 412 KB |
| 1      | 答案正确 | 3 ms   | 496 KB |
| 2      | 答案正确 | 3 ms   | 356 KB |
| 3      | 答案正确 | 3 ms   | 360 KB |
| 4      | 答案正确 | 120 ms | 608 KB |



## 优化

1. 把 `map` 换成 `unordered_map` ，时间减少 15ms，效率提升 12.5%

| 测试点 | 结果     | 耗时   | 内存   |
| ------ | -------- | ------ | ------ |
| 0      | 答案正确 | 3 ms   | 372 KB |
| 1      | 答案正确 | 3 ms   | 384 KB |
| 2      | 答案正确 | 4 ms   | 384 KB |
| 3      | 答案正确 | 4 ms   | 384 KB |
| 4      | 答案正确 | 105 ms | 552 KB |



2. 换成 `unordered_map` 以及 `cin`  换成 `scanf` ，运行时间减少 52ms，效率提升 43.3%

| 测试点 | 结果     | 耗时  | 内存   |
| ------ | -------- | ----- | ------ |
| 0      | 答案正确 | 5 ms  | 592 KB |
| 1      | 答案正确 | 5 ms  | 384 KB |
| 2      | 答案正确 | 6 ms  | 384 KB |
| 3      | 答案正确 | 4 ms  | 424 KB |
| 4      | 答案正确 | 68 ms | 552 KB |



```c++
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

int main() {
	int n, m, k, cnt = 0;
	cin >> n >> m;
	unordered_map<int, vector<int>> ma;
	vector<int> ans;
	for(int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		ma[b].push_back(a);
	}
	cin >> k;
	for(int i = 0; i < k; ++i) {
		set<int> pre;
		bool flag = 1;
		for(int j = 0; j < n; ++j) {
			int d;
			scanf("%d", &d);
			if(ma.count(d)) {
				for(auto it:ma[d]) {
					if(pre.count(it) == 0) {
						flag = 0;
					}
				}
			}
			pre.insert(d);
		}
		if(!flag) {
			ans.push_back(i);
		}
	}
	for(int i = 0; i < ans.size(); ++i) {
		if(i) printf(" ");
		printf("%d", ans[i]);
	}
	return 0;
} 
```





3. 程序设计上的优化。

   - 图的拓扑结构存储采用邻接表，节省空间以及提升效率。数组中的下标值即为结点编号，这个位置存放的内容是它的所有后继；同时用数组 `int in[1010] = {0}` 记录每个结点有多少个前驱结点。
   - 判定时复制 `in` 到 `vector<int> tin` 中，以此作为基准，输入一个结点后先检查这个结点的前驱，如果 `tin` 中存放的前驱结点数量大于 0，就表示非拓扑序列；同时把它的后继结点的 `tin` 值都减 1，自然如果一个结点的前驱结点都已经遍历过那么 `tin` 中对应位置的值应是 1
   - 输出控制采用计数变量 `cnt` ，初始值设定为 0，`cnt` 非 0 时都先输出空格，再输出序列编号。为了节省空间，不再另外使用数组记录答案值，每轮循环中判定不是拓扑序列就立即输出。

   时间复杂度分析，读取并存储图结构时由于采用邻接表，`vector` 的访问和随机存取比 `map` 高效，时间复杂度 O(n)，判定时的查询也同样高效一点，总的时间复杂度应该略低于 O(nlogn)；空间复杂度近似于 O(n)

```c++
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, a, b, k, in[1010] = {0}, cnt = 0;
	scanf("%d %d", &n, &m);
	vector<int> v[1010];			//邻接表存储拓扑结构
	for(int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		in[b]++;
	}
	cin >> k;
	for(int i = 0; i < k; ++i) {
		bool flag = 1;				//判定拓扑序列
		vector<int> tin(in, in+n+1);
		for(int j = 0; j < n; ++j) {
			scanf("%d", &a);
			if(tin[a] != 0) flag = 0;		//非拓扑序列
			for(auto it: v[a]) tin[it]--;
		}
		if(flag == 1) continue;
		if(cnt) printf(" ");		//空格输出控制
		printf("%d", i);
		cnt++;
	}
	return 0;
} 
```



从测试结果来看，运行时间减少 92ms，效率提升 76.7%

| 测试点 | 结果     | 耗时  | 内存   |
| ------ | -------- | ----- | ------ |
| 0      | 答案正确 | 5 ms  | 424 KB |
| 1      | 答案正确 | 5 ms  | 472 KB |
| 2      | 答案正确 | 5 ms  | 384 KB |
| 3      | 答案正确 | 5 ms  | 380 KB |
| 4      | 答案正确 | 28 ms | 384 KB |