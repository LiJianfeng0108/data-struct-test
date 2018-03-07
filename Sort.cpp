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

//顺序表查找
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
//折半查找
int searchBin(SSTable &st,int key)
{
	int low=1;
	int high=st.length;
	int mid;
	while(low<=high)
	{
		//二分
		mid = (low+high)/2;
		//黄金分割
		//mid = low+(high-low)*0.618;
		if(st.elem[mid]==key){return mid;}
		else if(st.elem[mid]>key){high = mid-1;}
		else{low = mid+1;}
		
	}
	return 0;
}

//折半插入排序
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

//快速排序
//一趟快速排序
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
//递归
void QSort(SSTable &st, int low, int high)
{
	if(low<high)
	{
		int pivotloc=Partition(st,low,high);
		QSort(st,low,pivotloc-1);
		QSort(st,pivotloc+1,high);
	}
}
//main函数调用
void quickSort(SSTable &st)
{
	int low=1;
	int high=st.length;
	QSort(st, low, high);
}


void main()
{
	SSTable st;
	
	cout<<"输入数组长度："<<endl;
	cin>>st.length;
	initList(st);
	cout<<"输入相应个数的整数(若调用折半查找，需输入非递减数组)："<<endl;
	inputList(st);
	cout<<"他们是："<<endl;
	outputList(st);

	//cout<<"输入查找元素："<<endl;
	//int key;
	//cin>>key;
	
	//顺序查找	
	//int sp;
	//sp=searchSeq(st,key);
	//cout<<"在第"<<sp<<"位置(顺序查找,若在0位置,则不存在该元素)"<<endl;
	
	//折半查找
	//sp=searchBin(st,key);
	//cout<<"在第"<<sp<<"位置(折半查找,若在0位置,则不存在该元素)"<<endl;
	
	cout<<endl;

	//折半插入排序
	BInsertSort(st);
	cout<<"折半插入排序后是："<<endl;
	outputList(st);

	cout<<endl;

	//快速排序	
	quickSort(st);
	cout<<"快速排序后是："<<endl;
	outputList(st);

	cout<<endl;
}