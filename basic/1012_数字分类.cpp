#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, flag[5] = {0}, cnt4 = 0, sum4 = 0;
	double a[5] = {0.0};
	cin >> n;
	vector<int> r1;
	for(int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		if(tmp % 10 == 0)
		{
			a[0] += tmp;
			flag[0] = 1;
		} 
		else if(tmp % 5 == 1)
		{
			r1.push_back(tmp);
			flag[1] = 1;
		}			
		else if(tmp % 5 == 2)
		{
			a[2]++; flag[2] = 1;
		}
		else if(tmp % 5 == 3)
		{
			cnt4++;
			sum4 += tmp; a[3] = sum4 * 1.0 / cnt4;
			flag[3] = 1;
		}			
		else
		{
			if(tmp > a[4]) 	a[4] = tmp;
			flag[4] = 1;
		}			
	}
	for(int i = 0; i < r1.size(); ++i)
	{
		if(i % 2 == 0) a[1] += r1[i];
		else a[1] -= r1[i];
	}
	for(int i = 0; i < 5; ++i)
	{
		if(i != 0) cout << " ";
		if(flag[i] == 0) cout << "N";
		else if(i == 3)	printf("%.1f", a[3]);
		else printf("%d", (int)a[i]);
	}
	return 0;
}
