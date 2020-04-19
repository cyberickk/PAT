#include <iostream>
using namespace std;

int main()
{
	int n, cnt = 0, line = 0;
	char c;
	cin >> n >> c;
	for(int i = 1; cnt < n; ++i)
	{
		if(2 * i * i - 1 > n) break;
		else
		{
			cnt = 2 * i * i - 1;
			line++;
		}
	}
	for(int i = 1; i <= line; ++i)
	{
		for(int j = 0; j < i - 1; ++j) cout << " ";
		for(int j = 0; j < 2 * (line - i) + 1; ++j) cout << c;
		for(int j = 0; j < i - 1; ++j) cout << " ";
		cout << endl;
		//string sn, sc;
		//sn = (i-1, " ");
		//sc.append(2 * (line - i + 1) + 1, c);
		//if(i == 1) cout << sc << endl;
		//else cout << sn << sc << sn << endl; 
	}
	for(int i = line - 1; i > 0; --i)
	{
		for(int j = 0; j < i - 1; ++j) cout << " ";
		for(int j = 0; j < 2 * (line - i) + 1; ++j) cout << c;
		for(int j = 0; j < i - 1; ++j) cout << " ";
		cout << endl;  
	}
	cout << n - cnt;
	
	return 0;
}
