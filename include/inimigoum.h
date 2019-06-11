#ifndef GAME_INIMIGO_UM_H
#define GAME_INIMIGO_UM_H

#include "inimigo.h"

#define _ALCANCE 1
#define _CUSTO_ATAQUE_BASICO 3

class InimigoUm : public Inimigo {
    public:
        InimigoUm(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula);

        bool ataque(Celula* alvo) override;
};

#endif