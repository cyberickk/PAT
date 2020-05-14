# 1125 Chain the Ropes

Given some segments of rope, you are supposed to chain them into one rope. Each time you may only fold two segments into loops and chain them into one piece, as shown by the figure. The resulting chain will be treated as another segment of rope and can be folded again. After each chaining, the lengths of the original two segments will be halved.

![rope.jpg](https://images.ptausercontent.com/46293e57-aa0e-414b-b5c3-7c4b2d5201e2.jpg)

Your job is to make the longest possible rope out of *N* given segments.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer *N* (2≤*N*≤104). Then *N* positive integer lengths of the segments are given in the next line, separated by spaces. All the integers are no more than 104.

### Output Specification:

For each case, print in a line the length of the longest possible rope that can be made by the given segments. The result must be rounded to the nearest integer that is no greater than the maximum length.

### Sample Input:

```in
8
10 15 12 3 4 13 1 15
```

### Sample Output:

```out
14
```



把绳子长度存入 `vector` 按从小到大存储，依次相加除 2；题目要求取不超过最大长度的整数，小数部分越除越小不会引起整数位增加，可以直接用 `int sum` 存储结果。注意两个绳子才可以打成结， `sum` 的初始值取 `v[0]` ，遍历时从 `v` 的第二个元素开始相加，这样除二后结果才正确。

输入绳子长度的时间复杂度 O(n)，排序的时间复杂度 O(nlogn)，计算总长的时间复杂度 O(n)，总的时间复杂度 O(nlogn)；空间复杂度O(n)

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;	
	scanf("%d", &n);
	vector<int> v(n);
	for(int i = 0; i < n; ++i) 
		scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	int sum = v[0];
	for(int i = 1; i < n; ++i) {
		sum += v[i];
		sum /= 2;				
	}
	printf("%d", sum);
	return 0;
}
```



| 测试点 | 结果     | 耗时 | 内存   |
| ------ | -------- | ---- | ------ |
| 0      | 答案正确 | 3 ms | 412 KB |
| 1      | 答案正确 | 3 ms | 384 KB |
| 2      | 答案正确 | 5 ms | 384 KB |
| 3      | 答案正确 | 5 ms | 512 KB |
| 4      | 答案正确 | 6 ms | 384 KB |



用 `multiset` 也可以实现。区别是 `sum` 初值不好取 `multiset` 的首位，迭代器也不方便从第二位开始，因此采用计数器 `cnt` ，从第二位起才开始除二。

每次输入元素时时间复杂度 O(logn)，存储全部长度的时间复杂度 O(nlogn)，计算总长的时间复杂度 O(n)，总的时间复杂度 O(nlogn)；空间复杂度 O(n)。因为每次插入元素都在排序，用时会比 `vector` 输入所有元素再排序长一些。

```c++
#include <iostream>
#include <set>

using namespace std;

int main() {
	int n, a;	
	scanf("%d", &n);
	multiset<int> v;
	for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        v.insert(a);
    }
	int sum = 0, cnt = 0;
	for(auto it:v) {
		sum += it;
        cnt++;
        if(cnt >= 2)
		    sum /= 2;				
	}
	printf("%d", sum);
	return 0;
}
```



| 测试点 | 结果     | 耗时 | 内存   |
| ------ | -------- | ---- | ------ |
| 0      | 答案正确 | 3 ms | 492 KB |
| 1      | 答案正确 | 3 ms | 424 KB |
| 2      | 答案正确 | 7 ms | 868 KB |
| 3      | 答案正确 | 6 ms | 868 KB |
| 4      | 答案正确 | 8 ms | 740 KB |