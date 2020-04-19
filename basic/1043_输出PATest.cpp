#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int a[6] = {0}, cnt = 0;
	for(int i = 0; i < s.size(); ++i)
	{
		switch(s[i])
		{
			case 'P':
				a[0]++; cnt++; break;
			case 'A':
				a[1]++; cnt++; break;
			case 'T':
				a[2]++; cnt++; break;
			case 'e':
				a[3]++; cnt++; break;
			case 's':
				a[4]++; cnt++; break;	
			case 't':
				a[5]++; cnt++; break;	
			default:
				break;	
		}
	}
	for(int i = 0; i < cnt;)
	{
		if(a[0] > 0)
		{
			cout << "P";
			a[0]--; i++;			
		}
		if(a[1] > 0)
		{
			cout << "A";
			a[1]--; i++;			
		}
		if(a[2] > 0)
		{
			cout << "T";
			a[2]--; i++;			
		}
		if(a[3] > 0)
		{
			cout << "e";
			a[3]--; i++;			
		}
		if(a[4] > 0)
		{
			cout << "s";
			a[4]--; i++;			
		}
		if(a[5] > 0)
		{
			cout << "t";
			a[5]--; i++;			
		}		
	}
	return 0;
}
