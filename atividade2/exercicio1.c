#include <stdio.h>

int main()
{
    int array[4] = {5, 7, 9,6};
    int i = 0, result = 0;

    for (i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        result += array[i];
    }

    printf("O resultado da soma e: %d", result);
    return 0;
}
