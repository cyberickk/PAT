#include <iostream>
using namespace std;

int main()
{
	int n, a[101] = {0}, s, cnt;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &s);
		a[s]++; 
	}
	scanf("%d", &cnt);  //scanf格式化输入，用cin前面需要ignore一次，否则会出错 
	for(int i = 0; i < cnt; ++i)
	{
		scanf("%d", &s);
		if(s < 0 || s > 100) continue;		
		if(i !=0) cout << " ";
		cout << a[s];
	}
	return 0;
}
