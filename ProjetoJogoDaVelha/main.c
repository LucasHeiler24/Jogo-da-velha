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

void checagemDeVitoria(){

}
int main()
{
    //Declara��o de vari�veis
    int jogadorAtual = 1, linha = 0;
    char tabuleiro[3][3]={
      {' ', ' ', ' '},
      {' ', ' ', ' '},
      {' ', ' ', ' '}}, coluna;


    printf("===============================\n");
    printf("JOGO DA VELHA EM LINGUAGEM C!\n");
    printf("===============================\n\n");

    exibirTabuleiroComLinhas(tabuleiro);

    //Vez do jogador X
    if(jogadorAtual = 1){
        //Escolha da linha
        printf("Jogador X, escolha a linha de 0 a 2: ");
        scanf(" %d", &linha);
        printf("\n");

        //Escolha da coluna
        printf("Jogador X, escolha a coluna de A a C: ");
        scanf(" %s", &coluna);
        printf("\n");

        //Valida��o: Valor Inv�lido
        while(linha < 0 || linha > 4 || coluna < 97 || coluna > 99){

            printf("\nEntrada invalida, digite outro valor\n\n");

            printf("Jogador X, escolha a linha de 0 a 2: ");
            scanf(" %d", &linha);
            printf("\n");

            printf("Jogador X, escolha a coluna de A a C: ");
            scanf(" %s", &coluna);
            printf("\n");

            //Converter as letras para n�meros na valida��o
            if(coluna == 'a' || coluna == 'A'){
                coluna = 0;
            }

            else if(coluna == 'b' || coluna == 'B'){
                coluna = 1;
            }

            else if(coluna == 'c' || coluna == 'C'){
                coluna = 2;
            }

            exibirTabuleiroComLinhas(tabuleiro);
        }

        //Converter as letras para n�meros fora da valida��o
        if(coluna == 'a' || coluna == 'A'){
            coluna = 0;
        }
        else if(coluna == 'b' || coluna == 'B'){
            coluna = 1;
        }
        else if(coluna == 'c' || coluna == 'C'){
            coluna = 2;
        }

        //Valida��o: Se a posi��o tiver ocupada
        while(tabuleiro[linha][coluna] == 'O' || tabuleiro[linha][coluna] == 'X'){

            printf("Algum jogador ja marcou esta posicao, escolha outra!\n\n");

            printf("Jogador X, escolha a linha de 0 a 2: ");
            scanf(" %d", &linha);
            printf("\n");

            printf("Jogador X, escolha a coluna de A a C: ");
            scanf(" %s", &coluna);
            printf("\n");

            /*Convers�o dos n�meros para deixar mais f�cil o
            utiliza��o do programa aos usu�rios*/
            if(linha == 1){
                linha = 0;
            }

            else if(linha == 2){
                linha = 1;
            }

            else if(linha == 3){
                linha = 3;
            }

            //Convers�o de letras para n�meros na valida��o
            if(coluna == 'a' || coluna == 'A'){
                coluna = 0;
            }

            if(coluna == 'b' || coluna == 'B'){
                coluna = 1;
            }

            else if(coluna == 'c' || coluna == 'C'){
                coluna = 2;
            }

            exibirTabuleiroComLinhas(tabuleiro);
        }

        //Colocando o X ou O no lugar escolhido pelo usu�rio
        tabuleiro[linha][coluna] = 'X';

        //Exibir novamente o tabuleiro com a jogada do jogador anterior
        exibirTabuleiroComLinhas(tabuleiro);

        //Passa a vez para o outro jogador
        jogadorAtual = 0;
        }

        //Vez do jogador O
        if(jogadorAtual == 0){

        printf("Jogador O, escolha a linha de 0 a 2: ");
        scanf(" %d", &linha);
        printf("\n");

        printf("Jogador O, escolha a coluna de A a C: ");
        scanf(" %s", &coluna);
        printf("\n");

        if(coluna == 'a' || coluna == 'A'){
            coluna = 0;
        }
        if(coluna == 'b' || coluna == 'B'){
            coluna = 1;
        }
        else if(coluna == 'c' || coluna == 'C'){
            coluna = 2;
        }

        while(tabuleiro[linha][coluna] == 'X' || tabuleiro[linha][coluna] == 'O'){

            printf("Algum jogador ja marcou esta posicao, escolha outra!\n");

            printf("Jogador O, escolha a linha de 0 a 2: ");
            scanf(" %d", &linha);
            printf("\n");

            printf("Jogador O, escolha a coluna de A a C: ");
            scanf(" %s", &coluna);
            printf("\n");

            if(coluna == 'a' || coluna == 'A'){
                coluna = 0;
            }

            if(coluna == 'b' || coluna == 'B'){
                coluna = 1;
            }

            else if(coluna == 'c' || coluna == 'C'){
                coluna= 2;
            }

            exibirTabuleiroComLinhas(tabuleiro);
        }

        tabuleiro[linha][coluna] = 'O';

        exibirTabuleiroComLinhas(tabuleiro);

        jogadorAtual = 1;

        }

        return 0;
}
