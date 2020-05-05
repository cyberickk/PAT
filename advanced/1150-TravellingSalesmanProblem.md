# 1150 Travelling Salesman Problem

The "travelling salesman problem" asks the following question: "Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city and returns to the origin city?" It is an NP-hard problem in combinatorial optimization, important in operations research and theoretical computer science. (Quoted from "https://en.wikipedia.org/wiki/Travelling_salesman_problem".)

In this problem, you are supposed to find, from a given list of cycles, the one that is the closest to the solution of a travelling salesman problem.

### Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers *N* (2<*N*≤200), the number of cities, and *M*, the number of edges in an undirected graph. Then *M* lines follow, each describes an edge in the format `City1 City2 Dist`, where the cities are numbered from 1 to *N* and the distance `Dist` is positive and is no more than 100. The next line gives a positive integer *K* which is the number of paths, followed by *K* lines of paths, each in the format:

*n* *C*1 *C*2 ... *C**n*

where *n* is the number of cities in the list, and *C**i*'s are the cities on a path.

### Output Specification:

For each path, print in a line `Path X: TotalDist (Description)` where `X` is the index (starting from 1) of that path, `TotalDist` its total distance (if this distance does not exist, output `NA` instead), and `Description` is one of the following:

- `TS simple cycle` if it is a simple cycle that visits every city;
- `TS cycle` if it is a cycle that visits every city, but not a simple cycle;
- `Not a TS cycle` if it is NOT a cycle that visits every city.

Finally print in a line `Shortest Dist(X) = TotalDist` where `X` is the index of the cycle that is the closest to the solution of a travelling salesman problem, and `TotalDist` is its total distance. It is guaranteed that such a solution is unique.

### Sample Input:

```in
6 10
6 2 1
3 4 1
1 5 1
2 5 1
3 1 8
4 1 6
1 6 1
6 3 1
1 2 1
4 5 1
7
7 5 1 4 3 6 2 5
7 6 1 3 4 5 2 6
6 5 1 4 3 6 2
9 6 2 1 6 3 4 5 2 6
4 1 2 5 1
7 6 1 2 5 4 3 1
7 6 3 2 5 4 1 6   
```

### Sample Output:

```out
Path 1: 11 (TS simple cycle)
Path 2: 13 (TS simple cycle)
Path 3: 10 (Not a TS cycle)
Path 4: 8 (TS cycle)
Path 5: 3 (Not a TS cycle)
Path 6: 13 (Not a TS cycle)
Path 7: NA (Not a TS cycle)
Shortest Dist(4) = 8
```



旅行商问题，图以所有边的形式给出，用二维数组存放，下标代表边的两个节点，值表示这条边的权重。给出的路径代表经过的节点，把节点序列用 `vector` 和 `set` 存储，对于每条路径判断以下几点：

- 路径总长度，查询二维数组求和即可
- 如果碰到不存在的边则 `flag = 0` 
- `TS cycle` 路径首尾节点相同，访问所有节点但访问的节点数量大于总的节点数量加一
- `TS simple cycle` 访问所有节点且数量刚好等于总节点数加一
- `Not a TS cycle` 首尾节点不同，或者访问节点数量小于等于总节点数
- 另外要求最短的旅行商环路序号以及距离，从每个符合 `TS cycle` 或者 `TS simple cycle` 的距离中存到最小值和序号即可

题目乍一看觉得比较复杂，其实梳理下来并不困难。首先解决数据结构的问题，图用什么来存储，给出的每条路径用什么来存储；接着就是针对每条路径的理解和判断，求路径长度很简单，判断是否为旅行商环路等价于遍历所有节点且首尾节点相同，简单旅行商环路是首尾节点相同其他节点遍历一次，简化成路径数量和节点总数的大小比较问题。

存储图的时间复杂度 O(n)，判断路径的时间复杂度 O(n)，总的时间复杂度 O(n)，空间复杂度 O(n)

```c++
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m, k, e[210][210], ans = 99999999, ansid;

void check(int index) {
	int cnt, sum = 0, flag = 1;
	cin >> cnt;
	set<int> s;
	vector<int> v(cnt);
	for(int i = 0; i < cnt; ++i) {
		cin >> v[i];
		s.insert(v[i]);
	}
	for(int i = 0; i < cnt-1; ++i) {
		if(e[v[i]][v[i+1]] == 0) {
      		flag = 0;
      		break;
    	}
		sum += e[v[i]][v[i+1]];
	}
	if(flag == 0) 
		printf("Path %d: NA (Not a TS cycle)\n", index);
	else if(v[cnt-1] != v[0] || s.size() != n)
		printf("Path %d: %d (Not a TS cycle)\n", index, sum);
	else if(cnt != n+1) {
		printf("Path %d: %d (TS cycle)\n", index, sum);
		if (sum < ans) {
		ans = sum;
		ansid = index;
		}
	}
	else {
		printf("Path %d: %d (TS simple cycle)\n", index, sum);
		if (sum < ans) {
		ans = sum;
		ansid = index;
		}
	}		 
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int a, b, d;
		cin >> a >> b >> d;
		e[a][b] = e[b][a] = d;
	}
	cin >> k;
	for(int i = 1; i <= k; ++i) {
		check(i);
	}
	printf("Shortest Dist(%d) = %d", ansid, ans);
	return 0;
} 
```

