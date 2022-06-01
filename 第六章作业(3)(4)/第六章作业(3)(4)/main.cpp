//计算机215 202110244532 周俊安
#include "ALGraph.h"
int main()
{
	ALGraph* G;
	int i, v, max = 0;
	int v1, v2;
	CreateALGraph(G);
	for (i = 0; i < G->n; i++)
		printf("%d顶点的出度为%d\n", i, GetOutdegree(G, i));
	v = MaxOutdegree(G, max);
	printf("最大出度的顶点: %d,其出度: %d\n", v, max);
	printf("出度零的顶点数: %d\n", ZeroOutgree(G));
	printf("拓扑排序:\n");
	TopsortQu(G);
	printf("请输入两条边:(用逗号隔开)\n");
	scanf("%d,%d", &v1, &v2);
	if (Isexist(G, v1, v2))
		printf("边<%d,%d>存在\n", v1, v2);
	else
		printf("边<%d,%d>不存在\n", v1, v2);
	return 0;
}