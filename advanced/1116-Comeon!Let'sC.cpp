#include <iostream>
#include <map>

using namespace std;

bool isPrime(int n) {
	for(int i = 2; i * i <= n; ++i) {
		if(n % i == 0)
			 return 0;
	}
	return 1;
}

int main() {
	int n, k, q;
	cin >> n;
	map<int, string> m;
	for(int i = 1; i <= n; ++i) {
		cin >> q;
		if(i == 1) m[q] = "Mystery Award";
		else if(isPrime(i))
			m[q] = "Minion";
	 	else
	 		m[q] = "Chocolate";
	}
	cin >> k;
	for(int i = 0; i < k; ++i) {
		cin >> q;
		printf("%04d: ", q);
		if(m.count(q)) {
			if(m[q] == "0")
				printf("Checked\n");
			else {
				cout << m[q] << endl;
				m[q] = "0";	
			}
		}
		else
			printf("Are you kidding?\n");
	}
	return 0;
} 
