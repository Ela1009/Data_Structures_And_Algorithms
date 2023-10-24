#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* mystrcat(char* destination, char* source)
{
    int duljina_destination = strlen(destination);
    int i;

    for (i = 0; source[i] != '\0'; i++)
    {
        destination[duljina_destination + i] = source[i];

    }
    destination[duljina_destination + i] = '\0';

    return destination;
}

int main()
{
    char destination[100] = "Strukture ";
    char* source = "podataka i algoritmi";


    printf("%s\n", strcat(destination, source));

    char destination2[100] = "Strukture ";
    printf("%s\n", mystrcat(destination2, source));

    return 0;
}
