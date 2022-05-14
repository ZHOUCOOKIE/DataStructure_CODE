//计算机215 202110244532 周俊安
typedef struct Node
{
	int data;
	Node* next;
};

struct Queue
{
	Node* rear;
};

void InitQueue(Queue*& q);
bool QueueEmpty(Queue* q);
bool EnQueue(Queue* q, int x);
bool DeQueue(Queue* q, int& e);
void print(Queue* q);