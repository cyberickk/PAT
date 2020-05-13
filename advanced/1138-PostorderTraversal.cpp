#include <iostream>
#include <vector>

using namespace std;

bool flag = 0;
vector<int> vpre, vin;

void postOrder(int pre, int inl, int inr) {
	if(inl > inr || flag == true) return;
	int i = inl;
	while(vin[i] != vpre[pre]) ++i;
	postOrder(pre+1, inl, i-1);
	postOrder(pre+i-inl+1, i+1, inr);
	if(flag == false) {
		printf("%d", vin[i]);
		flag = true;
	}
}

int main () {
	int n;	
	cin >> n;
	vpre.resize(n);
	vin.resize(n);
	for(int i = 0; i < n; ++i) 
		scanf("%d", &vpre[i]); 
	for(int i = 0; i < n; ++i) 
		scanf("%d", &vin[i]);
	postOrder(0, 0, n-1);
	return 0;
}
