#include "RearQueue.h"
#include <stdlib.h>
#include <stdio.h>
//4. 算法设计：在一个循环链队中只有尾指针]
//（记为rear，结点结构为数据源data，指针域为next，没有管理头结点），
//请给出这个队列的入队、出队实现过程。
void InitRear(rear*& R)
{
	R = (rear*)malloc(sizeof(rear));
	if (R == NULL)
	{
		printf("内存分配不成功！\n");
		return;
	}
	R->next = R;
	R->r = R;
}

bool EnRear(rear*& R, ElemType e)
{
	rear* p = R->r, * q;
	//while (p->next != R)//入队时间复杂度需要是1，此方法不符合
	//{
	//	p = p->next;
	//}
	q = (rear*)malloc(sizeof(rear));
	if (q == NULL)
	{
		printf("内存分配不成功！\n");
		return false;
	}
	p->next = q;
	q->data = e;
	q->next = R;
	return true;
}