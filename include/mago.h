#ifndef GAME_MAGO_H
#define GAME_MAGO_H

#include "personagem.h"

#define _ALCANCE_BASICO 3
#define _ALCANCE_STUN 2

#define _CUSTO_ATAQUE_BASICO 3
#define _CUSTO_STUN 3

#define _TURNOS_STUN 1

class Mago : public Personagem {     
    public:
        Mago(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula);
        
        bool ataque(Celula* alvo, Celula** mapa) override;
        bool stun(Celula* alvo, Celula** mapa); //Habilidade de atordoamento
};

#endif