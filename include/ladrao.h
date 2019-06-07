#ifndef GAME_LADRAO_H
#define GAME_LADRAO_H

#include "personagem.h"

class Ladrao : public Personagem {
    private:
        int _danoCritico;

    public:
        Ladrao(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula);

        int getDanoCritico();
        void setDanoCritico(int danoCritico);

        bool ataque(Celula* alvo) override;
        bool arco(Celula* alvo, Celula** mapa); //Habilidade de ataque à distância
};

#endif