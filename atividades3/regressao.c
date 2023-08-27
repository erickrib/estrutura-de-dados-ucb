#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int records = 0;

typedef struct
{
    int x;
    float y;
} Data;

int mediaX(Data x[records])
{
    int soma = 0;
    for (int i = 0; i < records; i++)
    {
        soma += x[i].x;
        // printf("%d\n", x[i].x);
    }

    printf("%d", records);

    return soma / records;
}

float mediaY(Data y[])
{
    float soma = 0;
    for (int i = 0; i < records; i++)
    {
        soma += y[i].y;
        printf("%.1f\n", y[i].y);
    }

    return soma /records;
}

float inclinacao(Data data[], int mediaX, float mediaY){
    float soma1 = 0;
    float soma2 = 0;

    for(int i = 0; i < records; i++){
        soma1 = (float)(data[i].x - mediaX) * (data[i].y - mediaY);
        soma2 = (float)(data[i].x - mediaX) * (float)(data[i].x - mediaX);
    }

    return soma1 / soma2;
}

float interceptacao(float mediaY, int mediaX, float inclinacao){
    return mediaY - (inclinacao * (float)mediaX);
}

float regressaoLinear(float x, float inclinacao, float interceptacao){
    return (inclinacao * x) + interceptacao ;
}

int main(int argc, char *argv[])
{
    FILE *file;
    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Erro de leitura");
        exit(1);
    }

    int read = 0;
    Data data[110];

    do
    {
        read = fscanf(file, "%d,%f\n", &data[records].x, &data[records].y);

        if (read == 2)
            records++;

        if (read != 2 && !feof(file))
        {
            printf("File format incorrect.\n");
            return 1;
        }

        if (ferror(file))
        {
            printf("Error reading file.\n");
            return 1;
        }

    } while (!feof(file));

    fclose(file);

    int medX = mediaX(data);
    float medY = mediaY(data);
    float inclin = inclinacao(data, medX, medY);
    float intercep = interceptacao(medY, medX, inclin);

    printf("y = %.1fx + %.0f", inclin, intercep);
    return 0;
}