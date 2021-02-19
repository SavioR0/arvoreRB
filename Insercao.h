#ifndef _INSERCAO_
#define _INSERCAO_ 
#include "Rotacoes.h"

void insertTree(Tree **t, Record r){
  if(*t == NULL){
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->esq    = NULL; 
    (*t)->dir    = NULL; 
    (*t)->cor = 1;
    (*t)->reg    = r; 
  } else {
    /*
    if(r.key < (*t)->reg.key){
      insertTree(&(*t)->esq, r);
      if ((getWeight(&(*t)->esq) - getWeight(&(*t)->dir)) == 2){
      	if(r.key < (*t)->esq->reg.key)
      		rotacaoSimplesDireita(t);
      	else
      		rotacaoDuplaDireita(t);
      }
    }
    
    if(r.key > (*t)->reg.key){
      insertTree(&(*t)->dir, r);
      if ((getWeight(&(*t)->dir) - getWeight(&(*t)->esq)) == 2){
      	if(r.key > (*t)->dir->reg.key)
      		rotacaoSimplesEsquerda(t);
      	else
      		rotacaoDuplaEsquerda(t);
      }
    }
  
  }

  (*t)->weight = getMaxWeight(getWeight(&(*t)->esq), getWeight(&(*t)->dir)) + 1;
  */
}
#endif