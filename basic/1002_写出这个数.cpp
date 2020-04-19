#include <string.h>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void printpy(char n)
{
	switch(n)
	{
		case '0' :
			cout << "ling" ; break;
		case '1' :
			cout << "yi"; 	break;
		case '2' :
			cout << "er"; break;
		case '3':
			cout << "san"; break; 
		case '4':
			cout << "si" ; break;
		case '5':
			cout << "wu" ; break;
		case '6':
			cout << "liu" ; break;
		case '7':
			cout << "qi" ; break;
		case '8':
			cout << "ba" ; break;
		case '9':
			cout << "jiu" ; break;
		default:
			break;
	}
}


void test0()
{
	int i=0,l=0, sum=0,k=0;
    string s1;
    cin >> s1;
    l = s1.length();  //用字符串存入长数字
        
	while(i < l)   //string可以直接用下标访问
    {
        sum = sum + s1[i] - '0';  // string里存的是char 类型，得到数字之和要减掉0的ASCII码值（49）
        ++i;
    } 
    string sums = to_string(sum);  //把int型的和再转换成字符串，便于每一位读拼音
    l = sums.length();
	for(k = 0; k != l-1; ++k )  //int 转换成string 后视觉顺序不变，高位在string[0]，低位(个位)在string[length-1]
	{
		printpy(sums[k]);	
        cout << " ";	
	}
    printpy(sums[l-1]);  //最后一位不加空格，单独输出
    cout << endl;
}
 
int main()
{
    test0();
    return 0;
}