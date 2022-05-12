#include "BiTree.h"
#include <stdio.h>

int main()
{
	BTNode* T, * T2 = NULL;
	char str[40] = "1(2,3(4(6,),5))";
	CreateBiTree(T, str);
	VisitRDL(T, 0);
	printf("二叉树的高度为%d\n",BiTreeDepth(T));
	printf("二叉树的节点个数为%d\n",BiTreeNodeAmount(T));
	printf("二叉树的中序遍历");
	InOrderTraverse(T);
	printf("\n二叉树的层次遍历");
	LevelTraverse(T);
	return 0;
}