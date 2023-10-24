#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* reverse(char* destination, char* source)
{
    int i;
    for (i = 0; source[i] != '\0'; i++)
    {
        destination[i] = source[strlen(source)-1-i];
    }
    destination[strlen(source)] = '\0';

    return destination;
}

int main6()
{
    char* source = "primjer";
    char* destination[50];
    reverse(destination, source);
    printf("String u koji se kopiralo: %s\n", destination);
    printf("String iz kojeg se kopiralo: %s\n", source);

    return 0;
}
