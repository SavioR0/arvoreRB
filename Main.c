#include<stdio.h>
#include<stdlib.h>
#include "arvoreRB.h"
#include "Insercao.h"
#include "Cor.h"


int main(){
	int reg[] = {6,4,8,5};
	Tree *raiz = CreateTree();
	Record r;

	for(int i=0; i<4; i++){
		r.key = reg[i];
		r.value = 1;
		insertTree(&raiz, r);
	}
	printf("\n\n\n%d %d\n\n\n",raiz->reg.key, raiz->cor);
	if(raiz->cor == 1)
		trocaCor(&raiz);

	showTreeInOrder(raiz);
	printf("\n");

	printf("%d %d,",raiz->reg.key, raiz->cor);
	printf("%d %d,",raiz->esq->reg.key, raiz->esq->cor);
	printf("%d %d\n",raiz->dir->reg.key, raiz->dir->cor);
	
	//r.key = 8;
	//removeTree(&raiz, NULL, r);
	
	//printf("%d ",raiz->reg.key);
	//printf("%d ",raiz->esq->reg.key);
	//printf("%d\n",raiz->dir->reg.key);

	
	return 0;
}