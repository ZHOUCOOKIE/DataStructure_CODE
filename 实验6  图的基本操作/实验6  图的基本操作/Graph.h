//邻接矩阵
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#define MAXV 100
#define INF 36727
//int visited[MAXV];

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
//邻接表
typedef struct ANode
{
	int adjvex;
	struct ANode* nextarc;
	InfoType info;
}ArcNode;

typedef struct VNode {
	InfoType data;
	ArcNode* firstarc;
}VNode;

typedef VNode AdjList[MAXV];
typedef struct {
	AdjList adjlist;
	int n, e;
}ALGraph;

void Print(MGraph* G);
bool CreateMGraph(MGraph*& G, int A[][6], char B[6]);
//void CreateALGraph(ALGraph*& G);
void MatToList(MGraph* g, ALGraph*& G);
void DFS(ALGraph* G, int v);//深度优先
void BFS(ALGraph* G, int v);
void DispAdj(ALGraph* G);