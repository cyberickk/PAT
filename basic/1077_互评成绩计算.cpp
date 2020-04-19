#include <iostream>
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
	{
		int sum = 0, max = 0, min = m, g2 = 0, num = 0; 
		float g1 = 0;
		cin >> g2;
		for(int j = 0; j < n-1; ++j)
		{
		 	int score;
			cin >> score;
			if(score >= 0 && score <= m)
			{
				++num; sum += score;
				if(score > max) max = score;
				if(score < min) min = score;
			}
		}
		sum = sum - max - min; num -= 2;
		g1 = sum * 1.0 / num; 
		cout << (int)((g1 + g2) / 2 + 0.5) << endl;
	}
	return 0;
}
