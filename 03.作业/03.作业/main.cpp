//#include "SqStack.h"
//#include <stdio.h>
////3. 算法设计：设字符串仅有圆括号、方括号、花括号组成，仅能嵌套；使用顺序栈，编写一个算法判断是否匹配。
////测试“[{{()}[]}(){[]}]”, “{[}]()”。
//
//bool Judge(SqStack*& S,ElemType e[])
//{
//	int i = 0, judge = 0;
//	ElemType  a1;
//	while ((e[i++] = getchar()) != '\n');//将输入的数字或者一串字母拆开，将单个字符从前往后存入字符数组e中
//	i = 0;
//	while (e[i] != '\n')//将字符数组中的元素逐个入栈
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
//	printf("请输入字符串仅有圆括号、方括号、花括号组成:");
//	printf("是否满足要求:%d", Judge(S, e));
//	return 0;
//}