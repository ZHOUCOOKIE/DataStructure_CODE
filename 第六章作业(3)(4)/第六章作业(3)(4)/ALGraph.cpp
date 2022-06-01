//�����215 202110244532 �ܿ���
#include "ALGraph.h"
void CreateALGraph(ALGraph*& G)
{
	int i, u, v, w;
	ArcNode* p;
	G = (ALGraph*)malloc(sizeof(ALGraph));
	printf("���붥�����ͱ������ö��ŷָ���");
	scanf("%d,%d", &G->n, &G->e);
	printf("����������������Ϣ��");
	for (i = 0; i < G->n; i++)
	{
		getchar();
		scanf("%c", &(G->adjlist[i].data));//����ͷ�ڵ���������ó�ֵ
		G->adjlist[i].firstarc = NULL;//������ͷ�ڵ��ָ�����ó�ֵ
	}
	printf("������������ߵ�����š��յ��š�Ȩֵ���м䶺�ŷָ�:\n");
	for (i = 0; i < G->e; i++)
	{
		getchar();
		scanf("%d,%d,%d", &u, &v, &w);
		p = (ArcNode*)malloc(sizeof(ArcNode));   //�����ڵ�*p
		p->adjvex = v;
		p->info = w;
		p->nextarc = G->adjlist[u].firstarc;  //��*p��������ͷ
		G->adjlist[u].firstarc = p;
	}
}

int GetOutdegree(ALGraph* G, int v)//��ĳһ���ĳ���
{
	int net = 0;
	ArcNode* p = NULL;
	if (!G)
		return -1;
	p = G->adjlist[v].firstarc;
	while (p)
	{
		net++;
		p = p->nextarc;
	}
	return net;
}
int MaxOutdegree(ALGraph* G, int& max)//��ͼ��������
{
	int i, max1, k = -1;
	max = GetOutdegree(G, 0);
	for (i = 0; i < G->n; i++)
	{
		max1 = GetOutdegree(G, i);
		if (max1 > max)
		{
			max = max1;
			k = i;//��¼����
		}
	}
	return k;
}
int ZeroOutgree(ALGraph* G)//�����Ϊ��Ľ�����
{
	int i, net = 0;
	ArcNode* p;
	if (!G)
		return net;
	for (i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		if (!p)
			net++;
	}
	return net;
}
bool Isexist(ALGraph* G, int i, int j)//�ж�<i,j>�Ƿ����
{
	ArcNode* p;
	if (!G)
		return false;
	p = G->adjlist[i].firstarc;
	while (p)
	{
		if (p->adjvex == j)
			return true;
		p = p->nextarc;
	}
	return false;
}
void TopsortQu(ALGraph* G)//��������
{
	ArcNode* p;
	int Qu[MAXV], front, rear;
	int i, j, net = 0;
	front = rear = -1;
	for (i = 0; i < G->n; i++)
		G->adjlist[i].count = 0;
	for (i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		while (p)
		{
			j = p->adjvex;
			G->adjlist[j].count++;
			p = p->nextarc;
		}
	}
	for (i = 0; i < G->n; i++)
	{
		if (G->adjlist[i].count == 0)
		{
			rear++;
			Qu[rear] = i;
		}
	}
	while (front != rear)
	{
		front++;
		i = Qu[front];
		net++;
		printf("%d ", i);
		p = G->adjlist[i].firstarc;
		while (p)
		{
			j = p->adjvex;
			G->adjlist[j].count--;
			if (G->adjlist[j].count == 0)
			{
				rear++;
				Qu[rear] = j;
			}
			p = p->nextarc;
		}
	}
	if (net < G->n)
		printf("����ʧ��,���ڻ�·\n");
	printf("\n");
}