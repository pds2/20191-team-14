#ifndef GAME_GUERREIRO_H
#define GAME_GUERREIRO_H

#include "personagem.h"

#define _ALCANCE 1
#define _CUSTO_ATAQUE_BASICO 3
#define _CUSTO_ESCUDO 2
#define _BONUS_ESCUDO 15

class Guerreiro : public Personagem {
    private:
        int _escudo;

    public:
        Guerreiro(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula);

        int getEscudo();

        void setHP(int HP);
        
        bool ataque(Celula* alvo) override;
        bool escudo();
};

#endif