#include <iostream>
using namespace std;

int main()
{
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int i = 0, j = 0;
	string week[7] = {"MON ", "TUE ", "WED ", "THU ", "FRI ", "SAT ", "SUN "};
	while(i < s1.size() && i < s2.size())
	{
		if(s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G')
		{
			cout << week[s1[i] - 'A'];
			break;
		}
		++i;
	}
	++i;
	while(i < s1.size() && i < s2.size())
	{
		if(s1[i] == s2[i])
		{
			char c = s1[i];
			if(isdigit(c))
			{
				printf("%02d:", c - '0');
				break;
			}	
			else if(c <= 'N' && c >='A')
			{
				printf("%02d:", c - 'A' + 10);
				break;
			}	
			else ;
		}
		++i;
	}
	
	while(j < s3.size() && j < s4.size())
	{
		if(s3[j] == s4[j] && isalpha(s3[j]))
		{
			printf("%02d", j);
			break;
		}
		++j;		
	}
	
	return 0;
} 
