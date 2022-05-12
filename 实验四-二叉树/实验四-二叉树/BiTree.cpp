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

int BiTreeNodeAmount(BTNode* T)
{
	static int n = 0;
	if (T != NULL)
	{
		n++;
		if (T->lchild != NULL || T->rchild != NULL)
		{
			BiTreeNodeAmount(T->lchild);
			BiTreeNodeAmount(T->rchild);
		}
	}
	return n;
}

void InOrderTraverse(BTNode* T)
{
	int i;
	if (T != nullptr)
	{
		InOrderTraverse(T->lchild);
		printf("%c", T->data);
		InOrderTraverse(T->rchild);
	}
}

void VisitRDL(BTNode* T, int n)
{
	int i;
	if (T != nullptr)
	{
		VisitRDL(T->rchild, n + 1);
		for (i = 0; n > i; i++)
		{
			printf("\t");
		}
		printf("%c\n", T->data);
		VisitRDL(T->lchild, n + 1);
	}
}

int BiTreeDepth(BTNode* T)
{
	int ldep, rdep;
	if (T->lchild != nullptr)
	{
		ldep = BiTreeDepth(T->lchild);
	}
	else
		ldep = 0;
	if (T->rchild != nullptr)
	{
		rdep = BiTreeDepth(T->rchild);
	}
	else
		rdep = 0;
	return (ldep > rdep) ? (ldep + 1) : (rdep + 1);
}

void LevelTraverse(BTNode* T)
{
	BTNode* p;
	BTNode* qu[6];
	int front, rear;
	front = rear = -1;
	rear++;
	qu[rear] = T;
	while (front != rear)
	{
		front = (front + 1) % 6;
		p = qu[front];
		printf("%c", p->data);
		if (p->lchild != nullptr)
		{
			rear = (rear + 1) % 6;
			qu[rear] = p->lchild;
		}
		if (p->rchild != nullptr)
		{
			rear = (rear + 1) % 6;
			qu[rear] = p->rchild;
		}
	}
}