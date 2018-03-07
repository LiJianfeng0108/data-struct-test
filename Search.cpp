#include<iostream.h>
#include<stdlib.h>
typedef struct
{
	int *elem;
	int length;
}SSTable;

void initList(SSTable &s)
{
	s.elem = (int *)malloc(s.length*sizeof(int));
	if(!s.elem) exit(0);
	
}

void inputList(SSTable &s)
{
	for(int i=1;i<=s.length;i++){
		cin>>s.elem[i];
	}	
}

void outputList(SSTable &s)
{
	for(int i=1;i<=s.length;i++)
	{
		cout<<s.elem[i]<<endl;
	}	
}

//˳������
int searchSeq(SSTable &st,int key)
{
	st.elem[0]=key;
	for(int i=st.length;i>0;--i)
	{
		if(key==st.elem[i])
		{
			return i;
		}
	}
	return 0;
}
//�۰����
int searchBin(SSTable &st,int key)
{
	int low=1;
	int high=st.length;
	int mid;
	while(low<=high)
	{
		//����
		mid = (low+high)/2;
		//�ƽ�ָ�
		//mid = low+(high-low)*0.618;
		if(st.elem[mid]==key){return mid;}
		else if(st.elem[mid]>key){high = mid-1;}
		else{low = mid+1;}
		
	}
	return 0;
}

void main()
{
	SSTable st;
	
	cout<<"�������鳤�ȣ�"<<endl;
	cin>>st.length;
	initList(st);
	cout<<"������Ӧ����������(�������۰���ң�������ǵݼ�����)��"<<endl;
	inputList(st);
	cout<<"�����ǣ�"<<endl;
	outputList(st);

	cout<<"�������Ԫ�أ�"<<endl;
	int key;
	cin>>key;
	
	//˳�����	
	int sp;
	sp=searchSeq(st,key);
	cout<<"�ڵ�"<<sp<<"λ��(˳�����,����0λ��,�򲻴��ڸ�Ԫ��)"<<endl;
	
	//�۰����
	sp=searchBin(st,key);
	cout<<"�ڵ�"<<sp<<"λ��(�۰����,����0λ��,�򲻴��ڸ�Ԫ��)"<<endl;

	
}