#include<bits/stdc++.h>
#define MAX 100
using namespace std;


struct Stack{
	int data[MAX];
	int top;
};

void read(int a[],int n)
{
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}	


void maoPao(int a[],int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);
		}
	}
}

void zjChaRu(int a[],int n)
{
	int i,j;
	for(i=2;i<=n;i++)
	{
		a[0]=a[i];
	//	cout<<a[0]<<endl;
		j=i;
		while(j)
		{	
			a[j]=a[j-1];
			if(a[j-1]<=a[0])
			{
				a[j]=a[0];
				break;
			}
			j--;
		}
	//read(a,n);
	}
}

void xiEr(int a[],int n)
{
	int i,j,k;
	int xier[3]={4,2,1};
	for( k=0;k<3;k++)
	{
		int d=xier[k];
		for (i=d+1;i<=n;i++)
		{
			if(a[i] <a[i-d] )
			{
				a[0]=a[i];a[i]=a[i-d];
				for(j=i-2*d;j>0&&(a[0] <a[j] );j=j-d )
					a[j+d]=a[j];
				a[j+d]=a[0];
			}
		}
	}
}

void kuaiPai(int a[],int l,int r)
{
	int n=r;
	if(l>r)
		return;
	a[0]=a[l];
	while(r>l)
	{
		while(a[r]>=a[0]&&l<r)
			r--;
		a[l]=a[r];
		while(a[l]<=a[0]&&l<r)
			l++;
		a[r]=a[l];
	}
	a[l]=a[0];
	kuaiPai(a,1,r-1);
	kuaiPai(a,r+1,n);
}
void kuaiPai_one_direct(int a[], int left, int right) {
	if(left>=right)
		return ;
    int x = a[right];
    int p = left - 1;
    for (int i = left; i < right; i++) {
        if (a[i] <= x) {
            p++;
            swap(a[p],a[i]);
        }
    }
    swap(a[p+1],a[right]);
    p++;
    kuaiPai_one_direct(a, left, p - 1);
    kuaiPai_one_direct(a, p + 1, right);
}

//快速排序数组划分

void jdXuanze(int a[],int n)
{
	a[0]=0x3f3f3f;
	int i,j,min;
	for(i=1;i<=n;i++)
	{
		min=0;
		for(j=i;j<=n;j++)
		{
			if(a[j]<=a[min])
				min=j;
		}
		swap(a[i],a[min]);
	}
}

void jsPaixu(int a[],int n)
{	
	Stack temp[10];
	int i,j,k=0,max=0,tong;
	for(i=1;i<n;i++)
		if(a[i]>max)
			max=a[i];
	while(true)
	{	
		int qumo=pow(10,k);
		if(max/qumo==0)break;
		for(int temp_top_init=0;temp_top_init<=9;temp_top_init++)
			temp[temp_top_init].top=-1;

		for(i=1;i<=n;i++)
		{
			tong=(int)( a[i]/qumo )%10;
			//printf("%d",tong);
			//system("pause");
			temp[tong].data[++temp[tong].top]=a[i];
		}
		/*
		for(int s_t=0;s_t<=9;s_t++)
		{
			for(int s_i=0;s_i<=temp[s_t].top;s_i++)
				printf("%d ",temp[s_t].data[s_i]);
		}
		printf("\n");
		*/
		j=1;
		for(tong=0;tong<10;tong++)
		{
			int len=temp[tong].top;
			while(temp[tong].top!=-1 )
			{
				a[j]=temp[tong].data[len-temp[tong].top];
				j++;
				temp[tong].top--;
			}
		}
		//printf("\n------------\n");
		k++;
	}
}

void duiPaixu(int a[],int n)
{
	
	
}
int main()//sqList??不存在的，lenth直接拿n存了 
{/*--------------数组下标从1开始，0留给哨兵项---------------*/
	int a[MAX];
	int i,j,k,n;
	srand((unsigned)time(NULL)); 
	printf("请输入数组长度：");
	scanf("%d",&n);
	a[0]=0;
	for(i=1;i<=n;i++)
	{
		a[i]=rand()%100;
		//scanf("%d",&a[i]);
	}
	read(a,n);
	printf("\n\n");
	//maoPao(a,n);//冒泡
	//zjChaRu(a,n);//直接插入
	//xiEr(a,n);//希尔
	//kuaiPai(a,1,n);//快排（教材版） 
	//kuaiPai_one_direct(a,1,n);//快排（算法导论版） 
	//jdXuanze(a,n);//简单选择
	//jsPaixu(a,n);//基数排序
	duiPaixu(a,n);//堆排序 
	read(a,n);
	return 0;
}
