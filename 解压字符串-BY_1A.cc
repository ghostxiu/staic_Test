//字符串的解压缩 网易互娱面试——笔试题
//by 1A 2018/8/15 使用栈来做
//收到压缩后的字符串如"A2BC3"代表"AABCCC"
//"A2A2BC3"代表"AAAABCCC"
//若存在括号，如"F(ABC)2C"代表"FABCABCC"
//"F(AB(A2C2)3)2D"代表"FABAACCAACCAACCABAACCAACCAACCD"
//现在给出输入为压缩前的字符串，输出为压缩后的字符串
#include<bits/stdc++.h>
using namespace std;



pair<int,string> fun(const string&str,int n,int i){
    string ans,c;
    for(;i<n;++i){
        if(str[i]=='(')
        {
            pair<int,string>tmp=fun(str,n,i+1);
            int j=tmp.first,num=0;
            while(isdigit((str[j])))
            {
                num=num*10+str[j]-'0';
                ++j;
            }
            i=j-1;
            while(num--){ans+=tmp.second;}
        }
        else if(str[i]==')'){
            return make_pair(i+1,ans);
        }
        else if(isdigit(str[i])){
            int j=i,num=0;
            while(isdigit((str[j]))){
                num=num*10+str[j]-'0';
                ++j;
            }
            i=j-1;
            while(num>1){ans+=c;--num;}
        }
        else{
            c=str[i];
            ans+=c;
        }
    }
}

string decompress(const string &str){
    int n=str.length();
    string ans;
    string c;
    for(int i=0;i<n;++i)
    {
        if(str[i]=='(')
        {
            pair<int,string>tmp=fun(str,n,i+1);
            int j=tmp.first,num=0;
            while(isdigit((str[j])))
            {

                num=num*10+str[j]-'0';
                ++j;
            }
            i=j-1;
            cout<<tmp.second<<' '<<num<<endl;
            while(num--){ans+=tmp.second;}
        }
        else if(isdigit(str[i]))
        {
            int j=i,num=0;
            while(isdigit((str[j])))
            {
                num=num*10+str[j]-'0';
                ++j;
            }
            i=j-1;
            while(num>1){ans+=c;--num;}
        }
        else
        {
            c=str[i];
            ans+=c;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    freopen("str.txt","r",stdin);
    string str;
    while(cin>>str)
    {
        cout<<str<<endl;
        cout<<decompress(str)<<endl;
    }
    return 0;
}
