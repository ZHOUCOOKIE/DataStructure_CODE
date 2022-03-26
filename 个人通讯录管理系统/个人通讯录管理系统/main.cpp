#define _CRT_SECURE_NO_WARNINGS
#include "contacts.h"
#include <stdio.h>
#include <stdlib.h>
enum Option
{
	PRINT,
	SEARCH,
	ADD,
	SORT,
	MODIFY,
	DELETE,
	SAVE,
	NOSAVE,
	EXIT
};

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
		case PRINT:
			PrintPlus(L1, L2);
			break;
		case SEARCH:
			system("cls");
			Search(L2);
			system("cls");
			break;
		case ADD:
			system("cls");
			Add(L1,L2);
			break;
		case SORT:
			system("cls");
			Sort(L2);
			break;
		case MODIFY:
			system("cls");
			Modify(L2);
			break;
		case DELETE:
			system("cls");
			Delete(L1, L2);
			break;
		case SAVE:
			system("cls");
			Save(L1);
			break;
		case NOSAVE:
			system("cls");
			NoSave(L1,L2);
			break;
		case EXIT:
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