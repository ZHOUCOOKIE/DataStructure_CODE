#define _CRT_SECURE_NO_WARNINGS
#include "contacts.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	Contact* L1 = NULL, * L2 = NULL;
	int input = 0;
	do
	{
		Menu();
		printf("请选择功能：");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			PrintPlus(L1, L2);
			break;
		case 1:
			system("cls");
			Search(L2);
			break;
		case 2:
			system("cls");
			Add(L1,L2);
			break;
		case 3:
			system("cls");
			Sort(L2);
			break;
		case 4:
			system("cls");
			Modify(L2);
			break;
		case 5:
			system("cls");
			Delete(L1, L2);
			break;
		case 6:
			system("cls");
			Save(L1);
			break;
		case 7:
			system("cls");
			NoSave(L1,L2);
			break;
		case 8:
			system("cls");
			Destroy(L1);
			Destroy(L2);
			printf("退出成功！");
			break;
		default:
			system("cls");
			printf("输入错误！\n");
			break;
		}
	} while (input != 8);
	return 0;
}