#include <iostream>
#include <vector>

using namespace std;

int main() {
	int k;
	string s, sout, sstuck;
	cin >> k >> s;
	vector<int> v(256, 0);
	for(int i = 0; i < s.size(); ++i) {
		if(v[s[i]] == 1)
			continue;
		else {
			if(s[i] != s[i-1] || s[i] != s[i+1]) {
				v[s[i]] = 1;
			}
			else {
				int cnt = 1;
				//i++;
				while(i < s.size() && s[i+1] == s[i]) {
					cnt++;
					i++;
				}
				i--;
				if(cnt % k != 0)
					v[s[i]] = 1;
				else
					v[s[i]] = -1;
			}
		}
	}
	for(int i = 0; i < s.size(); ++i) {
		sout += s[i];
		if(v[s[i]] == -1) {
			sstuck += s[i];
			i += k-1;
			v[s[i]] = -2;
		}
		if(v[s[i]] == -2) {
			i += k-1;
		}
	}
	cout << sstuck << endl << sout;
	return 0;
} 
