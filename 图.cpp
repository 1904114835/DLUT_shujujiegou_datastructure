#include<bits/stdc++.h>
#define MAX 100 
using namespace std;

typedef struct arcNode{
	int vex;
//	int weight;
	arcNode *next;
}*ANode;
typedef struct vNode{
	int data;
	arcNode *next;
}*VNode;

typedef struct lianbiao_G
{
	vNode *v[MAX];
	int vexnum,arcnum;
	int type;	
}*Graph; 




void lb_creat(Graph G)
{
	int i,j,k;
	printf("请输入顶点数：");
	scanf("%d",&G->vexnum);
	printf("请输入顶点信息：");
	for(i=0;i<G->vexnum;i++)
	{
		vNode *tempNode=(vNode*)malloc(sizeof(vNode));
		scanf("%d",&tempNode->data);
		tempNode->next=NULL;
		G->v[i]=tempNode;
	}
	printf("请输入边数：");
	scanf("%d",&G->arcnum);
	printf("请输入边（首尾顶点）：\n");
	for(i=0;i<G->arcnum;i++)
	{
		int f,r;
		scanf("%d %d",&f,&r);
		ANode tempNode=(ANode)malloc(sizeof(arcNode));
		tempNode->next=G->v[f]->next;
		tempNode->vex=r;
		G->v[f]->next=tempNode;
	}
}

void dfs(Graph G,int i,int visit[])//深度优先搜索 
{
	visit[i]=1;
	printf("%d ",G->v[i]->data);
	for(ANode p=G->v[i]->next;p!=NULL;p=p->next)
	{
		int w=p->vex;
		if(visit[w]==0)dfs(G,w,visit);
	}
}

void lb_dfs(Graph G)//深度优先搜索预处理 
{
	int i;
	int visit[MAX];
	for(i=0;i<G->vexnum;i++)
		visit[i]=0;
	i=0;
	for(i=0;i<G->vexnum;i++)
		if(visit[i]==0)
			dfs(G,i,visit);
}


void bfs(Graph G,int i,int visit[])//广度优先搜索 
{	
	int q[MAX];
	int f=0,r=0; //初始化一个空队列
	visit[i] = 1; printf("%d",G->v[i]->data);//访问v
	q[r++]=i; //刚刚访问的顶点v入队
	while(f!=r)
	{
		int w=q[f++]; //取队首顶点w（w已经访问过，现在要访问w的未被访问的邻接点）
		for(ANode p=G->v[w]->next; p!=NULL; p=p->next)
		{
			int k=p->vex;
			if(!visit[k])
			{
				visit[k]=1; 
				printf("%d",G->v[k]->data);
				q[r++]=k;
			}
		}
	}
}
void lb_bfs(Graph G)//广度优先搜索预处理 
{
	int visit[G->vexnum];
	for(int i=0;i<G->vexnum;i++)
		visit[i]=0;
	for(int i=0;i<G->vexnum;i++)
		if(visit[i]==0)
			bfs(G,i,visit);
}



int main()
{
	int n;
	Graph G;
	G=(Graph)malloc(sizeof(lianbiao_G));
	lb_creat(G);
	lb_dfs(G);
	return 0;	
} 
