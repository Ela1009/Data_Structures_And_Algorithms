#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS

#define RANDOM (rand() * rand())

int* generate(int n) { 
	int* niz = (int*)malloc(n * sizeof(int));
	niz[0] = 1 + rand() % 5;
	for (int i = 1; i < n; i++) {
		niz[i] = niz[i - 1] + 1 + rand() % 5;
	}
	return niz;
}

void shuffle(int* niz, int n) { 
	for (int i = 0; i < n; i++) {
		int j = RANDOM % n;
		int tmp = niz[i];
		niz[i] = niz[j];
		niz[j] = tmp;
	}
}

int cmp(const void* a, const void* b) { 
	return *((int*)a) - *((int*)b);
}

int presjek(int* niz1, int len1, int* niz2, int len2) 
{
	int duzina_presjeka = 0;

	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			if(niz1[i]==niz2[j])
				{
					duzina_presjeka++;
				}
		}
	}
	return duzina_presjeka;
}

int presjek_jedan_sortiran(int* niz1, int len1, int* niz2, int len2) 
{
	int duzina_sortiranog_presjeka = 0;

	qsort(niz2, len2, sizeof(int), cmp);

	int* rezultat;

	for (int i = 0; i < len1; i++)
	{
		rezultat = (int*)bsearch(&niz1[i], niz2, len2, sizeof(int), cmp);
		duzina_sortiranog_presjeka++;
	}
	return duzina_sortiranog_presjeka;
}

int presjek_oba_sortirana(int* niz1, int len1, int* niz2, int len2) 
{
	int duzina_oba_sortirana = 0;
	int i = 0;
	int j = 0;

	qsort(niz1, len1, sizeof(int), cmp);
	qsort(niz2, len2, sizeof(int), cmp);

	while (i < len1 && i < len2)
	{
		if (j < len2)
		{
			if (niz1[i] == niz2[j])
			{
				duzina_oba_sortirana++;
				i++;
				j++;
			}
			if (niz1[i] > niz2[j])
			{
				j++;
			}
			if (niz1[i] < niz2[j])
			{
				i++;
			}
		}
		else
		{
			return duzina_oba_sortirana;
		}
	}
	return duzina_oba_sortirana;
}

int najveci_broj(int* niz, int len)
{
	int najveci_broj = niz[0];

	for (int i = 1; i < len; i++)
	{
		if (najveci_broj < niz[i])
		{
			najveci_broj = niz[i];
		}
	}
	return najveci_broj;
}

int presjek_po_indeksima(int* niz1, int len1, int* niz2, int len2) 
{
	int brojac = 0;

	int najveci1 = najveci_broj(niz1, len1);
	int najveci2 = najveci_broj(niz2, len2);

	int* indeksA = (int*)calloc(najveci1 + 1, sizeof(int));
	int* indeksB = (int*)calloc(najveci2 + 1, sizeof(int));

	for (int i = 0; i < len1; i++)
	{
		indeksA[niz1[i]] = 1;
	}
	for (int i = 0; i < len2; i++)
	{
		indeksB[niz2[i]] = 1;
	}

	if (najveci1 >= najveci2)
	{
		for (int i = 0; i <= najveci2; i++)
		{
			if (indeksA[i] == 1 && indeksB[i] == 1)
			{
				brojac++;
			}
		}
	}
	else
	{
		for (int i = 0; i <= najveci1; i++)
		{
			if (indeksA[i] == 1 && indeksB[i] == 1)
			{
				brojac++;
			}
		}
	}
	free(indeksA);
	free(indeksB);

	return brojac;
}

int main() {
	srand((unsigned int)time(NULL)); 
	
	int len1 = 400000;
	int len2 = 400000;
	int* niz1 = generate(len1);
	int* niz2 = generate(len2);
	
	clock_t t_0;
	t_0 = clock(); 
	int presjek_niza_duzina = presjek(niz1, len1, niz2, len2);
	t_0 = clock() - t_0; 
	double time_consumed = ((double)t_0) / CLOCKS_PER_SEC; 
	printf("Funkciji je trebalo %f sekundi da se izvrsi. \n", time_consumed);
	printf("Duzina presjeka niza je: %d\n", presjek_niza_duzina);
	printf("\n");
	free(niz1);
	free(niz2);

	int* niz3 = generate(len1);
	int* niz4 = generate(len2);
	clock_t t_01;
	t_01 = clock();
	int presjek_sortirani = presjek_jedan_sortiran(niz3, len1, niz4, len2);
	t_01 = clock() - t_01;
	double time_consumed1 = ((double)t_01) / CLOCKS_PER_SEC;
	printf("Funkciji je trebalo %f sekundi da se izvrsi. \n", time_consumed1);
	printf("Duzina presjeka niza iznosi: %d\n", presjek_sortirani);
	printf("\n");
	free(niz3);
	free(niz4);

	int* niz5 = generate(len1);
	int* niz6 = generate(len2);
	clock_t t_02;
	t_02 = clock();
	int presjek_sortirani_dva = presjek_oba_sortirana(niz5, len1, niz6, len2);
	t_02 = clock() - t_02;
	double time_consumed2 = ((double)t_02) / CLOCKS_PER_SEC;
	printf("Funkciji je trebalo %f sekundi da se izvrsi. \n", time_consumed2);
	printf("Duzina presjeka niza iznosi: %d\n", presjek_sortirani_dva);
	printf("\n");
	free(niz5);
	free(niz6);

	int* niz7 = generate(len1);
	int* niz8 = generate(len2);
	clock_t t_03;
	t_03 = clock();
	int presjek_index = presjek_po_indeksima(niz7, len1, niz8, len2);
	t_03 = clock() - t_03;
	double time_consumed3 = ((double)t_03) / CLOCKS_PER_SEC;
	printf("Funkciji je trebalo %f sekundi da se izvrsi. \n", time_consumed3);
	printf("Duzina presjeka niza iznosi: %d\n", presjek_index);
	free(niz7);
	free(niz8);

	return 0;
}
