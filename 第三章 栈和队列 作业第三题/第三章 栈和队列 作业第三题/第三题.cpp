#include "SqStack.h"
#include <stdio.h>

//3. 算法设计：设字符串仅有圆括号、方括号、花括号组成，仅能嵌套；使用顺序栈，编写一个算法判断是否匹配。测试“[{ {()}[]}() { [] }]”, “{ [}] ()”。

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
		printf("匹配");
	}
	else
		printf("不匹配");
	return 0;
}