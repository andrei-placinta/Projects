/*
6.Sa se realizeze un program care realizeaza suma a doua
numere intr-o metoda separata de metoda main, iar aceea
metoda returneaza un pointer.
*/
#include <stdio.h>
#include <stdlib.h>

int sum(int x, int y)	
{
	int *adr,adun;
	adun = x + y;
	adr = &adun;
	return adr;
}

int main()
{
	int a, b,*s;
	printf("a="); scanf("%d", &a);
	printf("b="); scanf("%d", &b);
	s = sum(a,b);
	printf("a+b=%d\n", *s);

	/*
	Alta metoda:

	int a, b, suma, *p, *q, *s;
	p = &a;
	q = &b;
	printf("a="); scanf("%d", p);
	printf("b="); scanf("%d", q);
	suma = *p + *q;
	s = &suma;
	printf("a+b=%d\n",*s);
	*/
	system("pause");
	return 0;
}

