#include <iostream>
#include <set>
using namespace std;

int main()
{
	int n, m, cp[100000] = {-1};
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		cp[a] = b;
		cp[b] = a;
	}
	cin >> m;
	set<int> sing, guest;
	set<int>::iterator it;
	for(int i = 0; i < m; ++i)
	{
		int t;
		cin >> t;
		guest.insert(t);
	}
	for(it = guest.begin(); it != guest.end(); ++it)
	{
		if(cp[*it] == -1 || guest.find(cp[*it]) == guest.end()) 
			sing.insert(*it);
		else if(guest.find(cp[*it]) != guest.end())
		{
			guest.erase(cp[*it]);
			guest.erase(*it);
		}
	}
	
	cout << sing.size() << endl;
	for(it = sing.begin(); it != sing.end(); ++it)
	{
		if(it != sing.begin()) cout << " ";
		printf("%05d", *it); //注意输出格式 
	}
	return 0;
}
