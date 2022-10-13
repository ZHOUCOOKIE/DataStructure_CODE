#include <stdio.h>
#define MAXL 15

typedef int keyType;
typedef int InfoType;

typedef struct {
	keyType key;
	InfoType data;
}NodeType;
typedef NodeType SeqList[MAXL];

typedef struct RecordType {
	keyType key;
	InfoType otherdata;
}RecordType;

int SeqSearch(SeqList R, int n, keyType k);//顺序查找算法
int BinSearch(SeqList R, int n, keyType k);//折半查找算法
void DirectInsertSort(RecordType r[], int n);//直接插入排序算法
void ShellSort(RecordType r[], int n, int dlta[], int t);//希尔排序算法
void QKSort(RecordType r[], int low, int high);//快速排序算法
void HeapSort(RecordType r[], int n);//堆排序算法

int main()
{
	int arr1[] = { 3,6,2,10,1,8,5,7,4,9 };
	int arr2[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr3[] = { 39,80,76,41,13,29,50,78,30,11,100,7,41,86 };
	SeqList R1, R2;
	RecordType r[MAXL];
	for (int i = 0; i < 10; i++)
	{
		R1[i].key = arr1[i];
	}
	printf("(1)顺序查找算法\n");
	printf("关键字序列:");
	for (int i = 0; i < 10; i++)
	{
		printf("%d  ", arr1[i]);
	}
	printf("\n");
	printf("\n元素5的位置是:%d\n", SeqSearch(R1, 10, 5));
	for (int i = 0; i < 10; i++)
	{
		R2[i].key = arr2[i];
	}
	printf("(2)折半查找算法\n");
	printf("关键字序列:");
	for (int i = 0; i < 10; i++)
	{
		printf("%d  ", arr2[i]);
	}
	printf("\n");
	printf("元素9的位置是%d\n", BinSearch(R2, 10, 9));
	for (int i = 0; i < 14; i++)
	{
		r[i].key = arr3[i];
	}
	printf("(3)直接插入排序算法\n");
	printf("排序测试关键字序列:");
	for (int i = 0; i < 14; i++)
	{
		printf("%d  ", arr3[i]);
	}
	printf("\n");
	DirectInsertSort(r, 14);
	for (int i = 0; i < 14; i++)
	{
		r[i].key = arr3[i];
	}
	printf("(4)希尔排序算法排序过程\n");
	int C[] = { 5,3,1 };
	ShellSort(r, 14, C, 3);
	for (int i = 0; i < 14; i++)
	{
		r[i].key = arr3[i];
	}
	printf("(5)快速排序算法排序过程\n");
	QKSort(r, 0, 13);
	for (int i = 0; i < 14; i++)
	{
		r[i].key = arr3[i];
	}
	printf("(6)堆排序算法排序过程\n");
	HeapSort(r, 14);
	return 0;
}

int SeqSearch(SeqList R, int n, keyType k)
{
	printf("查找5所比较的关键字：\n");
	int i = 0;
	while (i < n && R[i].key != k)
	{
		printf("%d  ", R[i].key);
		i++;
	}
	if (i >= n)
		return -1;
	else
	{
		printf("%d  ", R[i].key);
		return i + 1;
	}
}

int BinSearch(SeqList R, int n, keyType k)
{
	printf("查找9的比较过程如下：\n");
	int low = 0, high = n - 1, mid, s = 0;
	while (low <= high)
	{
		s++;
		mid = (low + high) / 2;
		if (R[mid].key == k)
		{
			printf("  第%d次比较:在[%d,%d]中比较元素R[%d]:%d\n", s, low, high, mid, R[mid].key);
			return mid + 1;
		}
		if (R[mid].key > k)
		{
			printf("  第%d次比较:在[%d,%d]中比较元素R[%d]:%d\n", s, low, high, mid, R[mid].key);
			high = mid - 1;
		}
		else
		{
			printf("  第%d次比较:在[%d,%d]中比较元素R[%d]:%d\n", s, low, high, mid, R[mid].key);
			low = mid + 1;
		}
	}
	return -1;
}

void DirectInsertSort(RecordType r[], int n)
{
	printf("直接插入算法排序过程:\n");
	int i, j, k;
	for (i = n; i > 0; i--)
		r[i].key = r[i - 1].key;
	for (i = 2; i <= n; i++)
	{
		if (r[i].key < r[i - 1].key)
		{
			r[0] = r[i];
			j = i - 1;
			while (r[0].key < r[j].key)
			{
				r[j + 1] = r[j];
				j = j - 1;
			}
			r[j + 1] = r[0];
		}
		for (k = 1; k <= n; k++) printf("%4d", r[k].key);
		printf("\n");
	}
}

void ShellInsert(RecordType r[], int n, int dk)
{
	int i, j;
	for (i = dk + 1; i <= n; i++)
	{
		if (r[i].key < r[i - dk].key)
		{
			r[0] = r[i];
			for (j = i - dk; j > 0 && r[0].key < r[j].key; j = j - dk)
				r[j + dk] = r[j];
			r[j + dk] = r[0];
		}
	}
	for (int k = 1; k <= n; k++)
		printf("%4d", r[k].key);
	printf("\n");
}
void ShellSort(RecordType r[], int n, int dlta[], int t)
{
	for (int i = n; i > 0; i--) 
		r[i].key = r[i - 1].key;
	for (int k = 0; k < t; k++)
		ShellInsert(r, n, dlta[k]);
}
int QKPass(RecordType r[], int low, int high)
{
	NodeType tmp;
	tmp.key = r[low].key;
	while (low < high)
	{
		while (low < high && r[high].key >= tmp.key)
			high--;
		if (low < high)
		{
			r[low] = r[high];
			low++;
		}
		while (low < high && r[low].key < tmp.key)
			low++;
		if (low < high)
		{
			r[high] = r[low];
			high--;
		}
	}
	r[low].key = tmp.key;
	return low;
}
void QKSort(RecordType r[], int low, int high)
{
	int pos;
	if (low < high)
	{
		pos = QKPass(r, low, high);
		for (int k = 0; k < 14; k++)
			printf("%4d", r[k].key);
		printf("\n");
		QKSort(r, low, pos - 1);
		QKSort(r, pos + 1, high);
	}
}
void HeapAdjust(RecordType r[], int s, int m)
{
	int j;
	NodeType rc;
	rc.key = r[s].key;
	for (j = 2 * s; j <= m; j = j * 2)
	{
		if (j < m&& r[j].key < r[j + 1].key)
			j = j + 1;
		if (rc.key >= r[j].key)
			break;
		else
		{
			r[s] = r[j];
			s = j;
		}
	}
	r[s].key = rc.key;
}
void HeapSort(RecordType r[], int n)
{
	int i;
	for (int i = n; i > 0; i--)
		r[i].key = r[i - 1].key;
	NodeType tmp;
	for (i = n / 2; i >= 1; i--)
		HeapAdjust(r, i, n);
	for (i = n; i > 1; i--)
	{
		tmp.key = r[1].key;
		r[1].key = r[i].key;
		r[i].key = tmp.key;
		HeapAdjust(r, 1, i - 1);
		for (int k = 1; k <= 14; k++) 
			printf("%4d", r[k].key);
		printf("\n");
	}
}