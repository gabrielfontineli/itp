#include <stdio.h>

int main()
{

    int saude_fisica, numero_trilhas;

    scanf("%d", &numero_trilhas);

    if (0 <= numero_trilhas && 5 > numero_trilhas)
    {
        printf("Iniciante\n");
    }else{
        scanf("%d", &saude_fisica);
        if (numero_trilhas >= 5 && 20 > numero_trilhas)
        {
            if (saude_fisica == 0)
            {
                printf("Iniciante\n");
            }else{
                printf("Intermediário\n");
            }
        }
        if (numero_trilhas >= 20)
        {
            if (saude_fisica == 0){
                printf("Intermediário\n");
            }else{
                printf("Avançado\n");
            }
        }
    }
}
