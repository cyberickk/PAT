 #include <iostream>
 #include <cmath>
 using namespace std;
 
 int main()
 {
 	int n;
 	float x, y, mod, max = 0;
 	cin >> n;
 	for(int i = 0; i < n; ++i)
 	{		
 		cin >> x >> y;
 		mod =sqrt(x * x + y * y);
 		if(mod > max) max = mod; 		
	}
 	printf("%.2f", max);
 
 	return 0;
 }
