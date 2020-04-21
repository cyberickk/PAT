# 1153 Decode Registration Card of PAT

A registration card number of PAT consists of 4 parts:

- the 1st letter represents the test level, namely, `T` for the top level, `A` for advance and `B` for basic;
- the 2nd - 4th digits are the test site number, ranged from 101 to 999;
- the 5th - 10th digits give the test date, in the form of `yymmdd`;
- finally the 11th - 13th digits are the testee's number, ranged from 000 to 999.

Now given a set of registration card numbers and the scores of the card owners, you are supposed to output the various statistics according to the given queries.

### Input Specification:

Each input file contains one test case. For each case, the first line gives two positive integers *N* (≤104) and *M* (≤100), the numbers of cards and the queries, respectively.

Then *N* lines follow, each gives a card number and the owner's score (integer in [0,100]), separated by a space.

After the info of testees, there are *M* lines, each gives a query in the format `Type Term`, where

- `Type` being 1 means to output all the testees on a given level, in non-increasing order of their scores. The corresponding `Term` will be the letter which specifies the level;
- `Type` being 2 means to output the total number of testees together with their total scores in a given site. The corresponding `Term` will then be the site number;
- `Type` being 3 means to output the total number of testees of every site for a given test date. The corresponding `Term` will then be the date, given in the same format as in the registration card.

### Output Specification:

For each query, first print in a line `Case #: input`, where `#` is the index of the query case, starting from 1; and `input` is a copy of the corresponding input query. Then output as requested:

- for a type 1 query, the output format is the same as in input, that is, `CardNumber Score`. If there is a tie of the scores, output in increasing alphabetical order of their card numbers (uniqueness of the card numbers is guaranteed);
- for a type 2 query, output in the format `Nt Ns` where `Nt` is the total number of testees and `Ns` is their total score;
- for a type 3 query, output in the format `Site Nt` where `Site` is the site number and `Nt` is the total number of testees at `Site`. The output must be in non-increasing order of `Nt`'s, or in increasing order of site numbers if there is a tie of `Nt`.

If the result of a query is empty, simply print `NA`.



**输入：**

- 准考证号 string，分数 int，构造 string id 和 int score 的结构体，所有人的信息用 vector 存储
- 指令代码 int a 和 条件 stirng s

**主体：**

- 类型1：某一级别的考生成绩降序排列，同一成绩按准考证号升序排列。用 vector 存储该级别的考生与成绩信息，便于使用 sort 进行排序，写 bool cmpsc 函数。排序完成后输出即可，如果没有符合要求的考生则输出 NA
- 类型2：某一考场的考生总成绩，从准考证号取子串 substr 得到考场信息，符合考场条件的考生计数并加总成绩，输出即可
- 类型3：某一日期的每个考场有多少考生，用 unordered_map 存放考场与考生数的映射，散列的方式效率高不会超时；构造 string room 和 int cnt 的结构体，用 vector 存放，同样编写 bool cmprm 函数完成排序，按序输出

**要点：**

- 重点是选用合适的数据结构，分别存放考生信息，某种统计类型下的考生信息，以及按题目要求完成排序
- 输出用 printf 效率高，用 cout 会超时



```c++
#include <iostream> 
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct stu {
	string id;
	int score;
};

struct dateroom {
	string room;
	int cnt;
};

static bool cmpsc(const stu& a, const stu& b) {
	return a.score > b.score ? 1 : (a.score == b.score ? (a.id < b.id ? 1 : 0) : 0);
}

static bool cmprm(const dateroom& a, const dateroom& b) {
	return a.cnt > b.cnt ? 1 : (a.cnt == b.cnt ? (a.room < b.room ? 1 : 0) : 0);
}

int main() {
	int n, m;
	cin >> n >> m;
	cin.ignore();
	vector<stu> raw(n);
	for(int i = 0; i < n; ++i) {
		cin >> raw[i].id >> raw[i].score;
	}
	for(int i = 1; i <= m; ++i) {
		int a;
		string s;
		cin >> a >> s;
		cin.ignore();
		printf("Case %d: %d %s\n", i, a, s.c_str());
		switch(a) {
			case 1:
				{
					vector<stu> tmp;
					for(auto it:raw) {
						if(it.id[0] == s[0])
									   tmp.push_back(it);
					}
					sort(tmp.begin(), tmp.end(), cmpsc);
					for(auto it : tmp) {
						printf("%s %d\n", it.id.c_str(), it.score);
					}
					if(tmp.size() == 0)
						cout << "NA" << endl;
				}				
				break;
			case 2:
				{
					int cnt = 0, sum = 0;
					for(auto it:raw) {
						string room = it.id.substr(1,3);
						if(room == s) {
							cnt++;
							sum += it.score;
						}
					}
					if(cnt == 0)
						   cout << "NA" << endl;
    		   		else
						cout << cnt << " " << sum << endl;
				}				
			 	break;
		 	case 3:
		 		{
		 			unordered_map<string, int> m;
			 		for(auto it:raw) {
			 			string date = it.id.substr(4,6);
			 			if(date == s) {
			 				string rm = it.id.substr(1,3);
			 				m[rm]++;
						 }
					}
					vector<dateroom> v;
					for(auto it:m) {
					 	v.push_back({it.first, it.second});
					}

				 	sort(v.begin(), v.end(), cmprm);
				 	for(auto it:v) {
				 	 	printf("%s %d\n", it.room.c_str(), it.cnt);
			  		}
			  		if(v.size() == 0)
			  			cout << "NA" << endl;
				}		 		
		 		break;
	 		default:
	 			break;	 			
		}
	}
	return 0;
}
```

