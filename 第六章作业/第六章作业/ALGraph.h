//计算机215 202110244532 周俊安
#include<stdlib.h>
#include<stdio.h>
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

void Print(MGraph* G);
bool CreateMGraph(MGraph*& G, int A[][7], char B[7]);