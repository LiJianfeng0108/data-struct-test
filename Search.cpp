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

	cout<<"输入查找元素："<<endl;
	int key;
	cin>>key;
	
	//顺序查找	
	int sp;
	sp=searchSeq(st,key);
	cout<<"在第"<<sp<<"位置(顺序查找,若在0位置,则不存在该元素)"<<endl;
	
	//折半查找
	sp=searchBin(st,key);
	cout<<"在第"<<sp<<"位置(折半查找,若在0位置,则不存在该元素)"<<endl;

	
}