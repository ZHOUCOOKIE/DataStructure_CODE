//�����215 202110244532 �ܿ���
#include "ALGraph.h"
int main()
{
	ALGraph* G;
	int i, v, max = 0;
	int v1, v2;
	CreateALGraph(G);
	for (i = 0; i < G->n; i++)
		printf("%d����ĳ���Ϊ%d\n", i, GetOutdegree(G, i));
	v = MaxOutdegree(G, max);
	printf("�����ȵĶ���: %d,�����: %d\n", v, max);
	printf("������Ķ�����: %d\n", ZeroOutgree(G));
	printf("��������:\n");
	TopsortQu(G);
	printf("������������:(�ö��Ÿ���)\n");
	scanf("%d,%d", &v1, &v2);
	if (Isexist(G, v1, v2))
		printf("��<%d,%d>����\n", v1, v2);
	else
		printf("��<%d,%d>������\n", v1, v2);
	return 0;
}