#include <stdio.h>
#include <stdlib.h>
void exibirTabuleiroComLinhas(char tabuleiro[][3]){ //nao coloca o valor de linhas no tabuleiro para a funcao
    int i, j;

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%c ", tabuleiro[i][j]);
            if(j!=2){ //essa logica indica as colunas que irao ter o '|', pois eu quero que so tenha em duas colunas
                printf("|");
            }
        }
            printf("\n");
            if(i!=2){ //essa logica indica as colunas que irao ter o '-', pois eu quero que so tenha em duas linhas
                printf("---------\n");
            }
    }
}
void main()
{
    int vezX = 1, vezO = 0;
    char tabuleiro[3][3]={
      {' ', ' ', ' '},
      {' ', ' ', ' '},
      {' ', ' ', ' '}};


    printf("===============================\n");
    printf("JOGO DA VELHA EM LINGUAGEM C!\n");
    printf("===============================\n\n");

    exibirTabuleiroComLinhas(tabuleiro);


}
