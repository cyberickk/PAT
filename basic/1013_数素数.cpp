#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n)
{
	for(int i = 2; i * i <= n; ++i) //遍历到平方根即可 1不是素数
		if(n % i == 0)	return 0;
	return 1;
}


int main()
{
	int m, n, cnt = 0, cnt1 = 0;
	cin >> m >> n;
	vector<int> prime;
	for(int i = 1; cnt < 10001; ++i)
	{
		if(isPrime(i))
		{
			prime.push_back(i);
			cnt++;
		}
	}
	for(int i = m; i <= n; ++i)
	{
		if(cnt1 != 0) cout << " ";
		cout << prime[i]; cnt1++;
		if(cnt1 == 10)
		{
			cout << endl;
			cnt1 = 0;
		}
	}
	
	return 0;
}
