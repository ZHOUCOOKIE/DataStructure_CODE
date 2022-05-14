//�����215 202110244532 �ܿ���
#include "QNode.h"
#include <stdlib.h>
#include <stdio.h>

void InitQueue(Queue*& q)
{
	q->rear = (Node*)malloc(sizeof(Node));
	q->rear->next = q->rear;
}

bool QueueEmpty(Queue* q)
{
	if (q->rear->next == q->rear)
		return false;
	else
		return true;
}

bool EnQueue(Queue* q, int x)
{
	Node* p = q->rear;
	while (p->next != q->rear)
	{
		p = p->next;
	}
	Node* newq;
	newq = (Node*)malloc(sizeof(Node));
	newq->data = x;
	newq->next = q->rear;
	p->next = newq;
	return true;
}

bool DeQueue(Queue* q, int& e)
{
	if (QueueEmpty(q) == 0)
	{
		printf("����Ϊ�գ�");
		return 0;
	}
	Node* deq = q->rear->next;
	q->rear->next = deq->next;
	e = deq->data;
	free(deq);
	return true;
}

void print(Queue* q)
{
	Node* p = q->rear;
	printf("���У�");
	if (QueueEmpty(q) == 0)
	{
		printf("��");
		return;
	}
	while (p->next != q->rear)
	{
		printf("%d  ", p->next->data);
		p = p->next;
	}
	printf("\n");
}