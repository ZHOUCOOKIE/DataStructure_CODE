#include "MGraph.h"
#include<stdio.h>

bool CreateMGraph1(MGraph*& G, int A[][7], char B[])
{
	int i, j;
	G = (MGraph*)malloc(sizeof(MGraph));
	if (!G)return false;
	G->n = 7;
	G->e = 10;
	for (i = 0; i < G->n; i++)
		G->vexs[i].no = B[i];
	for (i = 0; i < G->n; i++)
	{
		for (j = 0; j < G->n; j++)
			G->edges[i][j] = A[i][j];
	}
	return true;
}

bool CreateMGraph2(MGraph*& G, int A[][6], char B[])
{
	int i, j;
	G = (MGraph*)malloc(sizeof(MGraph));
	if (!G)return false;
	G->n = 6;
	G->e = 9;
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

void Prim(MGraph* G, int v)
{
	int lowcost[Maxsize], closest[Maxsize];
	int i, j, k = 0, min;
	for (i = 0; i < G->n;i++)
	{
		lowcost[i] = G->edges[i][v];
		closest[i] = v;
	}
	for (i = 1; i < G->n; i++)
	{
		min = INF;
		for (j = 0; j < G->n; j++)
		{
			if (lowcost[j] != 0 && lowcost[j]< min)
			{
				min = lowcost[j];
				k = j;
			}
		}
		lowcost[k] = 0;
		printf("边(%d,%d)的权值为%d\n", closest[k], k, min);
		for (j = 0; j < G->n; j++)
		{
			if (G->edges[j][k] != 0 && G->edges[j][k] < lowcost[j])
			{
				lowcost[j] = G->edges[j][k];
				closest[j] = k;
			}
		}
	}
}