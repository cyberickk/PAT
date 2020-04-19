#include <iostream>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int q[356] = {0}, m = 0;
	for(int i = 0; i < s1.size(); ++i)
		q[s1[i]]++;
	for(int i = 0; i < s2.size(); ++i)
	{
		if(q[s2[i]] > 0)
			q[s2[i]]--;
		else
			m++;
	}
	if(m > 0) cout << "No " << m;
	else 	cout << "Yes " << s1.size() - s2.size();
 	return 0;	
}

