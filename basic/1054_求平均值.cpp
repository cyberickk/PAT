#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	int n,valid = 0;
	double sum = 0, tmp;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		char a[50], b[50];
		int flag = 0;
		cin >> a;
		sscanf(a, "%lf", &tmp);
		sprintf(b,"%.2f", tmp); 
		for(int j = 0; j < strlen(a); ++j)
		{
			if(a[j] != b[j])	flag = 1;
			continue;
		}				
		if(flag || tmp < -1000 || tmp > 1000)
			printf("ERROR: %s is not a legal number\n", a);		
		else
		{
			sum += tmp;
			++valid;
		}				
	} 
	if(valid == 0)
		printf("The average of 0 numbers is Undefined\n");
	else if(valid == 1)		 
		printf("The average of 1 number is %.2f", valid, sum / valid);
	else
		printf("The average of %d numbers is %.2f", valid, sum / valid);	
	
	return 0;			
}
