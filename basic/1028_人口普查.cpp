#include <iostream>
using namespace std;

int main()
{
	int n, cnt = 0;
	string y, o, old = "2014/09/06", young = "18140906";
	cin >> n;
	cin.ignore();
	for(int i = 0; i < n; ++i)
	{
		string name,age;
		cin >> name >> age;
		if(age < "1814/09/06" || age > "2014/09/06") continue;
		++cnt;
		if(age >= young) // =
		{
			young = age; y = name;
		}
		if(age <= old) // =
		{
			old = age; o = name;
		}

	}
	cout << cnt;
	if(cnt != 0)  cout << " " << o << " " << y << endl;
	return 0;
}
 
