#include <stdio.h>
#include <stdlib.h>


int contador=0;//variavel global para contar o numero de chamadas no backtracking
int tabuleiro[9][9] = {//tabuleiro de entrada para resolução
                        {0,0,0,0,0,0,4,5,6},
                        {0,0,0,0,0,0,0,0,0},
                        {0,5,0,0,4,6,0,9,2},
                        {2,8,0,7,0,0,0,0,3},
                        {6,0,0,0,1,0,5,0,0},
                        {0,0,0,0,0,8,0,0,0},
                        {0,0,0,0,0,0,3,0,0},
                        {8,0,0,9,0,4,6,0,0},
                        {0,2,0,8,0,0,0,0,1}
                    };

//função responsavel por imprimir o tabuleiro
int imprimirTabuleiro(int tabuleiro[9][9]){
    int i,j;
    for(i = 0;i < 9;i++){
        for(j = 0;j < 9;j++){
            printf("%d ",tabuleiro[i][j]);
        }
        printf("\n");
    }
}
//função responsável por encontrar as posições vazias no tabuleiro
int Encontrar0(int tabuleiro[9][9],int *linha,int *coluna){
    for(*linha = 0;*linha < 9;(*linha)++){
        for(*coluna = 0;*coluna < 9;(*coluna)++){
            if(tabuleiro[*linha][*coluna] == 0)
                return 1;
        }
    }
    return 0;
}

//função responsavel por percorrer as linhas e conferir

int ConfereLinha(int tabuleiro[9][9],int linha,int numero){
    int i;
    for(i = 0;i < 9;i++){
        if(tabuleiro[linha][i] == numero)
            return 1;
    }
    return 0;
}
//função responsavel por percorrer as colunas e conferir
int ConfereColuna(int tabuleiro[9][9],int coluna,int numero){
    int i;
    for(i = 0;i < 9;i++){
        if(tabuleiro[i][coluna] == numero)
            return 1;
    }
    return 0;
}

//função responsavel por percorrer ao pequeno quadro e conferir
int Confere3x3Bloco(int tabuleiro[9][9],int Ilinha,int Icol,int numero){
    int i,j;
    for(i = 0;i<3;i++){
        for(j = 0;j<3;j++){
            if(tabuleiro[i+Ilinha][j+Icol] == numero)
                return 1;
        }
    }
    return 0;
}

//função resposavel por garantir as regras do jogo chamando a conferelinha,conferecoluna e confere3X3Bloco
int ChamadaConfere(int tabuleiro[9][9],int linha,int coluna,int numero){
    if(ConfereLinha(tabuleiro,linha,numero) == 0 && ConfereColuna(tabuleiro,coluna,numero) == 0 &&
       Confere3x3Bloco(tabuleiro,(linha - linha%3),(coluna - coluna%3),numero) == 0) {
       return 1;
       }
    return 0;
}
//função responsavel por resolver recursivamente o jogo,utilizando backtracking
int Resolve(int tabuleiro[9][9]){
    int linha,coluna;
    if(Encontrar0(tabuleiro,&linha,&coluna) == 0)
        return 1;
    int numero;
    for(numero = 1;numero <= 9;numero++){
        if(ChamadaConfere(tabuleiro,linha,coluna,numero) == 1){
            tabuleiro[linha][coluna] =  numero;
            if(Resolve(tabuleiro) == 1){
                    contador++;
                return 1;
            //backtrack

            }
            tabuleiro[linha][coluna] = 0;
        }
    }
    return 0;
}



int main()
{

    printf("Jogo de entrada:\n\n");
    imprimirTabuleiro(tabuleiro);
    printf("\n\n\n");
    printf("Jogo Resolvido:\n\n");
    if(Resolve(tabuleiro) == 1)
        imprimirTabuleiro(tabuleiro);

    printf("\n\nNumero de trocas (chamadas backtracking) %d",contador);
    printf("\n\n\n");
    return 0;
}
