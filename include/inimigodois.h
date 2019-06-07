#ifndef GAME_INIMIGO_DOIS_H
#define GAME_INIMIGO_DOIS_H

#include "personagem.h"

class InimigoDois : public Personagem {
    public:
        InimigoDois(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula);

        bool ataque(Celula* celula) override;
};

#endif