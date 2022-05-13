#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int i, j;
	int k = 0;
	srand((unsigned int)time(NULL));//重新播种
	int arr[1000];
	for (i = 0; i < 1000; i++)//往数组写入随机数字
	{
		arr[i] = rand();
	}
	for (i = 0; i < 1000; i++)//顺序选出一个数字
	{
		k = 0;
		for (j = 0; j < 1000; j++)//将选出来的数字与数组其他数字比较
		{
			if (arr[i] > arr[j])
			{
				k++;
				if (k == 5)//累计等于5次说明已经是第6大的数字
				{
					break;
				}
			}
		}
		if (k == 4)//如果比较完仅大于其他数字4次说明是第五大的数字
		{
			printf("%d", arr[i]);
			return 0;
		}
	}
}
