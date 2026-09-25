/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Miguel Otávio Cardoso Ramos
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 25/09/2026
Objetivo    : Calcular a distância total percorrida pelo entregador entre todas as entregas
Dificuldade : Entender os limites e e d e como devem ser atualizados, montar a lógica da main.
Uso de IA   : Apoio no desenvolvimento do programa passo a passo, construção da busca binária e erros de sintaxe.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
 
int buscaBinaria(int x, int n, int v[]){
    int e, d, m;
    e = 0;
    d = n-1;
    
    while(e<=d){
        m = ((e+d)/2);
        if(v[m] == x){
            return m;
        }
        
        if(v[m] < x){
            e = m + 1;
    } else{
        d = m - 1;
    }
}
    return -1;

}

int main() {
    int N, M;

    scanf("%d", &N);
    scanf("%d", &M);

    int casas[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &casas[i]);
    }
    
    int posicao_atual = 0;
    int distancia = 0;
    
    for (int i = 0; i < M; i++) {
        int destino;
        scanf("%d", &destino);
        
        int posicao_destino = buscaBinaria(destino, N, casas);
    
        distancia += abs(posicao_destino - posicao_atual); // abs para manter valor absoluto, se não zeraria ficar indo e voltando
    
        posicao_atual = posicao_destino;
    }
    
    printf("%d\n", distancia);

    return 0;
}


