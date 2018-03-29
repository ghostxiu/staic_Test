//携程笔试题：顺时针旋转数组
//难点在于输入获取
#include <iostream>
#include <queue>
using namespace std;
const int Max_size = 1000 ;
int main(void)
{
	char c_t[Max_size];
	cin.getline(c_t,Max_size);

	int p , n;
	p = n = 0;
	int c[Max_size];

	while(1)
	{

		if(c_t[p] >= '0' && c_t[p] <= '9')
		{
			c[n] = c_t[p] - 48 ;
			n++;
		}
		if(c_t[p] == '\0') break ;
		p++;
	}



	int a[n][n];
	for(int i = 0 ; i < n ; ++i)
	{
		a[0][i] = c[i];
	}
	for(int i = 1 ; i < n ; ++i)
	{
		for(int j = 0 ; j < n ;++j)
		{
			cin >> a[i][j];
		}
	}


    //转置
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            int temp = 0;
            //沿主对角线对称位置上的元素进行交换
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    //逆序：对一维数组而言，将每一行第i个元素与第N-i-1个元素进行交换
    for (int i = 0; i < n; ++i)
    {
        for (int j = n - 1; j >= n / 2; --j) //注意j循环的条件为 j>=N/2
        {
            int temp = 0;
            temp = a[i][j];   //第i行末元素
            a[i][j] = a[i][n - j - 1];
            a[i][n - j - 1] = temp;
        }
    }
	for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout  << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;

}

//By Ghostxiu 2018/3/29
//本程序地址：https://github.com/ghostxiu/staic_Test