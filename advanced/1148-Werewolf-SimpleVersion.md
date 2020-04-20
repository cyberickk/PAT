# 1148 Werewolf - Simple Version

Werewolf（狼人杀） is a game in which the players are partitioned into two parties: the werewolves and the human beings. Suppose that in a game,

- player #1 said: "Player #2 is a werewolf.";
- player #2 said: "Player #3 is a human.";
- player #3 said: "Player #4 is a werewolf.";
- player #4 said: "Player #5 is a human."; and
- player #5 said: "Player #4 is a human.".

Given that there were 2 werewolves among them, at least one but not all the werewolves were lying, and there were exactly 2 liars. Can you point out the werewolves?

Now you are asked to solve a harder version of this problem: given that there were *N* players, with 2 werewolves among them, at least one but not all the werewolves were lying, and there were exactly 2 liars. You are supposed to point out the werewolves.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer *N* (5≤*N*≤100). Then *N* lines follow and the *i*-th line gives the statement of the *i*-th player (1≤*i*≤*N*), which is represented by the index of the player with a positive sign for a human and a negative sign for a werewolf.

### Output Specification:

If a solution exists, print in a line in ascending order the indices of the two werewolves. The numbers must be separated by exactly one space with no extra spaces at the beginning or the end of the line. If there are more than one solution, you must output the smallest solution sequence -- that is, for two sequences *A*=*a*[1],...,*a*[*M*] and *B*=*b*[1],...,*b*[*M*], if there exists 0≤*k*<*M* such that *a*[*i*]=*b*[*i*] (*i*≤*k*) and *a*[*k*+1]<*b*[*k*+1], then *A* is said to be smaller than *B*. In case there is no solution, simply print `No Solution`.



代码本身并不复杂，难点是如何用程序求解这样一道逻辑题。有解的条件是存在两个狼人，存在两个人说谎，一个是好人，一个是狼人；于是用枚举的办法遍历所有的 2 个狼人组合，再从头遍历每个人说的话，判断这个人是否说谎；一轮遍历结束后是否满足有解的条件，满足则输出两个狼人的编号。那么如何判断满足解的条件，需要解决三个问题：

1. 怎样判断说谎
2. 怎样判断说谎只有 2 个人并且是一好一坏
3. 怎样判断只有 2 个狼人，这个已经在假设中解决了，我们枚举的情况就是只存在 2 个狼人

同时我们要解决的问题是如何表示。题目的输入存放在 `vector<int> v(n+1)` 中，按玩家编号存入 1~n 位；用 `vector<int> a(n+1, 1)` 存放身份， 1 是好人， -1 是狼人，在假设开始时全置为 1，并且把假设的两个狼人的身份位置为 -1；最后用 `vector<int> lie` 存放说谎人的编号。

继续解决前面的问题，怎样判断说谎。说谎者分为两种情况：

1. 说对方是好人而实际上是坏人，那么该说谎者给出的信息 `v(k) > 0` ，而在表示身份的数组中这个编号的值应该为负数，即 `a[abs(v[k])] < 0`
2. 说对方是坏人而实际上是好人，那么该说谎者给出的信息 `v(k) < 0` ，而在表示身份的数组中这个编号的值应该为正数，即 `a[abs(v[k])] > 0`

可见以上的两个判断是异号的，总结下来就是满足 `v[k] * a[abs(v[k])] < 0` 则这个人说谎。

而说谎的只有 2 人很好判断，`lie` 的大小为 2 即可  ，说谎的两个人一好一坏，则身份位是 1 和 -1，`lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0` 同时满足这两个条件即可。

最后梳理一下程序的思路，用到的数据结构是三个数组 `vecotr<int> v(n+1), a(n+1, 1), lie` ，首先将题目的输入存放在 `v` 中，然后开始遍历，外循环 `i` 从 1 遍历到 n， 内循环 `j` 从 i+1 遍历到 n，循环内首先创建数组 `a` 和 `lie`, 然后把两个狼人的身份置为 -1；接着 `k` 从 1 遍历到 n，判断每个人是否说谎，说谎则将编号放入 `lie` 中；遍历结束后判断 `lie` 中是否只有两个人并且一好一坏，满足条件则输出编号 `i` 和 `j`，结束程序。所有循环结束仍没有输出，则表示无解，输出 `No Solution` 结束程序。

另外注意所有的编号都是 1~n， 如果用 0~n 则以上程序不适用，结果会出错。

有三层循环，算法的时间复杂度 O(n^3)，空间复杂度 O(n)



```c++
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n+1);
	for(int i = 1; i <= n; ++i)
		cin >> v[i];
	for(int i = 1; i <= n; ++i) {
		for(int j = i+1; j <= n; ++j) {
			vector<int> a(n+1, 1), lie;
			a[i] = a[j] = -1;
			for(int k = 1; k <= n; ++k) {
				if(v[k] * a[abs(v[k])] < 0)
					lie.push_back(k);
			}
			if(lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0) {
				cout << i << " " << j;
				return 0;
			}
		}
	}
	cout << "No Solution" << endl;
	return 0;
}
```

