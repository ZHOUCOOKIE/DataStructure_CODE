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

void PrintAMG(MGraph* G);//����ڽӾ���G
void PrintALG(ALGraph* G);//����ڽӱ�G
int InDegreeM(MGraph* G, int v);//�ڽӾ��������
int InDegreeL(ALGraph* G, int v);//�ڽӱ��󶥵����
void LDFS(ALGraph* G, int v);//����������� �ڽӱ�
void LBFS(ALGraph* G, int v);//����������� �ڽӱ�
void MDFS(MGraph* G, int v);//����������� �ڽӾ���
void MBFS(MGraph* G, int v);//����������� �ڽӾ���