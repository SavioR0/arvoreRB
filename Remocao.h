#ifndef _REMOCAO_
#define _REMOCAO_
#include "Cor.h"
#include "Rotacoes.h"

Tree *rebalanceTree(Tree **t){
	//printf("PAssou aqui\n");
	//nó vermelho é sempre filho à esquerda
	if(AcessarCor(&(*t)->dir)==1)
		rotacaoSimplesEsquerda(t);
	//Filho da esquerda e neto da esquerda são vermelhos
	if( (*t)->esq != NULL && AcessarCor(&(*t)->esq) == 1 && AcessarCor(&(*t)->esq->esq) == 1)
		rotacaoSimplesDireita(t);
	//2 Filhos Vermelhos
	if(AcessarCor(&(*t)->esq)== 1 && AcessarCor(&(*t)->dir)== 1)
		trocaCor(t);
	
	return *t;
}
Tree *mover2EsqRED(Tree **t){
    trocaCor(t);
	if(AcessarCor(&(*t)->dir->esq) == 1){
		rotacaoSimplesDireita(&(*t)->dir);
		rotacaoSimplesEsquerda(t);
		trocaCor(t);
	}
	return *t;
}
Tree *mover2DirRED(Tree **t){
    trocaCor(t);
	if(AcessarCor(&(*t)->esq->esq) == 1){
		rotacaoSimplesDireita(t);
		trocaCor(t);
	}
	return *t;
}

Tree *removerMenor(Tree **t){
	if((*t)->esq == NULL){
		free(t);
		return NULL;
	}
	if(AcessarCor(&(*t)->esq) == 0 && AcessarCor(&(*t)->esq->esq) == 0)
		mover2EsqRED(t);

	*t = removerMenor(&(*t)->esq);
	return rebalanceTree(t);
}
//Procura o nó mais á esquerda
Tree *procurarMenor(Tree **t){
	Tree *no1 = *t;
	Tree *no2 = (*t)->esq;
	while(no2 != NULL){
		no1 = no2;
		no2 = no2->esq;
	}
	return no1;
}

Tree *remover(Tree **t,Tree *pai, Record r){	
	if(r.key < (*t)->reg.key){
		if(AcessarCor(&(*t)->esq) == 0 && AcessarCor(&(*t)->esq->esq)== 0)
			mover2EsqRED(t);
		remover(&(*t)->esq,pai,r);
	}else{
		if(AcessarCor(&(*t)->esq) == 1)
			rotacaoSimplesDireita(t);
	
		if(r.key == (*t)->reg.key && ((*t)->dir == NULL)){
			
			if(pai->dir == NULL && pai->esq->esq != NULL  && (*t)->reg.key !=11){
				printf("remove");
				free(*t);
				pai->esq = pai->esq->esq;
			}
			return NULL;
		} 

		if(AcessarCor(&(*t)->dir) == 0 && AcessarCor(&(*t)->dir->esq) == 0){
			mover2DirRED(t);
		}
		if(r.key == (*t)->reg.key){
			Tree *aux = procurarMenor(&(*t)->dir);
			(*t)->reg.key = aux->reg.key;
			(*t)->dir = removerMenor(&(*t)->dir);
		}else{
			remover(&(*t)->dir, pai,r);
		}
	}
	return rebalanceTree(t);
}


void removeTree(Tree **t, Tree **f, Record r){
	Tree *pai ;
  	if (*t == NULL){ 
  		printf("[ERROR]: Record not found!!!\n");
    	return;
  	}
	printf("%d\n", (*t)->reg.key);
  	if (r.key < (*t)->reg.key){ 
		removeTree(&(*t)->esq, t, r); 
		return;
	}
  	if (r.key > (*t)->reg.key){ 
		removeTree(&(*t)->dir, t, r); 
		return;
	}
	pai = *f;
	//Tree *h = *t;
	*t = remover(&(*t),pai,r);
  	
}

#endif