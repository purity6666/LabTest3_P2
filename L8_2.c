#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING 20

typedef struct tim 
{
    char naziv[MAX_STRING];
    int broj_postignutih_g;
    int broj_primljenih_g;
    int broj_bodova;
} TIM;

void ucitaj(TIM *);
void sortiraj(TIM *, int);
void ispisi(TIM *, int);

int main() 
{
    int n;
    do
    {
        printf("Unesi broj timova: ");
        scanf("%d", &n);
    } while (n < 1);

    TIM *tim;

    tim =(TIM *) calloc(n, sizeof(TIM));

    if (tim == NULL)
    {
        printf("Greska pri alokaciji\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d. tim\n", i+1);
        ucitaj(&tim[i]);
    }

    sortiraj(tim, n);
    ispisi(tim, n);
    
    free(tim);
    return 0;
}

void ucitaj(TIM *tim)
{
    if (!tim) return;

    printf("Unesi naziv tima: ");
    scanf("%19s", tim->naziv);

    printf("Unesi broj postignutih golova: ");
    scanf("%d", &tim->broj_postignutih_g);

    printf("Unesi broj primljenih golova: ");
    scanf("%d", &tim->broj_primljenih_g);

    printf("Unesi broj bodova: ");
    scanf("%d", &tim->broj_bodova);

}

void sortiraj(TIM *t, int n)
{
    int max_indeks;
    TIM temp;
    for (int i = 0; i < n; i++)
    {
        max_indeks = i;
        for (int j = i; j < n; j++)
        {
            if ((t[j].broj_bodova > t[max_indeks].broj_bodova) || 
                (t[j].broj_bodova == t[max_indeks].broj_bodova && (t[j].broj_postignutih_g - t[j].broj_primljenih_g) > (t[max_indeks].broj_postignutih_g - t[max_indeks].broj_primljenih_g)) ||
                (t[j].broj_bodova == t[max_indeks].broj_bodova && (t[j].broj_postignutih_g - t[j].broj_primljenih_g) == (t[max_indeks].broj_postignutih_g - t[max_indeks].broj_primljenih_g) && t[j].broj_postignutih_g > t[max_indeks].broj_postignutih_g))
                max_indeks = j;
        }

        if (max_indeks != i)
        {
            temp = t[i];
            t[i] = t[max_indeks];
            t[max_indeks] = temp;
        }
    }
}

void ispisi(TIM *t, int n)
{
    printf("%-4s %-20s %4s %4s %4s %4s \n", "RB.", "NAZIV", "GPO", "GPR", "GR", "BOD");
    for (int i = 0; i < n; i++)
    {
        printf("%2d.  %-20s %4d %4d %4d %4d \n", i + 1, 
            t[i].naziv, 
            t[i].broj_postignutih_g, 
            t[i].broj_primljenih_g, 
            t[i].broj_postignutih_g - t[i].broj_primljenih_g, 
            t[i].broj_bodova);
    }
    
}