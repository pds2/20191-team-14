#ifndef GAME_LADRAO_H
#define GAME_LADRAO_H

#include "personagem.h"

class Ladrao : public Personagem {     
    public:
        Ladrao();

        void ataque() override;
};

#endif