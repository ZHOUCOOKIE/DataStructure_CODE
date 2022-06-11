#include "HuffNode.h"

int main()
{
	HuffNode ht[20];
	HuffCode hcd[20];
	int n;
	n = HuffmanCreate(ht);
	PrintHT(ht, n);
	Encoding(ht, hcd, n);
	return 0;
}