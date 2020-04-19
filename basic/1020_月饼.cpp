#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct mc{
	float num, price, unit;
};

bool cmp(const mc& a, const mc& b)
{
	return a.unit > b.unit;
}

int main()
{
	int n, d;
	cin >> n >> d;
	vector<mc> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i].num;
	for(int i = 0; i < n; ++i)
	cin >> v[i].price;
	for(int i = 0; i < n; ++i)
		v[i].unit = v[i].price * 1.0 / v[i].num;
	sort(v.begin(), v.end(), cmp);
	float sum = 0;
	for(int i = 0; i < v.size() && d > 0; ++i)
	{
		if(v[i].num <= d)
		{
			sum += v[i].price;
			d -= v[i].num;
		}
		else
		{
			sum += v[i].unit * d;
			d = 0;
		}
	}
	printf("%.2f", sum);
	return 0;
}
