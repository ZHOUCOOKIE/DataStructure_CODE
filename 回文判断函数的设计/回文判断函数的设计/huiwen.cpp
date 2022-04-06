//�����215 202110244532 �ܿ���
#include "SqQueue.h"
#include "SqStack.h"
#include <stdio.h>

bool Palindrome(SqStack*& S, SqQueue*& Q, ElemType e[])
{
	ElemType a1 = 1, a2 = 1;
	int i = 0, judge = 0;
	while (e[i] != '\n')//���ַ������е�Ԫ���������ջ�Ͷ���
	{
		Push(S, e[i]);
		EnQueue(Q, e[i]);
		i++;
	}

	while (a1 == a2)//����ջ�Ǻ���ȳ����������Ƚ��ȳ����������ǶԳƵģ�����ֻҪ��ջԪ�غͳ���Ԫ�غ�ȼ����������Ҫ������˵������ѭ������
	{
		judge++;
		Pop(S, a1);
		DeQueue(Q, a2);
		if (judge - 1 == 0.5 * i || judge - 1 == int(0.5 * i))//������ż����Ԫ��ʱ���Ƚϵ����鳤��һ�뼴��֤���ǻ�������������������Ԫ��ʱ���Ƚϵ����鳤�ȼ�һ��һ�뼴��֤���ǻ�����
		{
			return true;
		}
	}
	return false;
}

int main()
{
	SqQueue* Q;
	SqStack* S;
	ElemType e[50], a1 = 1, a2 = 1;
	int i = 0, judge = 0;
	InitQueue(Q);//��ʼ��
	InitStack(S);
	printf("������һ���������ֻ���һ����ĸ��");
	while ((e[i++] = getchar()) != '\n');//����������ֻ���һ����ĸ�𿪣��������ַ���ǰ��������ַ�����e��
	printf("������ֻ���һ����ĸ�Ƿ�Ϊ��������%d", Palindrome(S, Q, e));
	DestroyQueue(Q);
	DestroyStack(S);
	return 0;
}