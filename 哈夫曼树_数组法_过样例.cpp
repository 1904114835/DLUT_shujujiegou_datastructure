#include<bits/stdc++.h>
#define MAX 100
using namespace std;
struct node{
	int weight=0;
	int parent=0;
	int rc=0;
	int lc=0;
	int flag=0;
};
int main()
{
	node all[MAX];
	int i,j,m,n;
	printf("请输入元素个数n: ");
	scanf("%d",&n);
	m=n;
	for(i=1;i<=n;i++)
		{
			scanf("%d",&all[i].weight);
			all[i].flag=1;
		}
	all[MAX-1].weight=0x3f3f3f;
	while(m!=0)
	{
		int minp=MAX-1,minp_b=MAX-1;
		for(i=1;i<2*n;i++)
		{
			if(all[i].flag==1&&all[i].weight<all[minp].weight)
				minp=i;
		}
		for(i=1;i<2*n;i++)
		{
			if(all[i].flag==1&&all[i].weight<all[minp_b].weight&&i!=minp)
				minp_b=i;
		}
		
		if(all[minp_b].weight==0x3f3f3f||all[minp].weight==0x3f3f3f)
			break;
	
		n++;
		
		all[minp].flag=0;
		all[minp_b].flag=0;

		all[n].weight=all[minp].weight+all[minp_b].weight;
		all[n].flag=1;
		
		all[n].lc=minp;
		all[n].rc=minp_b;
		
		all[minp].parent=n;
		all[minp_b].parent=n;
		
				
	//	cout<<all[minp_b].weight<<" "<<all[minp].weight<<endl;
		m--;
		
		
	/*	for(j=1;j<=n;j++)
		{
			cout<<all[j].weight <<" "<<all[j].parent <<" "<<all[j].lc <<" "<<all[j].rc <<endl;
		}*/
	}
	
	for(j=1;j<=n;j++)
	{
		cout<<all[j].weight <<" "<<all[j].parent <<" "<<all[j].lc <<" "<<all[j].rc <<endl;
	}
	return 0;
}
