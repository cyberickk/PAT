# 1104 Sum of Number Segments

Given a sequence of positive numbers, a segment is defined to be a consecutive subsequence. For example, given the sequence { 0.1, 0.2, 0.3, 0.4 }, we have 10 segments: (0.1) (0.1, 0.2) (0.1, 0.2, 0.3) (0.1, 0.2, 0.3, 0.4) (0.2) (0.2, 0.3) (0.2, 0.3, 0.4) (0.3) (0.3, 0.4) and (0.4).

Now given a sequence, you are supposed to find the sum of all the numbers in all the segments. For the previous example, the sum of all the 10 segments is 0.1 + 0.3 + 0.6 + 1.0 + 0.2 + 0.5 + 0.9 + 0.3 + 0.7 + 0.4 = 5.0.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer *N*, the size of the sequence which is no more than 105. The next line contains *N* positive numbers in the sequence, each no more than 1.0, separated by a space.

### Output Specification:

For each test case, print in one line the sum of all the numbers in all the segments, accurate up to 2 decimal places.

### Sample Input:

```in
4
0.1 0.2 0.3 0.4          
```

### Sample Output:

```out
5.00
```



求所有片段的元素和，并不需要枚举每个片段的元素分别求和，而是看每个元素一共出现多少次（即元素出现在多少个不同的序列中）。设包含该元素的片段首尾位置是 `p` 和 `q` ，由于片段中元素顺序与原序列中的顺序一致，可知  `p` 和 `q`  的取值由元素前后各有几个元素决定（含元素本身的位置），不同的首尾位置即决定了不同的序列。 `p = i `， `q = n - i + 1` ， 于是一个元素出现的次数为 `i * (n-i+1)`，这样对每个元素求和即可。

最后控制输出时保留两位小数。

时间复杂度 O(n)，空间复杂度 O(1)

```c++
#include <iostream>
using namespace std;

int main() {
	int n;
	double sum = 0.0, tmp;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> tmp;
		sum += tmp * i * (n-i+1);
	}
	printf("%.2f", sum);
	return 0;
}
```

