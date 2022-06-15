#include "Graph.h"
int main()
{
	MGraph* MG;
	ALGraph* LG;
	int i, j;
	int A[][6] = {
		{ 0, 5, INF, 7, INF, INF },
		{ INF,0,4,INF,INF,INF },
		{ 8,INF,0,INF,INF,9 },
		{ INF,INF,5,0,INF,6 },
		{ INF,INF,INF,5,0,INF },
		{ 3,INF,INF,INF,1,0, },
		{ 3,INF,INF,INF,1,0 }
	};
	char B[] = "012345";
	MG = (MGraph*)malloc(sizeof(MGraph));
	if (!MG)
		exit(0);
	MG->n = 6;
	MG->e = 10;
	for (i = 0; i < MG->n; i++)
		MG->vexs[i].no = B[i];
	for (i = 0; i < MG->n; i++)
	{
		for (j = 0; j < MG->n; j++)
			MG->edges[i][j] = A[i][j];
	}
	printf("�ڽӾ��󴴽��ɹ�\n");
	char C[] = "012345";
	ANode* p = NULL;
	LG = (ALGraph*)malloc(sizeof(ALGraph));
	if (!LG)
		exit(0);
	LG->n = 6;
	LG->e = 10;
	for (i = 0; i < LG->n; i++)
	{
		LG->adjlist[i].no = C[i];
		LG->adjlist[i].firstarc = NULL;
	}
	for (i = 0; i < LG->n; i++)
		for (j = LG->n - 1; j >= 0; j--)
		{
			if (A[i][j] > 0 && A[i][j] < INF)
			{
				p = (ANode*)malloc(sizeof(ANode));
				if (!p)
					exit(0);
				p->adjvex = j;
				p->info = A[i][j];
				p->nextarc = LG->adjlist[i].firstarc;
				LG->adjlist[i].firstarc = p;
			}
		}
	printf("�ڽӱ����ɹ�\n");
	PrintAMG(MG);
	PrintALG(LG);
	printf("���ڽӾ�����ÿ���������:\n");
	for (j = 0; j < MG->n; j++)
		printf("%c��������Ϊ %d\n", MG->vexs[j].no, InDegreeM(MG, j));
	printf("���ڽӱ���ÿ���������:\n");
	for (j = 0; j < MG->n; j++)
		printf("%c��������Ϊ%d\n", LG->adjlist[j].no, InDegreeL(LG, j));
	for (i = 0; i < 6; i++)
		visited[i] = 0;
	printf("������ȱ������ڽӾ���: ");
	MDFS(MG, 0);
	printf("\n������ȱ������ڽӾ���: ");
	MBFS(MG, 0);
	for (i = 0; i < 6; i++)
		visited[i] = 0;
	printf("������ȱ������ڽӱ�: ");
	LDFS(LG, 0);
	printf("\n������ȱ������ڽӱ�: ");
	LBFS(LG, 0);
	return 0;
}