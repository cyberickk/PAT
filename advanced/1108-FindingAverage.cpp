#include <iostream>
#include <vector>
using namespace std;

bool islegal(double d) {
	double t = d * 100;
	return ((int)t == t) ? 1 : 0;
}

int main() {
	int n, cnt = 0, sum = 0;
	cin >> n;
	cin.ignore();
	string s;
	for(int i = 0; i < n; ++i) {
		cin >> s;
		bool flag = 1;
		for(int j = 0; j < s.size(); ++j) {
			if(!isdigit(s[j])) {
				flag = 0;
				break;
			}
			if(s[j] == '.') {
				for(int k = j+1; k < s.size(); ++k) {
					if(!isdigit(s[j]) || k-j > 2) {
						flag = 0;
						break;
					}
				}
			}
		}		
		double d = stod(s);
		if(d < -1000 || d > 1000 || islegal(d) == 0)
			flag = 0;
		if(!flag) cout << "ERROR: " << s <<  " is not a legal number\n";
		else {
			cnt++;
			sum += d;
		}
	}
	if(cnt == 0)
		cout << "The average of 0 numbers is Undefined\n";
	else
 		printf("The average of %d numbers is %.2f\n", cnt, sum/cnt);
	return 0;
}
