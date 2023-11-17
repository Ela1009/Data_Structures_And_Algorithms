#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float x;
	float y;
}Koordinate;

int main()
{
	int n;
	printf("Unesite broj struktura: \n");
	scanf("%d", &n);

	Koordinate* niz = (Koordinate*)malloc(n * sizeof(Koordinate));

	printf("Unesite koordinate: \n");
	for (int i = 0; i < n; i++)
	{
		scanf("%f %f", &koordinate[i].x, &koordinate[i].y)
	}

	FILE* fp = fopen("koordinate.bin", "wb");

	if (fp == NULL)
	{
		printf("Greska\n");
		return 1;
	}

	fwrite(&n, sizeof(int), 1, fp);

	fwrite(Koordinate, sizeof(Koordinate), n, fp);

	fclose(fp);

	free(Koordinate);

	printf("Podaci zapisani u koordinate.bin"\n);

	return 0;
}