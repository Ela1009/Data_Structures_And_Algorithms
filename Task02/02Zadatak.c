#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* filtriraj(int* niz, int n, int th, int* nth)
{
	*nth = 0;
	int i;
	int* niz2= (int*)malloc(n * sizeof(int));

	for (i=0; i < n; i++)
	{
		if (niz[i] < th)
		{
			niz2[*nth] = niz[i];
			(*nth)++;
		}
	}
	return niz2;
}

int main7()
{
	int niz[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(niz) / sizeof(niz[0]);
	int th = 3;
	int i;
	int nth;

	int* niz2=filtriraj(niz, n, th, &nth);

	for (i = 0; i < nth; i++)
	{
		printf("%d ", niz2[i]);
	}
	free(niz2);
	return 0;
}