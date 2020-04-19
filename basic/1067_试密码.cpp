#include <iostream>
using namespace std;

int main()
{
	string cre, trys;
	int n, trynum = 0;
	cin >> cre >> n;
	cin.ignore(); 
	while(getline(cin, trys))
	{
		if(trys.size() == 1 && trys[0] == '#') return 0;
		++trynum;
		if(trys == cre)
		{
			cout << "Welcome in\n";
			return 0; 
		}
		else
		{
			cout << "Wrong password: " << trys << endl;
		}
		if(trynum >= n )
		{
			cout << "Account locked\n";
			return 0;
		}
	}
	return 0;
}
