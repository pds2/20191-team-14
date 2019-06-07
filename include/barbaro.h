#ifndef GAME_BARBARO_H
#define GAME_BARBARO_H

#include "personagem.h"

class Barbaro : public Personagem {
    private:
        int _danoExtra;

    public:
        Barbaro(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula);

        int getDanoExtra();
        void setDanoExtra(int danoExtra);

        bool ataque(Celula* alvo) override;
        bool berserk(); //Habilidade que aumenta o dano do próximo ataque do bárbaro;cumulativa dentro do turno

        void terminaTurno() override;
};

#endif