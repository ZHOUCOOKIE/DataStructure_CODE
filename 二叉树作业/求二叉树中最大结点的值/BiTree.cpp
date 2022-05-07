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

int FindMax(BTNode* T)
{
	int max, max1;
	if (T == NULL)
		return NULL;
	max = T->data;
	if (T->lchild != nullptr && max < (max1 = FindMax(T->lchild)))
		max = max1;
	if (T->rchild != nullptr && max < (max1 = FindMax(T->rchild)))
		max = max1;
	return max;
}

void CopyTree(BTNode* T1, BTNode*& T2)
{
	if (T1 == NULL)
	{
		T2 = NULL;
	}
	else
	{
		if (!(T2 = (BTNode*)malloc(sizeof(BTNode))))
		{
			exit(1);
		}
		T2->data = T1->data;
		CopyTree(T1->lchild, T2->lchild);
		CopyTree(T1->rchild, T2->rchild);
	}
}

BTNode* FirstNode(BTNode*& T)
{
	BTNode* p = T;
	if (p == NULL)
		return NULL;
	while (p->lchild || p->rchild)
	{
		if (p->lchild)
			p = p->lchild;
		else
			p = p->rchild;
	}
	return p;
}
//A(B(D,E(G,)),C(,F))
void VistNode(BTNode* T)
{
	if (T != NULL)
	{
		printf("%c", T->data);
		if (T->lchild != NULL || T->rchild != NULL)
		{
			VistNode(T->lchild);
			VistNode(T->rchild);
		}
	}
}

BTNode* FindParent(BTNode* ptr, Elemtype child)
{
	if (ptr == nullptr || ptr->data == child)
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
	if (ptr == nullptr || (ptr->lchild != nullptr && ptr->lchild->data == child) || (ptr->rchild != nullptr && ptr->rchild->data == child))
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