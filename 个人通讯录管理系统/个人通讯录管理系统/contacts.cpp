#include "contacts.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Menu()//�����
{
	printf("--------------------����ͨѶ¼����ϵͳ----------------------------\n");
	printf("----------0����ʾ����ͨѶ¼--------1������ͨѶ¼------------------\n");
	printf("----------2�����ͨѶ¼��Ա--------3���޸�ͨѶ¼��Ա��Ϣ----------\n");
	printf("----------4��ɾ��ͨѶ¼��Ա��Ϣ----5������------------------------\n");
	printf("----------6��������----------------7���˳�����--------------------\n");
	printf("------------------------------------------------------------------\n");
}

void PrintPlus(Contact*& L1, Contact*& L2)//�����
{
	Fread(L2);
	if (L2 == NULL)
	{
		return;
	}
	else
	{
		Print(L2);
	}

	if (L1 == NULL)
	{
		printf("��δ�����ͨѶ¼��\n");
		return;
	}
	else
	{
		printf("����Ϊδ�����ͨѶ¼��Ϣ��\n");
		Print(L1);
	}
	//Contact* p = L1->Next;
	//while (p->Next != NULL)
	//{
	//	printf("%d %s %s %s %lld %s %s\n", p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
	//	p = p->Next;
	//}
	//printf("%d %s %s %s %lld %s %s\n", p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
}

