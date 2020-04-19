#include <iostream>
using namespace std;

int main()
{
	int mcake,city,max = 0, last = 0;
	cin >> mcake >> city;
	int a[city][mcake] = {0}, sales[mcake] = {0};
	for(int i = 0; i < city; ++i)
	{
		for(int j = 0; j < mcake; ++j)
				cin >> a[i][j];
	}
	for(int j = 0; j < mcake; ++j)
	{
		for(int i = 0; i < city; ++i)
		{
			sales[j] += a[i][j];
		}
		if(sales[j] >= max)
		{
			max = sales[j];
			last = j; 
	    } 
	}
	cout << max << endl;
	for(int i = 0; i < last; ++i)
	{
		if(sales[i] == max)
			cout << i+1 << " ";				
	}
	cout << last+1 << endl;
	return 0;
}
