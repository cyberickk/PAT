#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int num0 = 0, num1 = 0;
	getline(cin, s);
	int sum = 0;
	for(int i = 0; i < s.size(); ++i)
	{
		if(isalpha(s[i]))
			sum += tolower(s[i]) - 'a' + 1; 
	}
	
	while(sum != 0)
	{
		if(sum % 2 == 0) ++num0;
		else ++num1;
		sum /= 2;
	}
	cout << num0 << " " << num1 << endl; 
	return 0;
}
