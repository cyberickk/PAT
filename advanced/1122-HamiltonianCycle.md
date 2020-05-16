# 1122 Hamiltonian Cycle

The "Hamilton cycle problem" is to find a simple cycle that contains every vertex in a graph. Such a cycle is called a "Hamiltonian cycle".

In this problem, you are supposed to tell if a given cycle is a Hamiltonian cycle.

### Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers *N* (2<*N*≤200), the number of vertices, and *M*, the number of edges in an undirected graph. Then *M* lines follow, each describes an edge in the format `Vertex1 Vertex2`, where the vertices are numbered from 1 to *N*. The next line gives a positive integer *K* which is the number of queries, followed by *K* lines of queries, each in the format:

*n* *V*1 *V*2 ... *V**n*

where *n* is the number of vertices in the list, and *V**i*'s are the vertices on a path.

### Output Specification:

For each query, print in a line `YES` if the path does form a Hamiltonian cycle, or `NO` if not.

### Sample Input:

```in
6 10
6 2
3 4
1 5
2 5
3 1
4 1
1 6
6 3
1 2
4 5
6
7 5 1 4 3 6 2 5
6 5 1 4 3 6 2
9 6 2 1 6 3 4 5 2 6
4 1 2 5 1
7 6 1 3 4 5 2 6
7 6 1 2 5 4 3 1
```

### Sample Output:

```out
YES
NO
NO
NO
YES
NO
```



哈密顿回路，包含一个图中的所有点的简单循环回路。用二维数组存储边（邻接矩阵），`vector` 和 `set` 同时存储给出的路径中的节点，判定以下几点：

- 是回路，`vector` 的第一个和最后一个元素相同
- 是简单回路，`vector` 的大小等于总结点数加一，并且 `set` 的大小是总结点数
- 路径中的相邻结点一定邻接，在读取每个结点的时候判断和上一个结点之间存在边即可

一般判定的思路都是设置标志位 `bool flag = 1` ，如果不满足条件则置为 0，最后按照标志输出对应结果。

读取边的时间复杂度 O(m)，判定每条路径的时间复杂度 O(n + logn)，总的时间复杂度 O(kn)；空间复杂度 O(n)

```c++
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	int n, m, k, a, b, e[210][210];
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		e[a][b] = e[b][a] = 1;
	}
	scanf("%d", &k);
	for(int i = 0; i < k; ++i) {
		int t;
		bool flag = 1;		
		scanf("%d", &t);
		vector<int> v(t);
		set<int> s;
		for(int j = 0; j < t; ++j)	{
			scanf("%d", &v[j]);
			s.insert(v[j]);
			if(j != 0)
				if(e[v[j]][v[j-1]] != 1)	flag = 0;
		}
		if(v[0] != v[t-1] || s.size() != n || v.size() != n+1)	flag = 0;
		if(flag)	printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
```



| 测试点 | 结果     | 耗时  | 内存   |
| ------ | -------- | ----- | ------ |
| 0      | 答案正确 | 4 ms  | 384 KB |
| 1      | 答案正确 | 3 ms  | 512 KB |
| 2      | 答案正确 | 4 ms  | 384 KB |
| 3      | 答案正确 | 4 ms  | 384 KB |
| 4      | 答案正确 | 73 ms | 492 KB |