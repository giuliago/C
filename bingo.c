#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct {
    int bingo_cartela[4][4];
    int vetor_repetidos[16];
    int contador;
} Bingo;

void gera_cartela(Bingo *Jogador){
    int k = 0;
    int x = 0;
    (*Jogador).vetor_repetidos[k] = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            (*Jogador).bingo_cartela[i][j] = rand()/1000;
            while (x <= k){
                for (int z = 0; z <= x; z++){
                    while (((*Jogador).bingo_cartela[i][j] == (*Jogador).vetor_repetidos[z]) || ((*Jogador).bingo_cartela[i][j] == 0)){
                    (*Jogador).bingo_cartela[i][j] = rand()/1000;
                    }
                }
                x++;
            }
            k++;
            (*Jogador).vetor_repetidos[k] =  (*Jogador).bingo_cartela[i][j];
        }
    }
}

void printa_cartela(Bingo *Jogador){
    for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                printf ("%d ", (*Jogador).bingo_cartela[i][j]);
        }
            printf("\n");
    }
}

void marca_cartela(Bingo *Jogador1, Bingo *Jogador2){
    int num = rand()/1000;
    while (num == 0){
        num = rand()/1000;
    }
    printf ("Número sorteado foi: %d\n", num);
    int flag = 0;
    for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                if ((*Jogador1).bingo_cartela[i][j] == num){
                    (*Jogador1).bingo_cartela[i][j] = 0;
                    (*Jogador1).contador ++;
                    printf ("Jogador 1 marcou ponto.\n");
                    flag = 1;
                }
                else if ((*Jogador2).bingo_cartela[i][j] == num){
                    (*Jogador2).bingo_cartela[i][j] = 0;
                    (*Jogador2).contador ++;
                    printf ("Jogador 2 marcou ponto.\n");
                    flag = 1;
                }
        }
    }
    if (flag == 0){
        printf ("Não conseguiram marcar ponto dessa vez.\n");
    }
}

void setAtributos(Bingo *Jogador){
    (*Jogador).contador = 0;
}

int main(){
    srand(time(0));
    setlocale(LC_ALL, "Portuguese");
    int x = 0;
    int y = 0;
    Bingo Jogador_1, Jogador_2;
    printf ("------------------JOGADOR 1---------------------\n");
    gera_cartela(&Jogador_1);
    printa_cartela(&Jogador_1);
    printf ("------------------JOGADOR 2---------------------\n");
    gera_cartela(&Jogador_2);
    printa_cartela(&Jogador_2);
    setAtributos(&Jogador_1);
    setAtributos(&Jogador_2);
    while (x < 16 && y < 16){
        printf ("----------------SORTEANDO NÚMERO----------------\n");
        marca_cartela(&Jogador_1, &Jogador_2);
        x = Jogador_1.contador;
        y = Jogador_2.contador;
    }
    printf ("----------------CARTELA DOS JOGADORES-------------------\n");
    printf ("----------------------JOGADOR 1-------------------------\n");
    printa_cartela(&Jogador_1);
    printf ("----------------------JOGADOR 2-------------------------\n");
    printa_cartela(&Jogador_2);
    if (x == 16){
        printf ("O Jogador 1 venceu!!");
    }
    else if (y == 16){
        printf ("O Jogador 2 venceu!!");
    }
}
