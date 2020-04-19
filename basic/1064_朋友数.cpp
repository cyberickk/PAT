#include <iostream>
#include <set>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	set<int> id;
	set<int>::iterator it;
	for(int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		int sum = 0;
		for(int j = 0; j < s.size(); ++j)
			sum += s[j] - '0';
		id.insert(sum);	
	}
	cout << id.size() << endl;
	for(it = id.begin(); it != id.end(); )
	{
		cout << *it ;
		if((++it) != id.end())
			cout << " ";
	}
	return 0;
}
