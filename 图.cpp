#include<bits/stdc++.h>
#define MAX 100
using namespace std;

typedef struct arcNode 
{
	int vex;
	int weight;
	arcNode *next;
}*ANode;
typedef struct vNode 
{
	int data;
	arcNode *next;
}*VNode;

typedef struct lianbiao_G 
{
	vNode *v[MAX];
	int vexnum,arcnum;
	int type;
}*Graph;

typedef struct juzhen_G 
{
	int map[MAX][MAX];
	int vex[MAX];
	int vexnum,arcnum;
}*juzhen_Graph;




void creat(Graph G,juzhen_Graph jz_G) 
{
	int i,j,k;
	printf("请输入顶点数：");
	scanf("%d",&G->vexnum);
	jz_G->vexnum=G->vexnum;
	printf("请输入顶点信息：");
	for(i=0; i<G->vexnum; i++) 
	{
		vNode *tempNode=(vNode*)malloc(sizeof(vNode));
		scanf("%d",&tempNode->data);
		tempNode->next=NULL;
		G->v[i]=tempNode;

		jz_G->vex[i]=tempNode->data;
	}

	for(i=0; i<jz_G->vexnum; i++)
		for(j=0; j<jz_G->vexnum; j++) 
		{
			if(i==j)
				jz_G->map[i][j]=0;
			else
				jz_G->map[i][j]=0x3f3f3f;
		}



	printf("请输入边数：");
	scanf("%d",&G->arcnum);
	jz_G->arcnum=G->arcnum;
	printf("请输入边（首尾顶点、权值）：\n");
	for(i=0; i<G->arcnum; i++) 
	{
		int f,r,wei;
		scanf("%d %d %d",&f,&r,&wei);
		ANode tempNode=(ANode)malloc(sizeof(arcNode));
		tempNode->next=G->v[f]->next;
		tempNode->vex=r;
		tempNode->weight=wei;
		G->v[f]->next=tempNode;

		jz_G->map[f][r]=wei;
		jz_G->map[r][f]=wei;
	}
}

void dfs(Graph G,int i,int visit[]) 
{
	//深度优先搜索
	visit[i]=1;
	printf("%d ",G->v[i]->data);
	for(ANode p=G->v[i]->next; p!=NULL; p=p->next) 
	{
		int w=p->vex;
		if(visit[w]==0)dfs(G,w,visit);
	}
}

void lb_dfs(Graph G) 
{
	//深度优先搜索预处理
	int i;
	int visit[MAX];
	for(i=0; i<G->vexnum; i++)
		visit[i]=0;
	i=0;
	for(i=0; i<G->vexnum; i++)
		if(visit[i]==0)
			dfs(G,i,visit);
}


void bfs(Graph G,int i,int visit[]) 
{
	//广度优先搜索
	int q[MAX];
	int f=0,r=0; //初始化一个空队列
	visit[i] = 1;
	printf("%d ",G->v[i]->data);//访问v
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
				printf("%d ",G->v[k]->data);
				q[r++]=k;
			}
		}
	}
}
void lb_bfs(Graph G) 
{
	//广度优先搜索预处理
	int visit[G->vexnum];
	for(int i=0; i<G->vexnum; i++)
		visit[i]=0;
	for(int i=0; i<G->vexnum; i++)
		if(visit[i]==0)
			bfs(G,i,visit);
}

void jz_print(juzhen_Graph jz_G) 
{
	printf("\n邻接矩阵表示法：\n");
	int i,j;
	for(i=0; i<jz_G->vexnum; i++) 
	{
		printf("\n");
		for(j=0; j<jz_G->vexnum; j++) 
		{
			printf("%d ",jz_G->map[i][j]);
		}
	}
}

/*
int minclosedge(EdgeType closedge[ ])
{
	int min,j,k;
	min=MAXEDGE;
	k=-1;
	for(j=0;j<G->vexnum;j++)
		if (closedge[j]. lowcost !=0&&closedge[j]. lowcost<min)
		{
			min=closedge[j]. lowcost;
			k=j;
		}
	return k;
}

void prim(AGraphs G,int u)
{
	int i,j,k;
	EdgeType closedge[MAX];
	for(j=0; j<G->vexnum; j++)
	{
		closedge[j]. adjvex=u;
		closedge[j]. lowcost=G->arcs[u][j];
	}
	closedge[u]. lowcost=0;
	for(i=1; i<G->vexnum; i++)
	{
		k=minclosedge(closedge);
		printf(“(%d,%d)”, closedge[k]. adjvex,k);
		closedge[k]. lowcost=0;
		for(j=0; j<G->venum; j++)
			if(G->arcs[k][j]< closedge[j]. lowcost)
			{
				closedge[j]. lowcost= G->arcs[k][j];
				closedge[j]. adjvex =k;
			}
	}
}
*/
void djstra(juzhen_Graph G,int k,int P[MAX][MAX], int D[ ]) 
{
	int i,w, j,min;
	int final[MAX]; 
	for (i=0; i<G->vexnum; i ++) 
	{//对每个点初始化 
		final[i]=0;//初始时所有点的最短路径都没有求出 
		
		D[i]=G->map[k][i];//初始化点到原点的距离，若有，为此值，若无，为无穷 
		
		for(w=0; w<G->vexnum; w ++)//对与第i个点，初始化它路径上的点 
			P[i][w]=0;
	
		if (D[i]<INFINITY)
		{//如果这个点和原点直接相连，那么它和原点间至少有路径 
			P[i][k]=1;//原点在路径上 
			P[i][i]=1;// 它本身也在路径上 
		}
	}
	D[k]=0;//原点到原点距离为0 
	final[k]=1;//原点在已求出路径的点中 
	for(i=1; i<G->vexnum; i ++) 
	{//只是为了重复n-1次。i无实际意义 
		min=0x3f3f3f;
		for (w=0; w<G->vexnum; w ++)
			if (final[w]==0&&D[w]<min) 
			{//对于不在集合S中的点，寻找路径最短 
				j=w;//记录这个点 
				min=D[w];
			}
	if(min== 0x3f3f3f){printf("\n该结点是孤立的点\n");return;}//说明从原点到任何点都没有路径，原点是孤立的点 
		final[j]=1;//把刚刚记录的最短点置为1 
		for(w=0; w<G->vexnum; w ++)//对于每个点 
			if(final[w]==0&&(min+G->map[j][w]<D[w])) 
			{//如果这个点不在S中，且刚刚新加入的点可以让路径更短，更新状态 
				D[w]=min+G->map[j][w];
				
				for(int tempP=0;tempP<MAX;tempP++)//把路径更新为新点路径 
					P[w][tempP]=P[j][tempP];
				P[w][w]=1;//把自身也纳入路径 
			}
	}
	
	for(i=0;i<G->vexnum;i++)
	{
	 	printf("\n");
		for(j=0;j<G->vexnum;j++)
			printf("%d ",P[i][j]);
	 } 

	
	
	
}
int main() 
{
	int n;
	Graph G;
	juzhen_Graph jz_G;
	G=(Graph)malloc(sizeof(lianbiao_G));
	jz_G=(juzhen_Graph)malloc(sizeof(juzhen_G));
	creat(G,jz_G);
	lb_bfs(G);

	jz_print(jz_G);

	int P[MAX][MAX],D[MAX];
	djstra(jz_G,0,P,D);


	return 0;
}
