#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int i, j;
	int k = 0;
	srand((unsigned int)time(NULL));//���²���
	int arr[1000];
	for (i = 0; i < 1000; i++)//������д���������
	{
		arr[i] = rand();
	}
	for (i = 0; i < 1000; i++)//˳��ѡ��һ������
	{
		k = 0;
		for (j = 0; j < 1000; j++)//��ѡ�����������������������ֱȽ�
		{
			if (arr[i] > arr[j])
			{
				k++;
				if (k == 5)//�ۼƵ���5��˵���Ѿ��ǵ�6�������
				{
					break;
				}
			}
		}
		if (k == 4)//����Ƚ����������������4��˵���ǵ���������
		{
			printf("%d", arr[i]);
			return 0;
		}
	}
}
