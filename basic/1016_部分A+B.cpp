#include <iostream>
#include <string>
using namespace std;

int main() 
{

	string a,b;
	int da,db,pa = 0,pb = 0,anum = 0,bnum = 0;
	cin >> a >> da >> b >> db;
	for(int i = 0; i < a.size(); ++i)
			if(da == a[i] - '0') ++anum;
	for(int i = 0; i < b.size(); ++i)
			if(db == b[i] - '0') ++bnum;
	if(anum) pa = da; 
	if(bnum) pb = db;
	for(int i = 1; i < anum; ++i)
			pa = 10 * pa + da;
	for(int i = 1; i < bnum; ++i)
			pb = 10 * pb + db;	
	cout << pa+pb << endl;
		
	return 0;
}
