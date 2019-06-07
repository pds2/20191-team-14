#ifndef GAME_MAGO_H
#define GAME_MAGO_H

#include "personagem.h"

class Mago : public Personagem {     
    public:
        Mago(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula);

        bool ataque(Celula* celula) override;
};

#endif