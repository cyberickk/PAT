# 1141 PAT Ranking of Institutions

After each PAT, the PAT Center will announce the ranking of institutions based on their students' performances. Now you are asked to generate the ranklist.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (≤105), which is the number of testees. Then N lines follow, each gives the information of a testee in the following format:

```
ID Score School  
```

where `ID` is a string of 6 characters with the first one representing the test level: `B` stands for the basic level, `A` the advanced level and `T` the top level; `Score` is an integer in [0, 100]; and `School` is the institution code which is a string of no more than 6 English letters (case insensitive). Note: it is guaranteed that `ID` is unique for each testee.

### Output Specification:

For each case, first print in a line the total number of institutions. Then output the ranklist of institutions in nondecreasing order of their ranks in the following format:

```
Rank School TWS Ns   
```

where `Rank` is the rank (start from 1) of the institution; `School` is the institution code (all in lower case); ; `TWS` is the **total weighted score** which is defined to be the integer part of `ScoreB/1.5 + ScoreA + ScoreT*1.5`, where `ScoreX` is the total score of the testees belong to this institution on level `X`; and `Ns` is the total number of testees who belong to this institution.

The institutions are ranked according to their `TWS`. If there is a tie, the institutions are supposed to have the same rank, and they shall be printed in ascending order of `Ns`. If there is still a tie, they shall be printed in alphabetical order of their codes.

### Sample Input:

```in
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu  
```

### Sample Output:

```out
5
1 cmu 192 2
1 au 192 3
3 pku 100 1
4 hypu 81 2
4 lanx 81 2
```



要统计学校对应的人数和加权总分，最后进行排名输出。使用以下两个数据结构：

- `unordered_map<string, scores> ma` 输入过程中存放学校名称以及对应的加权总分和人数，构建映射关系
- `vector<insti> v` 统计完毕后把 `ma` 中的学校名称以及对应的加权总分和人数进行整合，存放到 `vector` 中，便于调用 `algorithm::sort` 和自定义的 `cmp` 函数进行排序

读入每一个学生分数后做以下处理：

- 学校名称转换为小写字母，调用 `algorithm::transform` ，可以直接进行 `tolower` 操作，`transform( InputIt first1, InputIt last1, OutputIt d_first, UnaryOperation unary_op )`   参数依次是字符串的起始位置，结束位置，改变后的字符串存放的起始位置，需要进行的操作
- 读取 `id` 的首位，根据考生类型对分数做加权处理。注意题目中的描述是 “`TWS` is the **total weighted score** which is defined to be the integer part of `ScoreB/1.5 + ScoreA + ScoreT*1.5`,” 过程中统一采用 `double score`，最后才取整数部分；如果每一步的 `score` 直接取整，最终结果会有测试点不通过
- 把处理完毕的 `school` 和 `score` 存放到 `ma` 中，更新 `sum` 并且 `cnt++`  

进行答案输出分为以下几步：

- `ma` 内容转存到 `vector v` 中，同时输入时转换为 `int sum` 
- 按照题目要求写出 `bool cmp()` 函数，完成排序
- 由于输出排名时存在并列问题，用 `prescore, prerank` 分别存放前一个学校的总分和排名，分数相同则输出前一个排名，不同则参考数组下标值，排名是 `i+1` 

时间复杂度：统计各学校分数 O(n)，插入数组 O(n)，数组排序 O(nlogn)，输出 O(n)，总的时间复杂度 O(nlogn)；空间复杂度 O(n)

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct scores {
	double sum;
	int cnt;
};

struct insti {
	string school;
	int sum, cnt;
};

bool cmp(const insti& a, const insti& b) {
	if(a.sum != b.sum)
		return a.sum > b.sum;
 	else if(a.cnt != b.cnt) 
	 	return a.cnt < b.cnt;
	else
		return a.school < b.school; 	
}

int main() {
	int n, prescore = -1, prerank = 0;
	double score;
	string id, school;
	unordered_map<string, scores> ma;
	vector<insti> v;
	scanf("%d", &n);	
	for(int i = 0; i < n; ++i) {
		cin.ignore();
		cin >> id >> score >> school;
		if(id[0] == 'B') score /= 1.5;
		if(id[0] == 'T') score *= 1.5;
		transform(school.begin(), school.end(), school.begin(), ::tolower);
		ma[school].sum += score;
		ma[school].cnt++;		
	}
	for(auto it:ma) {
		v.push_back({it.first, (int)it.second.sum, it.second.cnt});
	}
	sort(v.begin(), v.end(), cmp);
	printf("%d\n", v.size());
	for(int i = 0; i < v.size(); ++i) {
		if(v[i].sum == prescore) 
			printf("%d %s %d %d\n", prerank, v[i].school.c_str(), v[i].sum, v[i].cnt);
		else {
			printf("%d %s %d %d\n", i+1, v[i].school.c_str(), v[i].sum, v[i].cnt);
			prerank = i+1;
		}
		prescore = v[i].sum;			
	}
	return 0;
}
```



| 测试点 | 结果     | 耗时   | 内存     |
| ------ | -------- | ------ | -------- |
| 0      | 答案正确 | 4 ms   | 384 KB   |
| 1      | 答案正确 | 4 ms   | 424 KB   |
| 2      | 答案正确 | 4 ms   | 424 KB   |
| 3      | 答案正确 | 4 ms   | 348 KB   |
| 4      | 答案正确 | 338 ms | 15256 KB |
| 5      | 答案正确 | 321 ms | 15540 KB |



也可以用两个 `map` 分别存放学校对应的加权总分和人数，运行时间减小，但使用内存会变大一些。



| 测试点 | 结果     | 耗时   | 内存     |
| ------ | -------- | ------ | -------- |
| 0      | 答案正确 | 4 ms   | 356 KB   |
| 1      | 答案正确 | 3 ms   | 432 KB   |
| 2      | 答案正确 | 2 ms   | 352 KB   |
| 3      | 答案正确 | 2 ms   | 424 KB   |
| 4      | 答案正确 | 243 ms | 20964 KB |
| 5      | 答案正确 | 301 ms | 21156 KB |