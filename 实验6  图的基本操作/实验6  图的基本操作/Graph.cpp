#include "Graph.h"
bool CreateMGraph(MGraph*& G, int A[][6], char B[6])
{
	int i, j;
	G = (MGraph*)malloc(sizeof(MGraph));
	if (!G)return false;
	G->n = 5;
	G->e = 16;
	for (i = 0; i < G->n; i++)
		G->vexs[i].no = B[i];
	for (i = 0; i < G->n; i++)
	{
		for (j = 0; j < G->n; j++)
			G->edges[i][j] = A[i][j];
	}
	return true;
}

void Print(MGraph* G)
{
	int i, j;
	for (i = 0; i < G->n; i++)
	{
		for (j = 0; j < G->n; j++)
		{
			if (G->edges[i][j] == INF)printf("∞ ");
			else printf("%2d ", G->edges[i][j]);
		}
		printf("\n");
	}
}

void DFS(ALGraph* G, int v)//深度优先
{
	ArcNode* p;
	int w;
	visited[v] = 1;
	printf("%d ", v);
	p = G->adjlist[v].firstarc;
	while (p != NULL)
	{
		w = p->adjvex;
		if (visited[w] == 0)
			DFS(G, w);
		p = p->nextarc;
	}
}

void BFS(ALGraph* G, int v)
{
	ArcNode* p;
	int w, i;
	int queue[MAXV], front = 0, rear = 0;
	//int visited[MAXV];
	for (i = 0; i < G->n; i++)
		visited[i] = 0;
	printf("%2d", v);
	visited[v] = 1;
	rear = (rear + 1) % MAXV;
	queue[rear] = v;
	while (front != rear)
	{
		front = (front + 1) % MAXV;
		w = queue[front];
		p = G->adjlist[w].firstarc;
		while (p != NULL)
		{
			if (visited[p->adjvex] == 0)
			{
				printf("%2d", p->adjvex);
				visited[p->adjvex] = 1;
				rear = (rear + 1) % MAXV;
				queue[rear] = p->adjvex;
			}
			p = p->nextarc;
		}
	}
	printf("\n");
}

void MatToList(MGraph* g, ALGraph*& G)
{
	int i, j, n = g->n;
	ArcNode* p;
	G = (ALGraph*)malloc(sizeof(ALGraph));
	for (i = 0; i < n; i++)
		G->adjlist[i].firstarc = NULL;
	for(i=0;i<n;i++)
		for (j = n - 1; j >= 0; j--)
		{
			if (g->edges[i][j] > 0 && g->edges[i][j] < INF)
			{
				p = (ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->info = g->edges[i][j];
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
			G->n = n;
			G->e = g->e;
		}
}

void DispAdj(ALGraph* G)
{
	int i;
	ArcNode* p;
	for (i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		printf("%c(%d):", G->adjlist[i].data,i);
		while (p != NULL)
		{
			printf("%3d(%2d)", p->adjvex, p->info);
			p = p->nextarc;
		}
		printf("\n");
	}
}