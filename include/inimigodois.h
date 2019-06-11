#ifndef GAME_INIMIGO_DOIS_H
#define GAME_INIMIGO_DOIS_H

#include "inimigo.h"

#define _ALCANCE 3
#define _CUSTO_ATAQUE_BASICO 4

class InimigoDois : public Personagem {
    public:
        InimigoDois(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula);

        bool ataque(Celula* celula) override;
};

#endif