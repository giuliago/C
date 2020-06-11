#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <locale.h>
using namespace std;

class Jogador
    {
    public:
        string name;
        int tempo;
        Jogador (string name)
        {
            this->name=name;
        }
    };

class Jogo
    {
    public:
        int indicePalavra;
        string palavras[1000];
        int tamanhostring, aux;
        char vetor_de_tracos[1000];
        Jogador* x;
        Jogo (string name)
        {
            srand(time (0));
            int indicePalavra = rand() % 50;
            this->indicePalavra=indicePalavra;
            ifstream arq_in_palavras("C:\\Users\\Giulianna\\Desktop\\palavras.txt");
            for(int i=0; i<1000; i++)
            {
            getline (arq_in_palavras, palavras[i]);
            this->palavras[i]=palavras[i];
            }
            this->x = new Jogador(name);
        }
        void novo_vetor()
        {
            int tamanhostring=palavras[indicePalavra].length();
            char vetor_de_tracos[tamanhostring];
            for (int i=0; i<tamanhostring; i++){
                vetor_de_tracos[i]='_';
                this->vetor_de_tracos[i]=vetor_de_tracos[i];
            }
            this->tamanhostring=tamanhostring;
        }
        int jogo_inicializa()
        {
            int tentativas=0, i, aux=0, aux2=0, flag;
            char tentativa;
            while (tentativas<5){
                printa_vetor();
                cout << "Entre com a letra:" << endl;
                cin >> tentativa;
                for (i=0; i<tamanhostring; i++){
                    if (vetor_de_tracos[i]==tentativa){
                            cout << "Letra já inserida." << endl;
                            tentativas--;
                            flag=1;
                            break;
                    }
                    if (palavras[indicePalavra][i]==tentativa){
                            vetor_de_tracos[i]=tentativa;
                            aux++;
                            aux2++;
                    }
                }
                if (aux==0 && flag==0){
                    cout << "Letra não encontrada." << endl;
                }
                tentativas++;
                if (aux2==palavras[indicePalavra].length()){
                    cout << endl << "Você acertou." << endl;
                    break;
            }
            }
            printa_vetor();
            this->aux=aux2;
        }
        void printa_vetor(){
            for (int j=0; j<tamanhostring; j++){
                cout << vetor_de_tracos[j] << " ";
                }
        }
        int jogo_final()
        {
            if (aux==palavras[indicePalavra].length()){
                    return 1;
            }
            if (aux!=palavras[indicePalavra].length()){
            string palavra_tentativa;
            cout << "Entre com a palavra:" << endl;
            cin >> palavra_tentativa;
            if (palavra_tentativa==palavras[indicePalavra]){
                cout << endl << "Acertou" << endl;
                return 1;
            }
            else {
                cout << "Errou, a palavra era:" << palavras[indicePalavra];
                return 0;
            }
            }
        }
        void grava()
        {
            string nomeatual;
            long long recordeatual=0;
            string aux;
            ifstream arq_saida_recorde("C:\\Users\\Giulianna\\Desktop\\recorde.txt");
            getline (arq_saida_recorde, nomeatual);
            getline (arq_saida_recorde, aux);
                    if (aux.length()>0){
                    recordeatual = stoi(aux.substr(0));
                    }
                if (x->tempo < recordeatual || recordeatual==0){
                    ofstream arq_grava_recorde("C:\\Users\\Giulianna\\Desktop\\recorde.txt");
                    arq_grava_recorde << x->name << endl;
                    arq_grava_recorde << x->tempo << endl;
                    cout << endl << "Você bateu o recorde:" << endl;
                    cout << x->name << endl;
                    cout << x->tempo;
                }
                else {
                    cout << endl << "Recorde atual:" << endl;
                    cout << nomeatual << endl;
                    cout << aux << endl;
                    cout << endl << "Seu tempo foi:" << endl;
                    cout << x->tempo;
                }
        }
    };

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    string name;
    long long tempoPartida;
    cout << "Entre com seu nome:" << endl;
    cin >> name;
    Jogo y(name);
    y.novo_vetor();
    long long tempoInicio = time (0);
    y.jogo_inicializa();
    if (y.jogo_final()){
        long long tempoFim = time (0);
        tempoPartida = tempoFim - tempoInicio;
        y.x->tempo=tempoPartida;
        y.grava();
    }
}
