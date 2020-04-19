 ///
 /// @file    1051_复数乘法.cpp
 /// @author  kk(blingblingda@hotmail.com)
 /// @date    2020-01-28 12:45:10
 ///

#include <math.h>

#include <iostream>
#include <iomanip>
using namespace std;
 
//其实没有必要用类和面向对象来写，再优化一个简单版本
//重点1：复数指数形式（极坐标）和常规形式（直角坐标）的转换
//重点2：实部虚部正负号输出，浮点数四舍五入的处理
//结果的规格化输出最好用printf

class ExpComplex;
class NormComplex;

class ExpComplex 
{
public:
    friend class NormComplex;
    ExpComplex(double ir = 0.00, double ip = 0.00)
    : _ir(ir)
    , _ip(ip)
    {}

    ExpComplex multi(ExpComplex e2);
    NormComplex toNorm();

    double getir()
    { return _ir; }
    double getip()
    { return _ip; }

private:
    double _ir;
    double _ip;
};

class NormComplex 
{
public:
    NormComplex(double ia = 0.00, double ib = 0.00)
    : _ia(ia)
    , _ib(ib)
    {}
    
    double getia()
    { return _ia; }
    double getib()
    { return _ib; }

    void display();   //重点部分！区分虚部正负号，接近0的浮点型数据特殊处理

private:
    double _ia;
    double _ib;
};
 

ExpComplex ExpComplex::multi(ExpComplex e2)
{
    double eir = 0.00, eip = 0.00;
    double e2ir, e2ip;
    e2ir = e2.getir(); e2ip = e2.getip();
    eir = _ir * e2ir;
    eip = _ip + e2ip;
    ExpComplex multie(eir,eip);
    return multie;    
    
}

NormComplex ExpComplex::toNorm()
{
    double nia,nib;
    nia = _ir * cos(_ip);
    nib = _ir * sin(_ip);

    NormComplex n(nia,nib);
    return n;

}


void NormComplex::display()
{
/*     cout << fixed << setprecision(2);
    if(_ia + 0.005 >= 0 && _ia < 0)
        cout << "0.00";
	else if(_ia > 0 && _ia < 0.01)
		cout << "-0.00";
    else cout << _ia;

    if(_ib >= 0) cout << "+" << _ib << "i";
    else if(_ib + 0.005 >= 0 && _ib < 0)
        cout << "0.00i";
    else cout << _ib << "i";

    cout << endl; */
	
	if(_ia + 0.005 >= 0 && _ia < 0)
		printf("0.00");
	else
		printf("%.2f", _ia);
	if(_ib >= 0)
		printf("+%.2fi", _ib);
	else if(_ib + 0.005 >= 0 && _ib < 0)
		printf("+0.00i");
	else 
		printf("%.2fi", _ib);
	
	printf("\n");
	
}

int main()
{
    double e1ir,e1ip,e2ir,e2ip;
    cin >> e1ir >> e1ip >> e2ir >> e2ip;

    ExpComplex e1(e1ir,e1ip);
    ExpComplex e2(e2ir,e2ip);
    ExpComplex e;
    e = e1.multi(e2);
    NormComplex n;
    n = e.toNorm();
    n.display();

    return 0;  
}
