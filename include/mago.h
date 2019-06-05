#ifndef GAME_MAGO_H
#define GAME_MAGO_H

#include "personagem.h"

class Mago : public Personagem {     
    public:
        Mago();

        void ataque() override;
};

#endif