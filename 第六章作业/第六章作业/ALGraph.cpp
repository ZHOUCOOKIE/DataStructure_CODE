//计算机215 202110244532 周俊安
#include "ALGraph.h"
bool CreateMGraph(MGraph*& G, int A[][7], char B[7])
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
			else printf("%d ", G->edges[i][j]);
		}
		printf("\n");
	}
}
