#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define kvadrat(x) (x)*(x)

typedef struct tacka
{
    double x;
    double y;
    char oznaka;
} TACKA;

typedef struct trougao
{
    TACKA a;
    TACKA b;
    TACKA c;
} TROUGAO;

void citaj(TACKA *);
int provjera(TACKA *);
TROUGAO trougao(TACKA *);
double obim(TROUGAO);

int main() 
{
    TACKA niz_t[3];
    TROUGAO tr;

    for (int i = 0; i < 3; i++)
        citaj(niz_t + i);


    if (!provjera(niz_t))
    {
        printf("Tacke ne formiraju trougao\n");
        return 0;
    }
    
    printf("Tacke formiraju trougao\n");
    tr = trougao(niz_t);

    printf("Obim tog trougla je: %lf\n", obim(tr));

    return 0;
}

void citaj(TACKA *t)
{
    double x_uneseno, y_uneseno;
    char oznaka_unesena;

    printf("Unesi tacku i njenu oznaku(x, y): ");
    scanf("%lf %lf %c", &x_uneseno, &y_uneseno, &oznaka_unesena);
    
    t->x = x_uneseno;
    t->y = y_uneseno;
    t->oznaka = oznaka_unesena;
}

int provjera(TACKA *t)
{
    double determinanta;

    determinanta = t[0].x * (t[1].y - t[2].y)
        + t[1].x * (t[2].y - t[0].y)
        + t[2].x * (t[0].y - t[1].y);

    if (determinanta)
        return 1;
    
    return 0;
}

TROUGAO trougao(TACKA *t)
{
    TROUGAO tr;
    tr.a = t[0];
    tr.b = t[1];
    tr.c = t[2];

    return tr;
}

double obim(TROUGAO t)
{
    double ab;
    double bc;
    double ac;

    ab = sqrt(kvadrat(t.b.x - t.a.x) + kvadrat(t.b.y - t.a.y));
    bc = sqrt(kvadrat(t.c.x - t.b.x) + kvadrat(t.c.y - t.b.y));
    ac = sqrt(kvadrat(t.a.x - t.c.x) + kvadrat(t.a.y - t.c.y));

    return ab + bc + ac;
}