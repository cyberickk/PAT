# 1120 Friend Numbers

Two integers are called "friend numbers" if they share the same sum of their digits, and the sum is their "friend ID". For example, 123 and 51 are friend numbers since 1+2+3 = 5+1 = 6, and 6 is their friend ID. Given some numbers, you are supposed to count the number of different friend ID's among them.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N. Then N positive integers are given in the next line, separated by spaces. All the numbers are less than 104.

### Output Specification:

For each case, print in the first line the number of different frind ID's among the given integers. Then in the second line, output the friend ID's in increasing order. The numbers must be separated by exactly one space and there must be no extra space at the end of the line.

### Sample Input:

```in
8
123 899 51 998 27 33 36 12      
```

### Sample Output:

```out
4
3 6 9 26
```



比较简单的题目，拆解为以下几个问题：

1. 如何计算 ID，我采取的办法是用 string 存放每个整数，遍历每一位求和；对整数按位取余求和也可以
2. 如何计算一组整数中有几个不同的 ID，自然联想到 set 元素值各异并且递增排列的特性，将 ID 存放到 set 中，最后输出 size 以及按序输出元素
3. 输出 set 元素时注意末位没有空格，采取常用的计数值方法，输入第一个元素前不插入空格，之后每次先输出空格再输出元素



每个整数不大于 $10^4$ ，程序用时取决于整数的个数，时间复杂度 O(n)；用 set 存放 ID，空间复杂度 O(n)

```c++
#include <iostream>
#include <set>
using namespace std;

int getid(const string& s) {
	int sum = 0;
	for(auto it:s) {
		sum += it - '0';
	}	
	return sum;
}

int main() {
	int n;
	cin >> n;
	string s;
	set<int> id;
	for(int i = 0; i < n; ++i) {
		cin >> s;
		id.insert(getid(s));
	}
	cout << id.size() << endl;
	int i = 0;
	for(auto it:id) {
		if(i != 0) cout << " ";
		++i;
		cout << it;		
	}
	return 0;
}
```

