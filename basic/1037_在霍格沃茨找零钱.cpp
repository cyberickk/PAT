#include <iostream>
using namespace std;

int main()
{
	int pg, ps, pk, hg, hs, hk, p, a;
	scanf("%d.%d.%d %d.%d.%d", &pg, &ps, &pk, &hg, &hs, &hk);
	p = pg * 17 * 29 + ps * 29 + pk;
	a = hg * 17 * 29 + hs * 29 + hk;
	int minus;
	minus = a - p;
	if(minus < 0)
	{
		cout << "-"; minus = abs(minus);
 	} 
	printf("%d.%d.%d", minus / 17 / 29, minus % (17 * 29) / 29, minus % 29);
	
	return 0;
}
