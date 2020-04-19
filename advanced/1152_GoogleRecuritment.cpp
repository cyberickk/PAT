#include <iostream>
#include <string>
using namespace std;

bool isPrime(int a)
{
	if(a == 1 || a == 0) return 0;
	for(int i = 2; i * i <= a; ++i)
	{
		if(a % i == 0) return 0;
	}
	return 1;
}

int main()
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	for(int i = 0; i <= n - k; ++i)
	{
		string s1;
		s1 = s.substr(i, k);
		int tmp = stoi(s1);
		if(isPrime(tmp))
		{
			cout << s1 << endl;
			return 0;
		}		
	}
	cout << "404" << endl;
	
	return 0;	
} 
