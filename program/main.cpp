#include <iostream>
#include "celula.h"

#define _LINHAS 10
#define _COLUNAS 10

//Função para criar o mapa e retornar ponteiro para tal
Celula** criaMapa(){
    Celula** mapa = new Celula*[_LINHAS];

    for (int i = 0; i < _LINHAS; i++){
        mapa[i] = new Celula[_COLUNAS];
    }

    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            mapa[i][j] = Celula(i, j); //TODO: usar construtor com elemento para desenhar o mapa
        }
    }

    return mapa;
}

//Função para desalocar memória do mapa
void deletaMapa(Celula** mapa){
    for (int i = 0; i < _LINHAS; i++)
        delete [] mapa[i];

    delete [] mapa;
}

int main(){
    Celula** mapa = criaMapa();

    //Loop principal do jogo
    while (1){
        break;
    }

    deletaMapa(mapa);

    return 0;
}
