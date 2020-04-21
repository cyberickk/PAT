# 1136 A Delayed Palindrome

Consider a positive integer *N* written in standard notation with *k*+1 digits *a**i* as *a**k*⋯*a*1*a*0 with 0≤*a**i*<10 for all *i* and *a**k*>0. Then *N* is **palindromic** if and only if *a**i*=*a**k*−*i* for all *i*. Zero is written 0 and is also palindromic by definition.

Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. Such number is called **a delayed palindrome**. (Quoted from https://en.wikipedia.org/wiki/Palindromic_number )

Given any positive integer, you are supposed to find its paired palindromic number.

### Input Specification:

Each input file contains one test case which gives a positive integer no more than 1000 digits.

### Output Specification:

For each test case, print line by line the process of finding the palindromic number. The format of each line is the following:

```
A + B = C    
```

where `A` is the original number, `B` is the reversed `A`, and `C` is their sum. `A` starts being the input number, and this process ends until `C` becomes a palindromic number -- in this case we print in the last line `C is a palindromic number.`; or if a palindromic number cannot be found in 10 iterations, print `Not found in 10 iterations.` instead.

### Sample Input 1:

```in
97152  
```

### Sample Output 1:

```out
97152 + 25179 = 122331
122331 + 133221 = 255552
255552 is a palindromic number.    
```

### Sample Input 2:

```in
196        
```

### Sample Output 2:

```out
196 + 691 = 887
887 + 788 = 1675
1675 + 5761 = 7436
7436 + 6347 = 13783
13783 + 38731 = 52514
52514 + 41525 = 94039
94039 + 93049 = 187088
187088 + 880781 = 1067869
1067869 + 9687601 = 10755470
10755470 + 07455701 = 18211171
Not found in 10 iterations.
```



判断是否回文：把字符串颠倒后再和它本身比较，相等则回文

把字符串转换为 long long int 做加法，在数字很大的情况下回超过数的表示范围，最后一个测试用例通不过

```c++
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	string tmp = s;
	reverse(tmp.begin(), tmp.end());
	if(s == "0") {
		printf("0 is a palindromic number.\n");
		return 0;
	}
	if(s == tmp) {
		printf("%s is a palindromic number.\n", s.c_str());
		return 0;
	}
	for(int i = 0; i < 10; ++i) {
		long long int a = stoll(s);
		long long int b = stoll(tmp);
		long long int c = a + b;
		printf("%lld + %lld = %lld\n", a, b, c);
		s = to_string(c);
		tmp = s;
		reverse(tmp.begin(), tmp.end());
		if(tmp == s) {
			printf("%lld is a palindromic number.\n", c);
			return 0;
		}
	}
	cout << "Not found in 10 iterations." << endl;
	return 0;
}
```



改成直接用字符串相加，并且这样会保留数字首位的 0，可以通过全部用例。

因为至多只计算 10 轮，时间复杂度和空间复杂度都在常量范围内，运行时间在 3ms

```c++
#include <iostream>
#include <algorithm>
using namespace std;

string add(const string& a, const string& b) {
	string sum;
	int flag = 0;		//判断有无进位
	for(int i = a.size()-1; i >=0; --i) {		//从后往前加，结束后逆置
		int c = a[i] + b[i] + flag - '0' - '0';
		if(c > 9) {
			flag = 1;
			c -= 10;
		}
		else flag = 0;		//重置 flag
		sum += c + '0';
	}
	if(flag) sum += '1';		//最后有无进位
	reverse(sum.begin(), sum.end());
	return sum;
}
int main() {
	string s, tmp;
	cin >> s;
	if(s == "0") {
		printf("0 is a palindromic number.\n");
		return 0;
	}
	for(int i = 0; i < 10; ++i) {
		tmp = s;
		reverse(tmp.begin(), tmp.end());
		if(tmp == s) {
			printf("%s is a palindromic number.\n", s.c_str());
			return 0;
		}
		string sum = add(s, tmp);
		printf("%s + %s = %s\n", s.c_str(), tmp.c_str(), sum.c_str());		
		s = sum;
	}
	cout << "Not found in 10 iterations." << endl;
	return 0;
}
```

