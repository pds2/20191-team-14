#include <iostream>
#include "celula.h"
#include "barbaro.h"
#include "guerreiro.h"
#include "ladrao.h"
#include "mago.h"

#define _LINHAS 10
#define _COLUNAS 10

#define _SP 6
#define _MP 3
#define _DIRECAO_PADRAO 'N'

#define _BARBARO_HP 120
#define _BARBARO_DANO 30

#define _GUERREIRO_HP 145
#define _GUERREIRO_DANO 15

#define _LADRAO_HP 100
#define _LADRAO_DANO 18

#define _MAGO_HP 80
#define _MAGO_DANO 20


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

//Cria personagem do bárbaro
Barbaro* criaBarbaro(Celula celula){
    Celula* celulaPtr = &celula;
    Barbaro* barbaro = new Barbaro(_BARBARO_HP, _MP, _SP, _BARBARO_DANO, _DIRECAO_PADRAO, celulaPtr);

    celulaPtr = nullptr;

    return barbaro;
}

//Desaloca personagem do bárbaro
void deletaBarbaro(Barbaro* barbaro){
    delete barbaro;
}

//Cria personagem do guerreiro
Guerreiro* criaGuerreiro(Celula celula){
    Celula* celulaPtr = &celula;
    Guerreiro* guerreiro = new Guerreiro(_GUERREIRO_HP, _MP, _SP, _GUERREIRO_DANO, _DIRECAO_PADRAO, celulaPtr);

    celulaPtr = nullptr;

    return guerreiro;
}

//Desaloca personagem do guerreiro
void deletaGuerreiro(Guerreiro* guerreiro){
    delete guerreiro;
}

//Cria personagem do ladrão
Ladrao* criaLadrao(Celula celula){
    Celula* celulaPtr = &celula;
    Ladrao* ladrao = new Ladrao(_LADRAO_HP, _MP, _SP, _LADRAO_DANO, _DIRECAO_PADRAO, celulaPtr);

    celulaPtr = nullptr;

    return ladrao;
}

//Desaloca personagem do ladrão
void deletaLadrao(Ladrao* ladrao){
    delete ladrao;
}

//Cria personagem do mago
Mago* criaMago(Celula celula){
    Celula* celulaPtr = &celula;
    Mago* mago = new Mago(_MAGO_HP, _MP, _SP, _MAGO_DANO, _DIRECAO_PADRAO, celulaPtr);

    celulaPtr = nullptr;

    return mago;
}

//Desaloca personagem do mago
void deletaMago(Mago* mago){
    delete mago;
}

int main(){
    Celula** mapa = criaMapa();

    Barbaro* barbaro = criaBarbaro(mapa[6][1]);
    Guerreiro* guerreiro = criaGuerreiro(mapa[7][1]);
    Ladrao* ladrao = criaLadrao(mapa[8][1]);
    Mago* mago = criaMago(mapa[9][1]);

    //Loop principal do jogo
    while (1){
        

        break;
    }

    //Desaloca tudo
    deletaMapa(mapa);
    deletaBarbaro(barbaro);
    deletaGuerreiro(guerreiro);
    deletaLadrao(ladrao);
    deletaMago(mago);

    return 0;
}
