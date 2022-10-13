#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	for (int i = 0; i < numsSize; ++i) {
		for (int j = i + 1; j < numsSize; ++j) {
			if (nums[i] + nums[j] == target) {
				int* ret = (int*)malloc(sizeof(int) * 2);
				ret[0] = i, ret[1] = j;
				*returnSize = 2;
				return ret;
			}
		}
	}
	*returnSize = 0;
	return NULL;
}

int main()
{
	int *a;
	int num[4] = { 1,2,3,4 };
	a = twoSum(num, 4, 5, 0);
	printf("%d", &a);
	return 0;
}