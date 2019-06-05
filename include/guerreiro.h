#ifndef GAME_GUERREIRO_H
#define GAME_GUERREIRO_H

#include "personagem.h"

class Guerreiro : public Personagem {
    public:
        Guerreiro(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula);

        bool ataque(Celula* celula) override;
};

#endif