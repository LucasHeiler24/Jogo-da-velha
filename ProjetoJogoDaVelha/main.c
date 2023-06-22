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

//Função para verificar se algum jogador ganhou
int checagemDeVitoria(char tabuleiro[][3], char jogador){
    int i = 0, checagem = 0;

    //Verifica as linhas
    for(i = 0; i = 3; i++){
        if(tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador){
            if(jogador == 'X'){
                return 1;
            }
            else{
                return 0;
            }
        }

        //Verifica as colunas
        if(tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador){
            if(jogador == 'X'){
                return 1;
            }
            else{
                return 0;
            }
        }

        else if(tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador){
            if(jogador == 'X'){
                return 1;
            }
            else{
                return 0;
            }
        }
        else if(tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador){
            if(jogador == 'X'){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
    return NULL;
}
int main()
{
    //Declaração de variáveis
    int jogadorAtual = 1, linha = 0;
    char tabuleiro[3][3]={
      {' ', ' ', ' '},
      {' ', ' ', ' '},
      {' ', ' ', ' '}}, coluna;


    printf("===============================\n");
    printf("JOGO DA VELHA EM LINGUAGEM C!\n");
    printf("===============================\n\n");

    exibirTabuleiroComLinhas(tabuleiro);

    while(checagemDeVitoria != 1 || checagemDeVitoria != 0){
    //Vez do jogador X
    if(jogadorAtual = 1){

        //Escolha da coluna
        printf("Jogador X, escolha a coluna de A a C: ");
        scanf(" %s", &coluna);
        printf("\n");

        //Escolha da linha
        printf("Jogador O, escolha a linha de 0 a 2: ");
        scanf(" %d", &linha);
        printf("\n");

        //Validação: Valor Inválido

        /*
        while(linha < 1 || linha > 4 || coluna < 65 ||
              coluna > 67 && coluna < 97 || coluna > 99){

            exibirTabuleiroComLinhas(tabuleiro);

            printf("\nEntrada invalida, digite outro valor\n\n");

            printf("Jogador X, escolha a coluna de A a C: ");
            scanf(" %s", &coluna);
            printf("\n");

            printf("Jogador X, escolha a linha de 0 a 2: ");
            scanf(" %d", &linha);
            printf("\n");

            */ //Arrumar



            /*Conversão dos números para deixar mais fácil o
            utilização do programa aos usuários*/
            if(linha == 1){
                linha = 0;
            }

            else if(linha == 2){
                linha = 1;
            }

            else if(linha == 3){
                linha = 3;
            }

            //Converter as letras para números na validação
            if(coluna == 'a' || coluna == 'A'){
                coluna = 0;
            }

            else if(coluna == 'b' || coluna == 'B'){
                coluna = 1;
            }

            else if(coluna == 'c' || coluna == 'C'){
                coluna = 2;
            }

        }

        if(linha == 1){
                linha = 0;
            }

            else if(linha == 2){
                linha = 1;
            }

            else if(linha == 3){
                linha = 3;
            }

        //Converter as letras para números fora da validação
        if(coluna == 'a' || coluna == 'A'){
            coluna = 0;
        }
        else if(coluna == 'b' || coluna == 'B'){
            coluna = 1;
        }
        else if(coluna == 'c' || coluna == 'C'){
            coluna = 2;
        }

        //Validação: Se a posição tiver ocupada
        while(tabuleiro[linha][coluna] == 'O' || tabuleiro[linha][coluna] == 'X'){

            printf("Algum jogador ja marcou esta posicao, escolha outra!\n\n");

            printf("Jogador X, escolha a coluna de A a C: ");
            scanf(" %s", &coluna);
            printf("\n");

            printf("Jogador O, escolha a linha de 0 a 2: ");
            scanf(" %d", &linha);
            printf("\n");

            if(linha == 1){
                linha = 0;
            }

            else if(linha == 2){
                linha = 1;
            }

            else if(linha == 3){
                linha = 3;
            }

            //Conversão de letras para números na validação
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

        //Colocando o X ou O no lugar escolhido pelo usuário
        tabuleiro[linha][coluna] = 'X';

        //Exibir novamente o tabuleiro com a jogada do jogador anterior
        exibirTabuleiroComLinhas(tabuleiro);

        //Chama a função para verificar a vitória
        checagemDeVitoria(tabuleiro, 'X');

        //Passa a vez para o outro jogador
        jogadorAtual = 0;
        }

        //Vez do jogador O
        if(jogadorAtual == 0){

        printf("Jogador O, escolha a coluna de A a C: ");
        scanf(" %s", &coluna);
        printf("\n");

        printf("Jogador O, escolha a linha de 0 a 2: ");
        scanf(" %d", &linha);
        printf("\n");

        if(linha == 1){
                linha = 0;
            }

            else if(linha == 2){
                linha = 1;
            }

            else if(linha == 3){
                linha = 3;
            }

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

            exibirTabuleiroComLinhas(tabuleiro);

            printf("Algum jogador ja marcou esta posicao, escolha outra!\n");

            printf("Jogador O, escolha a coluna de A a C: ");
            scanf(" %s", &coluna);
            printf("\n");

            printf("Jogador O, escolha a linha de 0 a 2: ");
            scanf(" %d", &linha);
            printf("\n");

            if(linha == 1){
                linha = 0;
            }

            else if(linha == 2){
                linha = 1;
            }

            else if(linha == 3){
                linha = 3;
            }

            if(coluna == 'a' || coluna == 'A'){
                coluna = 0;
            }

            if(coluna == 'b' || coluna == 'B'){
                coluna = 1;
            }

            else if(coluna == 'c' || coluna == 'C'){
                coluna= 2;
            }

        }

        tabuleiro[linha][coluna] = 'O';

        exibirTabuleiroComLinhas(tabuleiro);

        checagemDeVitoria(tabuleiro, 'X');


        jogadorAtual = 1;

        }
    }
        return 0;
}
