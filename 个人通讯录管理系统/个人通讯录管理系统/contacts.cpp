#include "contacts.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Menu()
{
	printf("--------------------------------------------����ͨѶ¼����ϵͳ------------------------------------------\n");
	printf("---------------------------------0����ʾ������ϵ��---------1��������ϵ��--------------------------------\n");
	printf("---------------------------------2�������ϵ����Ϣ---------3��������������ϵ��--------------------------\n");
	printf("---------------------------------4���޸���ϵ����Ϣ---------5��ɾ����ϵ����Ϣ----------------------------\n");
	printf("---------------------------------6������-------------------7��������------------------------------------\n");
	printf("----------------------------------------------8 ���˳�����----------------------------------------------\n");
}

void display(Contact*& L1, Contact*& L2)
{
	system("cls");//��������
	if (L2 == NULL)
		load(L2);
	Print(L2);
	if (L1 == NULL)
	{
		printf("�޻�δ�����������ϵ����Ϣ��\n");
		return;
	}
	else
	{
		printf("����Ϊδ�����ͨѶ¼��Ϣ��\n");
		Print(L1);
	}
}

void Print(Contact*& L)
{
	if (L == NULL)//��ֹ�Ƿ������ڴ�
		return;
	Contact* p = L->Next;
	printf("  ����  ����     �Ա�\t �ֻ�����      QQ����\t      ������λ\t               ����\n");
	while (p != NULL && p->Next != NULL)
	{
		printf(" %4d  %-10s %-5s %10s  %-12lld %-20s %-30s\n", p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
		p = p->Next;
	}
	if(p != NULL)
		printf(" %4d  %-10s %-5s %10s  %-12lld %-20s %-30s\n", p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
}

void search(Contact*& L2)
{
	system("cls");
	int search = 0;
	char judge;
	if (L2 == NULL)
	{
		load(L2);
		if (L2 == NULL)
		{
			return;
		}
	}
	while (1)
	{
		Contact* p = L2->Next;
		printf("��ѡ��Ҫ���ҵķ�ʽ(1������ 2���ֻ��� 3��QQ�� 4����λ 5������):");
		scanf("%d", &search);
		switch (search)
		{
		case 1:
			char name[MAX_NAME];
			printf("������Ҫ���ҵ����֣�");
			scanf("%s", name);
			while (p->Next != NULL)
			{
				if (strcmp(p->Name, name) == 0)
				{
					break;
				}
				p = p->Next;
			}
			if (strcmp(p->Name, name) != 0)
			{
				printf("δ�ҵ���ϵ�ˣ�\n");
				break;
			}
			printf("����Ϊ%s��ͨѶ¼��Ϣ��%d %s %s %s %lld %s %s\n", p->Name, p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
			break;
		case 2:
			char phnum[MAX_PHNUM];
			printf("������Ҫ���ҵĵ绰��");
			scanf("%s", phnum);
			while (p->Next != NULL)
			{
				if (strcmp(p->PhNum, phnum) == 0)
				{
					break;
				}
				p = p->Next;
			}
			if (strcmp(p->PhNum, phnum) != 0)
			{
				printf("δ�ҵ���ϵ�ˣ�\n");
				break;
			}
			printf("�绰Ϊ%s��ͨѶ¼��Ϣ��%d %s %s %s %lld %s %s\n", p->PhNum, p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
			break;
		case 3:
		{
			long long qqnum;
			printf("������Ҫ���ҵ�QQ��");
			scanf("%lld", &qqnum);
			while (p->Next != NULL)
			{
				if (p->QQNuM == qqnum)
				{
					break;
				}
				p = p->Next;
			}
			if (p->QQNuM != qqnum)
			{
				printf("δ�ҵ���ϵ�ˣ�\n");
				break;
			}
			printf("QQΪ%lld��ͨѶ¼��Ϣ��%d %s %s %s %lld %s %s\n", p->QQNuM, p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
		}
		break;
		case 4:
		{
			char comp[MAX_COMP];
			int i = 0;
			printf("������Ҫ���ҵĵ�λ��");
			scanf("%s", comp);
			while (p->Next != NULL)
			{
				if (strcmp(p->ComP, comp) == 0)
				{
					printf("��λΪ%s��ͨѶ¼��Ϣ��%d %s %s %s %lld %s %s\n", p->ComP, p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
					i++;
				}
				p = p->Next;
			}
			if (strcmp(p->ComP, comp) == 0)
			{
				printf("��λΪ%s��ͨѶ¼��Ϣ��%d %s %s %s %lld %s %s\n", p->ComP, p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
				i++;
			}
			if (i == 0)
			{
				system("cls");
				printf("δ�ҵ���ϵ�ˣ�\n");
				break;
			}
			break;
		}
		case 5:
			char email[MAX_EMAIL];
			printf("������Ҫ���ҵ����䣺");
			scanf("%s", email);
			while (p->Next != NULL)
			{
				if (strcmp(p->Email, email) == 0)
				{
					break;
				}
				p = p->Next;
			}
			if (strcmp(p->Email, email) != 0)
			{
				printf("δ�ҵ���ϵ�ˣ�\n");
				break;
			}
			printf("����Ϊ%s��ͨѶ¼��Ϣ��%d %s %s %s %lld %s %s\n", p->Email, p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
			break;
		}
		printf("�Ƿ�ȡ�����ң���Y/N��\n");
		getchar();//��ֹ��֮ǰ�м�������
		scanf("%c", &judge);
		if (judge == 'Y')
		{
			break;
		}
	}
}

void enter(Contact*& L1, Contact*& L2)
{
	if (L2 == NULL)
	{
		load(L2);
	}
	Contact* s, * p = L2, * r;
	int i = 0;
	if (L1 == NULL)
	{
		L1 = (Contact*)calloc(1, sizeof(Contact));
	}
	r = L1;
	while (r->Next != NULL)
	{
		r = r->Next;
	}
	printf("��������Ҫ��Ӷ���λ��ϵ�ˣ�");
	scanf("%d", &i);
	for (; i > 0; i--)//һ�������뵥����L1��
	{
		printf("��������Ϣ��(���� ���� �Ա� �ֻ����� QQ���� ������λ ����)");
		s = (Contact*)calloc(1, sizeof(Contact));
		if (s == NULL)
		{
			printf("�����ڴ�ʧ�ܣ�\n");
			return;
		}
		scanf("%d %s %s %s %lld %s %s", &s->age, s->Name, s->Sex, s->PhNum, &s->QQNuM, s->ComP, s->Email);
		if (L2 != NULL)
		{
			p = L2->Next;
			char name[MAX_NAME];
			strcpy(name, s->Name);
			while (p->Next != NULL)
			{
				if (strcmp(p->Name, name) == 0)//��ֹ����
				{
					break;
				}
				p = p->Next;
			}
			while (strcmp(p->Name, name) == 0)
			{
				printf("���������ϵ�˴����������޸ĺ������룡\n");
				printf("������������Ϣ��(���� ���� �Ա� �ֻ����� QQ���� ������λ ����)");
				scanf("%d %s %s %s %lld %s %s", &s->age, s->Name, s->Sex, s->PhNum, &s->QQNuM, s->ComP, s->Email);
				strcpy(name, s->Name);
			}
		}

		r->Next = s;
		r = s;
	}
	r->Next = NULL;
	system("cls");
	printf("�����ɹ����ɰ�6����������߼����������������\n");
}

void Modify(Contact*& L2)
{
	printf("��ѡ���޸���ϵ�˵���ʾ��ʽ��1����ʾȫ��ͨѶ¼���Ҵ��� 2������ָ����ϵ�ˣ�");
	int modify = 0;
	scanf("%d", &modify);
	if (L2 == NULL)
	{
		load(L2);
		if (L2 == NULL)
		{
			return;
		}
	}
	switch (modify)
	{
	case 1:
	{
		Print(L2);
		printf("��ѡ���޸ĵڼ��е���ϵ��:");
		int i = 0;
		int judge = 0;
		int interrupt = 0;
		Contact* p = L2->Next;
		scanf("%d", &i);
		for (; i > 1; i--)//ʹָ��ָ��Ҫ�޸ĵ�������ϵ��
		{
			p = p->Next;
		}
		while (1)
		{
			printf("��ѡ��Ҫ�޸ĵ���Ϣ��1������ 2������ 3���Ա� 4���ֻ��� 5��QQ�� 6����λ 7�����䣩");
			scanf("%d", &judge);
			switch (judge)
			{
			case 1:
				int age;
				printf("������������Ϣ��");
				scanf("%d", &age);
				p->age = age;
				break;
			case 2:
				char name[MAX_NAME];
				printf("������������Ϣ��");
				scanf("%s", name);
				strcpy(p->Name, name);
				break;
			case 3:
				char sex[MAX_SEX];
				printf("������������Ϣ��");
				scanf("%s", sex);
				strcpy(p->Sex, sex);
				break;
			case 4:
				char phnum[MAX_PHNUM];
				printf("������������Ϣ��");
				scanf("%s", phnum);
				strcpy(p->PhNum, phnum);
				break;
			case 5:
				long long qqnum;
				printf("������������Ϣ��");
				scanf("%lld", &qqnum);
				p->QQNuM = qqnum;
				break;
			case 6:
				char comp[MAX_COMP];
				printf("������������Ϣ��");
				scanf("%s", comp);
				strcpy(p->ComP, comp);
				break;
			case 7:
				char email[MAX_EMAIL];
				printf("������������Ϣ��");
				scanf("%s", email);
				strcpy(p->Email, email);
				break;
			}
			printf("�Ƿ���������޸ģ���0���� 1���ǣ�\n");
			scanf("%d", &interrupt);
			if (interrupt == 0)
			{
				break;
			}
		}
		system("cls");
		printf("�޸���ɣ�\n");
		break;
	}
	case 2:
		int search = 0, jud = 0;
		char judge;
		if (L2 == NULL)
		{
			load(L2);
			if (L2 == NULL)
			{
				return;
			}
		}
		Contact* p = L2->Next;
		while (1)
		{
			printf("��ѡ��Ҫ���ҵķ�ʽ��(1������ 2���ֻ��� 3��QQ�� 4������):");
			scanf("%d", &search);
			switch (search)
			{
			case 1:
				char name[MAX_NAME];
				printf("������Ҫ���ҵ����֣�");
				scanf("%s", name);
				while (p->Next != NULL)
				{
					if (strcmp(p->Name, name) == 0)
					{
						break;
					}
					p = p->Next;
				}
				if (strcmp(p->Name, name) != 0)
				{
					printf("δ�ҵ���ϵ�ˣ�\n");
					break;
				}
				printf("��ѡ��Ҫ�޸ĵ���Ϣ��1������ 2������ 3���Ա� 4���ֻ��� 5��QQ�� 6����λ 7�����䣩:");
				scanf("%d", &jud);
				switch (jud)
				{
				case 1:
					int age;
					printf("������������Ϣ��");
					scanf("%d", &age);
					p->age = age;
					break;
				case 2:
					char name[MAX_NAME];
					printf("������������Ϣ��");
					scanf("%s", name);
					strcpy(p->Name, name);
					break;
				case 3:
					char sex[MAX_SEX];
					printf("������������Ϣ��");
					scanf("%s", sex);
					strcpy(p->Sex, sex);
					break;
				case 4:
					char phnum[MAX_PHNUM];
					printf("������������Ϣ��");
					scanf("%s", phnum);
					strcpy(p->PhNum, phnum);
					break;
				case 5:
					long long qqnum;
					printf("������������Ϣ��");
					scanf("%lld", &qqnum);
					p->QQNuM = qqnum;
					break;
				case 6:
					char comp[MAX_COMP];
					printf("������������Ϣ��");
					scanf("%s", comp);
					strcpy(p->ComP, comp);
					break;
				case 7:
					char email[MAX_EMAIL];
					printf("������������Ϣ��");
					scanf("%s", email);
					strcpy(p->Email, email);
					break;
				}
				break;
			case 2:
			{
				char phnum[MAX_PHNUM];
				printf("������Ҫ���ҵĵ绰��");
				scanf("%s", phnum);
				while (p->Next != NULL)
				{
					if (strcmp(p->PhNum, phnum) == 0)
					{
						break;
					}
					p = p->Next;
				}
				if (strcmp(p->PhNum, phnum) != 0)
				{
					printf("δ�ҵ���ϵ�ˣ�\n");
					break;
				}
				printf("��ѡ��Ҫ�޸ĵ���Ϣ��1������ 2������ 3���Ա� 4���ֻ��� 5��QQ�� 6����λ 7�����䣩:");
				scanf("%d", &jud);
				switch (jud)
				{
				case 1:
					int age;
					printf("������������Ϣ��");
					scanf("%d", &age);
					p->age = age;
					break;
				case 2:
					char name[MAX_NAME];
					printf("������������Ϣ��");
					scanf("%s", name);
					strcpy(p->Name, name);
					break;
				case 3:
					char sex[MAX_SEX];
					printf("������������Ϣ��");
					scanf("%s", sex);
					strcpy(p->Sex, sex);
					break;
				case 4:
					char phnum[MAX_PHNUM];
					printf("������������Ϣ��");
					scanf("%s", phnum);
					strcpy(p->PhNum, phnum);
					break;
				case 5:
					long long qqnum;
					printf("������������Ϣ��");
					scanf("%lld", &qqnum);
					p->QQNuM = qqnum;
					break;
				case 6:
					char comp[MAX_COMP];
					printf("������������Ϣ��");
					scanf("%s", comp);
					strcpy(p->ComP, comp);
					break;
				case 7:
					char email[MAX_EMAIL];
					printf("������������Ϣ��");
					scanf("%s", email);
					strcpy(p->Email, email);
					break;
				}
				break;
			}
			case 3:
			{
				long long qqnum;
				printf("������Ҫ���ҵ�QQ��");
				scanf("%lld", &qqnum);
				while (p->Next != NULL)
				{
					if (p->QQNuM == qqnum)
					{
						break;
					}
					p = p->Next;
				}
				if (p->QQNuM != qqnum)
				{
					printf("δ�ҵ���ϵ�ˣ�\n");
					break;
				}
				printf("��ѡ��Ҫ�޸ĵ���Ϣ��1������ 2������ 3���Ա� 4���ֻ��� 5��QQ�� 6����λ 7�����䣩:");
				scanf("%d", &jud);
				switch (jud)
				{
				case 1:
					int age;
					printf("������������Ϣ��");
					scanf("%d", &age);
					p->age = age;
					break;
				case 2:
					char name[MAX_NAME];
					printf("������������Ϣ��");
					scanf("%s", name);
					strcpy(p->Name, name);
					break;
				case 3:
					char sex[MAX_SEX];
					printf("������������Ϣ��");
					scanf("%s", sex);
					strcpy(p->Sex, sex);
					break;
				case 4:
					char phnum[MAX_PHNUM];
					printf("������������Ϣ��");
					scanf("%s", phnum);
					strcpy(p->PhNum, phnum);
					break;
				case 5:
					long long qqnum;
					printf("������������Ϣ��");
					scanf("%lld", &qqnum);
					p->QQNuM = qqnum;
					break;
				case 6:
					char comp[MAX_COMP];
					printf("������������Ϣ��");
					scanf("%s", comp);
					strcpy(p->ComP, comp);
					break;
				case 7:
					char email[MAX_EMAIL];
					printf("������������Ϣ��");
					scanf("%s", email);
					strcpy(p->Email, email);
					break;
				}
				break;
			}
			break;
			case 4:
			{
				char email[MAX_EMAIL];
				printf("������Ҫ���ҵ����䣺");
				scanf("%s", email);
				while (p->Next != NULL)
				{
					if (strcmp(p->Email, email) == 0)
					{
						break;
					}
					p = p->Next;
				}
				if (strcmp(p->Email, email) != 0)
				{
					printf("δ�ҵ���ϵ�ˣ�\n");
					break;
				}
				printf("��ѡ��Ҫ�޸ĵ���Ϣ��1������ 2������ 3���Ա� 4���ֻ��� 5��QQ�� 6����λ 7�����䣩:");
				scanf("%d", &jud);
				switch (jud)
				{
				case 1:
					int age;
					printf("������������Ϣ��");
					scanf("%d", &age);
					p->age = age;
					break;
				case 2:
					char name[MAX_NAME];
					printf("������������Ϣ��");
					scanf("%s", name);
					strcpy(p->Name, name);
					break;
				case 3:
					char sex[MAX_SEX];
					printf("������������Ϣ��");
					scanf("%s", sex);
					strcpy(p->Sex, sex);
					break;
				case 4:
					char phnum[MAX_PHNUM];
					printf("������������Ϣ��");
					scanf("%s", phnum);
					strcpy(p->PhNum, phnum);
					break;
				case 5:
					long long qqnum;
					printf("������������Ϣ��");
					scanf("%lld", &qqnum);
					p->QQNuM = qqnum;
					break;
				case 6:
					char comp[MAX_COMP];
					printf("������������Ϣ��");
					scanf("%s", comp);
					strcpy(p->ComP, comp);
					break;
				case 7:
					char email[MAX_EMAIL];
					printf("������������Ϣ��");
					scanf("%s", email);
					strcpy(p->Email, email);
					break;
				}
				break;
			}
			break;
			}
			printf("�Ƿ�ȡ�����ң���Y/N��\n");
			getchar();
			scanf("%c", &judge);
			if (judge == 'Y')
			{
				break;
			}
		}
		printf("�޸ĺ��뱣�棡\n");
		break;
	}
}

void Delete(Contact*& L1, Contact*& L2)
{
	int judge = 0;
	printf("��ѡ��ģʽ��1��ɾ���ѱ������ϵ�˵���Ϣ2��ɾ����δ�������ϵ����Ϣ3��ɾ��ԭͨѶ¼�����ļ����ݣ�");
	scanf("%d", &judge);
	switch (judge)
	{
	case 1:
	{
		if (L2 == NULL)
		{
			load(L2);
		}
		Print(L2);
		printf("��ѡ��ɾ���ڼ��е���ϵ��:");
		int i = 0;
		scanf("%d", &i);
		Contact* p = L2, * q;
		int j = 0;
		if (i < 1)
			break;
		while (p != NULL && j < i - 1)//ʹָ��ָ��Ҫ�޸ĵ�������ϵ��
		{
			j++;
			p = p->Next;
		}
		if (p == NULL)
			break;
		else
		{
			q = p->Next;
			if (q == NULL)
				break;
			p->Next = q->Next;
			free(q);
		}
		printf("�����ɹ����ɰ�6����������߼����������������\n");
	}
	break;
	case 2:
	{
		if (L1 == NULL)
		{
			printf("�޻�δ�������ϵ����Ϣ\n");
			return;
		}
		printf("��ѡ����Ҫɾ���Ļ�δ�������ϵ����Ϣ��\n");
		Print(L1);
		printf("��ѡ��ɾ���ڼ��е���ϵ��:");
		int i = 0;
		scanf("%d", &i);
		Contact* p = L1, * q;
		int j = 0;
		if (i < 1)
			break;
		while (p != NULL && j < i - 1)//ʹָ��ָ��Ҫ�޸ĵ�������ϵ��
		{
			j++;
			p = p->Next;
		}
		if (p == NULL)
			break;
		else
		{
			q = p->Next;
			if (q == NULL)
				break;
			p->Next = q->Next;
			free(q);
		}
		if (L1->Next == NULL)
		{
			L1 = NULL;
		}
		printf("ɾ����ɣ�\n");
	}
	break;
	case 3:
		remove("contact.txt");//remove��������ֱ�ӽ��ļ�ɾ����
		Destroy(L2);
		printf("���Ѿ��ɹ�ɾ��ԭͨѶ¼�ļ�����\n");
		break;
	}
}

void save(Contact*& L1, Contact*& L2)
{
	int  judge;
	FILE* fp;
	printf("�Ƿ񱣴��ԭͨѶ¼���޸ģ�(��1/��2/ȡ������0)\n");
	scanf("%d", &judge);
	if (1 == judge)
	{
		Contact* p = L2->Next;
		fp = fopen("contact.txt", "w");
		if (fp == NULL)
		{
			printf("\n�޷����ļ����޷������ļ���");
			return;
		}
		while (p->Next != NULL)
		{
			fprintf(fp, "%d %s %s %s %lld %s %s\n", p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
			p = p->Next;
		}
		fprintf(fp, "%d %s %s %s %lld %s %s\n", p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
		fclose(fp);
	}
	else if (2 == judge)
	{
		Destroy(L2);
	}
	if (L1 == NULL)
	{
		printf("����������ϵ����Ϣ��\n");
		return;
	}
	printf("\n�Ƿ����е���Ϣ�����ͨѶ¼�У�(��1/��2/ȡ������0)\n");
	Print(L1);
	scanf("%d", &judge);
	if (1 == judge)
	{
		Contact* p = L1->Next;
		fp = fopen("contact.txt", "at");
		if (fp == NULL)
		{
			printf("\n�޷����ļ����޷������ļ���");
			return;
		}
		while (p->Next != NULL)
		{
			fprintf(fp, "%d %s %s %s %lld %s %s\n", p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
			p = p->Next;
		}
		fprintf(fp, "%d %s %s %s %lld %s %s\n", p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
		fclose(fp);
		Destroy(L1);
	}
	else if (2 == judge)
	{
		Destroy(L1);
	}
	else if (0 == judge)
	{
		return;
	}
}

void NoSave(Contact*& L1, Contact*& L2)
{
	Destroy(L1);
	Destroy(L2);
	printf("�����ɹ���\n");
}

void Destroy(Contact*& L)//ɾ��������
{
	if (L == NULL)
	{
		return;
	}
	Contact* pre = L, * p = L->Next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->Next;
	}
	free(pre);
	L = NULL;
}

void load(Contact*& L2)//��ȡ�ı��ļ��е����ݲ����浽������L2��
{
	FILE* fp;
	Contact* p, * s;
	fp = fopen("contact.txt", "rt");
	if (fp == NULL)
	{
		printf("���ѱ���ͨѶ¼��\n");
		return;
	}
	L2 = (Contact*)calloc(1, sizeof(Contact));
	if (L2 == NULL)
	{
		printf("�����ڴ�ʧ�ܣ�\n");
		return;
	}
	p = L2;
	while (!feof(fp))
	{
		s = (Contact*)calloc(1, sizeof(Contact));
		if (s == NULL)
		{
			printf("�����ڴ�ʧ�ܣ�\n");
			return;
		}
		fscanf(fp, "%d %s %s %s %lld %s %s\n", &s->age, s->Name, s->Sex, s->PhNum, &s->QQNuM, s->ComP, s->Email);//���ļ����浽�ڵ���
		p->Next = s;
		p = s;
	}
	p->Next = NULL;

	fclose(fp);
}

void Sort(Contact*& L2)
{
	if (L2 == NULL)
	{
		load(L2);
	}
	Contact* q = L2->Next, * p = q->Next;
	//�����м����
	int temp0;
	char temp1[MAX_NAME];
	char temp2[MAX_SEX];
	char temp3[MAX_PHNUM];
	long long temp4;
	char temp5[MAX_COMP];
	char temp6[MAX_EMAIL];
	while (q != NULL)
	{
		p = q->Next;
		while (p != NULL)
		{
			if (strcmp(q->Name, p->Name) > 0)//��������෴���Ѻ������ϵ����Ϣ���Ƹ�ǰ�棬ǰ�����ϵ����Ϣ���Ƹ�����
			{
				temp0 = q->age;
				q->age = p->age;
				p->age = temp0;
				strcpy(temp1, q->Name);
				strcpy(q->Name, p->Name);
				strcpy(p->Name, temp1);

				strcpy(temp2, q->Sex);
				strcpy(q->Sex, p->Sex);
				strcpy(p->Sex, temp2);

				strcpy(temp3, q->PhNum);
				strcpy(q->PhNum, p->PhNum);
				strcpy(p->PhNum, temp3);

				temp4 = q->QQNuM;
				q->QQNuM = p->QQNuM;
				p->QQNuM = temp4;

				strcpy(temp5, q->ComP);
				strcpy(q->ComP, p->ComP);
				strcpy(p->ComP, temp5);

				strcpy(temp6, q->Email);
				strcpy(q->Email, p->Email);
				strcpy(p->Email, temp6);
			}
			p = p->Next;
		}
		q = q->Next;
	}
	FILE* fp;
	fp = fopen("contact.txt", "w"); //��w����ʽ�򿪣�Ϊ�˸���ԭ�����ļ�����
	if (fp == NULL)
	{
		printf("�޷����ļ����޷������ļ���");
		return;
	}
	p = L2->Next;
	while (p->Next != NULL)
	{
		fprintf(fp, "%d %s %s %s %lld %s %s\n", p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
		p = p->Next;
	}
	fprintf(fp, "%d %s %s %s %lld %s %s\n", p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
	fclose(fp);
	printf("����ɹ���\n");
}