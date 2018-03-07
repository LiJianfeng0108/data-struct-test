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

	cout<<"请一次输入一个字符后回车，以'~'结束"<<endl;
	cout<<"请输入根"<<endl;
	CreateBiTree(T);

	cout<<"先序遍历，它们是："<<endl;
	DLR(T);
	cout<<endl;
	cout<<"中序遍历，它们是："<<endl;
	LDR(T);
	cout<<endl;
	cout<<"后序遍历，它们是："<<endl;
	LRD(T);
	cout<<endl;
	cout<<"层次遍历，它们是："<<endl;
	LevelTravelBiTree(T);
	cout<<endl;
	
	int depth = Depth(T);
	cout<<"树深度："<<depth<<endl;
	
	count=0;
	cout<<"叶子结点有："<<endl;
	Visit(T,count);
	cout<<endl<<"叶子结点数："<<count<<endl;
	
	
}
//先序生成
int CreateBiTree(BiTree &T)
{
	char ch;
	
	cin>>ch;
	if(ch=='~') T=NULL;
	else{
		if(!(T=(BiTNode *)malloc(sizeof(BiTNode)))) exit(0);
		T->data = ch;
		cout<<"请输入"<<T->data<<"的左孩子"<<endl;
		CreateBiTree(T->LChild);
		cout<<"请输入"<<T->data<<"的右孩子"<<endl;
		CreateBiTree(T->RChild);
	}
	return 1;
}
//先序遍历
int DLR(BiTree &T)
{
	if(T!=NULL){
		cout<<T->data;
		DLR(T->LChild);
		DLR(T->RChild);
	}
	return 1;
}
//中序遍历
int LDR(BiTree &T)
{
	if(T!=NULL){
		
		LDR(T->LChild);
	  	cout<<T->data;
		LDR(T->RChild);
	}
	return 1;
}
//后序遍历
int LRD(BiTree &T)
{
	if(T!=NULL){
		
		LRD(T->LChild);
		LRD(T->RChild);
		cout<<T->data;
	}
	return 1;
}
//层次遍历
int LevelTravelBiTree(BiTree &T)
{
	BiTNode* Q[100];//假设不溢出
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

//求树的深度,递归法
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
//统计叶子结点个数，并输出接点元素
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
