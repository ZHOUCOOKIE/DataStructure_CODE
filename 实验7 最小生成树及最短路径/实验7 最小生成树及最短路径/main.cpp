#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define Maxsize 50
#define INF 32767
typedef int InfoType;
typedef struct {
	char data;
	InfoType info;
}VerTexType;
typedef int ArcType;

typedef struct AMGraph {
	VerTexType vexs[Maxsize];
	ArcType arcs[Maxsize][Maxsize];
	int vexnum, arcnum;
}AMGraph;

int visited[Maxsize];
typedef struct {
	int v;//���
	int u;//�յ�
	int w;//Ȩֵ
}Edge;
int LocateVex(AMGraph* G, char v)//���ض�������λ��
{
	int i;
	for (i = 0; i < G->vexnum; i++)
	{
		if (v == G->vexs[i].data)
			return i;
	}
	return -1;
}

void InsertSort(Edge E[], int n)
{
	int i, j;
	Edge temp;
	for (i = 1; i < n; i++)
	{
		temp = E[i];
		j = i - 1;
		while (j >= 0 && temp.w < E[j].w)
		{
			E[j + 1] = E[j];
			j--;
		}
		E[j + 1] = temp;
	}
}
void Kruskal(AMGraph* G)
{
	//����߼���������Ϣ
	//��Ȩֵ��С��������
	//���鼯�����켯��
	//�жϽ���Ƿ�����ͬһ���ϣ����Ƿ���ͨ
	//ѭ���������б�
	Edge E[Maxsize];//�߼���
	int vset[Maxsize];//��㼯��
	int i, j, k;
	int v, u;
	int sn1, sn2;
	k = 0;
	for (i = 0; i < G->vexnum; i++)//��ʼ����������������
		vset[i] = i;
	for (i = 0; i < G->vexnum; i++)//����߼�
		for (j = i; j < G->vexnum; j++)
		{
			if (G->arcs[i][j] != 0 && G->arcs[i][j] != INF)
			{
				E[k].u = i;
				E[k].v = j;
				E[k].w = G->arcs[i][j];
				k++;
			}
		}
	InsertSort(E, G->arcnum);//���ߴ�С�����������
	k = 1;//��ʾĿǰ����ĵڼ�����
	j = 0;
	while (k < G->vexnum)
	{
		v = E[j].v;
		u = E[j].u;
		sn1 = vset[v];
		sn2 = vset[u];
		if (sn1 != sn2)
		{
			printf("��(%d,%d)��ȨֵΪ%d\n", u, v, E[j].w);
			for (i = 0; i < G->vexnum; i++)
				if (vset[v] == sn2)
					vset[v] = sn1;
			k++;
		}
		j++;
	}
}
void Prim(AMGraph* G, int v)
{
	//��������lowcost��������뼯�ϵ���ʹ���
	//��������closest������뼯����С���������Ķ���
	//��ʼ��lowcost��closest
	//while---Ѱ����С���۵ı�
	//���ö�����뼯�ϣ�������lowcost�Լ�closest
	int lowcost[Maxsize], closest[Maxsize];
	int i, j, k = 0, min;
	for (i = 0; i < G->vexnum; i++)
	{
		lowcost[i] = G->arcs[i][v];
		closest[i] = v;
	}
	for (i = 1; i < G->vexnum; i++)
	{
		min = INF;
		for (j = 0; j < G->vexnum; j++)//�ҳ�������С�ı�
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
		}
		lowcost[k] = 0;//��k������뼯��
		printf("��(%d,%d)��ȨֵΪ%d\n", closest[k], k, min);
		for (j = 0; j < G->vexnum; j++)
		{
			if (G->arcs[j][k] != 0 && G->arcs[j][k] < lowcost[j])
			{
				lowcost[j] = G->arcs[j][k];
				closest[j] = k;
			}
		}
	}
}
void Dispath(AMGraph* G, int dist[], int path[], int final[], int v)
{
	int i, j, k;
	int apath[Maxsize], d;
	for (i = 0; i < G->vexnum; i++)
		if (final[i] == 1 && i != v)
		{
			printf("��%d��%d�����·������Ϊ:%d\t·��Ϊ:", v, i, dist[i]);
			d = 0;
			apath[d] = i;
			k = path[i];
			if (k == -1)
				printf("��·��\n");
			else
			{
				while (k != v)
				{
					d++;
					apath[d] = k;
					k = path[k];
				}
				d++;
				apath[d] = v;
				printf("%d ", apath[d]);
				for (j = d - 1; j >= 0; j--)
					printf("%d ", apath[j]);
				printf("\n");
			}
		}
}
void Dijkstra(AMGraph* G, int v)
{
	//����dist���飬final���飬path���飬��ʼ��
	//�����С����Ķ���
	//��������뼯�ϣ�����dist�����path����
	int dist[Maxsize], final[Maxsize], path[Maxsize];
	int i, j, k = 0, min;
	for (i = 0; i < G->vexnum; i++)
	{
		dist[i] = G->arcs[v][i];
		final[i] = 0;
		if (G->arcs[v][i] < INF)
			path[i] = v;
		else
			path[i] = -1;
	}
	path[v] = 0;
	final[v] = 1;
	for (i = 1; i < G->vexnum; i++)
	{
		min = INF;
		for (j = 0; j < G->vexnum; j++)
		{
			if (final[j] == 0 && dist[j] < min)
			{
				min = dist[j];
				k = j;
			}
		}
		final[k] = 1;
		for (j = 0; j < G->vexnum; j++)
		{
			if (final[j] == 0 && G->arcs[k][j] != 0 && G->arcs[k][j] < INF && G->arcs[k][j] + dist[k] < dist[j])
			{
				dist[j] = dist[k] + G->arcs[k][j];
				path[j] = k;
			}
		}
	}
	Dispath(G, dist, path, final, v);
}
int main()
{
	AMGraph* G;
	int i, j;
	int A[][7] = {
		{0,50,60,INF,INF,INF,INF},
		{50,0,INF,65,40,INF,INF},
		{60,INF,0,52,INF,INF,45},
		{INF,65,52,0,50,30,42},
		{INF,40,INF,50,0,70,INF},
		{INF,INF,INF,30,70,0,INF},
		{INF,INF,45,42,INF,INF,0}
	};
	int C[][6] = {
		{0,INF,5,30,INF,INF},
		{2,0,INF,INF,8,INF},
		{INF,15,0,INF,INF,7},
		{INF,INF,INF,0,INF,INF},
		{INF,INF,INF,4,0,INF},
		{INF,INF,INF,10,18,0},
	};
	char B[] = "ABCDEFG";
	G = (AMGraph*)malloc(sizeof(AMGraph));
	if (!G)
		exit(0);
	G->vexnum = 7;
	G->arcnum = 10;
	for (i = 0; i < G->vexnum; i++)
		G->vexs[i].data = B[i];
	for (i = 0; i < G->vexnum; i++)
	{
		for (j = 0; j < G->vexnum; j++)
			G->arcs[i][j] = A[i][j];
	}
	printf("����ķ�㷨\n");
	Prim(G, 0);
	printf("��³˹�����㷨\n");
	Kruskal(G);

	free(G);

	G = (AMGraph*)malloc(sizeof(AMGraph));
	if (!G)
		exit(0);
	G->vexnum = 6;
	G->arcnum = 9;
	for (i = 0; i < G->vexnum; i++)
		G->vexs[i].data = B[i];
	for (i = 0; i < G->vexnum; i++)
	{
		for (j = 0; j < G->vexnum; j++)
			G->arcs[i][j] = C[i][j];
	}
	printf("�ҿ�˹�����㷨\n");
	Dijkstra(G, 0);
	free(G);
	return 0;
}
