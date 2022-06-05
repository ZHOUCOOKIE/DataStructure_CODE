#include<stdlib.h>

#define MAXV 100
#define INF 36727
#define Maxsize 50
typedef int InfoType;
typedef struct {
	int no;
	InfoType info;
}VertexType;

typedef struct {
	int edges[MAXV][MAXV];
	int n, e;
	VertexType vexs[MAXV];
}MGraph;

void Print(MGraph* G);
bool CreateMGraph1(MGraph*& G, int A[][7], char B[]);
bool CreateMGraph2(MGraph*& G, int A[][6], char B[]);
void Prim(MGraph* G, int v);