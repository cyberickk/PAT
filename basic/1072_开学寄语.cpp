#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, pstu = 0, psta = 0;
	cin >> n >> m;
	cin.ignore();
	vector<int> check;
	for(int i = 0; i < m; ++i)
	{
		int c;
		cin >> c;
		check.push_back(c);
	}
	for(int i = 0; i < n; ++i)
	{
		string name;
		int num, flag = 0;
		cin >> name >> num;
		vector<int> sta;
		for(int j = 0; j < num; ++j)
		{
			int staff;
			cin >> staff;
			if(find(check.begin(),check.end(),staff) != check.end())
			{
				++flag; ++psta;
				sta.push_back(staff);
			}
		}
		if(flag)
		{
			++pstu;
			cout << name << ":";
			for(int i = 0; i < flag; ++i)
				printf(" %04d", sta[i]);
			cout << endl;
		}
		cin.ignore();
	}
	cout << pstu << " " << psta;
	return 0;
	
} 
