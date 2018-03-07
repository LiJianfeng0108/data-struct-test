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
		cout<<s.elem[i]<<" ";
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

//�۰��������
void BInsertSort(SSTable &st)
{
	for(int i=2;i<=st.length;i++)
	{
		st.elem[0]=st.elem[i];
		int low=1;
		int high=i-1;
		while(low<=high)
		{
			int mid=(high+low)/2;
			if(st.elem[0]>st.elem[mid])
				low=mid+1;
			else high=mid-1;
		}
		for(int j=i-1;j>=high+1;--j)
			st.elem[j+1]=st.elem[j];
		st.elem[high+1]=st.elem[0];

	}
}

//��������
//һ�˿�������
int Partition(SSTable &st,int low, int high)
{
	st.elem[0]=st.elem[low];
	int pivotkey=st.elem[low];
	while(low<high)
	{
		while(low<high&&st.elem[high]>=pivotkey) high--;
		st.elem[low]=st.elem[high];
		while(low<high&&st.elem[low]<=pivotkey) low++;
		st.elem[high]=st.elem[low];	
	}
	st.elem[low]=st.elem[0];
	return low;
}
//�ݹ�
void QSort(SSTable &st, int low, int high)
{
	if(low<high)
	{
		int pivotloc=Partition(st,low,high);
		QSort(st,low,pivotloc-1);
		QSort(st,pivotloc+1,high);
	}
}
//main��������
void quickSort(SSTable &st)
{
	int low=1;
	int high=st.length;
	QSort(st, low, high);
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

	//cout<<"�������Ԫ�أ�"<<endl;
	//int key;
	//cin>>key;
	
	//˳�����	
	//int sp;
	//sp=searchSeq(st,key);
	//cout<<"�ڵ�"<<sp<<"λ��(˳�����,����0λ��,�򲻴��ڸ�Ԫ��)"<<endl;
	
	//�۰����
	//sp=searchBin(st,key);
	//cout<<"�ڵ�"<<sp<<"λ��(�۰����,����0λ��,�򲻴��ڸ�Ԫ��)"<<endl;
	
	cout<<endl;

	//�۰��������
	BInsertSort(st);
	cout<<"�۰����������ǣ�"<<endl;
	outputList(st);

	cout<<endl;

	//��������	
	quickSort(st);
	cout<<"����������ǣ�"<<endl;
	outputList(st);

	cout<<endl;
}