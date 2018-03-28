/*
问题定义
一个圆划分为N个扇形，现用M种颜色对其上色，要求相邻两块扇形的颜色不能相同，问有多少种上色方案？（其中N>=1,M>=3)
注意：不考虑对称性，例如：一个圆划分为2个扇形，用3种颜色上色方案有“黑红，黑白，白红，白黑，红白，红黑”6种，相当于每个扇形都有编号，是不一样的。

解题思路
采用数学归纳的思想。求n个扇形的上色方案，相当于在n-1个扇形中插入一个扇形，这时只需考虑两种情况：1、第1个扇形和第n-1个扇形颜色不一样，这有s(n-1)种情况，此时插入的扇形n有m-2种颜色选择；2、第1个扇形和第n-1个扇形颜色一样(n>3)，这有s(n-2)种情况，此时插入的扇形n有m-1种颜色选择。
由以上分析可得：

s(1) = m;
s(2) = m(m-1);
s(3) = m(m-1)(m-2);
s(n) = s(n-1)*(m-2)+s(n-2)*(m-1);
*/

#include<iostream>
using namespace std;
int dp[103];
int main()
{
   int colors,colorLevel;
   cin >> colors >> colorLevel ;
   dp[1] = colors;
   dp[2] = colors*(colors-1);
   int tmp = dp[2];
   for(int i=3;i<=colorLevel;i++)
   {
   	  tmp *= (colors-1);
   	  dp[i] = tmp-dp[i-1];
   }
   cout<<dp[colorLevel];
    return 0;
}

/*
#include <iostream>
#include <string>

using namespace std;

int theCount = 0;
int theStack[1000];
int stackIndex=1;

void  P(int colors,int splitCount, int t,int theColor)
{
	if(t>=splitCount+1) {theCount++;return;}
	for(int i=1;i<=colors;i++)
		if(i!=theColor)
		{
			if(t==splitCount&&i==theStack[1]) continue;
			theStack[stackIndex++]=i;
			P(colors,splitCount,t+1,i);
			stackIndex--;
		}

}

int main()
{
	int colors,splitCount;
	cout << "please enter the colors and splittimes:" << endl;
	cin >> colors >> splitCount  ;

	for(int i=0;i<splitCount;i++)
     theStack[i]=-1;
    P(colors,splitCount,1,-1);
	cout << "Kinds of times:" ;
	cout<<theCount << endl;

	return 0;
}

*/
/*
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int fun(int n, int m) {
    int r;
    if (n == 1) r = m;
    else if (n == 2) r = m * (m - 1);
    else if (n == 3) r = m * (m - 1)*(m - 2);
    else {
        r = fun(n - 1, m)*(m - 2) + fun(n - 2, m)*(m - 1);
    }
    return r;
}

int main() {
    int n, m;
    cin >> m >> n;
    int r = fun(n, m);
    cout << r;
    system("pause");
    return 0;
}
*/
