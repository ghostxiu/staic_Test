//�ַ����Ľ�ѹ�� ���׻������ԡ���������
//by 1A 2018/8/15 ʹ��ջ����
//�յ�ѹ������ַ�����"A2BC3"����"AABCCC"
//"A2A2BC3"����"AAAABCCC"
//���������ţ���"F(ABC)2C"����"FABCABCC"
//"F(AB(A2C2)3)2D"����"FABAACCAACCAACCABAACCAACCAACCD"
//���ڸ�������Ϊѹ��ǰ���ַ��������Ϊѹ������ַ���
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
