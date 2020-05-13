# 1142 Maximal Clique

A **clique** is a subset of vertices of an undirected graph such that every two distinct vertices in the clique are adjacent. A **maximal clique** is a clique that cannot be extended by including one more adjacent vertex. (Quoted from https://en.wikipedia.org/wiki/Clique_(graph_theory))

Now it is your job to judge if a given subset of vertices can form a maximal clique.

### Input Specification:

Each input file contains one test case. For each case, the first line gives two positive integers Nv (≤ 200), the number of vertices in the graph, and Ne, the number of undirected edges. Then Ne lines follow, each gives a pair of vertices of an edge. The vertices are numbered from 1 to Nv.

After the graph, there is another positive integer M (≤ 100). Then M lines of query follow, each first gives a positive number K (≤ Nv), then followed by a sequence of K distinct vertices. All the numbers in a line are separated by a space.

### Output Specification:

For each of the M queries, print in a line `Yes` if the given subset of vertices can form a maximal clique; or if it is a clique but not a **maximal clique**, print `Not Maximal`; or if it is not a clique at all, print `Not a Clique`.

### Sample Input:

```in
8 10
5 6
7 8
6 4
3 6
4 5
2 3
8 2
2 7
5 3
3 4
6
4 5 4 3 6
3 2 8 7
2 2 3
1 1
3 4 3 6
3 3 2 1    
```

### Sample Output:

```out
Yes
Yes
Yes
Yes
Not Maximal
Not a Clique
```



图的存储采用二维数组，相邻的边置为 1， 否则是 0；

点集分为以下几种：

- maximal clique 点集中的任意两个点相邻接，并且再加入其它的点都不再满足该条件（即加入的点不能和已经存在的所有点相邻接）
- not maxima clique，点集中的任意两个点相邻接，但仍存在其它的点，加入后依然符合该条件
- not a clique 点集中存在不相邻的两个点

判定时把结点存入 `vector` 中，并且用数组 `int has[210]` 记录出现的点，便于下面寻找没出现的点。判定分为以下步骤：

- 遍历点集中的所有点，如果出现一对结点不相邻，则  `not clique`，直接输出判定结果
- 在确定是 clique 的情况下，判定是否是 maximal，即遍历点集中不存在的点，如果找到一个点可以和点集中所有的点相邻，则 `Not Maximal`
- 否则遍历结束，确定是 maximal，输出 `Yes` 

读取所有边的时间复杂度 O(n)，判定每个点集的时间复杂度 O(n^2)，总的时间复杂度 O(n^2)；空间复杂度 O(n)

```c++
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int nv, ne, m, a, b, e[210][210];
	scanf("%d %d", &nv, &ne);
	for(int i = 0; i < ne; ++i) {
		scanf("%d %d", &a, &b);
		e[a][b] = e[b][a] = 1;
	}
	scanf("%d", &m);
	for(int i = 0; i < m; ++i) {
		int k, t, hash[210] = {0};
		scanf("%d", &k);
		vector<int> v(k);
		for(int j = 0; j < k; ++j) {
			scanf("%d", &v[j]);
			hash[v[j]] = 1;
		}
		bool isclique = 1, ismaximal = 1;
		for(int j = 0; j < k; ++j) {
			for(int l = j+1; l < k; ++l) {
				if(!isclique) break;
				if(e[v[j]][v[l]] == 0) {
					isclique = 0; 
					printf("Not a Clique\n");
					break;
				}
			}
			
		}
		if(isclique) {
			for(int j = 1; j <= nv; ++j) {
				if(hash[j] == 0) {
					for(int l = 0; l < k; ++l) {
						if(e[v[l]][j] == 0) break;
						if(l == k-1) ismaximal = 0;
					}
				}
				if(ismaximal == 0) {
					printf("Not Maximal\n");
					break;
				}
			}
			if(ismaximal) printf("Yes\n");
		}		
	}
	return 0;
}
```



| 测试点 | 结果     | 耗时  | 内存   |
| ------ | -------- | ----- | ------ |
| 0      | 答案正确 | 2 ms  | 372 KB |
| 1      | 答案正确 | 3 ms  | 424 KB |
| 2      | 答案正确 | 4 ms  | 384 KB |
| 3      | 答案正确 | 17 ms | 616 KB |
| 4      | 答案正确 | 4 ms  | 484 KB |