#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	char data;
	int weight;
	int parent;
	int leftchild;
	int rightchild;
}HuffNode;

typedef struct
{
	char cd[20];
	int start;
}HuffCode;

int HuffmanCreate(HuffNode* ht);//������������
void PrintHT(HuffNode* ht, int n);//��ӡ��������
void Encoding(HuffNode* ht, HuffCode hcd[], int n);//�������������뼰��ӡ