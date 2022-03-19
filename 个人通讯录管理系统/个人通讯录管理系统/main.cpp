#define _CRT_SECURE_NO_WARNINGS
#include "contacts.h"
#include <stdio.h>
enum Option
{
	PRINT,
	SEARCH,
	ADD,
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
			PrintPlus(L1,L2);
			break;
		case SEARCH:
			break;
		case ADD:
			Add(L1);
			break;
		case MODIFY:
			break;
		case DELETE:
			Delete(L1);
			break;
		case SAVE:
			Save(L1);
			L1 = NULL;
			break;
		case NOSAVE:
			NoSave(L1);
			break;
		case EXIT:
			Destroy(L1);
			break;
		default:
			printf("输入错误！");
			break;
		}
	} while (input != 7);
	return 0;
}