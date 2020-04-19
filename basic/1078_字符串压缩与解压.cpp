#include <iostream>
using namespace std;

void zip(const string& s)
{
	string s1;
	for(int i = 0; i < s.size();)
	{
		int t = 1;
		while(s[i] == s[i+1])
		{
				++t; ++i;
		}
		if(t > 1) s1 = s1 + to_string(t);
		s1 = s1 + s[i];
		++i; 
	}
	cout << s1;
}

void unzip(const string& s)
{
	for(int i = 0; i < s.size(); ++i)
	{
		int t = 1;
		if(isdigit(s[i]))
		{
			t = s[i] - '0';
			while(isdigit(s[i+1]))
				t = (t * 10 + s[++i] - '0');
			++i;
			for(int j = 0; j < t; ++j)
				cout << s[i];
		}
		else if(isalpha(s[i]))
	 		cout << s[i];
	    else
	    	cout << " ";
	}
}

int main()
{
	char c;
	cin >> c;
	cin.ignore();
	string s;
	getline(cin, s);
	if(c == 'C')
 		zip(s);
	else
		unzip(s);
	return 0;
}
