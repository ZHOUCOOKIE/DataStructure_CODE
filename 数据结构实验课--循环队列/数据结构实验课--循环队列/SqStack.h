//计算机215 202110244532 周俊安
#define MAXSIZE 50
//typedef char ElemType;
typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int top;
}SqStack;

void InitStack(SqStack*& S);
void DestroyStack(SqStack*& S);
bool StackEmpty(SqStack*& S);
bool StackFull(SqStack*& S);
bool Push(SqStack*& S, ElemType e);
bool Pop(SqStack*& S, ElemType& e);
bool GetStack(SqStack*& S, ElemType& e);


