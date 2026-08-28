/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Miguel Otávio Cardoso Ramos
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 28/08/2026
Objetivo    : Ler 100 valorees inteiros e apresentar o maior valor e sua respectiva posição. Utilizando Aloc. Dinâmica.
Dificuldade : Compreender que eu poderia usar &n[i] para ser o endereço da posição de cada inteiro, funcionando como um vetor mesmo.
Uso de IA   : Não fiz o uso de IA
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
 
int main() {


int *n; // sendo n, um ponteiro que vai guardar o endereço do primeiro elemento do meu vetor dinâmico
int maior;
int posicao;

n = malloc(100*sizeof(int));

for(int i=0; i<100; i++){
    scanf("%d", &n[i]);
    if(i==0)
        maior = n[i], posicao = i+1;
    else
        if(n[i]>maior)
        maior = n[i], posicao = i+1;
}

printf("%d\n", maior);
printf("%d\n", posicao);
    free(n);
    return 0;
}
