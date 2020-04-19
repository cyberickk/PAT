#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int m, n, s, gap = 0, f = 0;
	string id;
	cin >> m >> n >> s;
	cin.ignore();
	vector<string> win;		
	for(int i = 1; i <= m; ++i)
	{
		cin >> id; 
		if(i < s) ;
		else if(i == s)
		{
			win.push_back(id);
			cout << id << endl;
		}
		else
		{
			++gap;
			if(gap == n)
			{
			 	if(find(win.begin(), win.end(), id) == win.end())
				{
					win.push_back(id);
					cout << id << endl;
					gap = 0;
				}
				else
					gap = n - 1;
			}
		}
			
	}
	if(win.size() == 0)
	cout << "Keep going...";	 
	return 0;
}
