#include <iostream>
using namespace std;

int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
int check[11] = {1,0,10,9,8,7,6,5,4,3,2};

bool validCheck(const string& s)
{
	int sum = 0;
	for(int i = 0; i < 17; ++i)
	{
		if(s[i] < '0' || s[i] > '9') return 0;
		sum += (s[i] - '0') * weight[i];
	}
	int tmp  = (s[17] == 'X') ? 10 : (s[17] - '0');
	return check[sum % 11] == tmp;
}

int main() 
{

	int n, flag = 0;
	string s;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> s;
		if(!(validCheck(s)))
		{
			flag = 1;
			cout << s << endl;
		} 
	}	
	if(!flag)  cout << "All passed" << endl;
	
	return 0;
}
