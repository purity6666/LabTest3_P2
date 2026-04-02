#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) 
{
    FILE *f1;
    FILE *f2;
    char str[25] = {0};
    char temp[25] = {0};

    if((f1 = fopen(argv[1], "r")) == NULL)
    {
        printf("Greska\n");
        return 0;
    }

    if((f2 = fopen(argv[2], "w")) == NULL)
    {
        printf("Greska\n");
        fclose(f1);
        return 0;
    }

    while(fscanf(f1, "%s", str) != EOF)
    {
        fprintf(f2, "%s\n", str);
        if(strlen(str) > strlen(temp))
            strcpy(temp, str);
    }
    
    fclose(f1);
    fclose(f2);

    printf("Najduza rijec: %s\n", temp);

    return 0;
}