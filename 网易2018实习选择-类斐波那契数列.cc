//用1*3的矩形铺满3*20矩形
//类斐波那契数列,递推公式为f(n) = f(n-1) + f(n-3)
#include<iostream>
int main()
{
	using namespace std ;
	int n ;
	cin >> n;
	int a[n] = {1,1,2 };
	for(int i = 3 ; i < n ; ++i)
	{
		a[i] = a[i-1] + a[i-3];
	}
	cout << a[n-1] << endl ;
}
//使用递推的方式完成了斐波那契数列
//By Ghostxiu 2018/3/28
