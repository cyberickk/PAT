#include <iostream>
using namespace std;

int main()
{
	int a[256] = {0};
	string s1, s2, s;
	getline(cin, s1);
	getline(cin, s2);
	s = s1 + s2;
	for(int i = 0; i < s.size(); ++i)
	{
		if(a[s[i]] == 0) cout << s[i];
		a[s[i]] = 1;	
	}
	return 0;
}