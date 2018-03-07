#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>
//单链表存储结构
typedef struct Node{
	int data;
	struct Node *next;
}node,*Linklist;


//创建单链表
void CreateList(Linklist &L, int n){
	L=(Linklist)malloc(sizeof(Node));
	L->next=NULL;
	cout<<"输入相应个数的数字："<<endl;
	for(int i=n;i>0;i--){
		Linklist p = (Linklist)malloc(sizeof(Node));
		cin>>p->data;
		p->next=L->next;
		L->next=p;
	}
}

//获取i位元素
int GetElem(Linklist &L,int n){
	
	Linklist p = L;
	int i = 0;
	while(i!=n){
		if(p->next==NULL){
			return -1;
		}
		p = p->next;
		i++;
	}
	return p->data;
	
}

//改变第i位元素
void ChangeElem(Linklist &L,int n){
	
	Linklist p = L;
	int i = 0;
	while(i!=n){
		if(p->next==NULL){
			puts("Error");
		}
		p = p->next;
		i++;
	}
	cout<<"改为："<<endl;
	cin>>p->data;
	
}

//删除第i位元素
void DeleteElem(Linklist &L,int n){
	
	Linklist p = L;
	int i = 0;
	while((i+1)!=n){
		if(p->next==NULL){
			puts("Error");
		}
		p = p->next;
		i++;
		
		
	}
	
	p->next=p->next->next;
	cout<<"删除后";
}

//第i位元素插入新元素
void InsertElem(Linklist &L,int n){
	
	Linklist p = L;
	int i = 0;
	while((i+1)!=n){
		if(p->next==NULL){
			puts("Error");
		}
		p = p->next;
		i++;
		
		
	}
	cout<<"添加的新元素是："<<endl;
	Linklist p2 = (Linklist)malloc(sizeof(Node));
	cin>>p2->data;
	p2->next=p->next;
	p->next=p2;
	cout<<"添加后";
	
}


//单链表合并
void MergeList(Linklist &La,Linklist &Lb,Linklist &Lc){
	Linklist pa=new Node;
	Linklist pb=new Node;
	Linklist pc=new Node;
	pa=La->next;
	pb=Lb->next;
	Lc=pc=pa;
	while(pa&&pb)
	{
		if(pa->data<=pb->data){
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else
		{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
	}
		pc->next=pa?pa:pb;
		delete(Lb);

}

//输出
void Display(Linklist &L, int n){
	Linklist p = L->next;
	cout<<"它们是："<<endl;
	while(p)
	{
		cout<<p->data<<endl;
		p=p->next;
	}
}

void main(){
	
	int n=0;
	cout<<"输入个数："<<endl;
	cin>>n;

	Linklist L;
	CreateList(L,n);
	Display(L,n);
	
	//查找
	int e;
	//cout<<"删除上述第几位元素？"<<endl;
	//cout<<"添加新元素到上述第几位？"<<endl;
	cout<<"查找上述第几位元素？"<<endl;
	int n2=0;
	cin>>n2;
	e = GetElem(L,n2);
	if(e==-1){
		cout<<"Error"<<endl;}
	else{
		cout<<"它是："<<endl<<e<<endl;

		//修改
		ChangeElem(L,n2);
		Display(L,n);

		//删除	
		//DeleteElem(L,n2);
		//Display(L,n-1);

		//插入
		//InsertElem(L,n2);
		//Display(L,n+1);
	}
	//其它提示
	cout<<"其他操作请调用相关函数！"<<endl;
}