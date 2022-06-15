#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>

#define MAXV 50
#define INF 32767
typedef int InfoType;
typedef struct {
	char no;
	InfoType info;
}VertexType;

typedef struct MGraph {
	VertexType vexs[MAXV];
	int edges[MAXV][MAXV];
	int n, e;
}MGraph;

typedef char VerType;
typedef struct ANode {
	int adjvex;
	struct ANode* nextarc;
	InfoType info;
}ANode;
typedef struct VNode {
	VerType no;
	struct ANode* firstarc;
}VNode;
typedef struct {
	VNode adjlist[MAXV];
	int n, e;
}ALGraph;
static int visited[MAXV];

void PrintAMG(MGraph* G);//输出邻接矩阵G
void PrintALG(ALGraph* G);//输出邻接表G
int InDegreeM(MGraph* G, int v);//邻接矩阵求入度
int InDegreeL(ALGraph* G, int v);//邻接表求顶点入度
void LDFS(ALGraph* G, int v);//深度优先搜索 邻接表
void LBFS(ALGraph* G, int v);//广度优先搜索 邻接表
void MDFS(MGraph* G, int v);//深度优先搜索 邻接矩阵
void MBFS(MGraph* G, int v);//广度优先搜索 邻接矩阵