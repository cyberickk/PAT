# **1128** N Queens Puzzle

The "eight queens puzzle" is the problem of placing eight chess queens on an 8×8 chessboard so that no two queens threaten each other. Thus, a solution requires that no two queens share the same row, column, or diagonal. The eight queens puzzle is an example of the more general *N* queens problem of placing *N* non-attacking queens on an *N*×*N* chessboard. (From Wikipedia - "Eight queens puzzle".)

Here you are NOT asked to solve the puzzles. Instead, you are supposed to judge whether or not a given configuration of the chessboard is a solution. To simplify the representation of a chessboard, let us assume that no two queens will be placed in the same column. Then a configuration can be represented by a simple integer sequence (*Q*1,*Q*2,⋯,*Q**N*), where *Q**i* is the row number of the queen in the *i*-th column. For example, Figure 1 can be represented by (4, 6, 8, 2, 7, 1, 3, 5) and it is indeed a solution to the 8 queens puzzle; while Figure 2 can be represented by (4, 6, 7, 2, 8, 1, 9, 5, 3) and is NOT a 9 queens' solution.

### Input Specification:

Each input file contains several test cases. The first line gives an integer *K* (1<*K*≤200). Then *K* lines follow, each gives a configuration in the format "*N* *Q*1 *Q*2 ... *Q**N*", where 4≤*N*≤1000 and it is guaranteed that 1≤*Q**i*≤*N* for all *i*=1,⋯,*N*. The numbers are separated by spaces.

### Output Specification:

For each configuration, if it is a solution to the *N* queens problem, print `YES` in a line; or `NO` if not.

### Sample Input:

```in
4
8 4 6 8 2 7 1 3 5
9 4 6 7 2 8 1 9 5 3
6 1 5 2 6 4 3
5 1 3 5 2 4    
```

### Sample Output:

```out
YES
NO
NO
YES
```



因为已经假设不会出现在同一列，所以只需比较是否处在同一行或者对角即可；将读入的元素存入 `vector<int> v` 中，每读入一个数据，遍历它之前的所有元素，相等表示处在同一行，值相减的绝对值与下标相减的绝对值相等表示在对角 `abs(v[j] - v[k]) == (j-k)` ，如果满足两个条件之一则将标志 `bool flag = 1 ` 并且退出循环；最后如果 `flag == 1` 则输出 `YES` 否则输出 `NO` 

时间复杂度 O(n * m * m)，空间复杂度 O(m)

```c++
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {		
		int cnt;
		cin >> cnt;
		vector<int> v(cnt);
		bool flag = 1;
		for(int j = 0;j < cnt; ++j) {
			cin >> v[j];
			for(int k = 0; k < j; ++k) {
				if(v[k] == v[j] || abs(v[k] - v[j]) == (j-k)) {
					flag = 0;
					break;
				}
			}
		}
		cout << (flag == 1 ? "YES\n" : "NO\n" );	//精简代码行数的一种写法		
	}
	return 0;
}
```

