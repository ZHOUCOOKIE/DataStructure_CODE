
//1.��дһ������ʵ��˳���ĸ��ֻ������㣬��ʵ���˳���Ԫ�ص�����Ϊchar�����������е���˳���Ļ�������������²���:
//��1����ʼ��˳���L
//��2��������˳���L��β������a��b��c��d��e��5���ַ�
//��3�����˳���L
//��4���ж�˳���L�Ƿ�Ϊ��
//��5�����˳���L�ĳ���
//��6�����˳���L�ĵ�3��Ԫ��
//��7�����Ԫ��a���߼�λ��
//��8���ڵ�4��Ԫ��λ���ϲ����ַ�f
//��9�����˳���L
//��10��ɾ��L�ĵ�3��Ԫ��
//��11�����˳���L
//��12���ͷ�˳���L
//����ʵ�鲽��
//1.��1���ο��̲����˳������ƣ��ļ���ΪSqList.cpp��
//��2����SqList.cpp�б�дmain���������ȵ���˳���ĸ�������Ȼ�������ƺõ�˳������������ʵ�����ݺ�Ҫ���е�12��������
//#include <stdio.h>
//#include <stdlib.h>
//#define MaxSize 60
//typedef char ElemType;
//
//typedef struct {
//	ElemType data[MaxSize];
//	int length;
//}SqList;
//
//void CreatList_Sq(SqList*& L, ElemType a[], int n);
//void InitList_Sq(SqList*& L);
//bool ListInsert_Sq(SqList*& L, int i, ElemType e);
//void ListTraverse_Sq(SqList*& L);
//bool ListEmpty_Sq(SqList* L);
//int ListLength_Sq(SqList* L);
//int LocateElem_Sq(SqList* L, ElemType e);
//bool ListDelete_Sq(SqList*& L, int i, ElemType& e);
//void DestroyList_Sq(SqList*& L);
//void Listabc_Sq(SqList*& L, int i);
//
//
//int main()
//{
//	ElemType e;
//	SqList* L;
//	InitList_Sq(L);
//	ListInsert_Sq(L, 1, 'e');
//	ListInsert_Sq(L, 1, 'd');
//	ListInsert_Sq(L, 1, 'c');
//	ListInsert_Sq(L, 1, 'b');
//	ListInsert_Sq(L, 1, 'a');
//	ListTraverse_Sq(L);
//	printf("%d\n",ListEmpty_Sq(L)); 
//	printf("%d\n", ListLength_Sq(L));
//	Listabc_Sq(L,3);
//	printf("%d\n", LocateElem_Sq(L, 'a'));
//	ListInsert_Sq(L, 4, 'f');
//	ListTraverse_Sq(L);
//	ListDelete_Sq(L, 3, e);
//	ListTraverse_Sq(L);
//	DestroyList_Sq(L);
//
//}
//
////��1����ʼ��˳���L
////��2��������˳���L��β������a��b��c��d��e��5���ַ�
////��3�����˳���L
////��4���ж�˳���L�Ƿ�Ϊ��
////��5�����˳���L�ĳ���
////��6�����˳���L�ĵ�3��Ԫ��
////��7�����Ԫ��a���߼�λ��
////��8���ڵ�4��Ԫ��λ���ϲ����ַ�f
////��9�����˳���L
////��10��ɾ��L�ĵ�3��Ԫ��
////��11�����˳���L
////��12���ͷ�˳���L
//
//void Listabc_Sq(SqList*& L,int i)
//{
//	printf("%c", L->data[i-1]);
//	printf("\n");
//}
//
//void InitList_Sq(SqList*& L)
//{
//	L = (SqList*)malloc(sizeof(SqList));
//	L->length = 0;
//}
//
//bool ListInsert_Sq(SqList*& L, int i, ElemType e)
//{
//	int j;
//	if (L->length == MaxSize)return false;
//	i--;
//	for (j = L->length; j > i; j--)
//		L->data[j] = L->data[j - 1];
//	L->data[i] = e;
//	L->length++;
//	return true;
//}
//
//void ListTraverse_Sq(SqList*& L)
//{
//	int i;
//	for (i = 0; i < L->length; i++)
//		printf("%c", L->data[i]);
//	printf("\n");
//}
//
//bool ListEmpty_Sq(SqList* L)
//{
//	return(L->length);
//}
//
//int ListLength_Sq(SqList* L)
//{
//	return(L->length);
//}
//
//int LocateElem_Sq(SqList* L, ElemType e)
//{
//	int i = 0;
//	while (i < L->length && L->data[i] != e)
//		i++;
//	if (i < L->length)
//		return i + 1;
//	else
//		return 0;
//}
//
//bool ListDelete_Sq(SqList*& L, int i, ElemType& e)
//{
//	int j;
//	if ((i < 1) || (i > L->length))
//		return false;
//	i--;
//	e = L->data[i];
//	for (j = i; j < L->length - 1; j++)
//		L->data[j] = L->data[j + 1];
//	L->length--;
//	return true;
//}
//
//void DestroyList_Sq(SqList*& L)
//{
//	free(L);
//}