#ifndef GAME_GUERREIRO_H
#define GAME_GUERREIRO_H

#include "personagem.h"

class Guerreiro : public Personagem {
    private:
        int _escudo;

    public:
        Guerreiro(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula);

        bool ataque(Celula* alvo) override;
        bool defesa();
};

#endif