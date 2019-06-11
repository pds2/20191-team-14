#ifndef GAME_INIMIGO_H
#define GAME_INIMIGO_H

#include "personagem.h"

#define _ALCANCE_VISAO 2

class Inimigo : public Personagem {
    public:
        Inimigo(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula);

        /*scan lê uma área ao redor do inimigo
        Se encontrar um personagem, tenta andar o mais próximo possível em direção a ele e atacá-lo*/
        Celula* scan(Celula** mapa);
};

#endif