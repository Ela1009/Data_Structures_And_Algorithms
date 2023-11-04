#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int** podijeli(int* niz, int n)
{
	int i;
	int* prva_polovina_niza = (int*)malloc((n/2) * sizeof(int));
	int* druga_polovina_niza = (int*)malloc((n-(n/2)) * sizeof(int));
	
	
	for (i = 0; i < n/2; i++)
	{
		prva_polovina_niza[i] = niz[i];
	}
	for (i = 0; i < (n-(n/2)); i++)
	{
		druga_polovina_niza[i] = niz[i+(n/2)];
	}

	int** rezultat = (int**)malloc(2 * sizeof(int*));

	rezultat[0] = prva_polovina_niza;
	rezultat[1] = druga_polovina_niza;

	return rezultat;
}

int main4()
{
	int niz[] = {1,2,3,4,5,6,7};
	int n = sizeof(niz) / sizeof(niz[0]);

	int** rezultat = podijeli(niz, n);

	int* prva_polovina_niza = rezultat[0];
	int* druga_polovina_niza = rezultat[1];

	
	printf("Prva polovina niza: \n");

	for (int i = 0; i < n/2; i++)
	{
		printf("%d \n", prva_polovina_niza[i]);
	}

	printf("Druga polovina niza: \n");

	if (n % 2 == 0)
	{
		for (int i = 0; i < n / 2; i++)
		{
			printf("%d \n", druga_polovina_niza[i]);
		}
	}
	else
	{
		for (int i = 0; i < (n / 2) + 1; i++)
		{
			printf("%d \n", druga_polovina_niza[i]);
		}
	}
	
	
	free(prva_polovina_niza);
	free(druga_polovina_niza);

	return 0;
}