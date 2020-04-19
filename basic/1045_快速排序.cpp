#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, max = -1;
	cin >> n;
	vector<int> v1(n), v2(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> v1[i];
		v2[i] = v1[i];
	}
	sort(v1.begin(), v1.end());
	vector<int> ans;
	for(int i = 0; i < n; ++i)
	{
		if(v1[i] == v2[i] && v2[i] > max) ans.push_back(v1[i]);
		if(v2[i] > max) max = v2[i];
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); ++i)
    {
        if(i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
	return 0;
}

