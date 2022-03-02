#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int n = 1000, arr[1000];
	int i, max, nextMax;
	srand(time(0));
	arr[0] = rand();//产生随机数 
	max = nextMax = arr[0];//初始化max和nextMax 
	for (i = 1; i < 1000; i++)//查找最大值和次大值
	{
		arr[i] = rand();
		if (arr[i] > max)
			max = arr[i];
		else if (arr[i] > nextMax && arr[i] < max)
			nextMax = arr[i];
	}
	printf("max is %d\n", max);
	printf("nextMax is %d\n", nextMax);
	return 0;
}

