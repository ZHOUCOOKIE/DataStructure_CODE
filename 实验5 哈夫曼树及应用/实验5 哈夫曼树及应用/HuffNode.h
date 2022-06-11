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

int HuffmanCreate(HuffNode* ht);//创建哈夫曼树
void PrintHT(HuffNode* ht, int n);//打印哈夫曼树
void Encoding(HuffNode* ht, HuffCode hcd[], int n);//创建哈夫曼编码及打印