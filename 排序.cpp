#include<bits/stdc++.h>
#define MAX 100
using namespace std;
static	int a[MAX];
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


void merge(int a[], int start, int mid, int end)
{
    int *tmp = (int *)malloc((end-start+1)*sizeof(int));    // tmp是汇总2个有序区的临时区域
    int i = start;            // 第1个有序区的索引
    int j = mid + 1;        // 第2个有序区的索引
    int k = 0;                // 临时区域的索引

    while(i <= mid && j <= end)
    {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }

    while(i <= mid)
        tmp[k++] = a[i++];

    while(j <= end)
        tmp[k++] = a[j++];

    // 将排序后的元素，全部都整合到数组a中。
    for (i = 0; i < k; i++)
        a[start + i] = tmp[i];

    free(tmp);
}


/*
 * 对数组a做若干次合并：数组a的总长度为len，将它分为若干个长度为gap的子数组；
 *             将"每2个相邻的子数组" 进行合并排序。
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     len -- 数组的长度
 *     gap -- 子数组的长度
 */
void merge_groups(int a[], int len, int gap)
{
    int i;
    int twolen = 2 * gap;    // 两个相邻的子数组的长度

    // 将"每2个相邻的子数组" 进行合并排序。
    for(i = 1; i+2*gap-1 <=len; i+=(2*gap))
    {
        merge(a, i, i+gap-1, i+2*gap-1);
    }

    // 若 i+gap-1 < len-1，则剩余一个子数组没有配对。
    // 将该子数组合并到已排序的数组中。
    if ( i+gap-1 <=len-1)
    {
        merge(a, i, i + gap - 1, len - 1);
    }
}

/*
 * 归并排序(从下往上)
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     len -- 数组的长度
 */
void merge_sort(int a[], int len)
{
    int n;

    if (a==NULL || len<=0)
        return ;

    for(n = 1; n <= len; n*=2)
        merge_groups(a, len, n);
}

void HeapAdjust(int a[],int s,int m)
{
	int j;
	a[0]=a[s];
	for (j=2*s;j<=m;j=j*2)
	{ 
		if(j<m&&a[j]< a[j+1])
			++j;
		if(a[0]>=a[j])
			break;
			
		
		a[s]=a[j];
		s=j;
	}
	a[s]=a[0];
}

void duiPaixu(int a[],int first,int mid,int n)//先构建一个大顶堆 
{
	int i,j,k;
	for(i=mid;i>0;i--)
		HeapAdjust(a,i,n);
	for(i=n;i>1;--i) //n-1趟堆排序
	{
		swap(a[i],a[1]);
		HeapAdjust(a,1,i-1);
	}
}
//
//8 25 56 49 78 11 65 41 36


int main()//sqList??不存在的，lenth直接拿n存了 
{/*--------------数组下标从1开始，0留给哨兵项---------------*/
	int i,j,k,n;
	srand((unsigned)time(NULL)); 
	printf("请输入数组长度：");
	scanf("%d",&n);
	a[0]=0;
	for(i=1;i<=n;i++)
	{
		//a[i]=rand()%100;
		scanf("%d",&a[i]);
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
	//merge_sort(a,n);//归并排序，我抄的，好像会出错，等会看。
	duiPaixu(a,1,n/2,n);//堆排序  
	read(a,n);
	return 0;
}
