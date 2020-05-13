# 1129 Recommendation System

Recommendation system predicts the preference that a user would give to an item. Now you are asked to program a very simple recommendation system that rates the user's preference by the number of times that an item has been accessed by this user.

### Input Specification:

Each input file contains one test case. For each test case, the first line contains two positive integers: N (≤ 50,000), the total number of queries, and K (≤ 10), the maximum number of recommendations the system must show to the user. Then given in the second line are the indices of items that the user is accessing -- for the sake of simplicity, all the items are indexed from 1 to N. All the numbers in a line are separated by a space.

### Output Specification:

For each case, process the queries one by one. Output the recommendations for each query in a line in the format:

```
query: rec[1] rec[2] ... rec[K]
```

where `query` is the item that the user is accessing, and `rec[i]` (`i`=1, ... K) is the `i`-th item that the system recommends to the user. The first K items that have been accessed most frequently are supposed to be recommended in non-increasing order of their frequencies. If there is a tie, the items will be ordered by their indices in increasing order.

Note: there is no output for the first item since it is impossible to give any recommendation at the time. It is guaranteed to have the output for at least one query.

### Sample Input:

```in
12 3
3 5 7 5 5 3 2 1 8 3 8 12
```

### Sample Output:

```out
5: 3
7: 3 5
5: 3 5 7
5: 5 3 7
3: 5 3 7
2: 5 3 7
1: 5 3 2
8: 5 3 1
3: 5 3 1
8: 3 5 1
12: 3 5 8
```



题目大意也是看了别人讲解才明白，题目给出用户点击的商品序列，而每次推荐位最多有 `k` 位，推荐位是之前用户点击频率最高的 `k` 个商品。针对输入的点击序列，对每个商品给出点击它之前给出的最多 `k` 个推荐商品。第一个点击的商品不用输出。

利用 `set` 的自动排序特性，想办法重载 `operator <`，使它按照点击频率由高到低排列，点击频率相同的情况下编号由低到高排列。元素采用自定义的 `struct item` 包含编号 `id` 、点击频次 `freq` 以及重载的 `operatore <` ；用 `int book` 数组记录每件商品的点击频次，每次输入后从 `set` 中删除当前编号，更新频次后重新插入，保持 `set` 的排序合乎要求；。`book` 要定义在全局，否则有两个测试点会出错，没明白为什么。。。

梳理一下程序的思路：

- 定义全局变量 `int book[50001]` ， `struct item` 作为 `set` 元素，`set<item> s`  存储商品并用作输出
- 读取输入的每个商品序号，先输出前 `k` 位，再删除它对应的 `set` 元素，更新频次后重新插入

输出前 `k` 位的时间复杂度 O(k)，删除并重新插入元素的时间复杂度 O(logn)，总的时间复杂度 O(nlogn)；空间复杂度 O(n)

复习一下 `set` 的特点：

- 元素和比较函数可以自定义，但是一经配置不可更改
- 元素可以插入、删除，但是不能更改
- 有序，可以前向和后向遍历，有双向迭代器
- 插入、删除、查找的时间复杂度 O(logn)，底层实现是红黑树

```c++
#include <iostream>
#include <set>

using namespace std;

struct item {
	int id, freq;
	bool operator < (const item& a) const {
		 return (a.freq != freq) ? freq > a.freq : id < a.id;
	}
	
};
int book[50001];

int main() {
	int n, k, d;
	scanf("%d %d", &n, &k);
	set<item> s;
	
	for(int i = 0; i < n; ++i) {
		scanf("%d", &d);
		
		if(i != 0) {
			printf("%d:", d);
			int j = 0;
			for(auto it = s.begin(); j < k && it != s.end(); ++it) {
				printf(" %d", it->id);
				++j;
			}
			printf("\n");
		}		
		auto it = s.find(item{d, book[d]});
		if(it != s.end()) s.erase(it);
		book[d]++;
		s.insert(item{d, book[d]});
	}	
	return 0;
}
```





| 测试点 | 结果     | 耗时   | 内存    |
| ------ | -------- | ------ | ------- |
| 0      | 答案正确 | 4 ms   | 356 KB  |
| 1      | 答案正确 | 4 ms   | 384 KB  |
| 2      | 答案正确 | 4 ms   | 356 KB  |
| 3      | 答案正确 | 125 ms | 6184 KB |
| 4      | 答案正确 | 119 ms | 4392 KB |
| 5      | 答案正确 | 101 ms | 1976 KB |