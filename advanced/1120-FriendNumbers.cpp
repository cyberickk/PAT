#include <iostream>
#include <set>
using namespace std;

int getid(const string& s) {
	int sum = 0;
	for(auto it:s) {
		sum += it - '0';
	}	
	return sum;
}

int main() {
	int n;
	cin >> n;
	string s;
	set<int> id;
	for(int i = 0; i < n; ++i) {
		cin >> s;
		id.insert(getid(s));
	}
	cout << id.size() << endl;
	int i = 0;
	for(auto it:id) {
		if(i != 0) cout << " ";
		++i;
		cout << it;		
	}
	return 0;
}
