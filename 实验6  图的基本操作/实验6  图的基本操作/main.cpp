#include "Graph.h"
#define _CRT_SECURE_NO_WARNINGS
int main()
{
	MGraph* G;
	ALGraph* Ga;
	int i;
	int A[][6] = {
		{0,5,INF,7,INF,INF},
		{INF,INF,4,INF,INF,INF},
		{8,INF,INF,INF,INF,9},
		{INF,INF,5,INF,INF,6},
		{INF,INF,INF,5,INF,INF},
		{INF,INF,INF,30,70,0},
		{3,INF,INF,INF,1,INF}
	};
	char B[] = "012345";
	CreateMGraph(G, A, B);
	MatToList(G, Ga);
	Print(G);
	for (i = 0; i < 6; i++)
		visited[i] = 0;
	DispAdj(Ga);
	DFS(Ga, 0);
	printf("\n");
	BFS(Ga, 0);
	return 0;
}