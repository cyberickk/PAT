#include <iostream>
#include <set>

using namespace std;

struct item {
	int id, freq;
	bool operator < (const item& a) const {
		 return (a.freq != freq) ? freq > a.freq : id < a.id;
	}
	
};
int book[50001];

int main() {
	int n, k, d;
	scanf("%d %d", &n, &k);
	set<item> s;
	
	for(int i = 0; i < n; ++i) {
		scanf("%d", &d);
		
		if(i != 0) {
			printf("%d:", d);
			int j = 0;
			for(auto it = s.begin(); j < k && it != s.end(); ++it) {
				printf(" %d", it->id);
				++j;
			}
			printf("\n");
		}		
		auto it = s.find(item{d, book[d]});
		if(it != s.end()) s.erase(it);
		book[d]++;
		s.insert(item{d, book[d]});
	}
	
	return 0;
}
