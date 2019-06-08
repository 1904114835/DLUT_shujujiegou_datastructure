#include<bits/stdc++.h>
#define MAX 200
using namespace std;
typedef struct Node{
	int data;
	Node *next; 
}*Link;

void my_swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
Link creatTcha(){
	cout<<"请输入int链表，以空格隔开，以0结尾"<<endl;
	int i=0;
	Link L;
	L=(Link)malloc(sizeof(Node));
	L->data=0;
	L->next=NULL;
	int a;
	while(++i)
	{	
		scanf("%d",&a);
		if(a!=0)
		{
			Link temp;
			temp=(Link)malloc(sizeof(Node));
			temp->data=a;
			temp->next=L->next;
			L->next=temp;
		}
		else{break;}
	}
	return L;
}


Link creatWcha(){
	cout<<"请输入int链表，以空格隔开，以0结尾"<<endl;
	int i;
	Link L;
	L=(Link)malloc(sizeof(Node));
	L->data=0;
	L->next=NULL;
	Link t;
	t=L;
	int a;
	while(++i)
	{	
		scanf("%d",&a);
		if(a!=0)
		{
			Link temp;
			temp=(Link)malloc(sizeof(Node));
			temp->data=a;
			t->next=temp;
			t=t->next;
		}
		else{
		t->next=NULL;
		break;
		}
	}
	return L;
}
void read(Link root)
{

	Node* temp;
	temp=root->next;
	while(true)
	{	
		printf("%d ",temp->data);
		if(temp->next==NULL)
			break;	
		temp=temp->next;
	}
	cout<<endl;
}
void charu(Link L){	
	cout<<"插入一个数据"<<endl; 
	int a;
	scanf("%d",&a);
	Link temp;
	temp=(Link)malloc(sizeof(Node));
	temp->data=a;
	temp->next=L->next;
	L->next=temp;
}

void sort_Link(Link L, Link end)    //将头指针为L，尾指针为end的链表进行排序
{
    if(L == NULL)
        return ;
    if(L == end)
        return ;
    Link pslow = L;
    Link pfast = L->next;
    while(pfast != end)
    {
        if(pfast->data < L->data)        //每次都选择待排序链表的头结点作为划分的基准
        {
            pslow = pslow->next;
            my_swap(&pslow->data ,& pfast->data);       //pslow指针指向比基准小的结点组成的链表
        }
        pfast = pfast->next;
    }
    my_swap(&pslow->data , &L->data);  //此时pslow指针指向比基准小的结点组成的链表的最后一个结点，也就是基准的位置，所以要与基准（head结点）交换
    sort_Link(L , pslow);             //ptemp为左右两部分分割点（基准）的前一个结点
    sort_Link(pslow->next , NULL);        //右部分是比基准大的结点组成的链表
}

void Linksort(Link L,Link end)
{
	if(L==NULL)return ;
	if(L==end)return ;
	Link l1,l2;
	l1=L;
	l2=l1->next;
	int temp;
	while(l2!=end){
		if(l2->data<L->data){
			l1=l1->next;
			temp=l2->data;
			l2->data=l1->data ;
			l1->data=temp;
		}
		l2=l2->next;
	}
			temp=l1->data;
			l1->data=L->data ;
			L->data=temp;
			
	Linksort(L,l1);
	Linksort(l1->next,NULL);
}


void nizhi(Link L)
{
	Link p,q;
	p=L->next;
	L->next=NULL;
	while(p)
	{
		q=p->next;
		p->next=L->next;
		L->next=p;
		p=q;
//		read(L);
	}
}

int main()
{
	Link L;
	L=creatTcha();
	cout<<"原始链表："<<endl;
	read(L);
	charu(L);
	cout<<"插入后："<<endl;
	read(L);
	Linksort(L->next,NULL);
	cout<<"排序后："<<endl;
	read(L);
	cout<<"逆置后："<<endl;
	nizhi(L);
	read(L);
	return 0;
}
