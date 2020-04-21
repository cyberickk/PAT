# **1140** Look-and-say Sequence

Look-and-say sequence is a sequence of integers as the following:

```
D, D1, D111, D113, D11231, D112213111, ...   
```

where `D` is in [0, 9] except 1. The (n+1)st number is a kind of description of the nth number. For example, the 2nd number means that there is one `D` in the 1st number, and hence it is `D1`; the 2nd number consists of one `D` (corresponding to `D1`) and one 1 (corresponding to 11), therefore the 3rd number is `D111`; or since the 4th number is `D113`, it consists of one `D`, two 1's, and one 3, so the next number must be `D11231`. This definition works for `D` = 1 as well. Now you are supposed to calculate the Nth number in a look-and-say sequence of a given digit `D`.

### Input Specification:

Each input file contains one test case, which gives `D` (in [0, 9]) and a positive integer N (≤ 40), separated by a space.

### Output Specification:

Print in a line the Nth number in a look-and-say sequence of `D`.

### Sample Input:

```in
1 8    
```

### Sample Output:

```out
1123123111
```



迭代的方法读字符串，把每次读取 `string s` 的结果存入 `string tmp` 中，读完后 `s = tmp`  再继续读 `string s ` 即可。

因为最多的迭代次数也只有 40 次，耗时 16ms；空间复杂度 O(n)

```c++
#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	string s;
	cin >> s >> n;					//首个字符串是单数字的
	for(int i = 1; i < n; ++i) {	//注意循环从 1 开始
		string tmp;
		for(int j = 0; j < s.size();++j) {
			tmp += s[j];
			int cnt = 1;
			while(s[j+1] == s[j]) { 	//此次结束循环的条件
				j++;					//j 自增在循环内部执行
				cnt++;
			}							//跳转到下一个不相同字符通过 for 循环的 ++j 执行
			tmp += to_string(cnt);
		}
		s = tmp;
	}
	cout << s;
	return 0;
}
```

