#ifndef GAME_INIMIGO_UM_H
#define GAME_INIMIGO_UM_H

#include "personagem.h"

class InimigoUm : public Personagem {
    public:
        InimigoUm(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula);

        bool ataque(Celula* celula) override;
};

#endif