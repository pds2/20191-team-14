#ifndef GAME_PEDRA_H
#define GAME_PEDRA_H

#include "personagem.h"

class Pedra : public Personagem {     
    public:
        Pedra(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula);
};

#endif