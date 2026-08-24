/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Miguel Otávio Cardoso Ramos
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 23/08/2026
Objetivo    : Ler 100 valorees inteiros e apresentar o maior valor e sua respectiva posição
Dificuldade : Ter a sacada de colocar o primeiro numero como maior. Relembrar estruturas.
Uso de IA   : Não fiz o uso de IA
-------------------------------------------------------------------------- */

#include <stdio.h>
 
int main() {


int n;
int maior;
int posicao;

for(int i=0; i<100; i++){
    scanf("%d", &n);
    if(i==0)
        maior = n, posicao = i+1;
    else
        if(n>maior)
        maior = n, posicao = i+1;
}

printf("%d\n", maior);
printf("%d\n", posicao);
    return 0;
}
