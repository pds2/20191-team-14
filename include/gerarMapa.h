#ifndef GAME_GERAR_MAPA_H
#define GAME_GERAR_MAPA_H

#include "celula.h"
#include "barbaro.h"
#include "guerreiro.h"
#include "ladrao.h"
#include "mago.h"
#include "inimigoum.h"
#include "inimigodois.h"
#include <iostream>

#define _LINHAS 10
#define _COLUNAS 10

#define _MAPA_ELEMENTO_VAZIO 'v'
#define _MAPA_ELEMENTO_BARBARO 'b'
#define _MAPA_ELEMENTO_GUERREIRO 'g'
#define _MAPA_ELEMENTO_LADRAO 'l'
#define _MAPA_ELEMENTO_MAGO 'm'
#define _MAPA_ELEMENTO_INIMIGO_UM '1'
#define _MAPA_ELEMENTO_INIMIGO_DOIS '2'
#define _MAPA_ELEMENTO_PEDRA 'p'
#define _MAPA_ELEMENTO_SAIDA 's'
#define _MAPA_ELEMENTO_INVULNERAVEL 'i'

//Função para criar o mapa e retornar ponteiro para tal
Celula** criaMapa();

//Função para desalocar memória do mapa
void deletaMapa(Celula** mapa);

//Função para desenhar exibição do mapa
void desenhaMapa(Celula** mapa);

//Fim de jogo
void gameOver();{
    cout << "Fim de jogo! Todos os personagens estão mortos..." << endl;
}

//Jogo terminado
void vitoria();