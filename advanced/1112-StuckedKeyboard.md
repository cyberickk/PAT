# 1112 Stucked Keyboard

On a broken keyboard, some of the keys are always stucked. So when you type some sentences, the characters corresponding to those keys will appear repeatedly on screen for *k* times.

Now given a resulting string on screen, you are supposed to list all the possible stucked keys, and the original string.

Notice that there might be some characters that are typed repeatedly. The stucked key will always repeat output for a fixed *k* times whenever it is pressed. For example, when *k*=3, from the string `thiiis iiisss a teeeeeest` we know that the keys `i` and `e` might be stucked, but `s` is not even though it appears repeatedly sometimes. The original string could be `this isss a teest`.

### Input Specification:

Each input file contains one test case. For each case, the 1st line gives a positive integer *k* (1<*k*≤100) which is the output repeating times of a stucked key. The 2nd line contains the resulting string on screen, which consists of no more than 1000 characters from {a-z}, {0-9} and `_`. It is guaranteed that the string is non-empty.

### Output Specification:

For each test case, print in one line the possible stucked keys, in the order of being detected. Make sure that each key is printed once only. Then in the next line print the original string. It is guaranteed that there is at least one stucked key.

### Sample Input:

```in
3
caseee1__thiiis_iiisss_a_teeeeeest          
```

### Sample Output:

```out
ei
case1__this_isss_a_teest
```



一个测试用例不能通过

```c++
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int k;
	string s, sout, sstuck;
	cin >> k >> s;
	vector<int> v(256, 0);
	for(int i = 0; i < s.size(); i++) {
		sout += s[i];
		
		if(v[s[i]] == -1) {
			i += k-1;
		}
		if(v[s[i]] == 0) {
			if(s[i] != s[i+1]) {
				v[s[i]] = 1;
			}				
			else {
				int cnt = 1;
				i++;
				while(i < s.size() && s[i] == s[i-1]) {
					i++;
					cnt++;
				}
				i--;
				if(cnt % k != 0) {
					sout.append(cnt-1, s[i]);
					v[s[i]] = 1;
				}
				else {
					sout.append(cnt / k - 1, s[i]);
					sstuck += s[i];
					v[s[i]] = -1;
				}
			}
		}		
	}
	cout << sstuck << endl << sout;
	return 0;
} 
```

