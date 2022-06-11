#include "HuffNode.h"

int HuffmanCreate(HuffNode* ht)
{
	int i, k, n, min1, min2, lnode, rnode;
	printf("请输入元素的个数：");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		getchar();
		printf("第%d个元素的=>\n\t结点值：", i);
		scanf("%c", &ht[i].data);
		printf("\t权 重：");
		scanf("%d", &ht[i].weight);
	}
	for (i = 1; i <= 2 * n - 1; i++)
	{
		ht[i].parent = 0;
		ht[i].leftchild = 0;
		ht[i].rightchild = 0;
	}
	for (i = n + 1; i <= 2 * n - 1; i++)
	{
		min1 = min2 = 32767;
		lnode = 1;
		rnode = 1;
		for (k = 1; k <= i - 1; k++)
			if (ht[k].parent == 0)
				if (ht[k].weight < min1)
				{
					min2 = min1;
					rnode = lnode;
					min1 = ht[k].weight;
					lnode = k;
				}
				else if (ht[k].weight < min2)
				{
					min2 = ht[k].weight;
					rnode = k;
				}
		ht[i].weight = min1 + min2;
		ht[i].leftchild = lnode;
		ht[i].rightchild = rnode;
		ht[i].parent = 0;
		ht[lnode].parent = i;
		ht[rnode].parent = i;

	}
	printf("哈夫曼树已成功建立！\n");
	return n;
}

void PrintHT(HuffNode* ht, int n)
{
	printf("data	weight	lchild	rchild	parent\n");
	for (int i = 1; i <= 2 * n - 1; i++)
	{
		if (i <= n)
			printf("%c", ht[i].data);
		printf("	%d	%d	%d	%d\n", ht[i].weight, ht[i].leftchild, ht[i].rightchild, ht[i].parent);
	}
}

void Encoding(HuffNode* ht, HuffCode hcd[], int n)
{
	HuffCode d;
	int i, k, f, c;
	for (i = 1; i <= n; i++)
	{
		d.start = n + 1;
		c = i;
		f = ht[i].parent;
		while (f != 0)
		{
			if (ht[f].leftchild == c)
				d.cd[--d.start] = '0';
			else
				d.cd[--d.start] = '1';
			c = f;
			f = ht[f].parent;
		}
		hcd[i] = d;
	}
	printf("输出哈夫曼编码：\n");
	for (i = 1; i <= n; i++)
	{
		printf("%c:", ht[i].data);
		for (k = hcd[i].start; k <= n; k++)
			printf("%c", hcd[i].cd[k]);
		printf("\n");
	}
}