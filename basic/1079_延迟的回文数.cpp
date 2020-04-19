#include <iostream>
#include <stack> 
#include <string>
#include <algorithm>
using namespace std;

bool isHui(const string& s)
{
	if(s[0] == '0') return 1;
	stack<int> st;
	int i = 0;
	for(i = 0; i < s.size()/2; ++i)
	{
		st.push(s[i]);		
	}
	if(s.size() % 2 == 1) ++i;
	for(; i < s.size(); ++i)
	{
		char c;
		c = st.top();
		st.pop();
		if(c != s[i])
			 return 0;
	}
	return 1;
}

string add(const string& A, const string& B)
{
 	int i=A.size()-1,sur=0;
    string C;
    while(i>=0)
    {
        int sum=A[i]-'0'+B[i]-'0';
        C+=(sur+sum)%10+'0';
        sur=(sur+sum)/10;
        --i;
    }
    if(sur>0)C+='0'+sur;
    reverse(C.begin(),C.end());
    return C;
}

int main()
{
	string s,sa,sb,sc;
	cin >> s;
	sa = s;
	if(isHui(s))
	{
		cout << s << " is a palindromic number.\n";
		return 0;
	}
	for(int i = 0; i < 10; ++i)
	{
		sb = sa;
		reverse(sb.begin(), sb.end());
		sc = add(sa,sb);
		cout << sa << " + " << sb << " = " << sc << endl;
		if(isHui(sc))
		{
			cout << sc << " is a palindromic number.\n";
			return 0;
		}
		sa = sc;		
	}
	cout << "Not found in 10 iterations." << endl;

	return 0;
}
