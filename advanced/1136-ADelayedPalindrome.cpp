#include <iostream>
#include <algorithm>
using namespace std;

string add(const string& a, const string& b) {
	string sum;
	int flag = 0;
	for(int i = a.size()-1; i >=0; --i) {
		int c = a[i] + b[i] + flag - '0' - '0';
		if(c > 9) {
			flag = 1;
			c -= 10;
		}
		else flag = 0;
		sum += c + '0';
	}
	if(flag) sum += '1';
	reverse(sum.begin(), sum.end());
	return sum;
}
int main() {
	string s, tmp;
	cin >> s;
	if(s == "0") {
		printf("0 is a palindromic number.\n");
		return 0;
	}
	for(int i = 0; i < 10; ++i) {
		tmp = s;
		reverse(tmp.begin(), tmp.end());
		if(tmp == s) {
			printf("%s is a palindromic number.\n", s.c_str());
			return 0;
		}
		string sum = add(s, tmp);
		printf("%s + %s = %s\n", s.c_str(), tmp.c_str(), sum.c_str());		
		s = sum;
	}
	cout << "Not found in 10 iterations." << endl;
	return 0;
}
