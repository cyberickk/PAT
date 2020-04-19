#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	getline(cin,s);
	int max = 0, a[26] = {0};
	char c;
	for(int i = 0; i < s.size(); ++i)
		s[i] = tolower(s[i]);
	for(int i = 0; i < s.size(); ++i)
	{
		if(islower(s[i]))
		{
			if(++a[s[i] - 'a'] > max)
			{
				max = a[s[i] - 'a']; c = s[i];
			}
			else if(a[s[i] - 'a'] == max)
			{
				c = min(s[i], c);
				max = a[c - 'a'];
			}
		}
	}
	cout << c << " " << max;
	return 0;	
}
