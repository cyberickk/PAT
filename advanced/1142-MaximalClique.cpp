#include <iostream>
#include <vector>

using namespace std;

int main() {
	int nv, ne, m, a, b, e[210][210];
	scanf("%d %d", &nv, &ne);
	for(int i = 0; i < ne; ++i) {
		scanf("%d %d", &a, &b);
		e[a][b] = e[b][a] = 1;
	}
	scanf("%d", &m);
	for(int i = 0; i < m; ++i) {
		int k, t, hash[210] = {0};
		scanf("%d", &k);
		vector<int> v(k);
		for(int j = 0; j < k; ++j) {
			scanf("%d", &v[j]);
			hash[v[j]] = 1;
		}
		bool isclique = 1, ismaximal = 1;
		for(int j = 0; j < k; ++j) {
			for(int l = j+1; l < k; ++l) {
				if(!isclique) break;
				if(e[v[j]][v[l]] == 0) {
					isclique = 0; 
					printf("Not a Clique\n");
					break;
				}
			}
			
		}
		if(isclique) {
			for(int j = 1; j <= nv; ++j) {
				if(hash[j] == 0) {
					for(int l = 0; l < k; ++l) {
						if(e[v[l]][j] == 0) break;
						if(l == k-1) ismaximal = 0;
					}
				}
				if(ismaximal == 0) {
					printf("Not Maximal\n");
					break;
				}
			}
			if(ismaximal) printf("Yes\n");
		}		
	}
	return 0;
}
