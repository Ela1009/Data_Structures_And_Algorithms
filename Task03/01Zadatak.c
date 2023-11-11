#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main2()
{
	int i;
	int n;
	FILE* fp;

	printf("Unesite broj elemenata n: ");
	scanf("%d", &n);

	int* niz = (int*)malloc(n * sizeof(int));

	printf("Unesite elemente niza: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &niz[i]);
	}

	fp = fopen("brojevi.bin", "wb");

	fwrite(&n, sizeof(int), 1, fp);

	fwrite(niz, sizeof(int), n, fp);

	fclose(fp);
	free(niz);

	return 0;
}