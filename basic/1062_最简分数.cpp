#include <iostream>
using namespace std;

int gcd(int m, int n)
{
	return n == 0 ? m : gcd(n, m % n);
}

int lcm(int m, int n, int t)
{
	int tmp;
	tmp = m * n / gcd(m, n); 
	return t * tmp / gcd(t, tmp);
}

int main()
{
	int n1,n2,m1,m2,k;
	scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
	int nn1, nn2, lc, gc, flag = 0;
	lc = lcm(m1, m2, k); gc = lc / k;
	nn1 = lc / m1 * n1; nn2 = lc / m2 * n2;
	for(int i = min(nn1, nn2) + 1; i < max(nn1, nn2); ++i)
	{		
		int tmp;
		tmp = i / gc;
		if(i % gc != 0 || tmp >= k ) continue; 
		if(gcd(tmp, k) == 1 && flag > 0)
		{
			printf(" %d/%d", tmp, k);
			++flag;
		}
		else if(gcd(tmp, k) == 1)
		{
			printf("%d/%d", tmp, k);
			++flag;
		}
		else ;						  
	}		 
	return 0;
}
