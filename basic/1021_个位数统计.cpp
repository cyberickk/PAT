#include <iostream>
using namespace std;

int main() 
{
	string s;
	cin >> s;
	int len, a[10] = {0};
	len = s.size();
	for(int i = 0; i < len; ++i)
	{
		++a[s[i]-'0'];
	}
	for(int i = 0; i < 10; ++i)
	{
		if(a[i])
		{
			printf("%d:%d\n",i,a[i]);
		}
	}
	
	return 0;
}
