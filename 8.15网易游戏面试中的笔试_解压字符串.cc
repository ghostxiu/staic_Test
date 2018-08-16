//字符串的解压缩 网易互娱面试——笔试题
//by Ghostxiu 2018/8/15 使用递归
//收到压缩后的字符串如"A2BC3"代表"AABCCC"
//"A2A2BC3"代表"AAAABCCC"
//若存在括号，如"F(ABC)2C"代表"FABCABCC"
//"F(AB(A2C2)3)2D"代表"FABAACCAACCAACCABAACCAACCAACCD"
//现在给出输入为压缩前的字符串，输出为压缩后的字符串

#include<bits/stdc++.h>

using namespace std ;
string inputStr;
string DeCompressStr(const string & inputStr);//解压字符串
void CopyStr(string & outStr,const string & str, int times);
//将字符串按次数复制进outputStr
void CopyStr(string & outStr,const char & str, int times);
//将字符按次数复制进outputStr，重载版本
int OtherCaculate(const string & inputStr ,int tag ,
                  string & outputStr, int tmpTag);
//处理带括号的情况（递归）

//主函数
int main()
{

    ios::sync_with_stdio(0);
    freopen("str.txt","r",stdin);
	while(cin >> inputStr)
	{
	    cout << inputStr << endl;
		string outputStr = DeCompressStr(inputStr);
		cout << "->"<<endl;
		cout << outputStr << endl<<endl;
	}
	return 0 ;
}

string DeCompressStr(const string & inputStr)
{
    string outputStr ;
    int outIndex = 0 , inIndex = 0 ;
    int len = inputStr.size();
    for(;inIndex < len ; ++inIndex)
    {
         if(inputStr[inIndex] != '(')
        {
            if(isdigit(inputStr[inIndex+1]) )
            {
                int times = inputStr[++inIndex] - '0';
                CopyStr(outputStr, inputStr[inIndex-1],times);
            }
            else
            {
                outputStr += inputStr[inIndex];
            }
        }
        else
        {
            inIndex = OtherCaculate(inputStr , inIndex ,outputStr,0);
        }
    }
    return outputStr;
}

void CopyStr(string & outStr,const string & str, int times)
{
    while(times--)
    {
        outStr += str;
    }
}

void CopyStr(string & outStr, const char & str, int times)
{
    outStr.insert(outStr.end(),times,str);
}

int OtherCaculate(const string & inputStr ,int tag ,
                  string & outputStr, int tmpTag)
{
    int i ;
    string tmpStr;
    for(i = tag + 1; inputStr[i] != ')' ; ++i)
    {
        if(inputStr[i] != '(')
        {
            if(isdigit(inputStr[i+1]) )
            {
                int times = inputStr[++i] - '0' ;
                CopyStr(tmpStr,inputStr[i-1],times);
            }
            else
            {
                tmpStr += inputStr[i];
            }
        }
        else
        {

            i =  OtherCaculate(inputStr, i,tmpStr,0);
        }

    }

    int times  = inputStr[++i] - '0';
    CopyStr(outputStr,tmpStr,times) ;
    return i;
}

