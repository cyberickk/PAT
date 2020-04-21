#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	string s;
	cin >> s >> n;
	for(int i = 1; i < n; ++i) {
		string tmp;
		for(int j = 0; j < s.size();++j) {
			tmp += s[j];
			int cnt = 1;
			while(s[j+1] == s[j]) {
				j++;
				cnt++;
			}
			tmp += to_string(cnt);
		}
		s = tmp;
	}
	cout << s;
	return 0;
}
