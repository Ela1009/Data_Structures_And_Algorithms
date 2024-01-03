#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

BSTree NewBSTree(){
	// Novo prazno stablo
	return NULL;
}

// Rekurzivno se trazi mjesto za novi cvor u stablu. Ako rijec postoji u stablu, ne dodaje se.
// bst parametar je dvostruki pokazivac.

void AddNode(BSTree* bst, const char* word) {
	if (*bst == NULL) {
		*bst = (BSTree)malloc(sizeof(Node));
		(*bst)->word = (char*)malloc(sizeof(char) * (strlen(word) + 1));
		strcpy((*bst)->word, word);
		(*bst)->left = NULL;
		(*bst)->right = NULL;
		return;
	}
	else if (strcmp((*bst)->word, word) > 0) {
		AddNode(&((*bst)->left), word);
	}
	else if (strcmp((*bst)->word, word) < 0) {
		AddNode(&((*bst)->right), word);
	}
}

// Rekurzivno se prolazi cijelo stablo da bi se pronasla najduza grana (visina stabla).

int BSTHeight(BSTree bst){
	if (bst == NULL){
		return 0;
	}
	int left_branch = BSTHeight(bst->left);
	int right_branch = BSTHeight(bst->right);

	if (left_branch >= right_branch){
		return (left_branch + 1);
	}
	else if (left_branch < right_branch){
		return (right_branch + 1);
	}
	return 0;
}

// Ispisuje rijeci u stablu na ekran po abecednom redu.
// In-order setnja po stablu (lijevo dijete, cvor, desno dijete)

void PrintBSTree(BSTree bst){
	if (bst == NULL){
		return;
	}
	PrintBSTree(bst->left); 
	printf("%s ", bst->word);
	PrintBSTree(bst->right);
}

// Snima rijec po rijec iz stabla u tekstualnu datoteku. Rijeci su odvojene razmakom.
// Pre-order setnja po stablu (ttenutni cvor pa djeca)

void SaveBSTree(BSTree bst, FILE* fd){
	if (bst == NULL){
		return;
	}
	fprintf(fd, "%s ", bst->word);
	SaveBSTree(bst->left, fd);
	SaveBSTree(bst->right, fd);
}

// Brise stablo (string word i sam cvor) iz memorije.
// Post-order setnja po stablu (prvo djeca pa trenutni cvor)

void DeleteBSTree(BSTree bst){
	if (bst == NULL){
		return;
	}
	DeleteBSTree(bst->left);
	DeleteBSTree(bst->right);

	free(bst->word);
	free(bst);
}

// Ucitava rijec po rijec iz tekstualne datoteke i dodaje ih u stablo preko AddNode() funkcije.
// Rijec duplicirati sa strdup().

BSTree LoadBSTree(FILE* fd){
	BSTree bst = NULL;
	char buffer[1024];
	while (readWord(fd, buffer)){
		AddNode(&bst, _strdup(buffer));
	}
	return bst;
}
