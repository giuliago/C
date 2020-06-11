#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void calculo(int *v, int n, int d){
    int i;
    int x = 0;
    for (i = 0; i < n; i++){
        if (((v[i] < v[i+1]) || (v[i] == v[i+1])) && (x < d)){//verifica se o primeiro número é menor ou igual
                                                            //que o próximo e se for é retirado do vetor
            v[i] = -1;
            x++;
        }
        else if ((v[i] > v[i+1]) && (x < d)) {
            v[i+1] = v[i];
            v[i] = -1;
            x++;
        }
    }
    for (i = 0; i < n; i++){//printa apenas os números válidos
        if (v[i] != -1){
            printf("%d", v[i]);
        }
    }
}

int main(){

setlocale(LC_ALL, "Portuguese");

int d; //números a serem retirados
int n; //tamanho do número
int i;

printf("Entre com o tamanho do número:\n");
scanf("%d", &n);

int num[n];

printf("Coloque 1 número para cada entrada:\n");

for(i = 0; i < n; i++){
scanf("%d", &num[i]);
}

printf("Escolha quantos números podem ser retirados:\n");
scanf("%d", &d);

calculo(num, n, d);
}
