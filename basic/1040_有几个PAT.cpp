#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
	string s;
	cin >> s;
	map<int, int> pnum, tnum;
	int last = 0, pcnt = 0, tcnt = 0;
	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i] == 'A')
		{
			if(pnum.count(last) && tnum.count(last))
			{
				pcnt = pnum[last];
				tcnt = tnum[last];
				//cout << "1: " << pcnt << " " << tcnt << endl;
				for(int j = last + 1; j < i; ++j)
					if(s[j] == 'P') pcnt++;	
				for(int j = last + 1; j < i; ++j)
					if(s[j] == 'T') tcnt--;
				//cout << "2: " << pcnt << " " << tcnt << endl;
			}
			else
			{
				pcnt = 0; tcnt = 0;
				for(int j = 0; j < i; ++j)
				if(s[j] == 'P') pcnt++;
				for(int j = i+1; j < s.size(); ++j)
				if(s[j] == 'T') tcnt++;
				//cout << "0: " << pcnt << " " << tcnt << endl;
			}
			pnum[i] = pcnt; tnum[i] = tcnt;
			last = i; 
		}
	}
	long long sum = 0;
	for(int i = 0; i < pnum.size(); ++i)
		sum += pnum[i] * tnum[i];
	cout  << sum % 1000000007 << endl;
	
	return 0;
}
