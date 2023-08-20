#include <stdio.h>

int main()
{
    int array[4] = {5, 7, 9,6};
    int i = 0, menor = array[0], maior = array[0];

    for (i = 1; i < 4; i++)
    {
        if (array[i] < menor)
        {
            menor = array[i];
        }

        if (array[i] > maior)
        {
            maior = array[i];
        }
    }

    printf("%d %d", menor, maior);
    return 0;
}