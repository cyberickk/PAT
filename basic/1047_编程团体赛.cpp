#include <iostream>
using namespace std;

int main()
{
	int n, a[1001] = {0},maxteam = 0, maxscore = 0; //������1~1000,�����С1001�����ܷ�����1000�Ķ� 
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int teamnum, memnum, score;
		scanf("%d-%d %d", &teamnum, &memnum, &score);
		a[teamnum] += score;
		if(a[teamnum] > maxscore)
		{
			maxteam = teamnum;
			maxscore = a[teamnum];
		}
	}
	cout << maxteam << " " << maxscore;
	
	return 0;
}
