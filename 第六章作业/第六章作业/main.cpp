#include "ALGraph.h"
int main()
{
	MGraph* G;
	int i;
	int A[][7] = {
		{0,50,60,INF,INF,INF,INF},
		{50,0,INF,65,40,INF,INF},
		{60,INF,0,52,INF,INF,45},
		{INF,65,52,0,50,30,42},
		{INF,40,INF,50,0,70,INF},
		{INF,INF,INF,30,70,0,43},
		{INF,INF,45,42,INF,43,0}
	};
	char B[] = "0123456";
	CreateMGraph(G, A, B);
	Print(G);
	return 0;
}