/*
1. Sa se scrie un program care citeste de la tastura "N" numere naturale.
Pentru fiecare numar se va determina forma lui binara,
se va calcula inversul binar ,
iar mai apoi se va afisa numarul zecimal calculat din inversul binar.
Ex:
27
0001 1011
1110 0100
228
*/
// RESTRICTII : Acest program accepta valori din sfera [0,65535]
#include <stdio.h>          // biblioteca pentru functii intrare-iesire
#include <stdlib.h>         // pentru functia system("pause");
#include <math.h>           // pentru functii matematice , cum ar fi functia putere pow
int main()
{
    int i, n, k = -1, aux, invers, v[100];                 //prin i parcurgem fiecare numar, prin k parcurgem fiecare bit , aux memoreaza bitul in care ne aflam
    printf("Cate numere doriti sa cititi?\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\n");
        scanf("%d", &v[i]);
        if (v[i] < 0)
            continue;
        invers = 0;
        if (v[i] <= 255)
            k = 7;
        else
            if (v[i] <= 65535)
                k = 15;

        while (k >= 0)
        {
            aux = v[i] >> k;
            if (aux & 1)
                printf("1");
            else
                printf("0");
            if (k % 4 == 0)
                printf(" ");
            k--;
        }
        printf("\n");
        if (v[i] <= 255)
            k = 7;
        else
            if (v[i] <= 65535)
                k = 15;
        while (k >= 0)
        {
            aux = ~v[i] >> k;
            if (aux & 1)
            {
                printf("1");
                invers = (int)pow(2, k) + invers;
            }
            else
                printf("0");
            if (k % 4 == 0)
                printf(" ");
            k--;
        }
        printf("\n%d\n", invers);         // exista si varianta 255-v[i] daca k=7 sau 65535-v[i] daca k=15
    }
    printf("\n");
    system("pause");
    return 0;
}
