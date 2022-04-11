//计算机215 202110244532 周俊安
typedef char ElemType;

typedef struct rear {
	ElemType data;
	struct rear* next,*r;
}rear;

bool EnRear(rear*& R, ElemType e);
void InitRear(rear*& R);