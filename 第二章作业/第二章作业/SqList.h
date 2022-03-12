#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;

void InitList_Sq(SqList*& L);
bool ListInsert_Sq(SqList*& L, int i, ElemType e);
void ListTraverse_Sq(SqList*& L);
void CreatList_Sq(SqList*& L, ElemType a[], int n);
bool ListEmpty_Sq(SqList* L);
void Union(SqList*& La, SqList*& Lb);
int ListLength_Sq(SqList* L);
int LocateElem_Sq(SqList* L, ElemType e);
bool ListDelete_Sq(SqList*& L, int i, ElemType& e);
void DestroyList_Sq(SqList*& L);
void Listlocate_Sq(SqList*& L, int i);
void Listbubble_sort(SqList*& L, int Maxsize);
void IntersectionList_Sq(SqList*& La, SqList*& Lb, SqList*& Lc);

//1.�ο��̲�P27 - 31���˳������ƣ���˳���Ԫ�ص�����Ϊint���ͣ�
// ��д���µ����������ԡ��������е���˳���Ļ�������������²���:
//��1����ʼ��˳���L
//��2�����β���1��2��3��4
//��3�����˳���L
//��4�����˳���L�ĳ���
//��5�����Ԫ��2���߼�λ��
//��6���ڵ�5��Ԫ��λ���ϲ���Ԫ��5
//��7�����˳���L
//��8��ɾ��L�ĵ�3��Ԫ��
//��9�����˳���L
//��10���ͷ�˳���L
//2.������˳�����ƵĻ����ϣ���ɽ̲�P22�㷨2.2�ĸ�д��ʹ�øó��������С�
//3. �㷨��ƣ�����һ��˳���������Ԫ��Ϊ��������д�㷨������С��0��Ԫ��
// �ƶ������д���0��Ԫ��ǰ�棬Ҫ���㷨��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1).
// ����ʾ�����㷨�������˳���Ļ�������������ֱ�Ӳ���˳���L��
//4.��дһ���㷨��һ�����Ա�L����˳��洢�ṹ������������Ԫ��Ϊ������
//ɾ������ֵ��[x, y]֮�������Ԫ�أ�Ҫ���㷨��ʱ�临�Ӷ�ΪO(n)��
//�ռ临�Ӷ�ΪO(1).����ʾ�����㷨�������˳���Ļ�������������ֱ�Ӳ���˳���L��
