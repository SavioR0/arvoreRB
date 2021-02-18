#include "arvoreRB.h"
#include "Insercao.h"
#include "Remocao.h"
#include "Rotacoes.h"

#include<stdio.h>
#include<stdlib.h>

int main(){
	int reg[] = {6,4,8,5};
	Tree *raiz = CreateTree();
	Record r;

	for(int i=0; i<4; i++){
		r.key = reg[i];
		r.value = 1;
		insertTree(&raiz, r);
	}

	showTreeInOrder(raiz);
	printf("\n");

	printf("%d ",raiz->reg.key);
	printf("%d ",raiz->esq->reg.key);
	printf("%d\n",raiz->dir->reg.key);
	
	r.key = 8;
	removeTree(&raiz, NULL, r);
	
	printf("%d ",raiz->reg.key);
	printf("%d ",raiz->esq->reg.key);
	printf("%d\n",raiz->dir->reg.key);

	
	return 0;
}