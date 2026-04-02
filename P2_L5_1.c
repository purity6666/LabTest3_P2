#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Osoba
{
    char ime[21];
    char prezime[21];
    char broj_telefona[20];
} OSOBA;

int main(int argc, char *argv[])
{
    int n;
    int mod;
    char dat_ime[32];
    OSOBA *niz;
    OSOBA o;
    FILE *fp;

    printf("mod=");
    scanf("%d", &mod);

    if (mod)
    {
        do
        {
            printf("n=");
            scanf("%d", &n);
        } while (n < 1);

        niz = calloc(n, sizeof(OSOBA));

        if (niz == NULL)
            return 0;

        for (int i = 0; i < n; i++)
        {
            printf("%d. osoba: ", i + 1);
            scanf("%s %s %s",
                  niz[i].ime,
                  niz[i].prezime,
                  niz[i].broj_telefona);
        }

        if ((fp = fopen(argv[1], "ab")) != NULL)
        {
            fwrite(niz, sizeof(OSOBA), n, fp);
            fclose(fp);
        } else
            printf("Greska\n");
        
        free(niz);
    } else
    {
        printf("ime=");
        scanf("%s", dat_ime);

        if (dat_ime[0] == '#')
            strcpy(dat_ime, argv[1]);
        
        if ((fp = fopen(dat_ime, "rb")))
        {
            while (fread(&o, sizeof(OSOBA), 1, fp))
                printf("%s %s %s\n", o.ime, o.prezime, o.broj_telefona);

            fclose(fp);
        } else
            printf("Greska\n");
       
    }

    return 0;
}