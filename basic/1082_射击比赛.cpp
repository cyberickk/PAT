#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n;
	map<int,int> dis;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int x = 0, y = 0, num = 0;
		cin >> num >> x >> y;
		dis.insert(pair<int,int>(x * x + y * y, num));
	}
	printf("%04d %04d\n", dis.begin()->second, dis.rbegin()->second);		
	return 0;
}
