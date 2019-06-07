#ifndef GAME_LADRAO_H
#define GAME_LADRAO_H

#include "personagem.h"

#define ALCANCE_LADRAO 1
#define CRITICO 2

class Ladrao : public Personagem {     
    public:
        Ladrao(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula);

        bool ataque(Celula* celula) override;
};

#endif