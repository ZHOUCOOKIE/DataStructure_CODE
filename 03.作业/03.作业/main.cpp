//#include "SqStack.h"
//#include <stdio.h>
////3. �㷨��ƣ����ַ�������Բ���š������š���������ɣ�����Ƕ�ף�ʹ��˳��ջ����дһ���㷨�ж��Ƿ�ƥ�䡣
////���ԡ�[{{()}[]}(){[]}]��, ��{[}]()����
//
//bool Judge(SqStack*& S,ElemType e[])
//{
//	int i = 0, judge = 0;
//	ElemType  a1;
//	while ((e[i++] = getchar()) != '\n');//����������ֻ���һ����ĸ�𿪣��������ַ���ǰ��������ַ�����e��
//	i = 0;
//	while (e[i] != '\n')//���ַ������е�Ԫ�������ջ
//	{
//		Push(S, e[i]);
//		i++;
//	}
//	while (Pop(S, a1))
//	{
//		if (a1 != '[' && a1 != ']' && a1 != '(' && a1 != ')' && a1 != '{' && a1 != '}')
//			break;
//		judge++;
//	}
//	if (judge == i)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	SqStack* S;
//	ElemType e[MAXSIZE];
//	InitStack(S);
//	printf("�������ַ�������Բ���š������š����������:");
//	printf("�Ƿ�����Ҫ��:%d", Judge(S, e));
//	return 0;
//}