# 1132 Cut Integer (20分)

Cutting an integer means to cut a K digits lone integer Z into two integers of (K/2) digits long integers A and B. For example, after cutting Z = 167334, we have A = 167 and B = 334. It is interesting to see that Z can be devided by the product of A and B, as 167334 / (167 × 334) = 3. Given an integer Z, you are supposed to test if it is such an integer.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (≤ 20). Then N lines follow, each gives an integer Z (10 ≤ Z <231). It is guaranteed that the number of digits of Z is an even number.

### Output Specification:

For each case, print a single line `Yes` if it is such a number, or `No` if not.

### Sample Input:

```in
3
167334
2333
12345678         
```

### Sample Output:

```out
Yes
No
No
```



解决以下几个问题：

1. 如何分割：将数字存放在字符串中，取 `substr`，再将 `string` 转化为 `int` 
2. 如何判断整除：三个字符串转换为整数，先除再乘，和原数字相等则可以整除；这里可以优化
3. 特殊情况处理：给出的数字为 0 时直接返回 `No`，分割后的两个数字中存在 0 时直接返回 `No`

时间复杂度 O(1)， 空间复杂度 O(1)

```c++
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		string a, b, c;
		cin >> a;
		int t = a.size();
		b = a.substr(0, t/2);
		c = a.substr(t/2);
		int na = stoi(a);
		int nb = stoi(b);
		int nc = stoi(c);
		if(nb == 0 || nc == 0) {
			cout << "No" << endl;
			continue;
		}
		else {
			double tmp = na / nb / nc;
		if(tmp * nb * nc == na)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		}
		
	}
	return 0;
}
```



优化，判断整除时 `a % (b * c) == 0 ` 则表示可以整除，代码进一步精简

```c++
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int a, b, c;
		cin >> a;
		string s = to_string(a);
		int t = s.size();
		b = stoi(s.substr(0, t/2));
	 	c = stoi(s.substr((t/2)));
	 	if(b * c != 0 && a % (b * c) == 0) 
	 		cout << "Yes" << endl;		
		else
			cout << "No" << endl;		
	}
	return 0;
}
```



