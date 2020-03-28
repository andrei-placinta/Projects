#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int stiva[MAX], top = -1;

void push(int element)
{
		stiva[++top] = element;
		printf("%d a fost adaugat in stiva \n", element);
}

void traverse()
{
	if (top == -1)
		printf("Stiva este goala \n");
	else
	{
		int i;
		printf("Elementele stivei : ");
		for (i = 0; i <= top; i++)
			printf("%d ", stiva[i]);
		printf("\n");
	}
}

int main()
{
	int i, c = -1, n = MAX + 1, v[MAX];
		while (c < 0 || c > 7)
		{
			printf("\nDati un numar intre 0-7\n");
			printf("c=");
			scanf("%d", &c);
		}
		while (n > MAX)
		{
			printf("Cate numere doriti sa cititi?\n");
			printf("n=");
			scanf("%d", &n);
		}
		for (i = 0; i < n; i++)
			scanf("%d", &v[i]);
		printf("Acum se citesc %d numere\n",n);
		for (i = 0; i < n; i++)
			printf("%d ", v[i]);
		printf("\n");
		for (i = 0; i < n; i++)
		{
			if (v[i] >> c == 1)
				push(v[i]);
		}
		traverse();
		system("pause");
		return 0;
}
