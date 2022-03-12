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

//1.参考教材P27 - 31完成顺序表的设计，设顺序表元素的类型为int类型，
// 并写如下的主函数测试。主函数中调用顺序表的基本操作完成如下操作:
//（1）初始化顺序表L
//（2）依次插入1，2，3，4
//（3）输出顺序表L
//（4）输出顺序表L的长度
//（5）输出元素2的逻辑位置
//（6）在第5个元素位置上插入元素5
//（7）输出顺序表L
//（8）删除L的第3个元素
//（9）输出顺序表L
//（10）释放顺序表L
//2.在以上顺序表设计的基础上，完成教材P22算法2.2的改写，使得该程序能运行。
//3. 算法设计：假设一个顺序表中所有元素为整数，编写算法将所有小于0的元素
// 移动到所有大于0的元素前面，要求算法的时间复杂度为O(n)，空间复杂度为O(1).
// （提示：该算法无需调用顺序表的基本操作，而是直接操作顺序表L）
//4.编写一个算法，一个线性表L采用顺序存储结构，若其中所有元素为整数，
//删除数据值在[x, y]之间的所有元素，要求算法的时间复杂度为O(n)，
//空间复杂度为O(1).（提示：该算法无需调用顺序表的基本操作，而是直接操作顺序表L）
