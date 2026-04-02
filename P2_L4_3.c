#include <stdio.h>
#include <stdlib.h>

typedef struct Artikal
{
    char sifra[6];
    char naziv[20];
    double cijena;
} ARTIKAL;

void ispis_u_fajl(ARTIKAL *niz, int n, FILE *f);

int main(int argc, char **argv) 
{
    int n;
    ARTIKAL *niz;
    FILE *fp;

    do
    {
        printf("n=");
        scanf("%d", &n);
    } while (n < 1);
    
    niz = calloc(n, sizeof(ARTIKAL));

    if (niz == NULL)
        return 0;
    
    for (int i = 0; i < n; i++)
    {
        printf("%d. artikal: ", i + 1);
        scanf("%s %s %lf", 
            niz[i].sifra, 
            niz[i].naziv, 
            &niz[i].cijena);
    }
    
    if ((fp = fopen(argv[1], "w")) != NULL)
    {
        ispis_u_fajl(niz, n, fp);
        fclose(fp);
    } else
        printf("Greska");

    free(niz);
    return 0;
}

void ispis_u_fajl(ARTIKAL *niz, int n, FILE *f)
{
    fprintf(f, "=== ===== ==================== ====== \n");
    fprintf(f, "RB. SIFRA  NAZIV               CIJENA \n");
    fprintf(f, "=== ===== ==================== ====== \n");

    for (int i = 0; i < n; i++)
    {
        fprintf(f, "%2d. %5s %-20s %6.2lf\n", 
            i + 1,
            niz[i].sifra,
            niz[i].naziv,
            niz[i].cijena);

    }

    fprintf(f, "=== ===== ==================== ======\n");
}