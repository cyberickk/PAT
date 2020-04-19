#include <iostream>
using namespace std;

int main()
{
	int n, d, pro = 0, empty = 0;
	float e;
	cin >> n >> e >> d;
	for(int i = 0; i < n; ++i)
	{
		int day, below = 0;
		cin >> day;
		float charge, rate;
		for(int j = 0; j < day; ++j)
		{
			cin >> charge;
			if(charge < e) ++below;
		}
		rate = below * 1.0 / day;
		if(rate > 0.5 && day <= d)
			++pro;
		else if(rate > 0.5 && day > d)
			++empty;		
	}
	float prorate, emptyrate;
	prorate = pro * 1.0 / n * 100;
	emptyrate = empty * 1.0 / n * 100;
	printf("%.1f%% %.1f%%", prorate, emptyrate);
	return 0;		
} 
