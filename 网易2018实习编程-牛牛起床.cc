//牛牛起床上学，有n组闹钟，起床到学校的时间为m，求最晚起床时间
//输入：第一行，闹钟组数n<100
//接下来n行：闹钟时间 时 分
//输入起床到学校的时间m
//输入上课时间
//输出:最晚起床时间 时 分

/*实例
输入:
3
5 0
6 0
7 0
59
6 59
输出：
6 0
*/
#include<iostream>
#include<algorithm>
const int HourtoMin = 60;//小时转化为分钟
int main()
{
	using namespace std ;
	int n ;
	while(cin >> n)
	{
	;
		int clock_t[n];
		int clc_h ,clc_m;
		for(int i = 0 ;i<n;++i)
		{
			cin >> clc_h >> clc_m ;
			clock_t[i] = clc_h*HourtoMin + clc_m ;
		}
		int walk_min = 0 ;
		int class_h , class_m,class_time;

		sort(clock_t,clock_t+n);

		cin >> walk_min ;
		cin >> class_h >> class_m;
		class_time = class_h * HourtoMin + class_m;
		class_time -= walk_min ;
		int tag = 0 ;
		for(int i = 0 ;i<n;++i)
		{
			if(clock_t[i] ==  class_time)
			{
				tag = i ;
				break;
			}
			if(clock_t[i] >  class_time)
			{
				tag = i - 1;
				break;
			}
		}
		int get_hour = clock_t[tag] / HourtoMin ;
		int get_min = clock_t[tag] % HourtoMin ;
		cout << get_hour << ' ' << get_min << endl;
	}


	return 0;
}
//By Ghostxiu 2018/3/28
//本程序地址：https://github.com/ghostxiu/staic_Test
