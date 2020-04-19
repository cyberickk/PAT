#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int f, n, k;
	cin >> f >> n >> k;
	int data[100005], next[100005], list[100005];
	for(int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		cin >> data[tmp] >> next[tmp];
	}
	int sum = 0;
	while(f != -1)
	{
		list[sum++] = f;
		f = next[f];
	}
	for(int i = 0; i < (sum - sum % k); i += k)
		reverse(begin(list) + i, begin(list) + i + k);
	for(int i = 0; i < sum - 1; ++i)
		printf("%05d %d %05d\n", list[i], data[list[i]], list[i+1]);
	printf("%05d %d -1\n", list[sum-1], data[list[sum-1]]);
	return 0;
}
