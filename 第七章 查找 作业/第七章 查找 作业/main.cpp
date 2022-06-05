//�����215��202110244532�ܿ���
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//���һ���㷨�������˳����3��6��2��10��1��8��5��7��4��9���в���˳�򷽷����ҹؼ���5�Ĺ��̡�
//���һ���ǵݹ���㷨�������˳����1��2��3��4��5��6��7��8��9��10���в��ö��ֲ��ҷ����ҹؼ���9�Ĺ��̡�
#define MAXL 10
typedef int KeyType;
typedef int InfoType;

typedef struct {
	KeyType key;
	InfoType data;
}NodeType;

typedef NodeType SeqList[MAXL];

void CreateSeqList(SeqList R, int arr[]);
int SeqSearch(SeqList R1, int n, KeyType k);
int BinSearch(SeqList R, int n, KeyType k);

int main()
{
	SeqList R1, R2;
	int arr1[] = { 3,6,2,10,1,8,5,7,4,9 };
	int arr2[] = { 1,2,3,4,5,6,7,8,9,10 };
	CreateSeqList(R1, arr1);
	CreateSeqList(R2, arr2);
	printf("5�����Ա�1�е�λ��Ϊ%d\n", SeqSearch(R1, 10, 5));
	printf("9�����Ա�2�е�λ��Ϊ%d\n", BinSearch(R2, 10, 9));
	return 0;
}


void CreateSeqList(SeqList R, int arr[])
{
	for (int i = 0; i <= 10; i++)
	{
		R[i].key = arr[i];
	}
}

int SeqSearch(SeqList R1, int n, KeyType k)
{
	int i = 0;
	while (i < n && R1[i].key != k)
	{
		printf("%d��%d�Ƚ�\n", R1[i].key, k);
		i++;
	}
	printf("%d��%d�Ƚ�\n", R1[i].key, k);
	if (i >= n)
		return -1;
	else
		return i;
}

int BinSearch(SeqList R, int n, KeyType k)
{
	int low = 0, high = n - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		printf("��[%d,%d]�бȽ�Ԫ��R[%d]:%d\n", low, high, mid, R[mid]);
		if (R[mid].key == k)
			return mid;
		if (R[mid].key > k)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}