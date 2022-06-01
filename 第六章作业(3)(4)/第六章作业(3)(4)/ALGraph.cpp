//计算机215 202110244532 周俊安
#include "ALGraph.h"
void CreateALGraph(ALGraph*& G)
{
	int i, u, v, w;
	ArcNode* p;
	G = (ALGraph*)malloc(sizeof(ALGraph));
	printf("输入顶点数和边数，用逗号分隔：");
	scanf("%d,%d", &G->n, &G->e);
	printf("依次输入各顶点的信息：");
	for (i = 0; i < G->n; i++)
	{
		getchar();
		scanf("%c", &(G->adjlist[i].data));//给有头节点的数据域置初值
		G->adjlist[i].firstarc = NULL;//给所有头节点的指针域置初值
	}
	printf("依次输入各条边的起点编号、终点编号、权值，中间逗号分隔:\n");
	for (i = 0; i < G->e; i++)
	{
		getchar();
		scanf("%d,%d,%d", &u, &v, &w);
		p = (ArcNode*)malloc(sizeof(ArcNode));   //创建节点*p
		p->adjvex = v;
		p->info = w;
		p->nextarc = G->adjlist[u].firstarc;  //将*p链到链表头
		G->adjlist[u].firstarc = p;
	}
}

int GetOutdegree(ALGraph* G, int v)//求某一结点的出度
{
	int net = 0;
	ArcNode* p = NULL;
	if (!G)
		return -1;
	p = G->adjlist[v].firstarc;
	while (p)
	{
		net++;
		p = p->nextarc;
	}
	return net;
}
int MaxOutdegree(ALGraph* G, int& max)//求图中最大出度
{
	int i, max1, k = -1;
	max = GetOutdegree(G, 0);
	for (i = 0; i < G->n; i++)
	{
		max1 = GetOutdegree(G, i);
		if (max1 > max)
		{
			max = max1;
			k = i;//记录顶点
		}
	}
	return k;
}
int ZeroOutgree(ALGraph* G)//求出度为零的结点个数
{
	int i, net = 0;
	ArcNode* p;
	if (!G)
		return net;
	for (i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		if (!p)
			net++;
	}
	return net;
}
bool Isexist(ALGraph* G, int i, int j)//判断<i,j>是否存在
{
	ArcNode* p;
	if (!G)
		return false;
	p = G->adjlist[i].firstarc;
	while (p)
	{
		if (p->adjvex == j)
			return true;
		p = p->nextarc;
	}
	return false;
}
void TopsortQu(ALGraph* G)//拓扑排序
{
	ArcNode* p;
	int Qu[MAXV], front, rear;
	int i, j, net = 0;
	front = rear = -1;
	for (i = 0; i < G->n; i++)
		G->adjlist[i].count = 0;
	for (i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		while (p)
		{
			j = p->adjvex;
			G->adjlist[j].count++;
			p = p->nextarc;
		}
	}
	for (i = 0; i < G->n; i++)
	{
		if (G->adjlist[i].count == 0)
		{
			rear++;
			Qu[rear] = i;
		}
	}
	while (front != rear)
	{
		front++;
		i = Qu[front];
		net++;
		printf("%d ", i);
		p = G->adjlist[i].firstarc;
		while (p)
		{
			j = p->adjvex;
			G->adjlist[j].count--;
			if (G->adjlist[j].count == 0)
			{
				rear++;
				Qu[rear] = j;
			}
			p = p->nextarc;
		}
	}
	if (net < G->n)
		printf("排序失败,存在回路\n");
	printf("\n");
}