#include "Graph.h"
void PrintAMG(MGraph* G)
{
	int i, j;
	for (i = 0; i < G->n; i++)
	{
		for (j = 0; j < G->n; j++)
		{
			if (G->edges[i][j] == INF)
				printf("∞");
			else
				printf("%2d", G->edges[i][j]);
		}
		printf("\n");
	}
}

void PrintALG(ALGraph* G)//输出邻接表G
{
	int i;
	ANode* p;
	for (i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		printf("%c(%d): ", G->adjlist[i].no, i);
		while (p != NULL)
		{
			printf("%3d(%2d)", p->adjvex, p->info);
			p = p->nextarc;
		}
		printf("\n");
	}
}

int InDegreeM(MGraph* G, int v)//邻接矩阵求入度
{
	int i, net = 0;
	for (i = 0; i < G->n; i++)
	{
		if (G->edges[i][v] > 0 && G->edges[i][v] < INF)
			net++;
	}
	return net;
}

int InDegreeL(ALGraph* G, int v)//邻接表求顶点入度
{
	int net = 0, i, j;
	ANode* p;
	if (!G)
		return -1;
	for (i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		while (p)
		{
			j = p->adjvex;
			if (j == v)
				net++;
			p = p->nextarc;
		}
	}
	return net;
}

void MDFS(MGraph* G, int v)//深度优先搜索 邻接矩阵
{
	int w;
	visited[v] = 1;
	printf("%c ", G->vexs[v].no);
	for (w = 0; w < G->n; w++)
	{
		if (G->edges[w][v] != INF && G->edges[w][v] != 0 && !visited[w])
			MDFS(G, w);
	}
}

void MBFS(MGraph* G, int v)//广度优先搜索 邻接矩阵
{
	ANode* p;
	char w;
	int i, j;
	int Qu[MAXV], front, rear;
	int visited[MAXV];
	front = rear = -1;
	for (i = 0; i < MAXV; i++)
		visited[i] = 0;
	printf("%c ", G->vexs[v].no);
	Qu[++rear] = v;
	visited[v] = 1;
	while (front != rear)
	{
		w = Qu[++front];
		for (j = 0; j < G->n; j++)
		{
			if (visited[j] == 0 && G->edges[w][j] > 0 && G->edges[w][j] < INF)
			{
				printf("%c ", G->vexs[j].no);
				visited[j] = 1;
				Qu[++rear] = j;
			}
		}
	}
	printf("\n");
}

void LDFS(ALGraph* G, int v)//深度优先搜索 邻接表
{
	ANode* p;
	int w;
	visited[v] = 1;
	printf("%c ", G->adjlist[v].no);
	p = G->adjlist[v].firstarc;
	while (p)
	{
		w = p->adjvex;
		if (visited[w] == 0)
			LDFS(G, w);
		p = p->nextarc;
	}
}

void LBFS(ALGraph* G, int v)//广度优先搜索 邻接表
{
	ANode* p;
	char w;
	int i;
	int Qu[MAXV], front, rear;
	int visited[MAXV];
	front = rear = -1;
	for (i = 0; i < MAXV; i++)
		visited[i] = 0;
	printf("%c ", G->adjlist[v].no);
	Qu[++rear] = v;
	visited[v] = 1;
	while (front != rear)
	{
		w = Qu[++front];
		p = G->adjlist[w].firstarc;
		while (p)
		{
			if (visited[p->adjvex] == 0)
			{
				printf("%c ", G->adjlist[p->adjvex].no);
				visited[p->adjvex] = 1;
				Qu[++rear] = p->adjvex;
			}
			p = p->nextarc;
		}
	}
	printf("\n");
}