//计算机215 202110244532 周俊安
#include "SqStack.h"
#include <stdlib.h>

void InitStack(SqStack *&S)
{
	S = (SqStack*)malloc(sizeof(SqStack));
	S->top = 0;
}

void DestroyStack(SqStack*& S)
{
	free(S);
}

bool StackEmpty(SqStack*& S)
{
	if (S->top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool StackFull(SqStack*& S)
{
	if (S->top == MAXSIZE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Push(SqStack*& S, ElemType e)
{
	if (S->top == MAXSIZE)
	{
		return false;
	}
	else
	{
		S->data[S->top] = e;
		S->top++;
		return true;
	}
}

bool Pop(SqStack*& S, ElemType &e)
{
	if (S->top == 0)
	{
		return false;
	}
	else
	{
		S->top--;
		e = S->data[S->top];
		return true;
	}
}

bool GetStack(SqStack*& S,ElemType &e)
{
	if (S->top == 0)
	{
		return false;
	}
	else
	{
		e = S->data[S->top - 1];
		return true;
	}
}