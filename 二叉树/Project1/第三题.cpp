#include "BiTree.h"
#include <stdio.h>
//3.���������ö�������洢�ṹ����д�㷨���������һ���Ǹ�����˫�׽�㡣
int main()
{
	BTNode* T;
	char str[40]="A(B(D,E(G,)),C(,F))";
	CreateBiTree(T, str);
	printf("%c",FindParent(T, 'F')->data);
	return 0;
}
