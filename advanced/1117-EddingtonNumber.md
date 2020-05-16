# 1117 Eddington Number

British astronomer Eddington liked to ride a bike. It is said that in order to show off his skill, he has even defined an "Eddington number", *E* -- that is, the maximum integer *E* such that it is for *E* days that one rides more than *E* miles. Eddington's own *E* was 87.

Now given everyday's distances that one rides for *N* days, you are supposed to find the corresponding *E* (≤*N*).

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer *N* (≤105), the days of continuous riding. Then *N* non-negative integers are given in the next line, being the riding distances of everyday.

### Output Specification:

For each case, print in a line the Eddington number for these *N* days.

### Sample Input:

```in
10
6 7 6 9 3 10 8 2 7 8
```

### Sample Output:

```out
6
```



逻辑题，关键是理清思路。累计 k 天骑行距离超过（大于） k，这个数值受到天数的限制。先将所有距离从大到小排序，从 0 开始检查，第 i 位表示目前为止一共 i+1天，距离一定要超过 i+1； `v[i] > i+1` 做判定条件，结果 `e++` ；增加到 `v[i] = i + 1` 或 `v[i] < i+1` 时退出循环，上一次循环结束后的 `e` 就是最大值。

时间复杂度 O(n)，空间复杂度 O(n)

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, e = 0;
	scanf("%d", &n);
	vector<int> v(n);
	for(int i = 0; i < n; ++i) 
		scanf("%d", &v[i]);
	sort(v.rbegin(), v.rend());
	while(e < n && v[e] > e+1) e++;
	printf("%d", e); 
	return 0;
}
```





| 测试点 | 结果     | 耗时  | 内存   |
| ------ | -------- | ----- | ------ |
| 0      | 答案正确 | 4 ms  | 512 KB |
| 1      | 答案正确 | 4 ms  | 512 KB |
| 2      | 答案正确 | 4 ms  | 364 KB |
| 3      | 答案正确 | 35 ms | 808 KB |
| 4      | 答案正确 | 4 ms  | 608 KB |
| 5      | 答案正确 | 5 ms  | 384 KB |