//�����215 202110244532 �ܿ���
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
int GetOutdegree(ALGraph* G, int v);//��ĳһ���ĳ���
int MaxOutdegree(ALGraph* G, int& max);//��ͼ��������
int ZeroOutgree(ALGraph* G);//�����Ϊ��Ľ�����
bool Isexist(ALGraph* G, int i, int j);//�ж�<i,j>�Ƿ����
void TopsortQu(ALGraph* G);//��������,����ʵ��
