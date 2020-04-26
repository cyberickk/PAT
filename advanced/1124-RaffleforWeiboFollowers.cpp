#include <iostream> 
#include <set>

using namespace std;

int main() {
	int m, n, s;
	cin >> m >> n >> s;
	if(s > m) {
		cout << "Keep going...\n";
		return 0;
	}
	set<string> win;
	string id;
	for(int i = 1; i < s; ++i) {
		cin >> id;
	}	
	cin >> id;
	cout << "2" << id << endl;
	win.insert(id);
	int cnt = 0;
	for(int i = 0; i < m-s; ++i) {		
		cin >> id;
		cnt++;
		if(cnt == n) {
			if(win.count(id)) 
				cnt--;
			else {
				win.insert(id);
				cout << "2" << id << endl;
				cnt = 1;
			}
		}
	}
	return 0;
}
