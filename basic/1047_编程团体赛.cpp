#include <iostream>
using namespace std;

int main()
{
	int n, a[1001] = {0},maxteam = 0, maxscore = 0; //队伍编号1~1000,数组大小1001，才能放入编号1000的队 
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
