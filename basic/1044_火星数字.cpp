#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ge[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string shi[13] = {"####", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
	
void etom(const string& a)
{
	int t = stoi(a);
	//cout << t << endl;
	if(t == 0) cout << "tret" << endl;
	else if(t > 0 && t < 13)	cout << ge[t] << endl;
	else
	{
		int t1 = t / 13;
		t = t % 13;
		cout << shi[t1] << " " << ge[t] << endl;
	}	
}

int main()
{
	
	int n;
	cin >> n;
	cin.ignore();
	for(int i = 0; i < n; ++i)
	{
		string s;
		getline(cin, s);
		if(isdigit(s[0])) etom(s);
		else
		{
			string ss, sg;
			int sum = 0, cnt = s.size();
			if(s == "tret") 
			{
				cout << "0" << endl;
				break;
			}
			else if(cnt < 5)
			{
				for(int j = 0; j < 13; ++j)
				{
					if(shi[j] == s)
						sum += 13 * j;
					if(ge[j] == s)
						sum += j;
					if(sum)
					{
						cout << sum << endl;
						break;
					}
				}				 
			}
			else
			{
				ss = s.substr(0, 3);
				sg = s.substr(4, 3);
				for(int j = 0; j < 14; ++j)
				{
				 	if(shi[j] == ss) 
					{
					 	sum += 13 * j;
						break; 
					}
				}
				for(int j = 0; j < 14; ++j)
				{
				 	if(ge[j] == sg)
					{
			 		 	sum += j;
						cout << sum << endl;
						break;
	 		 		}
				}
			}
		}
	}
	
	return 0;
}
