/*
1.Sa se scrie un program care calculeaza suma elementelor unui
vector folosindu - ne doar de variabile de tip pointer.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int nr, suma = 0, * adr, * i, * n;
	printf("Cate elemente sunt in vector?\n ");
	scanf("%d", &nr);
	adr = (int*)malloc(nr * sizeof(int));
	n = adr + nr;
	printf("Introduceti elementele vectorului: \n");
	for (i = adr; i < n; i++)
	{
		scanf("%d", i);
		suma = suma + *i;
	}
	printf("Suma este: %d \n", suma);
	free(adr);
	system("pause");
	return 0;
}