#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n,j;
	string s;
	cin >> s >> n;
	for(int cnt = 1; cnt < n; ++cnt)
	{
		string t;
		for(int i = 0; i < s.size(); i = j)
		{
			for(j = i; j < s.size() && s[j]==s[i];++j) ;
			t += s[i] + to_string(j - i);					
		}
	 	s = t;
	}
	cout << s << endl;
	return 0;
}