void Print(Contact*& L)//�����
{
	Contact* p = L->Next;
	printf("����  ����  �Ա�\t�ֻ�����\tQQ����\t������λ\t����\n");
	while (p->Next != NULL)
	{
		printf("%d %s %s %s %lld %s %s\n", p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
		p = p->Next;
	}
	printf("%d %s %s %s %lld %s %s\n", p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
}

void Search(Contact*& L2)//�����
{
	int search = 0;
	char judge;
	if (L2 == NULL)
	{
		Fread(L2);
		if (L2 == NULL)
		{
			return;
		}
	}
	Contact* p = L2->Next;
	while (1)
	{
		printf("�Ƿ�ȡ�����ң���Y/N��\n");
		getchar();
		scanf("%c", &judge);
		if (judge == 'Y')
		{
			break;
		}
		printf("��ѡ��Ҫ���ҵķ�ʽ��(1������ 2���ֻ��� 3��QQ�� 4����λ 5������)");
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
			char comp[MAX_COMP];
			printf("������Ҫ���ҵĵ�λ��");
			scanf("%s", comp);
			while (p->Next != NULL)
			{
				if (strcmp(p->ComP, comp) == 0)
				{
					break;
				}
				p = p->Next;
			}
			if (strcmp(p->ComP, comp) != 0)
			{
				printf("δ�ҵ���ϵ�ˣ�\n");
				break;
			}
			printf("��λΪ%s��ͨѶ¼��Ϣ��%d %s %s %s %lld %s %s\n", p->ComP, p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
			break;
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
	}
}

void Add(Contact*& L1, Contact*& L2)//�����
{
	Contact* s, * p = L2,*r;
	int i = 0;
	L1 = (Contact*)calloc(1, sizeof(Contact));
	if (L1 == NULL)
	{
		printf("�����ڴ�ʧ�ܣ�");
		return;
	}
	r = L1;
	printf("��������Ҫ��Ӷ���λ��ϵ�ˣ�");
	scanf("%d", &i);
	for (; i > 0; i--)
	{
		printf("��������Ϣ��(���� ���� �Ա� �ֻ����� QQ���� ������λ ����)");
		s = (Contact*)calloc(1, sizeof(Contact));
		if (s == NULL)
		{
			printf("�����ڴ�ʧ�ܣ�");
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
				if (strcmp(p->Name, name) == 0)
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
		//18 �ܿ��� �� 13242825240 2117289243 ����ũҵ����ѧԺ zhoucookie@outlook.com
		//19 �ܿ� �� 1324282520 21172892 ����ũҵ����Ժ zhoucookie@outlk.com
		r->Next = s;
		r = s;
	}
	r->Next = NULL;
}

void Modify(Contact*& L2)//�����
{
	printf("��ѡ���޸���ϵ�˵���ʾ��ʽ��1����ʾȫ��ͨѶ¼���Ҵ��� 2������ָ����ϵ�ˣ�");
	int modify = 0;
	scanf("%d", &modify);
	if (L2 == NULL)
	{
		Fread(L2);
		if (L2 = NULL)
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
		for (; i > 1; i--)
		{
			p = p->Next;
		}
		while (1)
		{
			printf("�Ƿ���������޸ģ���0���� 1���ǣ�\n");
			scanf("%d", &interrupt);
			if (interrupt == 0)
			{
				break;
			}
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
		}
			FILE* fp;
			fp = fopen("contact.txt", "w");
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
			printf("�޸���ɣ�\n");
		
		break;
	}
	case 2:
		int search = 0, jud = 0;
		char judge;
		if (L2 == NULL)
		{
			Fread(L2);
			if (L2 == NULL)
			{
				return;
			}
		}
		Contact* p = L2->Next;
		while (1)
		{
			printf("�Ƿ�ȡ�����ң���Y/N��\n");
			getchar();
			scanf("%c", &judge);
			if (judge == 'Y')
			{
				break;
			}
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
		}
		FILE* fp;
		fp = fopen("contact.txt", "w");
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
		printf("�޸���ɣ�\n");
		break;
	}
}

void Delete(Contact*& L1, Contact*& L2)//�����
{
	int judge = 0;
	printf("��ѡ��ģʽ��1��ɾ��ԭͨѶ¼�ļ�����2��ɾ����δ�������ϵ����Ϣ3��ɾ��ԭͨѶ¼�����ļ����ݣ�");
	scanf("%d", &judge);
	switch (judge)
	{
	case 1:
	{
		FILE* fp = fopen("contact.txt", "r");
		if (L2 == NULL)
		{
			Fread(L2);
		}
		Print(L2);
		printf("��ѡ��ɾ���ڼ��е���ϵ��:");
		int i = 0;
		scanf("%d", &i);
		Contact* p = L2, * q;
		int j = 0;
		if (i < 1)
			break;
		while (p != NULL && j < i - 1)
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
		fclose(fp);
		fp = fopen("contact.txt", "w");
		if (fp == NULL)
		{
			printf("�޷����ļ����޷������ļ���");
			return;
		}
		p = L2->Next;
		if (p = NULL)
		{
			printf("����ʧ�ܣ�");
			break;
		}
		while (p->Next != NULL)
		{
			fprintf(fp, "%d %s %s %s %lld %s %s\n", p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
			p = p->Next;
		}
		fprintf(fp, "%d %s %s %s %lld %s %s\n", p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
		fclose(fp);
		printf("ɾ����ɣ�\n");
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
		while (p != NULL && j < i - 1)
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
		printf("ɾ����ɣ�\n");
	}
	break;
	case 3:
		remove("contact.txt");
		Destroy(L2);
		printf("���Ѿ��ɹ�ɾ��ԭͨѶ¼�ļ�����\n");
		break;
	}
}

void Save(Contact*& L1)//��ʵ��
{
	int  judge;
	if (L1 == NULL)
	{
		printf("����ʧ�ܣ�\n");
		return;
	}
	printf("ȷ�Ͻ����е���Ϣ�����ļ�����(��1/��2/ȡ������0)\n");
	Print(L1);
	scanf("%d", &judge);
	if (1 == judge)
	{
		FILE* fp;
		Contact* p = L1->Next;
		fp = fopen("contact.txt", "at");
		if (fp == NULL)
		{
			printf("�޷����ļ����޷������ļ���");
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
	else if (0==judge)
	{
		return;
	}
}

void NoSave(Contact*& L1, Contact*& L2)//��ʵ��
{
	Destroy(L1);
	Destroy(L2);
	printf("�����ɹ���\n");
}

void Destroy(Contact*& L)//��������L���ͷ�����Lռ�õ��ڴ�ռ䡣
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

void Fread(Contact*& L2)//�����
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
		fscanf(fp, "%d %s %s %s %lld %s %s\n", &s->age, s->Name, s->Sex, s->PhNum, &s->QQNuM, s->ComP, s->Email);
		p->Next = s;
		p = s;
	}
	p->Next = NULL;

	fclose(fp);
}