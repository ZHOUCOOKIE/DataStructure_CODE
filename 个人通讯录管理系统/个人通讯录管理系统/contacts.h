#define _CRT_SECURE_NO_WARNINGS

#pragma once

#define MAX_NAME 20
#define MAX_SEX 20
#define MAX_PHNUM 12
#define MAX_QQNUM 10
#define MAX_COMP 30
#define MAX_EMAIL 30

typedef struct Contact {
	int age;
	char Name[MAX_NAME];
	char sex[MAX_SEX];
	char PhNum[MAX_PHNUM];
	long long QQNuM;//使用字符数组打印的时候会出bug
	char ComP[MAX_COMP];
	char Email[MAX_EMAIL];
	struct Contact* Next;
}Contact;

void Menu();
void PrintPlus(Contact*& L1, Contact*& L2);
void Print(Contact*& L);
void Search();
void Add(Contact*& L);
void Modify();
void Delete(Contact*& L);
void Save(Contact*& L);
void NoSave(Contact*& L);
void Destroy(Contact*& L);
void Fread(Contact*& L);
