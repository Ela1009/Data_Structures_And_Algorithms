#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float x, y, z;
}Vrh;

typedef struct {
	float nx, ny, nz;
	Vrh niz_vrhova[3];
	unsigned short boja;
}Trokut;

typedef struct {
	Trokut* niz_trokuta;
	int broj_trokuta;
}Objekt3D;

Objekt3D* citaj_binarno(FILE* fp)
{
	int i;
	Objekt3D* objekt = (Objekt3D*)malloc(sizeof(Objekt3D));
	
	fseek(fp, 80, SEEK_SET);

	fread(&objekt->broj_trokuta, sizeof(unsigned int), 1, fp);

	objekt->niz_trokuta = (Trokut*)malloc(sizeof(Trokut) * objekt->broj_trokuta);

	for (i = 0; i < objekt->broj_trokuta; i++)
	{
		fread(&(objekt->niz_trokuta[i]), 50, 1, fp);
	}

	return objekt;
}

void zapisi_binarno(FILE* fp, Objekt3D* objekt)
{
	char zaglavlje[80] = { 0 };

	fwrite(zaglavlje, sizeof(zaglavlje[0]), 80, fp);
	fwrite(&(objekt->broj_trokuta), sizeof(unsigned int), 1, fp);

	for (int i = 0; i < objekt->broj_trokuta; i++)
	{
		fwrite(&(objekt->niz_trokuta[i]), 50, 1, fp);
	}
}

void zapisi_tekst(FILE* fp, Objekt3D* objekt)
{
	int i;

	fprintf(fp, "solid name\n");

	for (int i = 0; i < objekt->broj_trokuta; i++)
	{
		fprintf(fp, "  facet normal %f %f %f\n", objekt->niz_trokuta[i].nx, objekt->niz_trokuta[i].ny, objekt->niz_trokuta[i].nz);
		fprintf(fp, "    outer loop\n");
		fprintf(fp, "      vertex %f %f %f\n", objekt->niz_trokuta[i].niz_vrhova[0].x, objekt->niz_trokuta[i].niz_vrhova[0].y, objekt->niz_trokuta[i].niz_vrhova[0].z);
		fprintf(fp, "      vertex %f %f %f\n", objekt->niz_trokuta[i].niz_vrhova[1].x, objekt->niz_trokuta[i].niz_vrhova[1].y, objekt->niz_trokuta[i].niz_vrhova[1].z);
		fprintf(fp, "      vertex %f %f %f\n", objekt->niz_trokuta[i].niz_vrhova[2].x, objekt->niz_trokuta[i].niz_vrhova[2].y, objekt->niz_trokuta[i].niz_vrhova[2].z);
		fprintf(fp, "    endloop\n");
		fprintf(fp, "  endfacet\n");
	}
	fprintf(fp, "endsolid\n");
}

void izbrisi(Objekt3D* objekt)
{
	free(objekt->niz_trokuta);
	free(objekt);
}

int main()
{
	FILE* fp1 = fopen("primjerbin.stl", "rb");
	if (!fp1)
	{
		return 1;
	}
	Objekt3D* objekt = citaj_binarno(fp1);

	fclose(fp1);

	FILE* fp2 = fopen("write.stl", "wb");

	if (!fp2)
	{
		return 1;
	}
	zapisi_binarno(fp2, objekt);

	fclose(fp2);

	FILE* fp3 = fopen("write.txt", "w");
	if (!fp3)
	{
		return 1;
	}
	zapisi_tekst(fp3, objekt);

	fclose(fp3);


	izbrisi(objekt);

	return 0;
}