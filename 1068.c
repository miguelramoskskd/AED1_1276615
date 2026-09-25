/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Miguel Otávio Cardoso Ramos
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 21/09/2026
Objetivo    : Ler uma expressao e verificar se os parentêses estão balanceados utilizando pilha encadeada.
Dificuldade : Tratamento da pilha vazia e implementar operações de pop e push.
Uso de IA   : Usei IA conversando por chat de voz como apoio, pedi que não me desse respostas prontos. Consultei em algumas nomenclaturas de string.
-------------------------------------------------------------------------- */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct No {
    char parenteses;
    struct No *prox;
};

// topo é um ponteiro que guarda o endereço do primeiro nó 

void push(struct No **topo){

    struct No *novo = malloc(sizeof(struct No));

    novo->parenteses = '(';
    novo->prox = *topo;  
    *topo = novo; // assim o topo da pilha sempre muda conforme adiciono novos elementos

}

void pop(struct No **topo) {

    struct No *lixo = *topo;
    *topo = (*topo)->prox;
    free(lixo);
    
}


int main(){

    char expressao[1001];
    
    while(fgets(expressao, 1001, stdin) != NULL) {

    if(expressao[strlen(expressao) - 1] == '\n'){
        expressao[strlen(expressao) - 1] = '\0';
    }

    int tamanho = strlen(expressao);

    struct No *topo = NULL;
    int incorreta = 0;
 
    for(int i = 0; i < tamanho; i++){
        if(expressao[i] == '('){
            push(&topo);
        }

        if(expressao[i] == ')'){

            if(topo == NULL){
                incorreta = 1;
            } else{
                pop(&topo);
            }

        }
    }

    if(incorreta == 1 || topo!=NULL){ // se eu descobri algum erro ou sobrou algo na pilha
        printf("incorrect\n");
    } else{
        printf("correct\n");
    }

    }

    return 0;
}