#ifndef GAME_INIMIGO_DOIS_H
#define GAME_INIMIGO_DOIS_H

#include "inimigo.h"

#define _ALCANCE 1
#define _CUSTO_ATAQUE_BASICO 4

class InimigoDois : public Inimigo {
    public:
        InimigoDois(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula);

        bool ataque(Celula* celula) override;
};

#endif