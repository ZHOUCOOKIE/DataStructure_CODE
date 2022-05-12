//计算机215 202110244532 周俊安
#include "BiTree.h"
#include <stdio.h>

int main()
{
	BTNode* T, * T2 = NULL;
	char str[40] = "A(B(D,E(G,)),C(,F))";
	CreateBiTree(T, str);
	printf("%c\n", FindParent(T, 'F')->data);
	printf("%c\n", FindMax(T));
	CopyTree(T, T2);
	VistNode(T);
	printf("\n");
	VistNode(T2);
	printf("\n");
	printf("%c", FirstNode(T)->data);
	return 0;
}