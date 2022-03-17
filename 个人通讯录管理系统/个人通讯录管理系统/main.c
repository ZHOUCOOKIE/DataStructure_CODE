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
	SAVEANDEXIT,
	EXITBUTNOSAVE
};

Contact1* Add2(void)
{
	Contact1* p;
	p = (Contact1*)malloc(sizeof(Contact1));
	p->Next = NULL;
	Contact1* q;
	q = (Contact1*)malloc(sizeof(Contact1));
	q->age = 11;
	p->Next = q;
	q->Next = NULL;
	return p;
}

int main()
{
	Contact1* L = NULL ;
	int input = 0;
	do
	{
		Menu();
		printf("ÇëÑ¡Ôñ¹¦ÄÜ£º");
		scanf("%d", &input);
		switch (input)
		{
		case PRINT:
			Print(L->Next);
			break;
		case SEARCH:
			break;
		case ADD:
			//Add(L1);
			L = Add2();
			break;
		case MODIFY:
			break;
		case DELETE:
			break;
		case SAVEANDEXIT:
			break;
		case EXITBUTNOSAVE:
			break;
		default:
			break;
		}
	} while (input);
	return 0;
}