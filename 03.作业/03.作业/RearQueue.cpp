#include "RearQueue.h"
#include <stdlib.h>
#include <stdio.h>
//4. �㷨��ƣ���һ��ѭ��������ֻ��βָ��]
//����Ϊrear�����ṹΪ����Դdata��ָ����Ϊnext��û�й���ͷ��㣩��
//�����������е���ӡ�����ʵ�ֹ��̡�
void InitRear(rear*& R)
{
	R = (rear*)malloc(sizeof(rear));
	if (R == NULL)
	{
		printf("�ڴ���䲻�ɹ���\n");
		return;
	}
	R->next = R;
	R->r = R;
}

bool EnRear(rear*& R, ElemType e)
{
	rear* p = R->r, * q;
	//while (p->next != R)//���ʱ�临�Ӷ���Ҫ��1���˷���������
	//{
	//	p = p->next;
	//}
	q = (rear*)malloc(sizeof(rear));
	if (q == NULL)
	{
		printf("�ڴ���䲻�ɹ���\n");
		return false;
	}
	p->next = q;
	q->data = e;
	q->next = R;
	return true;
}