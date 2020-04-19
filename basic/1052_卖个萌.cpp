#include <iostream>
#include <vector>
using namespace std;

vector<string> hand, eye, mouth;

void getemoji(const string& s, vector<string> vec)
{
	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i] == '[')
		{
			while(s[++i] != ']')
			{
				string se;
				se += s[i];
			}
			vec.push_back(se);
		}
		else ++i;
	}
}
int main()
{
	for(int i = 0; i < 3; ++i)
	{
		string s;
		getline(cin, s);
		if(i == 0)  getemoji(s, hand);
		else if(i == 1) getemoji(s, eye);
		else getemoji(s, mouth);		
	}
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		string emoji;
		for(int j = 0; j < 5; ++j)
		{
			int num;
			cin >> num;
			if(invalid(num, j))
			{
				cout << "Are you kidding me? @\/@" << endl;
				break;
			}
			else
			{
				
			}
		}
	}
	return 0;
}
