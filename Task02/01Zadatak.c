#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* podniz(int* niz, int start, int stop) 
{
	int* niz2;
	int i, j = 0;
	int len = stop - start;

	niz2 = (int*)malloc(len * sizeof(int));

	for (i=start; i<=stop; i++)
	{
		niz2[j] = niz[i];
		j++;
	}
	return niz2;
	
}

int main()
{
	int niz[] = {1,2,3,4,5,6,7,8,9,10};
	int* niz2;
	int start = 3;
	int stop = 7;
	int i;
	int len2 = stop - start;

	niz2 = podniz(niz, start, stop);

	for (i = 0; i < len2; i++)
	{
		printf("%d ", niz2[i]);
	}
	free(niz2);
	return 0;
}