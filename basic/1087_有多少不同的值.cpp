#include <iostream>
#include <set>
using namespace std;

int main()
{
	int n;
	set<int> result;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		result.insert(i / 2 + i / 3 + i / 5);
	cout << result.size() << endl;
 	return 0; 
} 
