#include <stdio.h>

int main()
{
    int years, count = 0;
    double entry,sum = 0;

    scanf("%d", &years);

    for (int i = 0; i < years; i++)
    {
        scanf("%lf", &entry);
        if (entry != -1)
        {
            sum += entry;
            count++;
        }
    }

    if (count == 0)
    {
        printf("A competicao nao possui dados historicos!\n");
    }
    else
    {
        printf("%.2lf\n", sum / count);
    }

    return 0;
}


