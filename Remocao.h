#ifndef _REMOCAO_
#define _REMOCAO_
#include "Cor.h"
#include "Rotacoes.h"

void rebalanceTree(Tree **t){
	printf("PAssou aqui\n");
	//nó vermelho é sempre filho à esquerda
	if(AcessarCor(&(*t)->dir)==1)
		rotacaoSimplesEsquerda(t);
	//Filho da esquerda e neto da esquerda são vermelhos
	if( (*t)->esq != NULL && AcessarCor(&(*t)->esq) == 1 && AcessarCor(&(*t)->esq->esq) == 1)
		rotacaoSimplesDireita(t);
	//2 Filhos Vermelhos
	if(AcessarCor(&(*t)->esq)== 1 && AcessarCor(&(*t)->dir)== 1)
		trocaCor(t);
}
void mover2EsqRED(Tree **t){
    trocaCor(t);
	if(AcessarCor(&(*t)->dir->esq) == 1){
		rotacaoSimplesDireita(&(*t)->dir);
		rotacaoSimplesEsquerda(t);
		trocaCor(t);
	}
}
void mover2DirRED(Tree **t){
    trocaCor(t);
	if(AcessarCor(&(*t)->esq->esq) == 1){
		rotacaoSimplesDireita(t);
		trocaCor(t);
	}
}

void removerMenor(Tree **t){
	if((*t)->esq == NULL){
		free(t);
		return;
	}
	if(AcessarCor(&(*t)->esq) == 0 && AcessarCor(&(*t)->esq->esq) == 0)
		mover2EsqRED(t);

	removerMenor(&(*t)->esq);
	rebalanceTree(t);
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

void remover(Tree **t, Record r){
	if(r.key < (*t)->reg.key){
		if(AcessarCor(&(*t)->esq) == 0 && AcessarCor(&(*t)->esq->esq)== 0)
			mover2EsqRED(t);
		remover(&(*t)->esq,r);
	}else{
		if(AcessarCor(&(*t)->esq) == 1)
			rotacaoSimplesDireita(t);
	
		if(r.key == (*t)->reg.key && ((*t)->dir == NULL)){
			free(*t);
			return;
		} 
		if(AcessarCor(&(*t)->dir) == 0 && AcessarCor(&(*t)->dir->esq) == 0){
			mover2DirRED(t);
		}
		if(r.key == (*t)->reg.key){
			Tree *aux = procurarMenor(&(*t)->dir);
			(*t)->reg.key = aux->reg.key;
			removerMenor(&(*t)->dir);
		}else{
			remover(&(*t)->dir, r);
			printf("PAssou aqui\n");
		}
	}
	rebalanceTree(t);
}


void removeTree(Tree **t, Tree **f, Record r){
	Tree *aux;
  	if (*t == NULL){ 
  		printf("[ERROR]: Record not found!!!\n");
    	return;
  	}

  	if (r.key < (*t)->reg.key){ 
		removeTree(&(*t)->esq, t, r); 
		return;
	}
  	if (r.key > (*t)->reg.key){ 
		removeTree(&(*t)->dir, t, r); 
		return;
	}
	//Tree *h = *t;
	remover(&(*t),r);
  	
}

#endif