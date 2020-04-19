#include <iostream>
#include <string> 
using namespace std;

int main()
{
	string s1, s2, bad;
	cin >> s1 >> s2;
	for(int i = 0, j = 0; i < s1.size();)
	{
		if(s1[i] != s2[j])
		{
			if(bad.find(toupper(s1[i])) == bad.npos) bad += toupper(s1[i]);
			i++;
		}
		else
		{
			i++; j++;
		}
	}
	cout << bad;	
	return 0;
}
