#include "stdio.h"
//��key
//int FindKey(int a[N],int key)
//{
//	int i;
//	for (i = 0; i < N; i++)
//	{
//		if (key == a[i])
//		{
//			return i;
//		}
//	}
//	if (i == N)
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int a[10] = { 0,3,4,6,34,2,7,8,9,54 };
//	int key = 3;
//	int i;
//	for (i = 0; i < 10; i++)
//	{
//		if (key == a[i])
//		{
//			return i;
//		}
//	}
//	if (i == 10)
//	{
//		return 0;
//	}
//}
//���������ֵ����Сֵ
//int main()
//{
//	int max, min;
//	int a[5] = { 5,2,22,3,3 };
//	max = a[0];
//	min = a[0];
//	for (int i = 0; i < 5; i++)
//	{
//		if (max < a[i])
//		{
//			max = a[i];
//		}
//		if (min > a[i])
//		{
//			min = a[i];
//		}
//	}
//	printf("%d\n", max);
//	printf("%d", min);
//}
//int FindMaxMin(int a[N])
//{
//	int max, min;
//	max = a[0];
//	min = a[0];
//	for (int i = 0; i < N; i++)
//	{
//		if (max <= a[i])
//		{
//			max = a[i];
//		}
//		if (min >= a[i])
//		{
//			min = a[i];
//		}
//	}
//}
//������������ȵ���������С����˳�����
//int Bubblesort(int x,int y,int z)
//{
//	int a[3];
//	int i, j, temp;
//	a[0] = x;
//	a[1] = y;
//	a[2] = z;
//	for (i = 0; i < 2; i++)
//	{
//		for (j = 0; j < 2 - i; j++)
//		{
//			if (a[j] > a[j + 1])
//			{
//				temp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = temp;
//			}
//		}
//	}
//}
//int main()
//{
//	int x = 3, y = 2, z = 1;
//	int a[3];
//	int i, j, temp;
//	a[0] = x;
//	a[1] = y;
//	a[2] = z;
//	for (i = 0; i < 3 - 1; i++)
//	{
//		for (j = 0; j < 3 - 1 - i; j++)
//		{
//			if (a[j] > a[j + 1])
//			{
//				temp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = temp;
//			}
//		}
//	}
//}
//���һ���㷨ƽ��������3n/2��ƽ���Ƚϴ������ҳ����ֵ����Сֵ
//int main()
//{
//	int a[5] = { 2,3,4,5,6 };
//	int max = a[0];
//	int min = a[0];
//	int i;
//	for (i = 1; i < 5; i++)
//	{
//		if (max < a[i])
//		{
//			max = a[i];
//		}
//		else if (min > a[i])
//		{
//			min = a[i];
//		}
//	}
//	return 0;
//}
//int FindMaxMin()
//{
//	int a[5] = { 2,3,4,5,6 };
//	int max = a[0];
//	int min = a[0];
//	int i;
//	for (i = 1; i < 5; i++)
//	{
//		if (max < a[i])
//		{
//			max = a[i];
//		}
//		else if (min > a[i])
//		{
//			min = a[i];
//		}
//	}
//	return 0;
//}
//����1000������������飬��д�������ҵ���������
//#include <stdlib.h>
//#include <time.h>
//int main()
//{
//	int a;
//	srand((unsigned int)time(NULL));
//	int arrlen = rand();
//	int* p;
//	p = (int*)calloc(arrlen, sizeof(int));
//	if (p != NULL)
//	{
//		for (int i = 0; i < arrlen; i++)
//		{
//			a = rand();
//			p[i] = a;
//		}
//		free(p);
//	}
//	return 0;
//}
//#include <stdlib.h>
//#include <time.h>
//int main()
//{
//	int a,i ,j;
//	int k = 0;
//	srand((unsigned int)time(NULL));
//	int arrlen = rand();
//	int* p;
//	p = (int*)calloc(arrlen, sizeof(int));
//	if (p != NULL)
//	{
//		for (i = 0; i < arrlen; i++)
//		{
//			a = rand();
//			p[i] = a;
//		}
//		for (i = 0; i < arrlen; i++)
//		{
//			k = 0;
//			for (j = 0; j < arrlen; j++)
//			{
//				if (p[i] > p[j])
//				{
//					k++;
//					if (k == 5)
//					{
//						break;
//					}
//				}
//			}
//			if (k == 4)
//			{
//				printf("%d", p[i]);
//				free(p); 
//				return 0;
//			}
//		}
//	}
//	free(p);
//	return 1;
//}
//#include <stdlib.h>
//#include <time.h>
//int main()
//{
//	int a, i, j;
//	int k = 0;
//	srand((unsigned int)time(NULL));//���²���
//	int arrlen = rand();
//	int* p;
//	p = (int*)calloc(arrlen, sizeof(int));//����������ȵ�����
//	if (p != NULL)
//	{
//		for (i = 0; i < arrlen; i++)//������д���������
//		{
//			a = rand();
//			p[i] = a;
//		}
//		for (i = 0; i < arrlen; i++)
//		{
//			printf("%d  ", p[i]);
//		}
//		for (i = 0; i < arrlen; i++)//˳��ѡ��һ������
//		{
//			k = 0;
//			for (j = 0; j < arrlen; j++)//��ѡ�������������������ֱȽ�
//			{
//				if (p[i] > p[j])
//				{
//					k++;
//					if (k == 5)//�ۼƵ���5��˵���Ѿ��ǵ�6�������
//					{
//						break;
//					}
//				}
//			}
//			if (k == 5)//���������4��˵���ǵ���������
//			{
//				printf("%d", p[i]);
//				free(p);
//				return 0;
//			}
//		}
//	}
//	free(p);
//	return 1;
//}
//#include <stdlib.h>
//#include <time.h>
//int main()
//{
//	int a, i, j;
//	int k = 0;
//	srand((unsigned int)time(NULL));//���²���
//	int arrlen = rand();
//	int* p;
//	p = (int*)calloc(arrlen, sizeof(int));//����������ȵ�����
//	if (p != NULL)
//	{
//		for (i = 0; i < arrlen; i++)//������д���������
//		{
//			a = rand();
//			p[i] = a;
//		}
//		for (i = 0; i < arrlen; i++)
//		{
//			printf("%d  ", p[i]);
//		}
//		for (i = 0; i < arrlen; i++)//˳��ѡ��һ������
//		{
//			k = 0;
//			for (j = 0; j < arrlen; j++)//��ѡ�������������������ֱȽ�
//			{
//				if (p[i] > p[j])
//				{
//					k++;
//					if (k == 5)//�ۼƵ���5��˵���Ѿ��ǵ�6�������
//					{
//						break;
//					}
//				}
//			}
//			if (k == 5)//���������4��˵���ǵ���������
//			{
//				printf("%d", p[i]);
//				free(p);
//				return 0;
//			}
//		}
//	}
//	free(p);
//	return 1;
//}
//#include<stdio.h>
//#include<time.h>
//#include<stdlib.h>
//int max5(int b[100]);
//int main()
//{
//	int a[100];
//	int i;
//	srand(time(NULL));
//	for (i = 0; i < 100; i++)
//	{
//		a[i] = rand();
//	}
//	printf("%d", max5(a));
//	return 0;
//}
//
//int max5(int b[100])
//{
//	int m, i, j;
//	for (i = 0; i < 100; i++)
//		for (j = i + 1; j < 100; j++)
//		{
//			if (b[j] > b[i])
//			{
//				m = b[i];
//				b[i] = b[j];
//				b[j] = m;
//			}
//		}
//	return b[4];
//
//}
//#include <stdlib.h>
//#include <time.h>
//int main()
//{
//	int a, i, j;
//	int k = 0;
//	srand((unsigned int)time(NULL));//���²���
//	int arr[1000];
//	for (i = 0; i < 1000; i++)//������д���������
//	{
//		a = rand();
//		arr[i] = a;
//	}
//		for (i = 0; i < 1000; i++)//˳��ѡ��һ������
//		{
//			k = 0;
//			for (j = 0; j < 1000; j++)//��ѡ�������������������ֱȽ�
//			{
//				if (arr[i] > arr[j])
//				{
//					k++;
//					if (k == 5)//�ۼƵ���5��˵���Ѿ��ǵ�6�������
//					{
//						break;
//					}
//				}
//			}
//			if (k == 4)//���������4��˵���ǵ���������
//			{
//				printf("%d", arr[i]);
//				return 0;
//			}
//		}
//}

