/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Miguel Otávio Cardoso Ramos
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 28/08/2026
Objetivo    : Ler 3 casos de matriz 9x9 e verificar se corresponde à uma solução de SUDOKU, utilizando alocação dinâmica.
Dificuldade : Conceito dos ponteiros ainda estava bem nebuloso para mim, ali no começo da alocação mesmo. Não sabia quando colocar um asterisco ou dois.
Uso de IA   : Apoio da IA, pedi à ela que não me desse respostas, apenas acompanhasse meu processo.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
 
int main() {

    int valido;
    int n;
    int **m;

    scanf("%d", &n);

    for(int caso = 0; caso < n; caso++){

        valido = 1;

        m = malloc(9*sizeof(*m));
        for(int i=0; i<9; i++){
            m[i] = malloc(9*sizeof(int));
        }

        // Leitura da matriz
        for(int k = 0; k < 9; k++){
            for(int j = 0; j < 9; j++){
                scanf("%d", &m[k][j]);
            }
        }
        
        // Verifica linhas
        for(int k = 0; k < 9; k++){
            for(int i = 0; i < 9; i++){
                for(int j = i + 1; j < 9; j++){
                    if(m[k][i] == m[k][j]){
                        valido = 0;
                    }
                }
            }
        }

        // Verifica colunas
        for(int k = 0; k < 9; k++){
            for(int i = 0; i < 9; i++){
                for(int j = i + 1; j < 9; j++){
                    if(m[i][k] == m[j][k]){
                        valido = 0;
                    }
                }
            }
        }

        // Verifica quadrantes
        for(int k = 0; k < 9; k += 3){
            for(int l = 0; l < 9; l += 3){

                int quadrante[9];
                int pos = 0;

                for(int i = k; i < k + 3; i++){
                    for(int j = l; j < l + 3; j++){
                        quadrante[pos] = m[i][j];
                        pos++;
                    }
                }

                for(int i = 0; i < 9; i++){
                    for(int j = i + 1; j < 9; j++){
                        if(quadrante[i] == quadrante[j]){
                            valido = 0;
                        }
                    }
                }
            }
        }

        // Resultado
           printf("Instancia %d\n", caso + 1);

        if(valido == 1)
            printf("SIM\n\n");
        else
            printf("NAO\n\n");

        for(int i=0; i<9; i++){
            free(m[i]);
        }
        free(m);
    }

    return 0;
}