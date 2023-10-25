#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* mystrstr(char* string, char* substring)
{
	int i, j, brojac;

	for (i = 0; string[i] != '\0'; i++)
	{
		brojac = 0;
		for (j = 0; substring[j] != '\0'; j++)
		{
			if (string[i + j] != substring[j])
			{
				break;
			}
			brojac++;
		}
		if (brojac == strlen(substring))
		{
			return &string[i]; 
		}						
	}							
	                            
	return NULL;
}


int main8()
{
	char* string = "xxxaabaaab";
	char* substring = "ab";
	char* rezultat2 = strstr(string, substring);
	printf("%s\n", rezultat2);

	char* rezultat = mystrstr(string, substring);
	printf("%s\n", rezultat);
	

	return 0;
}