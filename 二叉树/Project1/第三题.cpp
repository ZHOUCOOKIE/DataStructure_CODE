#include "BiTree.h"
#include <stdio.h>
//3.二叉树采用二叉链表存储结构，试写算法求二叉树中一个非根结点的双亲结点。
int main()
{
	BTNode* T;
	char str[40]="A(B(D,E(G,)),C(,F))";
	CreateBiTree(T, str);
	printf("%c",FindParent(T, 'F')->data);
	return 0;
}
