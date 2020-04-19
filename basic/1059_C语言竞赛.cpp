#include <iostream>
#include <vector>
#include <map>
#include <set> 
using namespace std;

bool isPrime(int a)
{
	if(a == 0 || a == 1) return 0; 
	for(int i = 2; i * i <= a; ++i)
	{
		if(a % i == 0) return 0;
	}
	return 1;
}

int main()
{
	int n;
	cin >> n;
	map<int, int> rank;
	set<int> check;
	for(int i = 1; i <= n; ++i)
	{
		int tmp;
		cin >> tmp;
		rank[tmp] = i;
	}
	int k;
	cin >> k;
	for(int i = 0; i < k; ++i)
	{
		int tmp;
		cin >> tmp;
		printf("%04d: ", tmp);
		if(check.find(tmp) != check.end())
			printf("Checked\n");
		else if(rank.find(tmp) == rank.end())
		 	printf("Are you kidding?\n");
		else
		{
			check.insert(tmp);
			int r = rank[tmp];
			if(r == 1) printf("Mystery Award\n");
			else if(isPrime(r)) printf("Minion\n");
			else printf("Chocolate\n"); 
		}
		
	}
	
	return 0;
} 
