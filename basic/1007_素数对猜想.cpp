#include <iostream>
using namespace std;

bool isPrime(int n)
{
	for(int i = 2; i * i <= n; ++i)
		if(n % i == 0) return 0;
	return 1;
}

int main()
{
	int n, cnt = 0;
	cin >> n;
	for(int i = 5; i <= n; ++i)
	{
		if(isPrime(i-2) && isPrime(i)) cnt++;
	}
	cout << cnt;
	return 0;
}
