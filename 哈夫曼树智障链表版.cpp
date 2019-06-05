#include<bits/stdc++.h>
#define MAX 100
using namespace std;
typedef struct Node{
	int data;
	Node *lc,*rc;
}*Tree;
typedef struct Node2{
	Tree data;
	Node2 *next; 
}*Link;
typedef struct Node3{
	int data;
	Tree next; 
}*Link2;
Link creat()
{
	Link L;
	L=(Link)malloc(sizeof(Node2));
	L->next=NULL;
	while(1)
	{
		int a;
		scanf("%d",&a);
		if(a!=0)
		{
			Tree t;
			t=(Tree)malloc(sizeof(Node));
			t->data=a;
			
			Link temp;
			temp=(Link)malloc(sizeof(Node2));
			temp->data=t;
			temp->next=L->next;
			L->next=temp;	
		}else{break;}
	}
	return L;
}
int read(Link L)
{
	int m=0;
	Link temp;
	temp=L->next;
	while(true)
	{	
		printf("%d ",temp->data->data);
		if(temp->next==NULL)
			break;	
		temp=temp->next;
		m++;
	}
	cout<<endl;
	return m;
}
void xxbl(Tree T)
{
	if(T!=NULL){
		printf("%d",T->data);
		xxbl(T->lc);
		xxbl(T->rc);
	}
	else{return;}
}
int main()
{
	Link all; 
	int i,j,m,n;
	printf("请输入元素，以0结尾:\n");
	Link L=creat();
	m=read(L);
	Tree Max;
	Max=(Tree )malloc(sizeof(Node));
	Max->data=0x3f3f3f;
	Tree root;
	while(m!=0)
	{
		Link2 min;
		Link2 min_bigger;
		min=(Link2)malloc(sizeof(Node3));
		min_bigger=(Link2)malloc(sizeof(Node3));
		min->data=0x3f3f3f;
		min_bigger->data=0x3f3f3f;
		
		Link temp_min;
		temp_min=L->next;
		
		while(true)
		{
			if(temp_min->data->data<min->data)
			{
				min->next=temp_min->data;
				min->data=temp_min->data->data;
			}
			if(temp_min->next==NULL)
				break;
			temp_min=temp_min->next;
		}
		
		temp_min=L->next;
		while(true)
		{
			if(temp_min->data->data<min_bigger->data&&temp_min->data->data>=min->data&&temp_min->data!=min->next)
			{
				min_bigger->next=temp_min->data;
				min_bigger->data=temp_min->data->data;
			}
			if(temp_min->next==NULL)
				break;	
			temp_min=temp_min->next;
		}//找最小和第二小 
		cout<<min->next->data<<" "<<min_bigger->next->data<<endl;

		if(min->next->data>0x3f3f3f||min_bigger->next->data>0x3f3f3f)
			break;

		Tree temproot=(Tree)malloc(sizeof(Node));
		temproot->lc=min->next;
		temproot->rc=min_bigger->next;
		temproot->data=min->next->data+min_bigger->next->data;
		root=temproot;
		
		Link temp=L->next;
		while(true)
		{	
			if(temp->data==min->next)
			{
				temp->data=Max;
			}	
			if(temp->data==min_bigger->next)
			{
				temp->data=temproot;
			}
			if(temp->next==NULL)
				break;	
			temp=temp->next;
		}
		m--;
	}
	return 0;
}
