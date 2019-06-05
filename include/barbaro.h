#ifndef GAME_BARBARO_H
#define GAME_BARBARO_H

#include "personagem.h"

class Barbaro : public Personagem {     
    public:
        Barbaro(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula);

        bool ataque(Celula* celula) override;
};

#endif