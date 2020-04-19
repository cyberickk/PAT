#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

void getnum(string n, int& up, int& down)
{
	string s;
	multiset<int> sort;
	for(int i = 0; i < 4; ++i)
		sort.insert(n[i] - '0');
	multiset<int>::iterator it;
	for(it = sort.begin(); it != sort.end(); ++it)
	{
		int tmp = *it;
		s += tmp + '0';
	}
	up = stoi(s);
	reverse(s.begin(), s.end());
	down = stoi(s);
}
int main()
{
	string n, s;
	int tmp, up = 0, down = 0;
	cin >> n;
	if(n.size() < 4) n.insert(0, 4 - n.size(), '0');
	while(1)
	{
		getnum(n, up, down);
		int tmp =  down - up;
		printf("%04d - %04d = %04d\n", down, up, tmp);
		if(up == down || tmp == 6174) break;		
		else
		{
			n = to_string(tmp);
			if(n.size() < 4) n.insert(0, 4 - n.size(), '0');
		}	
	}
	
	return 0;
}
