//�����215 32 �ܿ���
#include<stdio.h>
#define MAXL 15
typedef int keyType;
typedef int InfoType;
typedef struct RecordType {
	keyType key;
	InfoType otherdata;
}RecordType;

void SelectSort(RecordType r[], int n);//��ѡ�������㷨
void DirectInsertSort(RecordType r[], int n);//ֱ�Ӳ��������㷨
void BubbleSort1(RecordType r[], int n);//ð�������㷨

int main()
{
	int arr[10] = { 16,3,5,8,43,45,2,1,34,7 };
	RecordType r[MAXL];
	for (int i = 1; i <= 10; i++)
	{
		r[i].key = arr[i - 1];
	}
	printf("�ؼ�������:");
	for (int i = 1; i <= 10; i++)
	{
		printf("%d  ", arr[i - 1]);
	}
	printf("\n��ѡ�������㷨\n");
	SelectSort(r, 10);
	for (int k = 1; k <= 10; k++)
		printf("%d ", r[k].key);

	for (int i = 1; i <= 10; i++)
	{
		r[i].key = arr[i - 1];
	}
	printf("\nֱ�Ӳ��������㷨\n");
	DirectInsertSort(r, 10);
	for (int k = 1; k <= 10; k++)
		printf("%d ", r[k].key);

	for (int i = 1; i <= 10; i++)
	{
		r[i].key = arr[i - 1];
	}
	printf("\nð�������㷨\n");
	BubbleSort1(r, 10);
	for (int k = 1; k <= 10; k++)
		printf("%d ", r[k].key);
	return 0;
}

void SelectSort(RecordType r[], int n)
{
	int i, j, t;
	RecordType tmp;
	for (i = 0; i < n; i++)
	{
		t = i;
		for (j = i + 1; j < n + 1; j++)
		{
			if (r[t].key > r[j].key)
				t = j;
		}
		if (t != i)
		{
			tmp = r[t];
			r[t] = r[i];
			r[i] = tmp;
		}
	}
}

void BubbleSort1(RecordType r[], int n)
{
	int i, j, change;
	change = 1;
	for (i = 1; i < n && change; ++i)
	{
		change = 0;
		for (j = 1; j < n; ++j)
		{
			if (r[j].key > r[j + 1].key)
			{
				r[0] = r[j];
				r[j] = r[j + 1];
				r[j + 1] = r[0];
				change = 1;
			}
		}
	}
}

void DirectInsertSort(RecordType r[], int n)
{
	int i, j, temp;
	for (i = 1; i < n + 1; i++)
	{
		if (r[i].key < r[i - 1].key)
		{
			temp = r[i].key;
			for (j = i - 1; temp < r[j].key; j--)
				r[j + 1].key = r[j].key;
			r[j + 1].key = temp;
		}
	}
}