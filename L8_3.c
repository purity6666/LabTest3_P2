#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING 35

typedef struct Dokument
{
    char naziv[MAX_STRING];
    char ekstenzija[MAX_STRING];
    int velicina;
}DOKUMENT;

DOKUMENT* formiraj(int *);
void ispisi(DOKUMENT);

int main()
{
    int n;
    int granica;
    DOKUMENT *dokument;

    do
    {
        printf("Unesi broj fajlova: ");
        scanf("%d", &n);
    } while (n < 1);

    dokument = formiraj(&n);

    printf("Unesi granicu velicine: ");
    scanf("%d", &granica);

    for (int i = 0; i < n; i++)
    {
        printf("%d. fajl\n", i + 1);
        printf("Unesi ime fajla: ");
        scanf("%34s", dokument[i].naziv);
        printf("Unesi ekstenziju fajla: ");
        scanf("%34s", dokument[i].ekstenzija);
        printf("Unesi velicinu fajla: ");
        scanf("%d", &dokument[i].velicina);
    }
    
    for (int i = 0; i < n; i++)
        if (dokument[i].velicina > granica)
            ispisi(dokument[i]);
    
    free(dokument);
    return 0;
}

DOKUMENT* formiraj(int *n)
{
    DOKUMENT *doc;

    doc = (DOKUMENT*) calloc(*n, sizeof(DOKUMENT));
    if (doc == NULL)
    {
        printf("Greska pri alokaciji \n");
        exit(1);
    }

    return doc; 
}

void ispisi(DOKUMENT d)
{
    printf("%s.%s | %d [B] \n",
        d.naziv,
        d.ekstenzija,
        d.velicina);
}
