#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* mystrcpy(char* destination, char* source)
{
    int i;
    for (i = 0; source[i] != '\0'; i++)
    {
        destination[i] = source[i];
    }
    destination[i] = '\0';

    return destination;
}

int main2()
{
    char* source = "primjer";
    char destination[50];
    strcpy(destination, source);
    printf("String u koji se kopiralo: %s\n", destination);
    printf("String iz kojeg se kopiralo: %s\n", source);

    mystrcpy(destination, source);
    printf("String u koji se kopiralo: %s\n", destination);
    printf("String iz kojeg se kopiralo: %s\n", source);

    return 0;
}