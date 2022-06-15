#include <stdio.h>
#include <stdlib.h>

#define MAXV 100
#define INF 32767
typedef int InfoType;
typedef struct
{
	int no;
	InfoType info;
}VertexType;
typedef struct
{
	int edges[MAXV][MAXV];
	int n, e;
	VertexType vexs[MAXV];
}MGraph;
typedef struct
{
	int u;
	int v;
	int w;
}Edge;

void PrintAMG(MGraph* G);
void Prim(MGraph* G, int v);
void Kruskal(MGraph* g);
void InsertSort(Edge E[], int n);
void Dispath(MGraph* g, int dist[], int path[], int s[], int v);
void Dijkstra(MGraph* g, int v);

int main()
{
	MGraph* G;
	int i, j;
	int A[][7] = {
		{0,50,60,INF,INF,INF,INF},
		{50,0,INF,65,40,INF,INF},
		{60,INF,0,52,INF,INF,45},
		{INF,65,52,0,50,30,42},
		{INF,40,INF,50,0,70,INF},
		{INF,INF,INF,30,70,0,INF},
		{INF,INF,45,42,INF,INF,0}
	};
	int C[][6] = {
	{0,INF,5,30,INF,INF},
	{2,0,INF,INF,8,INF},
	{INF,15,0,INF,INF,7},
	{INF,INF,INF,0,INF,INF},
	{INF,INF,INF,4,0,INF},
	{INF,INF,INF,10,18,0},
	};
	char B[] = "ABCDEFG";
	G = (MGraph*)malloc(sizeof(MGraph));
	if (!G)
		exit(0);
	G->n = 7;
	G->e = 10;
	for (i = 0; i < G->n; i++)
		G->vexs[i].no = B[i];
	for (i = 0; i < G->n; i++)
	{
		for (j = 0; j < G->n; j++)
			G->edges[i][j] = A[i][j];
	}
	Prim(G, 0);
	Kruskal(G);
	free(G);
	G = (MGraph*)malloc(sizeof(MGraph));
	if (!G)
		exit(0);
	G->n = 6;
	G->e = 9;
	for (i = 0; i < G->n; i++)
		G->vexs[i].no = B[i];
	for (i = 0; i < G->n; i++)
	{
		for (j = 0; j < G->n; j++)
			G->edges[i][j] = C[i][j];
	}
	Dijkstra(G, 0);
	free(G);
	return 0;
}

void Prim(MGraph* g, int v)
{
	int lowcost[MAXV];
	int min;
	int closest[MAXV], i, j, k;
	printf("Prim算法\n");
	for (i = 0; i < g->n; i++)
	{
		lowcost[i] = g->edges[v][i];
		closest[i] = v;
	}
	for (i = 1; i < g->n; i++)
	{
		min = INF;
		for (j = 0; j < g->n; j++)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
		}
		printf("边(%c,%c)权为：%d\n", g->vexs[closest[k]], g->vexs[k], min);
		lowcost[k] = 0;
		for (j = 0; j < g->n; j++)
			if (g->edges[k][j] != 0 && g->edges[k][j] < lowcost[j])
			{
				lowcost[j] = g->edges[k][j];
				closest[j] = k;
			}
	}
}

void InsertSort(Edge E[], int n)
{
	int i, j;
	Edge temp;
	for (i = 1; i < n; i++)
	{
		temp = E[i];
		j = i - 1;
		while (j >= 0 && temp.w < E[j].w)
		{
			E[j + 1] = E[j];
			j--;
		}
		E[j + 1] = temp;
	}
}

void Kruskal(MGraph* g)
{
	int i, j, u1, v1, sn1, sn2, k;
	int vset[MAXV];
	Edge E[10];
	k = 0;
	printf("Kruskal算法\n");
	for (i = 0; i < g->n; i++)
		for (j = i; j < g->n; j++)
			if (g->edges[i][j] != 0 && g->edges[i][j] != INF)
			{
				E[k].u = i; E[k].v = j; E[k].w = g->edges[i][j];
				k++;
			}
	InsertSort(E, g->e);
	for (i = 0; i < g->n; i++)
		vset[i] = i;
	k = 1;
	j = 0;
	while (k < g->n)
	{
		u1 = E[j].u; v1 = E[j].v;
		sn1 = vset[u1];
		sn2 = vset[v1];
		if (sn1 != sn2)
		{
			printf("边(%c,%c)权为：%d\n", g->vexs[u1], g->vexs[v1], E[j].w);
			k++;
			for (i = 0; i < g->n; i++)
			{
				if (vset[i] == sn2)
					vset[i] = sn1;
			}
			j++;
		}
	}
}

void Dijkstra(MGraph* G, int v)
{
	int dist[MAXV], final[MAXV], path[MAXV];
	int i, j, k = 0, min;
	for (i = 0; i < G->n; i++)
	{
		dist[i] = G->edges[v][i];
		final[i] = 0;
		if (G->edges[v][i] < INF)
			path[i] = v;
		else
			path[i] = -1;
	}
	path[v] = 0;
	final[v] = 1;
	for (i = 1; i < G->n; i++)
	{
		min = INF;
		for (j = 0; j < G->n; j++)
		{
			if (final[j] == 0 && dist[j] < min)
			{
				min = dist[j];
				k = j;
			}
		}
		final[k] = 1;
		for (j = 0; j < G->n; j++)
		{
			if (final[j] == 0 && G->edges[k][j] != 0 && G->edges[k][j] < INF && G->edges[k][j] + dist[k] < dist[j])
			{
				dist[j] = dist[k] + G->edges[k][j];
				path[j] = k;
			}
		}
	}
	Dispath(G, dist, path, final, v);
}

void Dispath(MGraph* g, int dist[], int path[], int s[], int v)
{
	int i, j, k;
	int apath[MAXV], d;
	for (i = 0; i < g->n; i++)
	{
		if (s[i] == 1 && i != v)
		{
			printf("从%c到%c的最短路径长度为：%d\t路径为：", g->vexs[v], g->vexs[i], dist[i]);
			d = 0; apath[d] = i;
			k = path[i];
			if (k == -1)
				printf("无路径\n");
			else
			{
				while (k != v)
				{
					d++;
					apath[d] = k;
					k = path[k];
				}
				d++; apath[d] = v;
				printf("%c ", g->vexs[apath[d]]);
				for (j = d - 1; j >= 0; j--)
					printf("%c ", g->vexs[apath[j]]);
				printf("\n");
			}
		}
	}
}