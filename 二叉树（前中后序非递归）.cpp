#include<bits/stdc++.h>
#define MAX 200
using namespace std;
typedef struct Node{
	int data;
	Node *lc,*rc;	
}Node,*Tree;

struct Stack{
	Tree data[MAX];
	int point;
};
struct Queue{
	Tree data[MAX];
	int f,r;
};

typedef struct
{
	struct 
	{
		Tree d;
		int flag;
	}data[MAX];
	int top;
}SeqStack2;


Tree creat(){
	Tree T;
	int a;
	scanf("%d",&a);
	if(a!=0)
	{	
		T=(Tree)malloc(sizeof(Node));
		T->data=a;
		T->lc=creat();
		T->rc=creat();
	}
	else {
		T=NULL;
	}
	return T;
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

void xxbl_No_digui(Tree root)
{
	Tree T;
	T=root;
	Stack s;
	s.point=-1;
	while(T!=NULL||s.point!=-1)
	{
		while(T!=NULL)
		{
			cout<<T->data<<" ";
			s.data[++s.point]=T;
			T=T->lc;
		}
		if(s.point!=-1)
		{
			T=s.data[s.point--];
			T=T->rc;
		}
	}
}

void zxbl_No_digui(Tree root)
{
	Tree T=root;
	Stack s;
	s.point=-1;
	while(T!=NULL||s.point!=-1){
		while(T!=NULL){
			s.data[++s.point]=T;
			T=T->lc;
		}
		if(s.point!=-1){
			T=s.data[s.point--];
			cout<<T->data<<" ";
			T=T->rc;
		}
	}
}

void  hxbl_No_digui(Tree root)
{
	cout<<"后序遍历："<<endl;
	SeqStack2 s;
	s.top=-1;
	Tree p=root;
	do
	{
		while(p!=NULL) 
		{
		s.data[++s.top].d=p;
		s.data[s.top].flag=0; 
		p=p->lc;
		}
		while((s.top>-1)&&(s.data[s.top].flag==1))
		{ 
			p=s.data[s.top--].d; 
			printf("%d ",p->data); 
		}
		if(s.top>-1)
		{
			s.data[s.top].flag=1;
			p=s.data[s.top].d;
			p=p->rc;
		}
	}while(s.top>-1);
}


int main()
{
	Tree T;
	printf("前序输入，以0结尾：\n");
	T=creat();
	xxbl(T);
	cout<<endl;
	xxbl_No_digui(T);
	cout<<endl;
	zxbl_No_digui(T);
	cout<<endl;
	hxbl_No_digui(T);
	return 0;
}
//1 2 4 0 0 5 0 0 3 6 0 0 7 0 0
