//计算机215 202110244532 周俊安
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAXV 50
#define INF 32767
typedef int InfoType;
typedef int Vertex;
typedef struct ANode
{
	int adjvex;
	struct ANode* nextarc;
	InfoType info;
}ArcNode;

typedef struct VNode
{
	Vertex data;
	ArcNode* firstarc;
	int count;
}VNode;

typedef VNode AdjList[MAXV];
typedef struct
{
	AdjList adjlist;
	int n, e;
}ALGraph;

void CreateALGraph(ALGraph*& G);
int GetOutdegree(ALGraph* G, int v);//求某一结点的出度
int MaxOutdegree(ALGraph* G, int& max);//求图中最大出度
int ZeroOutgree(ALGraph* G);//求出度为零的结点个数
bool Isexist(ALGraph* G, int i, int j);//判断<i,j>是否存在
void TopsortQu(ALGraph* G);//拓扑排序,队列实现
