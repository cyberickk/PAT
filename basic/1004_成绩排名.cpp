#include <iostream>
using namespace std;

int main()
{
	int n, score, max = 0, min = 100;
	string name, id, maxname, maxid, minname, minid;
 	cin >> n;
 	for(int i = 0; i < n; ++i)
 	{
 		cin >> name >> id >> score;
 		if(score > max)
 		{
 			max = score; maxname = name; maxid = id;
		}
		if(score < min)
		{
			min = score; minname = name; minid = id;
		}
 	}
	cout << maxname << " " << maxid << endl
		 << minname << " " << minid;
	return 0;
} 
