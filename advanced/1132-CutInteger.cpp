#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int a, b, c;
		cin >> a;
		string s = to_string(a);
		int t = s.size();
		b = stoi(s.substr(0, t/2));
	 	c = stoi(s.substr((t/2)));
	 	if(b * c != 0 && a % (b * c) == 0) 
	 		cout << "Yes" << endl;		
		else
			cout << "No" << endl;		
	}
	return 0;
}
