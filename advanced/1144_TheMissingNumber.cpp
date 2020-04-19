#include <iostream>
#include <set>
using namespace std;

int main()
{
	int n, min = 1;
	cin >> n;
	set<int> data;	
	for(int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		data.insert(tmp);
	}
	set<int>::iterator it = data.begin();
	while(it != data.end())
	{
		if(*it > 0 ) min = *it + 1;
		if((*(++it)) > min)
		{
			cout << min;
			return 0;
		}
	}
	cout << min;
	
	return 0;
}

