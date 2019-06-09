#ifndef GAME_INIMIGO_H
#define GAME_INIMIGO_H

#include "personagem.h"

class Inimigo : public Personagem {
    public:
        Inimigo(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula);

        /*scanMapa recebe uma célula inicial de referencial na ponta do mapa onde os inimigos começam
        ele então varre todo mapa procurando por um inimigo e compara sua posição com a do inimigo para
        saber se é o mais próximo*/
        void scanMapa(Celula* inicio);
        bool ataque(Celula* celula) override;
};

#endif