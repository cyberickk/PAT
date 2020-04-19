#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		int j, flag = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for(j = 0; s[j] == 'P'; ++j)
		{
			if(s[j] != 'A')
			{
				flag = 1;
				continue;
			}
			else cnt1++;
		}
		if(flag)
		{
			cout << "NO" << endl;
			continue;
		}	
		for( j++; s[j] != 'T'; ++j)
		{
			if(s[j] != 'A')
			{
				flag = 1;
				continue;
			}
			else cnt2++;
		}
		if(flag)
		{
			cout << "NO" << endl;
			continue;
		}
		for(j++; j < s.size(); ++j)
		{
			if(s[j] != 'A')
			{
				flag = 1;
				continue;
			}
			else cnt3++;
		}
		if(flag || cnt1 * cnt2 != cnt3)
		{
			cout << "NO" << endl;
			continue;
		}	 		
		if(!flag) 
			cout << "YES" << endl;
	}
	
	return 0;
}
