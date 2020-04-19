#include <iostream>
using namespace std;

int main() 
{

	int c1,c2,diff;
	cin >> c1 >> c2;
	diff = (c2 - c1 + 50)/100;
	int hh,mm,ss;
	hh = diff / 3600;
	mm = (diff % 3600) / 60;
	ss = diff % 60;
	printf("%02d:%02d:%02d\n", hh,mm,ss);
	return 0;
}