#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int mystrcmp(char* str1, char* str2)
{
	int i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			if (str1[i] > str2[i])
			{
				return 1;
			}
			else if (str1[i] < str2[i])
			{
				return -1;
			}
		}
		i++;
	}
	return 0;

}

int main9()
{
	char* str1 = "abcx";
	char* str2 = "abcx";
	int rezultat = mystrcmp(str1, str2);

	if (rezultat > 0)
	{

		printf("Str1 je veci od str2\n");
	}
	else if (rezultat < 0)
	{
		printf("Str1 je manji od str2\n");
	}
	else
	{
		printf("stringovi su jednaki\n");
	}

	int rezultat2 = strcmp(str1, str2);

	if (rezultat > 0)
	{

		printf("Str1 je veci od str2\n");
	}
	else if (rezultat < 0)
	{
		printf("Str1 je manji od str2\n");
	}
	else
	{
		printf("stringovi su jednaki\n");
	}

	return 0;
}