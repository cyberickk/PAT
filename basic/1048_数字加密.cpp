#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

int main()
{
	string enc, num, sec;
	char psw[14] = {"0123456789JQK"};
	cin >> enc >> num;
	reverse(enc.begin(), enc.end());
	reverse(num.begin(), num.end());
	if(enc.size() < num.size())		enc.append(num.size() - enc.size(), '0');
	else 	num.append(enc.size() - num.size(), '0');  //???
	for(int i = 0; i < num.size(); ++i)
	{
		if(i % 2 == 0)
	 		sec += psw[(enc[i] - '0' + num[i] - '0') % 13];
		else
		{
			int tmp;
			tmp = num[i] - enc[i];
			if(tmp < 0) 	tmp = tmp + 10;
			sec += psw[tmp];
		}
	}
	//reverse(sec.begin(), sec.end());
	//cout << sec;
	for(int i = sec.size() - 1; i >= 0; --i)
			cout << sec[i];
	return 0;
	
} 
