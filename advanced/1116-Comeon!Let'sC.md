# 1116 Come on! Let's C

"Let's C" is a popular and fun programming contest hosted by the College of Computer Science and Technology, Zhejiang University. Since the idea of the contest is for fun, the award rules are funny as the following:

- 0、 The Champion will receive a "Mystery Award" (such as a BIG collection of students' research papers...).
- 1、 Those who ranked as a prime number will receive the best award -- the Minions (小黄人)!
- 2、 Everyone else will receive chocolates.

Given the final ranklist and a sequence of contestant ID's, you are supposed to tell the corresponding awards.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (≤104), the total number of contestants. Then N lines of the ranklist follow, each in order gives a contestant's ID (a 4-digit number). After the ranklist, there is a positive integer K followed by K query ID's.

### Output Specification:

For each query, print in a line `ID: award` where the award is `Mystery Award`, or `Minion`, or `Chocolate`. If the ID is not in the ranklist, print `Are you kidding?` instead. If the ID has been checked before, print `ID: Checked`.

### Sample Input:

```in
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222         
```

### Sample Output:

```out
8888: Minion
0001: Chocolate
1111: Mystery Award
2222: Are you kidding?
8888: Checked
2222: Are you kidding?
```



拆解为以下几个问题：

1. 读取 ID，根据循环的计数变量 `i` 计算获得的奖项。存储 ID 与对应奖项，ID 为 4 位整数，直接用 `int` 即可，奖项用 `string`， 构造 `map<int, string> m` 
2. 查询时分为有奖项记录、有记录已查询过、无记录几种情况，对于已查询过的特殊处理，虽然可以用 `set` 记录已经查询过的 ID，但为了节省空间，在每次查询输出后将 `map` 中的奖项置空，那么在查询时发现为空则输出 `Checked` 。

ID 是 4 位整数，判定素数的时间是常数级，整体时间复杂度 O(n)；用 `map` 存放奖项，空间复杂度 O(n)

```c++
#include <iostream>
#include <map>

using namespace std;

bool isPrime(int n) {
	for(int i = 2; i * i <= n; ++i) {
		if(n % i == 0)
			 return 0;
	}
	return 1;
}

int main() {
	int n, k, q;
	cin >> n;
	map<int, string> m;
	for(int i = 1; i <= n; ++i) {
		cin >> q;
		if(i == 1) m[q] = "Mystery Award";
		else if(isPrime(i))
			m[q] = "Minion";
	 	else
	 		m[q] = "Chocolate";
	}
	cin >> k;
	for(int i = 0; i < k; ++i) {
		cin >> q;
		printf("%04d: ", q);	//输出格式为 4 位整数
		if(m.count(q)) {
			if(m[q] == "0")
				printf("Checked\n");
			else {
				cout << m[q] << endl;
				m[q] = "0";	
			}
		}
		else
			printf("Are you kidding?\n");
	}
	return 0;
} 
```

