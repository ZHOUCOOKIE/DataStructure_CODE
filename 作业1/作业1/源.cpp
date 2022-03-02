#include "stdio.h"
//找key
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
//找数组最大值和最小值
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
//输入三个不相等的整数，从小到大顺序输出
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
//设计一个算法平均不多于3n/2的平均比较次数，找出最大值与最小值
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
//生成1000个随机整数数组，编写函数查找第五大的整数
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
//	srand((unsigned int)time(NULL));//重新播种
//	int arrlen = rand();
//	int* p;
//	p = (int*)calloc(arrlen, sizeof(int));//生成随机长度的数组
//	if (p != NULL)
//	{
//		for (i = 0; i < arrlen; i++)//往数组写入随机数字
//		{
//			a = rand();
//			p[i] = a;
//		}
//		for (i = 0; i < arrlen; i++)
//		{
//			printf("%d  ", p[i]);
//		}
//		for (i = 0; i < arrlen; i++)//顺序选出一个数字
//		{
//			k = 0;
//			for (j = 0; j < arrlen; j++)//将选出来的数字与所有数字比较
//			{
//				if (p[i] > p[j])
//				{
//					k++;
//					if (k == 5)//累计等于5次说明已经是第6大的数字
//					{
//						break;
//					}
//				}
//			}
//			if (k == 5)//如果仅大于4次说明是第五大的数字
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
//	srand((unsigned int)time(NULL));//重新播种
//	int arrlen = rand();
//	int* p;
//	p = (int*)calloc(arrlen, sizeof(int));//生成随机长度的数组
//	if (p != NULL)
//	{
//		for (i = 0; i < arrlen; i++)//往数组写入随机数字
//		{
//			a = rand();
//			p[i] = a;
//		}
//		for (i = 0; i < arrlen; i++)
//		{
//			printf("%d  ", p[i]);
//		}
//		for (i = 0; i < arrlen; i++)//顺序选出一个数字
//		{
//			k = 0;
//			for (j = 0; j < arrlen; j++)//将选出来的数字与所有数字比较
//			{
//				if (p[i] > p[j])
//				{
//					k++;
//					if (k == 5)//累计等于5次说明已经是第6大的数字
//					{
//						break;
//					}
//				}
//			}
//			if (k == 5)//如果仅大于4次说明是第五大的数字
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
//	srand((unsigned int)time(NULL));//重新播种
//	int arr[1000];
//	for (i = 0; i < 1000; i++)//往数组写入随机数字
//	{
//		a = rand();
//		arr[i] = a;
//	}
//		for (i = 0; i < 1000; i++)//顺序选出一个数字
//		{
//			k = 0;
//			for (j = 0; j < 1000; j++)//将选出来的数字与所有数字比较
//			{
//				if (arr[i] > arr[j])
//				{
//					k++;
//					if (k == 5)//累计等于5次说明已经是第6大的数字
//					{
//						break;
//					}
//				}
//			}
//			if (k == 4)//如果仅大于4次说明是第五大的数字
//			{
//				printf("%d", arr[i]);
//				return 0;
//			}
//		}
//}

