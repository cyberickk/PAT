#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int n, m, tmp, k;
	scanf("%d%d", &n, &m);
	vector<int> total(m), wrong(m);
	vector<set<char>> right(m);
	for(int i = 0; i < m; ++i)
	{
		scanf("%d %d %d ", &total[i], &tmp, &k);
		for(int j = 0; j < k; ++j)
		{
			char c;
			scanf(" %c", &c);
			right[i].insert(c);
		}			
	}
	for(int i = 0; i < n; ++i)
	
	
	return 0;
}
