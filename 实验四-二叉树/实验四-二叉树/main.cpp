#include "BiTree.h"
#include <stdio.h>

int main()
{
	BTNode* T, * T2 = NULL;
	char str[40] = "1(2,3(4(6,),5))";
	CreateBiTree(T, str);
	VisitRDL(T, 0);
	printf("�������ĸ߶�Ϊ%d\n",BiTreeDepth(T));
	printf("�������Ľڵ����Ϊ%d\n",BiTreeNodeAmount(T));
	printf("���������������");
	InOrderTraverse(T);
	printf("\n�������Ĳ�α���");
	LevelTraverse(T);
	return 0;
}