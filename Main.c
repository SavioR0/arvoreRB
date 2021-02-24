#include<stdio.h>
#include<stdlib.h>
#include "arvoreRB.h"
#include "Insercao.h"
#include "Remocao.h"
#include "Cor.h"


int main(){
	int reg[] = {11,2,1,5,4,7,8,13,15,14};
	Tree *raiz = CreateTree();
	Record r;
	int tam = sizeof(reg)/sizeof(reg[0]);
	
	printf("ELEMENTOS A SEREM ADICIONADOS:");
	for (int i = 0; i<tam;i++)
		printf(" %d ", reg[i]);
	printf("\n");

	for(int i=0; i<tam; i++){
		r.key = reg[i];
		r.value = 1;
		insertTree(&raiz, r);
	}
	
	
	printf("\n\tORDEM CRESCENTE\n");
	showTreeInOrder(raiz);
	printf("\n----------------\n");
	print2D(raiz);
	printf("\n--------------------\n");

	printf("Raiz : %d", raiz->reg.key);
	raiz->cor==1? printf(" (Vermelho) "): printf(" (Preto) ");
	printf("\tEsquerda : %d",raiz->esq->reg.key);
	raiz->esq->cor==1? printf("(Vermelho) "): printf("(Preto) ");
	printf("\tDireita : %d",raiz->dir->reg.key);
	raiz->dir->cor==1? printf(" (Vermelho) \n"): printf(" (Preto) \n");
	
	r.key = 7;
	removeTree(&raiz, NULL, r);
	
	printf("\n\tAPÓS REMOÇÃO 7(Folha):\n");
	showTreeInOrder(raiz);
	printf("\n--------------------\n");
	print2D(raiz);
	printf("\n--------------------\n");

	printf("Raiz: %d ",raiz->reg.key);
	raiz->esq->reg.key? printf("\tEsquerda: %d",raiz->esq->reg.key):printf("\tEsquerda:NULL");
	raiz->dir->reg.key? printf("\tDireita: %d\n",raiz->dir->reg.key):printf("\tDireita: NULL\n");

	r.key = 14;
	removeTree(&raiz, NULL, r);
	printf("\n\tAPÓS REMOÇÃO 14 11 13:\n");
	showTreeInOrder(raiz);
	printf("\n--------------------\n");
	print2D(raiz);
	printf("\n--------------------\n");

	printf("Raiz: %d ",raiz->reg.key);
	raiz->esq->reg.key? printf("\tEsquerda: %d",raiz->esq->reg.key):printf("\tEsquerda:NULL");
	raiz->dir->reg.key? printf("\tDireita: %d\n",raiz->dir->reg.key):printf("\tDireita: NULL\n");
	return 0;
}