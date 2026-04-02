#include <stdio.h>
#define PI 3.14159
#define p(x) (x)*(x)*PI

typedef struct Krug
{
    double x;
    double y;
    double r;
} KRUG;

int main(int argc, char** argv) 
{
    FILE *fp;
    KRUG krug;
    KRUG krug_max = {0};

    if((fp = fopen(argv[1], "r")) != NULL)
    {
        while(fscanf(fp, "(%lf,%lf,%lf)\n", &krug.x, &krug.y, &krug.r) == 3)
            if(krug.r > krug_max.r)
                krug_max = krug;
    } else 
        printf("Greska\n");

    fclose(fp);

    printf("Najvecu povrsinu (P=%lf) ima krug:\n (%lf, %lf, %lf)\n",
        p(krug_max.r),
        krug_max.x,
        krug_max.y,
        krug_max.r);

    return 0;
}