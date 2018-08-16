//互娱2018/8/9 游戏研发 笔试第二题 2018 弱密码
//By Ghostxiu 2018/8/11
//http://x.wolfmark.org
//输入是测试个数n和n个密码
//满足以下5种描述的是弱密码：
//1.长度<8
//2.密码中以下任何一种：小写字母、大写字母、特殊字符、数字
//3.存在连续3个数字构成等差数列，公差为0也是
//4.存在连续3个顺序的大写字母、小写字母，或者三个同样的
//5.包含以下常用密码:"password","admin","qwerty","hello","iloveyou","112233"
//若为弱密码，输出"no",否则输出"yes"


#include<iostream> //cin,cout
#include<algorithm>
#include<string> //
#include<set>
#include<cctype>//islower isupper isalpha
using namespace std ;
int times;
const int al_size = 6;
string alwaysUse[al_size] = {"password","admin","qwerty","hello","iloveyou","112233"};
const int ch_size = 23;
char charUse[23]={'!','@','#','$','%','&','*','(',')','_','-','+','=','{','}','[',']',',','.','<','>','?','/'};
int main()
{
    cin >> times;
    bool weak_tag[times] = {0} ;
    for(int i = 0 ; i < times ; ++i)
    {
        string temp ;
        cin >> temp ;
        int len = temp.size();
        //1.长度小于8
        if(len < 8)
        {
           //cout << "tag1" << endl;
            weak_tag[i] = true;//是弱密码,输出应为no
            continue;
        }
        //2.包含各种字符
        set<int> charSetkinds;

        for(int j = 0 ;  j < len && !weak_tag[i] ; ++j)
        {
            if(temp[j] >= '0' && temp[j] <= '9')
            {
                charSetkinds.insert(1);
            }
            else if(temp[j] >= 'a' && temp[j] <= 'z')
            {
                charSetkinds.insert(2);
            }
            else if(temp[j] >= 'A' && temp[j] <= 'Z')
            {
                charSetkinds.insert(3);
            }
            else if((temp[j] >= '!' && temp[j] <= '/') ||
                    (temp[j] >= ':' && temp[j] <= '?') ||
                    temp[j] == '{' || temp[j] == '}' ||
                    (temp[j] >= '[' && temp[j]<='_'))
            {
                charSetkinds.insert(4);
            }

        }
        if(charSetkinds.size() < 4)
        {
           //cout << "tag2" << endl;
            weak_tag[i] = true;//是弱密码,输出应为no
            continue;
        }
        //3/4.存在连续三个字母或等差数列
        for(int j = 0 ; j < len - 2 && !weak_tag[i] ; ++j)
        {
            if(isalpha(temp[j])&&isalpha(temp[j+1])
               &&isalpha(temp[j+2]))
            {
                if(temp[j]+1 == temp[j+1] &&
                   temp[j+1] + 1== temp[j+2])
                {
                   //cout << "tag3" << endl;
                    weak_tag[i] = true;//是弱密码,输出应为no
                    continue;
                }
            }
            else if(isdigit(temp[j]) && isdigit(temp[j+1])
                    && isdigit(temp[j+2]) && !weak_tag[i])
                    {
                        int diff = temp[j+1] - temp[j];
                        if(diff == temp[j+2] - temp[j+1])
                        {
                           //cout << "tag4" << endl;
                            weak_tag[i] = true;//是弱密码,输出应为no
                            continue;
                        }
                    }
        }
        //5.不包含常用密码
        for(int j = 0 ; j < al_size  && !weak_tag[i] ; ++j)
        {
            if(temp.find(alwaysUse[j]) != -1)
            {
               //cout << "tag5" << endl;
                weak_tag[i] = true;//是弱密码,输出应为no
                continue;
            }
        }


    }
    for(int i = 0 ; i < times ; ++i)
    {
        if(weak_tag[i])
        {
            cout << "no"<<endl;
        }
        else
        {
            cout << "yes" <<endl;
        }
    }
    return 0;
}

//By Ghostxiu 2018/8/11
//http://x.wolfmark.org
