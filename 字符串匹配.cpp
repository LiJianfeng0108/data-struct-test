#include<iostream.h>
#include<Stdio.h>
#include<Conio.h>
#include<Stdlib.h>

#define MAXSIZE 255
typedef unsigned char SString[MAXSIZE+1];

void get_nextval(SString T,int nextval[]);

//�����ַ���
void CreateString(SString s){
	char ch=0;
	int i=0;
	static int n=1;
	cout<<"�������ַ���"<<n<<endl;
	n++;
	while(ch!=10)//���з�ASCII��
	{
		ch=s[++i]=getchar();
	}
	s[0]=i-1;//�����±�Ϊ0�Ĵ��S�ĳ���,��ȥ���Ļ��з�

}

//BF�㷨
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
            i=i-j+2;//����ָ����ݵ��ոձȽϵ��¸�λ��
            j=1;//ģʽ��ָ���������һλ
        }
    }
    if(j>t[0])
        return i-t[0];
    else
        return 0;
}

//KMP�㷨
int Index_KMP(SString S,SString T,int pos)
{
	//����ģʽ��T��next������T������S�е�pos���ַ�֮���λ��
	int i = pos,j = 1;
	int next[512];
	get_nextval(T,next);//���next����
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
	//��ģʽ��T��next��������ֵ����������nextval
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
	//a=Index(s,t,0);//����BF�㷨
	a = Index_KMP(s,t,0);

    if(a)
		cout<<"��"<<a<<"���ַ���ʼƥ��\n";
     else
        cout<<"2�в�����1�������ִ�\n";
}