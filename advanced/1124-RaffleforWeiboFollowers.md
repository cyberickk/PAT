# 1124 Raffle for Weibo Followers

John got a full mark on PAT. He was so happy that he decided to hold a raffle（抽奖） for his followers on Weibo -- that is, he would select winners from every N followers who forwarded his post, and give away gifts. Now you are supposed to help him generate the list of winners.

### Input Specification:

Each input file contains one test case. For each case, the first line gives three positive integers M (≤ 1000), N and S, being the total number of forwards, the skip number of winners, and the index of the first winner (the indices start from 1). Then M lines follow, each gives the nickname (a nonempty string of no more than 20 characters, with no white space or return) of a follower who has forwarded John's post.

Note: it is possible that someone would forward more than once, but no one can win more than once. Hence if the current candidate of a winner has won before, we must skip him/her and consider the next one.

### Output Specification:

For each case, print the list of winners in the same order as in the input, each nickname occupies a line. If there is no winner yet, print `Keep going...` instead.

### Sample Input 1:

```in
9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain          
```

### Sample Output 1:

```out
PickMe
Imgonnawin!
TryAgainAgain          
```

### Sample Input 2:

```in
2 3 5
Imgonnawin!
PickMe          
```

### Sample Output 2:

```out
Keep going...
```





抽奖的分为首个中奖 `s` 和与上一位中奖者间隔 `n` ，注意数清楚间隔 `n` 到底是隔了几个人。要求抽奖者不重复，用 `set<string> win` 存放中奖者 `id`，每次选取符合条件的中奖者时先查看是否已存在，不存在则可以输出并记录到 `win` 中。

所以遍历时分为以下几种情况：

- 前 1~s-1位不做任何处理
- 第 s 位按获奖处理，存入 `win` 并且输出
- 之后用 `cnt` 计数间隔的人数， `cnt == n` 时可以抽奖，在 `win` 中进行确认；已存在则 `cnt--` 继续遍历下一个，不存在的同样按获奖处理，存入 `win` 并且输出

最后遍历结束时 `win` 为空则输出 `Keep going...`

`set count` 的时间复杂度是 O(logn)，`set insert` 的平均时间复杂度是 O(logn)， 最坏情况下（比如间隔是 1）时间复杂度 O(nlogn)，空间复杂度 O(n)

```c++
#include <iostream> 
#include <set>

using namespace std;

int main() {
	int m, n, s;
	cin >> m >> n >> s;
	set<string> win;
	string id;	
	int cnt = 0;
	for(int i = 1; i <= m; ++i) {		
		cin >> id;
		if(i < s) {
			continue;
		}
		else if(i == s) {
			cout << id << endl;	
			win.insert(id);		
		}
		else {
			cnt++;
			if(cnt == n) {
				if(win.count(id)) 
					cnt--;
				else {
					win.insert(id);
					cout << id << endl;
					cnt = 0;
				}
			}
		}		
	}
	if(win.size() == 0) 
		cout << "Keep going..." << endl;
	return 0;
}
```

