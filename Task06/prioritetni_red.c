#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	void* podaci;
	int prioritet;

}Element;

void zamijeni_elemente(Element* niz, int lijevo, int desno){
	Element temp = niz[lijevo];
	niz[lijevo] = niz[desno];
	niz[desno] = temp;
}

void popravi_vrh(Element* niz, int i) {
	if (i == 0)
	{
		return;
	}
	int roditelj = (i - 1) / 2;
	if (niz[roditelj].prioritet < niz[i].prioritet)
	{
		zamijeni_elemente(niz, roditelj, i);
		popravi_vrh(niz, roditelj);
	}
}

void dodaj(Element* niz, int n, int* pozicija)
{
	niz[*pozicija].prioritet = n; 
	int trenutni_indeks = *pozicija;
	*pozicija += 1; 
	popravi_vrh(niz, trenutni_indeks);
}

void popravi_dno(Element* niz, int i, int* N)
{
	int lijevo_dijete = 2 * i + 1;
	int desno_dijete = 2 * i + 2;

	if (desno_dijete >= *N && lijevo_dijete >= *N)
	{
		return;
	}
	else if (lijevo_dijete < *N && desno_dijete >= *N)
	{
		if (niz[i].prioritet < niz[lijevo_dijete].prioritet)
		{
			zamijeni_elemente(niz, i, lijevo_dijete);
			popravi_dno(niz, lijevo_dijete, N);
		}

	}
	else if (desno_dijete < *N)
	{
		if (niz[i].prioritet < niz[lijevo_dijete].prioritet && niz[lijevo_dijete].prioritet >= niz[desno_dijete].prioritet)
		{
			zamijeni_elemente(niz, i, lijevo_dijete);
			popravi_dno(niz, lijevo_dijete, N);
		}
		else if (niz[i].prioritet < niz[desno_dijete].prioritet && niz[desno_dijete].prioritet >= niz[lijevo_dijete].prioritet)
		{
			zamijeni_elemente(niz, i, desno_dijete);
			popravi_dno(niz, desno_dijete, N);
		}
	}
}

void ukloni_s_vrha(Element* niz, int* N)
{
	niz[0] = niz[*N - 1];
	*N -= 1;
	popravi_dno(niz, 0, N);
}

void print(Element* niz, int* pozicija)
{
	for (int i = 0; i < *pozicija; i ++)
	{
		printf("Element[%d]: %d\n", i, niz[i].prioritet);
	}
}

void dodaj_iterativno(Element* niz, int br, int* pozicija)
{
	niz[*pozicija].prioritet= br;
	*pozicija += 1;
}

void iterativno_popravi_dno(Element* niz, int* pozicija)
{

	int i = *pozicija - 1;
	while (1) {
		if (i == 0)
		{
			break;
		}
		int roditelj = (i - 1) / 2;
		if (niz[roditelj].prioritet < niz[i].prioritet)
		{
			zamijeni_elemente(niz, roditelj, i);
			i = roditelj;
		}
		else if (niz[roditelj].prioritet >= niz[i].prioritet)
		{
			break;
		}
	}
}

void ukloni_iterativno(Element* niz, int* pozicija)
{
	niz[0] = niz[*pozicija - 1];
	*pozicija -= 1;
}

void popravi_ukloni_iterativno(Element* niz, int* pozicija)
{
	int i = 0;
	while (1)
	{
		int lijevo_dijete = 2 * i + 1;
		int desno_dijete = 2 * i + 2;
		if (desno_dijete >= *pozicija && lijevo_dijete >= *pozicija - 1)
		{
			break;
		}
		else if (lijevo_dijete < *pozicija && desno_dijete >= *pozicija)
		{
			if (niz[i].prioritet < niz[lijevo_dijete].prioritet)
			{
				zamijeni_elemente(niz, i, lijevo_dijete);
				i = lijevo_dijete;
			}
		}
		else if (desno_dijete < *pozicija) {
			if (niz[i].prioritet < niz[lijevo_dijete].prioritet && niz[lijevo_dijete].prioritet >= niz[desno_dijete].prioritet)
			{
				zamijeni_elemente(niz, i, lijevo_dijete);
				i = lijevo_dijete;
			}
			else if (niz[i].prioritet <= niz[desno_dijete].prioritet && niz[desno_dijete].prioritet >= niz[lijevo_dijete].prioritet) {
				zamijeni_elemente(niz, i, desno_dijete);
				i = desno_dijete;
			}
		}
	}
}

int main(void)
{
	int N = 10000;
	Element* niz = (Element*)malloc(N * sizeof(Element));
	int pozicija = 0;
	if (!niz)
	{
		printf("Error");
		return NULL;
	}

	dodaj(niz, 4, &pozicija);
	dodaj(niz, 8, &pozicija);
	dodaj(niz, 1, &pozicija);
	dodaj(niz, 202, &pozicija);
	dodaj(niz, 18, &pozicija);
	dodaj(niz, 22, &pozicija);
	dodaj(niz, 6, &pozicija);
	dodaj(niz, 3, &pozicija);
	dodaj(niz, 300, &pozicija);
	dodaj(niz, 3010, &pozicija);

	print(niz, &pozicija);
	printf("\n");
	ukloni_s_vrha(niz, &pozicija);
	print(niz, &pozicija);
	free(niz);

	return 0;
}