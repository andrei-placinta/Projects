#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int stiva[2][MAX], top[2] = { -1,-1}; // top[0] si top[1] corespund stivei 1 ( stiva[0] ) si stivei 2 ( stiva[1] )
void push(int element,int nr)
{
		stiva[nr][++top[nr]] = element;
}

int pop(int nr)
{
	if (top[nr] == -1)
		return 0;
	else
	{
		printf("%d", stiva[nr][top[nr]]);
		return stiva[nr][top[nr]--];
	}
}

int main()
{
	int i,n=-1,k=-1,kn,aux,palindrom=1;
		while (n < 0 || n > 65535)
		{
		printf("Dati un numar pana in 65535\n");
		printf("n=");
		scanf("%d", &n);
		}
		kn = n; // pentru determinarea numarului de biti relevanti
		do
		{
			k++;
			kn = kn / 2;
		} while (kn);
		printf("Numarul %d in binar este :\n", n);	// stiva[0] - biti , stiva[1]-cifre
		while (k >= 0)
		{
			aux = n >> k;
			if (aux & 1)
			{
				printf("1");
				push(1,0);
			}
			else
			{
				printf("0");
				push(0,0);
			}
			k--;
		}		
		aux = n;	//pentru adaugarea fiecarei cifre de la dreapta la stanga numarului in stiva
		do					
		{
			push(aux%10, 1);
			aux = aux / 10;
		} while (aux);
		printf("\nInversul acestui numar este:\n");
		for (i = 0; i <= top[1]; i++)					
		{
			printf("%d", stiva[1][i]);
			if (stiva[1][i] != stiva[1][top[1]-i])	//verificam daca prima cifra si ultima cifra situate din stiva sunt egale
				palindrom = 0;
		}
		for (i = 0; i <= top[0]; i++)
			if (stiva[0][i] != stiva[0][top[0] - i])//verificam daca primul bit si ultimul bit situati in stiva sunt egali
				palindrom = 0;
		printf("\n");
		printf("Inversul binar este:\n");//putem vedea inversul binar prin apelarea multipla a functiei POP care elimina si afiseaza elementele din stiva
		while (top[0] != -1)
			pop(0);
		printf("\n");
		if (palindrom == 1)		//numarul este palindrom numai si numai daca este egal cu inversul sau, atat in baza 10 cat si in baza 2.
			printf("Numarul este palindrom\n");
		else
			printf("Numarul nu este palindrom\n");
		system("pause");
		return 0;
}
