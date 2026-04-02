#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char string[100] = {0};
    char dat_ime[32] = {0}; 
    int mod;
    FILE *fp;

    printf("Mod: ");
    scanf("%d", &mod);

    if (mod)
    {
        printf("Unesi string: \n");
        scanf("%s", string);
        
        for (int i = 0; i < strlen(string); i++)
        {
            int mali = 0;

            if(string[i] >= 'a' && string[i] <= 'z')
                mali = 1;

            string[i] += 3;

            if ((string[i] > 'Z' && !mali) || (string[i] > 'z' && mali))
                string[i] -= 26;
        }
        
        if((fp = fopen(argv[1], "wb")) != NULL)
        {
            fwrite(string, sizeof(char), strlen(string), fp);
            fclose(fp);
        }
        else
        {
            printf("Greska");
            return 0;
        }
        
    } else
    {
        printf("Ime: ");
        scanf("%s", dat_ime);

        if (dat_ime[0] == '#')
            strcpy(dat_ime, argv[1]);
        
        if ((fp = fopen(dat_ime, "rb")))
        {
            while (fread(string, sizeof(char), 1, fp))
                printf("%c", string[0]);

            fclose(fp);
            printf("\n");
        } else
            printf("Greska\n");
    }
    

    return 0;
}