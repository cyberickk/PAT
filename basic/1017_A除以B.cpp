#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int b, r;
	cin >> s >> b;
	int tmp = (s[0] - '0') / b;
	int len = s.length();
	if((tmp != 0 && len > 1) || len == 1)  cout << tmp;
	r = (s[0] - '0') % b;
	for(int i = 1; i < len; ++i)
	{
		tmp = (r * 10 + s[i] - '0') / b;
		cout << tmp;
		r = (r * 10 + s[i] - '0') % b; 
	}
	cout << " " << r;
	
	return 0;
}
