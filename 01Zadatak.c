#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int mystrlen(char* string)
{
	int i = 0;
	int brojac = 0;
	for (i; string[i] != '\0'; i++)
	{
		brojac++;
	}
	return brojac;
}

int main7()
{
	char* string = "string";

	printf("Duljina stringa je: %d\n", mystrlen(string));
	printf("Duljina stringa je: %d\n", strlen(string));

	return 0;
}

