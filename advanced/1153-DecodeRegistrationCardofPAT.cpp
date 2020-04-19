#include <iostream> 
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct stu {
	string id;
	int score;
};

struct dateroom {
	string room;
	int cnt;
};

static bool cmpsc(const stu& a, const stu& b) {
	return a.score > b.score ? 1 : (a.score == b.score ? (a.id < b.id ? 1 : 0) : 0);
}

static bool cmprm(const dateroom& a, const dateroom& b) {
	return a.cnt > b.cnt ? 1 : (a.cnt == b.cnt ? (a.room < b.room ? 1 : 0) : 0);
}

int main() {
	int n, m;
	cin >> n >> m;
	cin.ignore();
	vector<stu> raw(n);
	for(int i = 0; i < n; ++i) {
		cin >> raw[i].id >> raw[i].score;
	}
	for(int i = 1; i <= m; ++i) {
		int a;
		string s;
		cin >> a >> s;
		cin.ignore();
		printf("Case %d: %d %s\n", i, a, s.c_str());
		switch(a) {
			case 1:
				{
					vector<stu> tmp;
					for(auto it:raw) {
						if(it.id[0] == s[0])
									   tmp.push_back(it);
					}
					sort(tmp.begin(), tmp.end(), cmpsc);
					for(auto it : tmp) {
						printf("%s %d\n", it.id.c_str(), it.score);
					}
					if(tmp.size() == 0)
						cout << "NA" << endl;
				}				
				break;
			case 2:
				{
					int cnt = 0, sum = 0;
					for(auto it:raw) {
						string room = it.id.substr(1,3);
						if(room == s) {
							cnt++;
							sum += it.score;
						}
					}
					if(cnt == 0)
						   cout << "NA" << endl;
    		   		else
						cout << cnt << " " << sum << endl;
				}
				
			 	break;
		 	case 3:
		 		{
		 			unordered_map<string, int> m;
			 		for(auto it:raw) {
			 			string date = it.id.substr(4,6);
			 			if(date == s) {
			 				string rm = it.id.substr(1,3);
			 				m[rm]++;
						 }
					}
					vector<dateroom> v;
					for(auto it:m) {
					 	v.push_back({it.first, it.second});
					}

				 	sort(v.begin(), v.end(), cmprm);
				 	for(auto it:v) {
				 	 	printf("%s %d\n", it.room.c_str(), it.cnt);
			  		}
			  		if(v.size() == 0)
			  			cout << "NA" << endl;
				}		 		
		 		break;
	 		default:
	 			break;
	 			
		}
	}
	return 0;
}
