#include "SqStack.h"
#include <stdio.h>

//3. �㷨��ƣ����ַ�������Բ���š������š���������ɣ�����Ƕ�ף�ʹ��˳��ջ����дһ���㷨�ж��Ƿ�ƥ�䡣���ԡ�[{ {()}[]}() { [] }]��, ��{ [}] ()����

int main()
{
	char arr[20] = { "[{{()}[]}(){[]}]" };
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
	SqStack* S;
	InitStack(S);
	for (int i = 0; i <= 19; i++)
	{
		Push(S, arr[i]);
	}
	while (StackEmpty(S) == false)
	{
		ElemType g;
		Pop(S, g);
		if (g == '[')a++;
		if (g == ']')b++;
		if (g == '(')c++;
		if (g == ')')d++;
		if (g == '{')
			e++;
		if (g == '}')f++;
	}
	if (a == b && c == d && e == f)
	{
		printf("ƥ��");
	}
	else
		printf("��ƥ��");
	return 0;
}