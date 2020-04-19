 ///
 /// @file    1086_就不告诉你.cpp
 /// @author  kk(blingblingda@hotmail.com)
 /// @date    2020-01-26 22:38:21
 ///


#include <iostream>
#include <string>
using namespace std;


int main()
{
 
    int a=0, b=0, mul=0;
    string lhs,rhs;
    
    cin >> a >> b;
	lhs = to_string(a * b);  //不能用int存放乘积，因为位数有可能超过int长度
    while(lhs.size() != 0)
    {
        char c = lhs.back();
        if(c == '0')
            lhs.pop_back();
        else break;
    } //删除末尾的0，防止逆置数字时以0开头
    for(string::reverse_iterator it = lhs.rbegin(); it != lhs.rend(); ++it)
    {
        char c = *it;
        rhs.push_back(c);
    } //用逆向迭代器将乘积每一位存入新的字符串中，达到逆置的效果
    cout << rhs << endl;

    return 0; 
}


从分值小的开始做（一般来说会简单一点）
有思路的题
	做题过程中参考cppreference, 针对性熟悉C++的知识
	例如string、vector等有哪些操作以及如何使用
	涉及某个操作不会写（Google搜索现学现用，例如如何把int转换成string）
有一点想法的题
	Google直接搜题号和标题
	能看懂就自己尝试写，啃不动就先跳过
	
做题过程
	一般提交之后主体部分是正确的
	有个别测试点会报错，再参考其他人的程序找到哪些特殊情况没考虑到
	完全正确后总结要考虑哪些临界点，以及新学到的用法
