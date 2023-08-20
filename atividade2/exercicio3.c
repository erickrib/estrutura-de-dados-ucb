#include <stdio.h>
#include <string.h>

int main()
{
    char *array[] = {"texto", "J", "EDA"};
    int tamanho = sizeof(array) / sizeof(array[0]);
    char *busca = "EDO";
    int result;
    for (int i = 0; i < tamanho; i++)
    {
        if (strcmp(array[i], busca) == 0)
        {
            result = 1;
        }
        else
        {
            result = 0;
        }
    }
    printf("%d\n", result);
    return 0;
}