/*
        Árvore RB
 1.Todo nó é vermelho ou preto
 2.A raiz é preta
 3.Toda folha (Nil) é preta
 4.Se um nó é vermelho, então os seus filhos são  pretos
 5.Para cada nó, todos os caminhos do nó para folhas descendentes contém o mesmo número de nós PRETOS.
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct Record Record;
typedef struct Tree Tree;

struct Record{
	int key;
	int value;
};

struct Tree{
	Record reg;
	Tree *esq, *dir;
	int cor; // 1 Para Vermelho, 0 para preto
};

Tree* CreateTree(){
	return NULL;
}

void pesquisa(Tree **t, Tree **aux, Record r){

	if(*t == NULL){
		printf("[ERROR]: Node not found!");
		return;
	}

	if((*t)->reg.key > r.key){ pesquisa(&(*t)->esq, aux, r); return;}
	if((*t)->reg.key < r.key){ pesquisa(&(*t)->dir, aux, r); return;}

	*aux = *t;
}

void rotacaoSimplesDireita(Tree **t){
	Tree *aux;
	aux = (*t)->esq;
	(*t)->esq = aux->dir;
	aux->dir = (*t);
	aux->cor = (*t)->cor;
	(*t)->cor = 1
	(*t) = aux;
}

void rotacaoSimplesEsquerda(Tree **t){
	Tree *aux;
	aux = (*t)->dir;
	(*t)->dir = aux->esq;
	aux->esq = (*t);
	aux->cor = (*t)->cor;
	(*t)->cor = 1;
	(*t) = aux;
}

void rotacaoDuplaDireita(Tree **t){
	rotacaoSimplesEsquerda(&(*t)->esq);
	rotacaoSimplesDireita(t);
}

void rotacaoDuplaEsquerda(Tree **t){
	rotacaoSimplesDireita(&(*t)->dir);
	rotacaoSimplesEsquerda(t);
}

void insertTree(Tree **t, Record r)
{
  if(*t == NULL){
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->esq    = NULL; 
    (*t)->dir    = NULL; 
    (*t)->weight = 0;
    (*t)->reg    = r; 
  } else {
    
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
}

void antecessor(Tree **t, Tree *r){ 

	if ((*t)->dir != NULL){ 
		antecessor(&(*t)->dir, r);
		return;
  	}
  	
  	r->reg = (*t)->reg;
  	r = *t; 
  	*t = (*t)->esq;
  	free(r);
} 


void rebalanceTree(Tree **t){
	int balance;
  	int left = 0;
  	int right = 0;

	balance = getWeight(&(*t)->esq) - getWeight(&(*t)->dir);
	if((*t)->esq)
		left = getWeight(&(*t)->esq->esq) - getWeight(&(*t)->esq->dir);
	if((*t)->dir)
		right = getWeight(&(*t)->dir->esq) - getWeight(&(*t)->dir->dir);

	printf("Raiz:%d, Filho esq:%d, Filho dir:%d\n", balance, left, right);

	if(balance == 2 && left >= 0)
		rotacaoSimplesDireita(t);
	if(balance == 2 && left < 0)
		rotacaoDuplaDireita(t);

	if(balance == -2 && right >= 0)
		rotacaoDuplaEsquerda(t);
	if(balance == -2 && right < 0)
		rotacaoSimplesEsquerda(t);
  	
  	
}

void removeTree(Tree **t, Tree **f, Record r){
	Tree *aux;
  	
  	if (*t == NULL){ 
  		printf("[ERROR]: Record not found!!!\n");
    	return;
  	}

  	if (r.key < (*t)->reg.key){ 
		removeTree(&(*t)->esq, t, r); return;
	}
  	if (r.key > (*t)->reg.key){ 
		removeTree(&(*t)->dir, t, r); return;
	}

  	if ((*t)->dir == NULL){ 
  		aux = *t;  
  		*t = (*t)->esq;
    	free(aux);
    	rebalanceTree(f);
    	return;
  	}

  	if ((*t)->esq != NULL){ 
  		antecessor(&(*t)->esq, *t); 
  		rebalanceTree(f);
  		return;
  	}

  	aux = *t;  
  	*t = (*t)->dir;
  	free(aux);
  	rebalanceTree(f);  	
  	
}


void showTreeInOrder(Tree *t)
{
  if(!(t == NULL)){
    showTreeInOrder(t->esq); 
    printf("%d ", t->reg.key);
    showTreeInOrder(t->dir); 
  }
}


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








