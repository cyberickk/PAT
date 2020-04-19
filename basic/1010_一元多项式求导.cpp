#include <iostream>
using namespace std;

int main()
{
	int t1, t2, flag = 0;
	while(cin >> t1 >> t2)
	{
		if(t2 != 0)
		{
			if(flag) cout << " ";
			cout << t1 * t2 << " " << t2-1;
			flag = 1;
		}		
	}
	if(flag == 0) cout << "0 0";
	return 0;
}
