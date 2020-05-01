#include <iostream> 
#include <set>

using namespace std;

int main() {
	int m, n, s;
	cin >> m >> n >> s;
	set<string> win;
	string id;	
	int cnt = 0;
	for(int i = 1; i <= m; ++i) {		
		cin >> id;
		if(i < s) {
			continue;
		}
		else if(i == s) {
			cout << id << endl;	
			win.insert(id);		
		}
		else {
			cnt++;
			if(cnt == n) {
				if(win.count(id)) 
					cnt--;
				else {
					win.insert(id);
					cout << id << endl;
					cnt = 0;
				}
			}
		}		
	}
	if(win.size() == 0) 
		cout << "Keep going..." << endl;
	return 0;
}
