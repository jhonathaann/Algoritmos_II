#include <stdio.h>
#include <string.h>
#define NUM_PLANETAS 9

int main(int argc, char *argv[])
{
    char *planetas[] = {"Mercurio", "Venus", "Terra", "Marte", "Jupiter",
                        "Saturno", "Urano", "Netuno", "Plutao"};
    int i, j, k;
    for (i = 1; i < argc; i++)
    {
        for (j = 0; j < NUM_PLANETAS; j++)
            if (strcmp(argv[i], planetas[j]) == 0)
            {
                k = j;
                j = NUM_PLANETAS;
            }
        if (j == NUM_PLANETAS + 1)
            printf("%s eh o planeta %d\n", argv[i], k);
        else
            printf("%s nao eh um planeta\n", argv[i]);
    }

    printf("teste\n");
    return 0;
}