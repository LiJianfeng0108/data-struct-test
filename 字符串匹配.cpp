#include<iostream.h>
#include<Stdio.h>
#include<Conio.h>
#include<Stdlib.h>

#define MAXSIZE 255
typedef unsigned char SString[MAXSIZE+1];

void get_nextval(SString T,int nextval[]);

//输入字符串
void CreateString(SString s){
	char ch=0;
	int i=0;
	static int n=1;
	cout<<"请输入字符串"<<n<<endl;
	n++;
	while(ch!=10)//换行符ASCII码
	{
		ch=s[++i]=getchar();
	}
	s[0]=i-1;//数组下标为0的存放S的长度,除去最后的换行符

}

//BF算法
int Index(SString s,SString t,int pos){
    int i=pos,j=1;
    while(i<=s[0]&&j<=t[0])
    {
        if(s[i]==t[j])
        {
            i++;j++;
        }
        else
        {
            i=i-j+2;//主串指针回溯到刚刚比较的下个位子
            j=1;//模式串指针回溯至第一位
        }
    }
    if(j>t[0])
        return i-t[0];
    else
        return 0;
}

//KMP算法
int Index_KMP(SString S,SString T,int pos)
{
	//利用模式串T的next函数求T在主串S中第pos个字符之后的位置
	int i = pos,j = 1;
	int next[512];
	get_nextval(T,next);//获得next数组
	while(i <=S[0] && j<=T[0])
	{
		if(j == 0 || S[i] == T[j])
		{
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if(j > T[0])
		return i - T[0];
	else
		return 0;
}

void get_nextval(SString T,int nextval[])
{
	//求模式串T的next函数修正值并存入数组nextval
	int i = 1,j = 0;
	nextval[1] = 0;
	while(i < T[0])
	{
		if(j==0 || T[i] == T[j])
		{
			++i;
			++j;
			if(T[i] != T[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	}
}

void main()
{
	
	SString s,t;
	CreateString(s);
	CreateString(t);

	int a=0;
	//a=Index(s,t,0);//调用BF算法
	a = Index_KMP(s,t,0);

    if(a)
		cout<<"第"<<a<<"个字符开始匹配\n";
     else
        cout<<"2中不存在1这样的字串\n";
}