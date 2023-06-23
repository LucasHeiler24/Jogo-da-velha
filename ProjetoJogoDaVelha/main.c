#include <stdio.h>
#include <stdlib.h>

void exibirTabuleiroComLinhas(char tabuleiro[][3]){ //n�o coloca o valor de linhas no tabuleiro para a fun��o
    int i, j;

    for(i=0;i<=2;i++){
        for(j=0;j<=2;j++){
            printf("%c ", tabuleiro[i][j]);
            if(j!=2){ //essa l�gica indica as colunas que ir�o ter o '|', pois eu quero que so tenha em duas colunas
                printf("|");
            }
        }
            printf("\n");
            if(i!=2){ //essa l�gica indica as colunas que ir�o ter o '-', pois eu quero que so tenha em duas linhas
                printf("---------\n");
            }
    }
}

//Fun��o para verificar se algum jogador ganhou
int checagemDeVitoria(char tabuleiro[][3], char jogador){
    int i = 0, j = 0, contadorEspacos = 0;

    //Verifica as linhas
    for(i = 0; i < 3; i++){
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

        //Verifica as diagonais
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

    //Verifica o empate
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
            contadorEspacos++;
            }
        }
    }

    if (contadorEspacos == 0) {
        return 3;
    }

    return 2;
}
int main()
{
    //Declara��o de vari�veis
    int jogadorAtual = 1, linha = 0, checagem = 2;
    char tabuleiro[3][3]={
      {' ', ' ', ' '},
      {' ', ' ', ' '},
      {' ', ' ', ' '}}, coluna;


    printf("===============================\n");
    printf("JOGO DA VELHA EM LINGUAGEM C!\n");
    printf("===============================\n\n");

    exibirTabuleiroComLinhas(tabuleiro);

    while(checagem == 2){

    //Vez do jogador X
    if(jogadorAtual == 1){

        //Escolha da coluna
        printf("Jogador X, escolha a coluna de A a C: ");
        scanf(" %c", &coluna);
        printf("\n");

        while(coluna != 'a' && coluna != 'b' && coluna != 'c'&&
              coluna != 'A' && coluna != 'B' && coluna != 'C'){

          exibirTabuleiroComLinhas(tabuleiro);

          printf("\n\nColuna invalida. Jogador X, selecione uma coluna de A a C: \n\n");

          scanf(" %c", &coluna);
        }

        //Escolha da linha
        printf("Jogador X, escolha a linha de 1 a 3: ");
        scanf(" %d", &linha);
        printf("\n");

        //Valida��o: Valor Inv�lido
        while(linha < 1 || linha > 3){

            exibirTabuleiroComLinhas(tabuleiro);

        printf("\nLinha invalida. Jogador X, selecione uma linha de 1 a 3\n\n");
            scanf(" %d", &linha);
            printf("\n");
        }

            //Convers�o para melhor uso do usu�rio
            if(linha == 1){
                linha = 0;
            }

            else if(linha == 2){
                linha = 1;
            }

            else if(linha == 3){
                linha = 2;
            }

        //Converter as letras para n�meros para ir na matriz
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

            exibirTabuleiroComLinhas(tabuleiro);

            printf("Algum jogador ja marcou esta posicao, escolha outra!\n\n");

            printf("Jogador X, escolha a coluna de A a C: ");
            scanf(" %c", &coluna);
            printf("\n");

            printf("Jogador X, escolha a linha de 1 a 3: ");
            scanf(" %d", &linha);
            printf("\n");

            if(linha == 1){
                linha = 0;
            }

            else if(linha == 2){
                linha = 1;
            }

            else if(linha == 3){
                linha = 2;
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
        }

        //Colocando o X ou O no lugar escolhido pelo usu�rio
        tabuleiro[linha][coluna] = 'X';

        //Exibir novamente o tabuleiro com a jogada do jogador anterior
        exibirTabuleiroComLinhas(tabuleiro);

        //Chama a fun��o para verificar a vit�ria
        checagem = checagemDeVitoria(tabuleiro, 'X');

        //Verificar quem foi o vencedor ou se empatou
        if(checagem == 1){
            printf("\n\nJogador X ganhou, Parabens!!!\n\n");
            break;
        }

        else if(checagem == 3){
            printf("\n\nEmpate, nenhum Jogador venceu\n\n");
            break;
        }

        //Passa a vez para o outro jogador
        jogadorAtual = 0;
        }

        //Vez do jogador O
        if(jogadorAtual == 0){

        printf("Jogador O, escolha a coluna de A a C: ");
        scanf(" %c", &coluna);
        printf("\n");

        //Valida��o: valor inv�lido para coluna
        while(coluna != 'a' && coluna != 'b' && coluna != 'c' &&
              coluna != 'A' && coluna != 'B' && coluna != 'C'){

            exibirTabuleiroComLinhas(tabuleiro);

            printf("\n\nColuna invalida. Jogador O, selecione uma coluna de A a C: \n\n");

            scanf(" %c", &coluna);
        }

        printf("Jogador O, escolha a linha de 1 a 3: ");
        scanf(" %d", &linha);
        printf("\n");

        //Valida��o: valor Inv�lido na linha
        while(linha < 1 || linha > 3){

            exibirTabuleiroComLinhas(tabuleiro);

            printf("\nLinha invalida. Jogador O, selecione uma linha de 1 a 3\n\n");
            scanf(" %d", &linha);
            printf("\n");
        }

            //Convers�es
            if(linha == 1){
                linha = 0;
            }

            else if(linha == 2){
                linha = 1;
            }

            else if(linha == 3){
                linha = 2;
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

        //Valida��o: posi��o j� ocupada por outro jogador
        while(tabuleiro[linha][coluna] == 'X' || tabuleiro[linha][coluna] == 'O'){

            exibirTabuleiroComLinhas(tabuleiro);

            printf("Algum jogador ja marcou esta posicao, escolha outra!\n\n");

            printf("Jogador O, escolha a coluna de A a C: ");
            scanf(" %c", &coluna);
            printf("\n");

            printf("Jogador O, escolha a linha de 1 a 3: ");
            scanf(" %d", &linha);
            printf("\n");

            //Convers�es
            if(linha == 1){
                linha = 0;
            }

            else if(linha == 2){
                linha = 1;
            }

            else if(linha == 3){
                linha = 2;
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

        checagem = checagemDeVitoria(tabuleiro, 'O');

        //Verificar quem foi o vencedor ou se empatou
        if(checagem == 0){
            printf("\n\nJogador O ganhou, Parabens!!!\n\n");
            break;
        }

        else if(checagem == 3){
            printf("\n\nNenhum Jogador ganhou\n\n");
            break;
        }

        //Passa a vez para o outro jogador
        jogadorAtual = 1;
        }
    }
        return 0;
}
