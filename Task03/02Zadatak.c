#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	FILE* fp;
	int n;

	fp = fopen("brojevi.bin", "rb");

	if (fp == NULL)
	{
		printf("Nije otvoren file\n");
	}

	fread(&n, sizeof(int), 1, fp);

	int* brojevi = (int*)malloc(n * sizeof(int));

	fread(brojevi, sizeof(int), n, fp);

	fclose(fp);

	printf("Brojevi iz filea: ");

	for (i = 0; i < n; i++)
	{
		printf("%d ", brojevi[i]);
	}
	free(brojevi);
	return 0;
}