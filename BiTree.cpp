#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode
{
	char data;
	struct BiTNode *LChild,*RChild;
}BiTNode,*BiTree;

int CreateBiTree(BiTree &T);
int DLR(BiTree &T);
int LDR(BiTree &T);
int LRD(BiTree &T);
int LevelTravelBiTree(BiTree &T);
int Depth(BiTree T);
int Visit(BiTree T,int& count);

void main()
{
	int count=0;
	BiTree T;

	cout<<"��һ������һ���ַ���س�����'~'����"<<endl;
	cout<<"�������"<<endl;
	CreateBiTree(T);

	cout<<"��������������ǣ�"<<endl;
	DLR(T);
	cout<<endl;
	cout<<"��������������ǣ�"<<endl;
	LDR(T);
	cout<<endl;
	cout<<"��������������ǣ�"<<endl;
	LRD(T);
	cout<<endl;
	cout<<"��α����������ǣ�"<<endl;
	LevelTravelBiTree(T);
	cout<<endl;
	
	int depth = Depth(T);
	cout<<"����ȣ�"<<depth<<endl;
	
	count=0;
	cout<<"Ҷ�ӽ���У�"<<endl;
	Visit(T,count);
	cout<<endl<<"Ҷ�ӽ������"<<count<<endl;
	
	
}
//��������
int CreateBiTree(BiTree &T)
{
	char ch;
	
	cin>>ch;
	if(ch=='~') T=NULL;
	else{
		if(!(T=(BiTNode *)malloc(sizeof(BiTNode)))) exit(0);
		T->data = ch;
		cout<<"������"<<T->data<<"������"<<endl;
		CreateBiTree(T->LChild);
		cout<<"������"<<T->data<<"���Һ���"<<endl;
		CreateBiTree(T->RChild);
	}
	return 1;
}
//�������
int DLR(BiTree &T)
{
	if(T!=NULL){
		cout<<T->data;
		DLR(T->LChild);
		DLR(T->RChild);
	}
	return 1;
}
//�������
int LDR(BiTree &T)
{
	if(T!=NULL){
		
		LDR(T->LChild);
	  	cout<<T->data;
		LDR(T->RChild);
	}
	return 1;
}
//�������
int LRD(BiTree &T)
{
	if(T!=NULL){
		
		LRD(T->LChild);
		LRD(T->RChild);
		cout<<T->data;
	}
	return 1;
}
//��α���
int LevelTravelBiTree(BiTree &T)
{
	BiTNode* Q[100];//���費���
	int front=-1,rear=-1;
	if (T)
	{
		Q[++rear] = T;
		cout<<T->data;
		while (front!=rear)
		{
			BiTNode* p;
			if (!(p=(BiTNode*)malloc(sizeof(BiTNode))))
				exit(0);
			p = Q[++front];
			if (p->LChild)
			{
				Q[++rear] = p->LChild;
				cout<<p->LChild->data;
                         }
			if (p->RChild)
			{
				Q[++rear] = p->RChild;
				cout<<p->RChild->data;
			}
		}
	}
	return 1;
}

//���������,�ݹ鷨
int Depth(BiTree T)
{
	if (!T)
		return 0;
	else
	{
		int a=Depth(T->LChild)+1;
		int b=Depth(T->RChild)+1;
		return a>b?a:b;
	}
}
//ͳ��Ҷ�ӽ�������������ӵ�Ԫ��
int Visit(BiTree T,int& count)
{
	if(T!=NULL){
		if((T->LChild==NULL)&&(T->RChild==NULL))
		{
			count++;
			cout<<T->data;
		}
		Visit(T->LChild,count);
	  	
		Visit(T->RChild,count);
	}
	
	return 1;
	
	
}
