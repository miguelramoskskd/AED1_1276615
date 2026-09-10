/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Miguel Otávio Cardoso Ramos
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 10/09/2026
Objetivo    : Implementar o processo de descarte e movimentação de cartas utilizando lista encadeada.
Dificuldade : Implementar a manipulação da lista, uso dos ponteiros de início e fim, o descarte e movimentação dos nós. E o controle de qntd de cartas restantes.
Uso de IA   : Apoio da IA, pedi à ela que não me desse respostas, apenas acompanhasse meu processo. Depois, após apresentar muita dificuldade, pedi ajuda para finalizar e corrigir meu código.
-------------------------------------------------------------------------- */

#include <stdlib.h>
#include <stdio.h>

struct No {
    int carta;
    struct No *prox;
};

int main() {

    int n; // quantidade de cartas
    scanf("%d", &n);
    

    while (n != 0) {
        int descartadas[50];
        int qtdDescartadas = 0;
        int quantidade = n;

        struct No *novo; // criação de um ponteiro para o novo nó
            novo = malloc(sizeof(struct No)); // alocação de memória para um struct nó

            struct No *inicio = NULL; // criação do ponteiro inicio apontando para NULL
            struct No *fim = NULL;   // criação do ponteiro fim apontando para NULL

            novo->carta = 1; // atribuindo o valor 1 à "carta" do novo nó
            novo->prox = NULL; // inicializando "proximo" do novo nó como NULL

            inicio = novo;
            fim = novo;

            for(int i = 1; i<n; i++){
                novo = malloc(sizeof(struct No)); // alocação de memória para um struct nó
                novo->carta = i+1; // atribuindo o valor 2 à "carta" do novo nó
                novo->prox = NULL; // inicializando "proximo" do novo nó como NULL

                fim->prox = novo; // liga o último nó atual ao novo nó
                fim = novo; // atualiza o ponteiro fim para que ele represente o novo último nó
            }


        while(quantidade>1){
            
            struct No *lixo = inicio; // criação de um ponteiro "lixo" para guardar o nó que será descartado
            inicio = inicio->prox; // atualiza o inicio para apontar para o próximo nó
            descartadas[qtdDescartadas] = lixo->carta; // coloca carta descartada em um vetor de descartadas
            qtdDescartadas++;
            free(lixo); // libera memória do nó descartado
            
            quantidade--;
            if(quantidade > 1){
                struct No*movido = inicio; // criação de um ponteiro "movido" para guardar o nó que será movido
                inicio = inicio->prox; // atualiza o inicio para apontar para o próximo nó
                fim->prox = movido; // liga o último nó atual ao nó que será movido
                fim = movido; // atualiza o ponteiro fim para representar o novo último nó
                fim->prox = NULL; // define NULL como próximo do último nó
            }
        }

        printf("Discarded cards:");

        for (int i = 0; i < qtdDescartadas; i++) {

            if(i>0) {
            printf(", ");
            }
            printf("%d", descartadas[i]);   
        }

        printf("\n");
        printf("Remaining card: %d\n", inicio->carta);
        free(inicio);
        scanf("%d", &n);
    }

    return 0;
}

