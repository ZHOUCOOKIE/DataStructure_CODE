//计算机215 202110244532 周俊安
#define MAXSIZE 50
typedef char ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

void InitQueue(SqQueue*& Q);
void DestroyQueue(SqQueue* Q);
bool QueueEmpty(SqQueue* Q);
bool QueueFull(SqQueue* Q);
bool EnQueue(SqQueue*& Q, ElemType e);
bool DeQueue(SqQueue*& Q, ElemType& e);
bool GetHead(SqQueue*& Q, ElemType& e);

