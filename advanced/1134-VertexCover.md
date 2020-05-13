# 1134 Vertex Cover

A **vertex cover** of a graph is a set of vertices such that each edge of the graph is incident to at least one vertex of the set. Now given a graph with several vertex sets, you are supposed to tell if each of them is a vertex cover or not.

### Input Specification:

Each input file contains one test case. For each case, the first line gives two positive integers *N* and *M* (both no more than 104), being the total numbers of vertices and the edges, respectively. Then *M* lines follow, each describes an edge by giving the indices (from 0 to *N*−1) of the two ends of the edge.

After the graph, a positive integer *K* (≤ 100) is given, which is the number of queries. Then *K* lines of queries follow, each in the format:

*N**v* *v*[1] *v*[2]⋯*v*[*N**v*]

where *N**v* is the number of vertices in the set, and *v*[*i*]'s are the indices of the vertices.

### Output Specification:

For each query, print in a line `Yes` if the set is a vertex cover, or `No` if not.

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
5
4 0 3 8 4
6 6 1 7 5 4 9
3 1 8 4
2 2 8
7 9 8 7 6 5 4 2
```

### Sample Output:

```out
No
Yes
Yes
No
No
```



题目大意一直没读懂，看了其他人的解释才明白。在给定的点集中，原图里任意一条边，都至少有一个顶点包含在点集中，则输出 `Yes` ，否则输出 `No` ；思路是先存储边，再检查每一条边。一开始用二维数组存放，有边的位置置为 1，否则是 0，检查点集时遍历二维数组每一个点，是 1 的位置就检查两个点是否都不存在，但是提交时后面两个测试点段错误，这样完全遍历需要 `n^2` 次循环，耗时太长了。

于是选用另一种方法存储已经有的边，检查时只遍历存在的边即可。创建两个 `vector<int> va, vb` ，每一条边，两个结点分别放在 `va`  `vb` 中，这样只需要 `m` 次循环即可全部检查完毕。还可以增加标志位 `flag` ，碰到两个点都不存在的边就 `flag = 0` 退出循环，节省时间。

存储边的时间复杂度 O(n)，存储每个点集的时间复杂度 O(n)，检查每个点集的时间复杂度 O(n)，总的时间复杂度 O(n^2)；空间复杂度 O(n)

```c++
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int n, m, k, a, b;
	scanf("%d %d", &n, &m);
	vector<int> va, vb;
	for(int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		va.push_back(a);
		vb.push_back(b);
	}
	scanf("%d", &k);	
	for(int i = 0; i < k; ++i) {
		set<int> check;
		bool flag = 1;
		scanf("%d", &a);
		while(a--) {
			scanf("%d", &b);
			check.insert(b);
		}
		for(int j = 0; j < m; ++j) {
			if(check.count(va[j]) == 0 && check.count(vb[j]) == 0) {
				flag = 0;
				break;
			}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}
```



| 测试点 | 结果     | 耗时   | 内存   |
| ------ | -------- | ------ | ------ |
| 0      | 答案正确 | 4 ms   | 452 KB |
| 1      | 答案正确 | 4 ms   | 352 KB |
| 2      | 答案正确 | 263 ms | 916 KB |
| 3      | 答案正确 | 253 ms | 792 KB |