#define _CRT_SECURE_NO_WARNINGS

#pragma once

#define MAX_NAME 20
#define MAX_QQNUM 10
#define MAX_PHNUM 12
#define MAX_COMP 20
#define MAX_EMAIL 20
#define MAX_SEX 20

typedef struct Contact {
	int age;
	char Name[MAX_NAME];
	char sex[MAX_SEX];
	char PhNum[MAX_PHNUM];
	char QQNuM[MAX_QQNUM];
	char ComP[MAX_COMP];
	char Email[MAX_EMAIL];
	struct Contact* Next;
}Contact;

typedef struct Contact1 {
	int age;

	struct Contact1* Next;
}Contact1;

void ContactInit(Contact* L);
void Menu();
void Print(Contact* s);
void Search();
void Add(Contact* L);
void Modify();
void Delete();
void SaveAndExit();
void ExitButSave();
