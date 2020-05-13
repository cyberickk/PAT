# 1137 Final Grading

For a student taking the online course "Data Structures" on China University MOOC (http://www.icourse163.org/), to be qualified for a certificate, he/she must first obtain no less than 200 points from the online programming assignments, and then receive a final grade no less than 60 out of 100. The final grade is calculated by *G*=(*G**m**i**d*−*t**e**r**m*×40%+*G**f**i**n**a**l*×60%) if *G**m**i**d*−*t**e**r**m*>*G**f**i**n**a**l*, or *G**f**i**n**a**l* will be taken as the final grade *G*. Here *G**m**i**d*−*t**e**r**m* and *G**f**i**n**a**l* are the student's scores of the mid-term and the final exams, respectively.

The problem is that different exams have different grading sheets. Your job is to write a program to merge all the grading sheets into one.

### Input Specification:

Each input file contains one test case. For each case, the first line gives three positive integers: P , the number of students having done the online programming assignments; M, the number of students on the mid-term list; and N, the number of students on the final exam list. All the numbers are no more than 10,000.

Then three blocks follow. The first block contains P online programming scores *G**p*'s; the second one contains M mid-term scores *G**m**i**d*−*t**e**r**m*'s; and the last one contains N final exam scores *G**f**i**n**a**l*'s. Each score occupies a line with the format: `StudentID Score`, where `StudentID` is a string of no more than 20 English letters and digits, and `Score` is a nonnegative integer (the maximum score of the online programming is 900, and that of the mid-term and final exams is 100).

### Output Specification:

For each case, print the list of students who are qualified for certificates. Each student occupies a line with the format:

`StudentID` *G**p* *G**m**i**d*−*t**e**r**m* *G**f**i**n**a**l* *G*

If some score does not exist, output "−1" instead. The output must be sorted in descending order of their final grades (*G* must be rounded up to an integer). If there is a tie, output in ascending order of their `StudentID`'s. It is guaranteed that the `StudentID`'s are all distinct, and there is at least one qullified student.

### Sample Input:

```in
6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81
```

### Sample Output:

```out
missing 400 -1 99 99
ydjh2 200 98 82 88
dx86w 220 88 81 84
wehu8 300 55 84 84
```



学生的所有分数用 `unordered_map<strring, scores> ma` 存放，存储时先进行判定，不合格的不用存储以便节省节省空间，判定如下：

- programming score >= 200 才进入 `ma`， 同时为该学生的其他成绩赋初值 `mid = -1; final = -1` ，便于后面判定是否缺少某一科目成绩；注意分数是非负数，所以初值不能设置为 0； 并且定义 `struct scores` 时不能赋初值，因为调用数据成员存入 `vector` 时传递初始化列表会报错
- 读取 mid final score 时都要先判定，已经在 `ma` 中的才存储

接下来计算总成绩，`total >= 60` 的把姓名和各科成绩打包存入 `vector<stu> v` 中。计算步骤如下：

- 首先要求 final >= 0 ，即有期末成绩则最终评分才有可能合格
- 按 `mid > final` 分两种情况计算总分，注意题目要求四舍五入到整数，四舍五入的处理是先加 0.5 再强制类型转换为 `int` ，这样小数部分不超过 0.5 的不进位，超过 0.5 的会进位取到整数部分
- 总成绩 `total >= 60` 才存入 `v` 中，因为没有 mid score 的已经初始化为 -1，所以无需分情况讨论，直接存储 `ma.mid` 即可

最后对 `v` 进行排序并输出。这类问题的常规思路都是先用 `unordered_map` 存放数据，之后处理数据并把结果放入 `vector` 中，由此可以调用 `algorithm::sort` 进行自定义排序

读取并存放成绩的时间复杂度不超过 O(nlogn)，计算总成绩的时间复杂度 O(n)，排序的时间复杂度 O(nlogn)，输出的时间复杂度 O(n)，总的时间复杂度 O(nlogn)；空间复杂度 O(n)

```c++
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

struct scores {
	int gp, mid, final, total;
};
struct stu {
	string id;
	int gp, mid, final, total;
};

bool cmp(const stu& a, const stu& b) {
	if(a.total != b.total)
		return a.total > b.total;
	else
		return a.id < b.id;
 
}

int main() {
	int p, m, n, tmp, total;
	unordered_map<string, scores> ma;
	vector<stu> v;
	string id;
	scanf("%d %d %d", &p, &m, &n);
	for(int i = 0; i < p; ++i) {
		cin >> id >> tmp;
		if(tmp >= 200) {
			ma[id].gp = tmp;
			ma[id].mid = -1;
			ma[id].final = -1;
			total = 0;
		}	
		
	}
	for(int i = 0; i < m; ++i) {
		cin >> id >> tmp;
		if(ma.count(id)) {
			ma[id].mid = tmp;
		}	
	}
	for(int i = 0; i < n; ++i) {
		cin >> id >> tmp;
		if(ma.count(id))	{
			ma[id].final = tmp;
		}
	}
	for(auto it:ma) {
		id = it.first;
		if(ma[id].final >= 0) {
			if(ma[id].mid < ma[id].final)
				total = ma[id].final;
			else
				total = (int)(ma[id].mid * 0.4 + ma[id].final * 0.6 + 0.5);
			if(total >= 60) {
				v.push_back({id, ma[id].gp, ma[id].mid, ma[id].final, total});	
			}
				
		}
	}
	sort(v.begin(), v.end(), cmp);
	for(auto it:v) {
		printf("%s %d %d %d %d\n", it.id.c_str(), it.gp, it.mid, it.final, it.total);
	}
	return 0;
}
```

几次提交的测试点 3 耗时基本都在 68ms 左右，其中一次不知道为什么变成 40ms

| 测试点 | 结果     | 耗时  | 内存    |
| ------ | -------- | ----- | ------- |
| 0      | 答案正确 | 4 ms  | 404 KB  |
| 1      | 答案正确 | 3 ms  | 352 KB  |
| 2      | 答案正确 | 3 ms  | 384 KB  |
| 3      | 答案正确 | 40 ms | 1920 KB |





下面是第一次做题的思路，用三个 `map` 存放各科成绩，运行时间和上面第一种解法差不多，不过占用内存明显增多，因为构建 `map`  还有  `string id` 都要重复占用空间。

```c++
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

struct stu {
	string id;
	int gp, mid, final, total;
};

bool cmp(const stu& a, const stu& b) {
	if(a.total != b.total)
		return a.total > b.total;
	else
		return a.id < b.id;
 
}

int main() {
	int p, m, n, tmp, total;
	unordered_map<string, int> mgp, mmid, mfinal;
	vector<stu> v;
	string id;
	scanf("%d %d %d", &p, &m, &n);
	for(int i = 0; i < p; ++i) {
		cin >> id >> tmp;
		if(tmp >= 200)	mgp[id] = tmp;
	}
	for(int i = 0; i < m; ++i) {
		cin >> id >> tmp;
		if(mgp.count(id)) 	mmid[id] = tmp;
	}
	for(int i = 0; i < n; ++i) {
		cin >> id >> tmp;
		if(mgp.count(id))	{
			mfinal[id] = tmp;
		}
	}
	for(auto it:mgp) {
		id = it.first;
		if(mfinal.count(id)) {
			if(mmid.count(id) == 0 || mmid[id] < mfinal[id])
				total = mfinal[id];
			else
				total = (int)(mmid[id] * 0.4 + mfinal[id] * 0.6 + 0.5);
			if(total >= 60) {
				if(mmid.count(id) == 0)
					v.push_back({id, mgp[id], -1, mfinal[id], total});
				else
					v.push_back({id, mgp[id], mmid[id], mfinal[id], total});	
			}
				
		}
	}
	sort(v.begin(), v.end(), cmp);
	for(auto it:v) {
		printf("%s %d %d %d %d\n", it.id.c_str(), it.gp, it.mid, it.final, it.total);
	}
	return 0;
}
```



| 测试点 | 结果     | 耗时  | 内存    |
| ------ | -------- | ----- | ------- |
| 0      | 答案正确 | 4 ms  | 356 KB  |
| 1      | 答案正确 | 4 ms  | 384 KB  |
| 2      | 答案正确 | 4 ms  | 384 KB  |
| 3      | 答案正确 | 69 ms | 2816 KB |

