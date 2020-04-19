#include <iostream>
#include <cmath>
using namespace std;

bool primeCheck(long num)
{
	if(num == 0 || num == 1) return 0; 
	for(int i = 2; i * i <= num; ++i)
	{
		if(num % i == 0)
			return 0;	
	}
	return 1;
}
int main()
{
	int l,k;
	string s;
	cin >> l >> k >> s;
	for(int i = 0; i <= l-k; ++i)
	{
		string subs;
		subs = s.substr(i,k);
		int sub = stoi(subs);
		if(primeCheck(sub))
		{
			cout << subs << endl;
			return 0;
		}
	}
	cout << "404" << endl;
	return 0;
}
