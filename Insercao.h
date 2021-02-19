#ifndef _INSERCAO_
#define _INSERCAO_ 
#include "Cor.h"
#include "Rotacoes.h"

void insertTree(Tree **t, Record r){
  if(*t == NULL){
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->esq    = NULL; 
    (*t)->dir    = NULL; 
    (*t)->cor = 1;
    (*t)->reg    = r; 
  } else {
    if(r.key < (*t)->reg.key){
      insertTree(&(*t)->esq, r);
    }else{
      insertTree(&(*t)->dir, r); 
    }

    if(AcessarCor(&(*t)->dir) == 1 && AcessarCor(&(*t)->esq) == 0){
      rotacaoSimplesEsquerda(t);
    }
    if(AcessarCor(&(*t)->dir) == 1 && AcessarCor(&(*t)->esq->esq) == 1){
      rotacaoSimplesDireita(t);
    }
    if(AcessarCor(&(*t)->dir) == 1 && AcessarCor(&(*t)->esq) == 1){
      trocaCor(t);
    }
  }
  //Testar a troca de cor da raiz
}
#endif