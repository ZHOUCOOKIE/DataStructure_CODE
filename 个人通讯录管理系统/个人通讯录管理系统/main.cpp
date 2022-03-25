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
		printf("��ѡ���ܣ�");
		scanf("%d", &input);
		switch (input)
		{
		case PRINT:
			PrintPlus(L1, L2);
			break;
		case SEARCH:
			Search(L2);
			break;
		case ADD:
			Add(L1,L2);
			system("cls");
			break;
		case SORT:
			Sort(L2);
			system("cls");
			break;
		case MODIFY:
			Modify(L2);
			system("cls");
			break;
		case DELETE:
			Delete(L1, L2);
			system("cls");
			break;
		case SAVE:
			Save(L1);
			system("cls");
			break;
		case NOSAVE:
			NoSave(L1,L2);
			system("cls");
			break;
		case EXIT:
			Destroy(L1);
			Destroy(L2);
			system("cls");
			break;
		default:
			printf("�������\n");
			break;
		}
	} while (input != 8);
	return 0;
}