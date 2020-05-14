# 1126 Eulerian Path

In graph theory, an Eulerian path is a path in a graph which visits every edge exactly once. Similarly, an Eulerian circuit is an Eulerian path which starts and ends on the same vertex. They were first discussed by Leonhard Euler while solving the famous Seven Bridges of Konigsberg problem in 1736. It has been proven that connected graphs with all vertices of even degree have an Eulerian circuit, and such graphs are called **Eulerian**. If there are exactly two vertices of odd degree, all Eulerian paths start at one of them and end at the other. A graph that has an Eulerian path but not an Eulerian circuit is called **semi-Eulerian**. (Cited from https://en.wikipedia.org/wiki/Eulerian_path)

Given an undirected graph, you are supposed to tell if it is Eulerian, semi-Eulerian, or non-Eulerian.

### Input Specification:

Each input file contains one test case. Each case starts with a line containing 2 numbers N (≤ 500), and M, which are the total number of vertices, and the number of edges, respectively. Then M lines follow, each describes an edge by giving the two ends of the edge (the vertices are numbered from 1 to N).

### Output Specification:

For each test case, first print in a line the degrees of the vertices in ascending order of their indices. Then in the next line print your conclusion about the graph -- either `Eulerian`, `Semi-Eulerian`, or `Non-Eulerian`. Note that all the numbers in the first line must be separated by exactly 1 space, and there must be no extra space at the beginning or the end of the line.

### Sample Input 1:

```in
7 12
5 7
1 2
1 3
2 3
2 4
3 4
5 2
7 6
6 3
4 5
6 4
5 6
```

### Sample Output 1:

```out
2 4 4 4 4 4 2
Eulerian
```

### Sample Input 2:

```in
6 10
1 2
1 3
2 3
2 4
3 4
5 2
6 3
4 5
6 4
5 6
```

### Sample Output 2:

```out
2 4 4 4 3 3
Semi-Eulerian
```

### Sample Input 3:

```in
5 8
1 2
2 5
5 4
4 1
1 3
3 2
3 4
5 3
```

### Sample Output 3:

```out
3 3 4 3 3
Non-Eulerian
```



欧拉回路问题。一个连通图如果所有的点度数均为偶数则是 `Eulerian` ，如果只有两个点的度数是奇数则是 `Semi-Eulerian` ， 则是 `Non-Eulerian` 。

一开始只用一个一维数组存储每个结点的度，最后统计输出。结果有一个测试点通不过。原因在于必须首先判定是连通图才能有 `Eulerian`  `Semi-Eulerian` ，如果不连通，即使结点度数满足要求也仍然是 `Non-Eulerian` 。所以采用二维数组存储每个结点相邻的点（邻接表法），第二维的 `size()` 是该结点的度，用深度优先搜索算法判定，如果最终遍历过的结点个数等于总结点数 `cnt ==  n` 那么是连通图。

存储图的时间复杂度 O(m)，DFS 时间复杂度 O(m+n)，输出度数的时间复杂度 O(n)，总的时间复杂度 O(n+m)；空间复杂度 O(n)

```c++
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v; 
vector<bool> visit;
int cnt = 0;

void dfs(int index) {
	visit[index] = 1;
	cnt++;
	for(int i = 0; i < v[index].size(); ++i)
		if(visit[v[index][i]] == 0)
			dfs(v[index][i]);
}

int main() {
	int n, m, a, b, odd = 0;
	scanf("%d %d", &n, &m);
	v.resize(n+1);
	visit.resize(n+1);
	for(int i = 1; i <= m; ++i) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a); 
	}	
	for(int i = 1; i <= n; ++i) {
		if(i != 1) printf(" ");
		printf("%d", v[i].size());
		if(v[i].size() % 2 == 1)	odd++;
	}
	dfs(1);
	if(odd == 0 && cnt == n) printf("\nEulerian\n");
	else if(odd == 2 && cnt == n) printf("\nSemi-Eulerian\n");
	else printf("\nNon-Eulerian\n");
	return 0;
} 
```



| 测试点 | 结果     | 耗时  | 内存    |
| ------ | -------- | ----- | ------- |
| 0      | 答案正确 | 4 ms  | 404 KB  |
| 1      | 答案正确 | 4 ms  | 384 KB  |
| 2      | 答案正确 | 3 ms  | 384 KB  |
| 3      | 答案正确 | 4 ms  | 384 KB  |
| 4      | 答案正确 | 4 ms  | 384 KB  |
| 5      | 答案正确 | 4 ms  | 488 KB  |
| 6      | 答案正确 | 44 ms | 1408 KB |