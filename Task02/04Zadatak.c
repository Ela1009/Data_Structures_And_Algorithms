#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	float x;
	float y;
} Tocka;

typedef struct{
	Tocka* vrhovi;
	int n;
} Poligon;

Poligon* novi_poligon(float* niz_x, float* niz_y, int n)
{
	Poligon* novi = (Poligon*)malloc(sizeof(Poligon));

	novi->n = n;

	novi->vrhovi= (Tocka*)malloc(n * sizeof(Tocka));

	for (int i = 0; i < n; i++)
	{
		novi->vrhovi[i].x = niz_x[i];
		novi->vrhovi[i].y = niz_y[i];
	}

	return novi;
}

Tocka** pozitivni(Poligon* p, int* np)
{
	int brojac=0;

	for (int i = 0; i < p->n; i++)
	{
		if (p->vrhovi[i].x > 0 && p->vrhovi[i].y > 0)
		{
			brojac++;
		}
	}

	Tocka** rezultat = (Tocka**)malloc(brojac * sizeof(Tocka*));

	int indeks = 0;

	for (int i = 0; i < p->n; i++)
	{
		if (p->vrhovi[i].x > 0 && p->vrhovi[i].y > 0)
		{
			rezultat[indeks] = &(p->vrhovi[i]);
			indeks++;
		}
	}
	*np = brojac;
	return rezultat;
}

int main2()
{
	float niz_x[] = {-1,2.2,4,3.1};
	float niz_y[] = {3.2,5,1,-2.6};

	int n = 4;

	Poligon* poligon = novi_poligon(niz_x, niz_y, n);

	int np;

	Tocka** pozitivni_vrhovi = pozitivni(poligon, &np);
	
	if (np > 0)
	{
		for (int i = 0; i < np; i++)
		{
			printf("Pozitivni vrhovi: x=%f, y=%f ", pozitivni_vrhovi[i]->x, pozitivni_vrhovi[i]->y);
		}
		free(pozitivni_vrhovi);
	}
	else
	{
		printf("Nema pozitivnih vrhova");
	}

	free(poligon->vrhovi);
	free(poligon);

	return 0;
}