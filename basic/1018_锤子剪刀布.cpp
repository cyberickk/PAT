#include <iostream>
#include <map>
using namespace std;

bool check(char a, char b)
{
	if((a == 'C' && b == 'J') || (a == 'J' && b == 'B') || (a == 'B' && b == 'C'))
		return 1;
	else return 0;
}
int main()
{
	int n, jcnt[3] = {0}, ycnt[3] = {0}, maxcntj = 0, maxcnty = 0;
	map<char, int> jwin, ywin;
	jwin = {{'B', 0}, {'C', 0}, {'J', 0}};
	ywin = {{'B', 0}, {'C', 0}, {'J', 0}};
	cin >> n; 
	for(int i = 0; i < n; ++i)
	{
		char j, y;
		cin >> j >> y;
		if(j == y)
		{
			jcnt[1]++; ycnt[1]++;						  	
		} 
		else if(check(j, y))
		{
			jcnt[0]++; ycnt[2]++;
			jwin[j]++;
			if(jwin[j] >= maxcntj)
				maxcntj = jwin[j];
		}
		else
		{
			jcnt[2]++; ycnt[0]++;
			ywin[y]++;
			if(ywin[y] >= maxcnty)
				maxcnty = ywin[y]; 
		}
	}
	cout << jcnt[0] << " " << jcnt[1] << " " << jcnt[2] << endl;
	cout << ycnt[0] << " " << ycnt[1] << " " << ycnt[2] << endl;
	map<char,int>::iterator it;
	for(it = jwin.begin(); it != jwin.end(); ++it)
	{
		if(it->second == maxcntj)
		{
			cout << it->first << " ";
			break;
	 	} 
	}
	for(it = ywin.begin(); it != ywin.end(); ++it)
	{
		if(it->second == maxcnty)
		{
			cout << it->first;
			break;
		} 
	}
	return 0;
}
