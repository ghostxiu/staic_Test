//互娱2018/8/9 游戏研发 笔试第一题 2018 工资上税
//By Ghostxiu 2018/8/10
//http://x.wolfmark.org
//输入是测试个数n和n个工资数
//输出是需缴纳的个税
//个税请参看2018个税表
#include<iostream> //cin,cout
using namespace std ;
int times;
double taxRate[7] = {0.03,0.1,0.2,0.25,0.3,0.35,0.45};
long needAcross[6] = {3000,9000,13000,10000,20000,35000};
long taxs[100]={0};
//计算个税的函数
long calcTax(long target,long tax ,int tag);

int main()
{
	int times;
	cin >> times;
	for(int i = 0 ; i < times ; ++i)
	{
		long salary ;
		cin >> salary;

		if(salary > 5000)
		{
			long target =salary - 5000;
			long tax = calcTax(target,0,0);
			taxs[i] = tax;
		}
	}
	for(int i = 0 ; i < times ; ++i)
	{
		cout << taxs[i] << endl;
	}
}

long calcTax(long target, long tax , int tag)
{

	if(target <= 0 || tag >= 6 )
	{
		return tax;
	}
	if(target - needAcross[tag] > 0  && tag < 6)
	{
		tax += long(needAcross[tag] * taxRate[tag] + 0.5);
		target -= needAcross[tag];
		calcTax(target,tax,tag+1);
	}
	else
	{
		tax += long(target * taxRate[tag] + 0.5);
		return tax;
	}

}
//By Ghostxiu 2018/8/10
//http://x.wolfmark.org
