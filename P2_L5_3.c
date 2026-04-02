/*
 Compile:
    gcc -o P2_L5_3 P2_L5_3.c
 Run:
    ./P2_L5_3 test3.bin
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int poredi(const void *a, const void *b);

int main(int argc, char *argv[])
{
    int n;
    FILE *fp;
    int mod;

    printf("Mod: ");
    scanf("%d", &mod);

    if (mod)
    {
        do
        {
            printf("n=");
            scanf("%d", &n);
        } while (n < 1);

        int niz[n];

        for (int i = 0; i < n; i++)
        {
            printf("Niz[%d]= ", i);
            scanf("%d", &niz[i]);
        }

        qsort(niz, n, sizeof(niz[0]), &poredi);

        if ((fp = fopen(argv[1], "wb")) != NULL)
        {
            fwrite(niz, sizeof(int), n, fp);
            fclose(fp);
        }
        else
            printf("Greska\n");
    } else
    {
        char dat_ime[32];

        printf("Ime: ");
        scanf("%s", dat_ime);

        if (dat_ime[0] == '#')
            strcpy(dat_ime, argv[1]);
        
        if ((fp = fopen(dat_ime, "rb")))
        {
            while (fread(&n, sizeof(int), 1, fp))
                printf("%d\n", n);

            fclose(fp);
            printf("\n");
        } else
            printf("Greska\n");
    }

    return 0;
}

int poredi(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}