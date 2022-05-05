#include "BiTree.h"
#include <stdlib.h>
#include <stdio.h>
void CreateBiTree(BTNode*& T, char* str)
{
	BTNode* St[10], * p = NULL;
	int top = -1, tag, j = 0;
	char ch;
	T = NULL;
	ch = str[j];
	while (ch != '\0')
	{
		switch (ch)
		{
		case '(':top++; St[top] = p; tag = 1; break;
		case ')':top--; break;
		case ',':tag = 2; break;
		default:p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch; p->lchild = p->rchild = NULL;
			if (T == NULL)
				T = p;
			else
			{
				switch (tag)
				{
				case 1:St[top]->lchild = p; break;
				case 2:St[top]->rchild = p; break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}

BTNode* FindParent(BTNode* ptr, Elemtype child)
{
	if (ptr == nullptr ||  ptr->data == child)
	{
		return nullptr;
	}
	else
	{
		return Parent(ptr, child);
	}
}

BTNode* Parent(BTNode* ptr, Elemtype child)
{
	if (ptr == nullptr || (ptr->lchild!=nullptr && ptr->lchild->data == child) || (ptr->rchild!=nullptr && ptr->rchild->data == child))
	{
		return ptr;
	}
	else
	{
		BTNode* p = Parent(ptr->lchild, child);
		{
			if (p == nullptr)
			{
				p = Parent(ptr->rchild, child);
			}
			return p;
		}
	}
}

//BTNode * FindNode(BTNode * BT, char X)
//{
//	char ch;
//	ch = X;
//	if (BT)
//	{
//		if ((BT->lchild != NULL && BT->lchild->data == ch) || (BT->rchild != NULL && BT->rchild->data == ch))
//		{
//			printf("%c的结点的孩子结点值为%c", BT->data, ch);
//
//		}
//		if ((BT->lchild != NULL && BT->lchild->data != ch) || (BT->rchild != NULL && BT->rchild->data != ch))
//		{
//
//			FindNode(BT->lchild, ch);
//			FindNode(BT->rchild, ch);
//		}
//	}
//	return BT;
//}

