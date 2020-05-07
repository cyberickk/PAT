# 1154 Vertex Coloring



A **proper vertex coloring** is a labeling of the graph's vertices with colors such that no two vertices sharing the same edge have the same color. A coloring using at most *k* colors is called a (proper) **k\-coloring**.

Now you are supposed to tell if a given coloring is a proper *k*-coloring.

### Input Specification:

Each input file contains one test case. For each case, the first line gives two positive integers *N* and *M* (both no more than 104), being the total numbers of vertices and edges, respectively. Then *M* lines follow, each describes an edge by giving the indices (from 0 to *N*−1) of the two ends of the edge.

After the graph, a positive integer *K* (≤ 100) is given, which is the number of colorings you are supposed to check. Then *K* lines follow, each contains *N* colors which are represented by non-negative integers in the range of **int**. The *i*-th color is the color of the *i*-th vertex.

### Output Specification:

For each coloring, print in a line `k-coloring` if it is a proper `k`-coloring for some positive `k`, or `No` if not.

### Sample Input:

```in
10 11
8 7
6 8
4 5
8 4
8 1
1 2
1 4
9 8
9 1
1 0
2 4
4
0 1 0 1 4 1 0 1 3 0
0 1 0 1 4 1 0 1 0 0
8 1 0 1 4 1 0 5 3 0
1 2 3 4 5 6 7 8 8 9   
```

### Sample Output:

```out
4-coloring
No
6-coloring
No
```



和前一道旅行商问题类似，图以每条边的形式给出，用 `vector<node> v` 来存储图， 其中 `struct node{int t1, t2};` ，数组中每个元素代表一条边。点的着色用 `int a[10010] = {0}` 和 `set<int> s` 同时存储，便于后面判断一共有多少种颜色。

接下来判断几色图，遍历所有的边，如果边的两个点着色相同则判定`No`，否则遍历结束输出 `%d-coloring` ，其中数字为 `s.size()` 

读入所有边的时间复杂度 O(m)，读取着色方案的时间复杂度 O(k)，其中判定每种方案的时间复杂度 O(n+m)，总的时间复杂度在 O(n^2)，因为 `k` 在 100 以内，时间复杂度接近于 O(n)；空间上主要用一个数组存储边，一个数组和一个集合存储着色，空间复杂度 O(n)

```c++
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
			if(a[v[i].t1] == a[v[i].t2]) { //核心判定条件，一条边上的两个点颜色是否相同
				flag = 0;
				break;
			}
		}
		if(flag) printf("%d-coloring\n", s.size());
		else printf("No\n");
	}
	return 0;
}
```

