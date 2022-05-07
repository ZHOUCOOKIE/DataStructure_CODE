#include "BiTree.h"
#include <stdio.h>

int main()
{
	BTNode* T, * T2 = NULL;
	char str[40] = "A(B(D,E(G,)),C(,F))";
	CreateBiTree(T, str);
	printf("%c\n", FindParent(T, 'F')->data);
	CopyTree(T, T2);
	VistNode(T);
	printf("\n");
	VistNode(T2);
	return 0;
}