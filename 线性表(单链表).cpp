#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>
//������洢�ṹ
typedef struct Node{
	int data;
	struct Node *next;
}node,*Linklist;


//����������
void CreateList(Linklist &L, int n){
	L=(Linklist)malloc(sizeof(Node));
	L->next=NULL;
	cout<<"������Ӧ���������֣�"<<endl;
	for(int i=n;i>0;i--){
		Linklist p = (Linklist)malloc(sizeof(Node));
		cin>>p->data;
		p->next=L->next;
		L->next=p;
	}
}

//��ȡiλԪ��
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

//�ı��iλԪ��
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
	cout<<"��Ϊ��"<<endl;
	cin>>p->data;
	
}

//ɾ����iλԪ��
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
	cout<<"ɾ����";
}

//��iλԪ�ز�����Ԫ��
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
	cout<<"��ӵ���Ԫ���ǣ�"<<endl;
	Linklist p2 = (Linklist)malloc(sizeof(Node));
	cin>>p2->data;
	p2->next=p->next;
	p->next=p2;
	cout<<"��Ӻ�";
	
}


//������ϲ�
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

//���
void Display(Linklist &L, int n){
	Linklist p = L->next;
	cout<<"�����ǣ�"<<endl;
	while(p)
	{
		cout<<p->data<<endl;
		p=p->next;
	}
}

void main(){
	
	int n=0;
	cout<<"���������"<<endl;
	cin>>n;

	Linklist L;
	CreateList(L,n);
	Display(L,n);
	
	//����
	int e;
	//cout<<"ɾ�������ڼ�λԪ�أ�"<<endl;
	//cout<<"�����Ԫ�ص������ڼ�λ��"<<endl;
	cout<<"���������ڼ�λԪ�أ�"<<endl;
	int n2=0;
	cin>>n2;
	e = GetElem(L,n2);
	if(e==-1){
		cout<<"Error"<<endl;}
	else{
		cout<<"���ǣ�"<<endl<<e<<endl;

		//�޸�
		ChangeElem(L,n2);
		Display(L,n);

		//ɾ��	
		//DeleteElem(L,n2);
		//Display(L,n-1);

		//����
		//InsertElem(L,n2);
		//Display(L,n+1);
	}
	//������ʾ
	cout<<"���������������غ�����"<<endl;
}