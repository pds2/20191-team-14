#include "pedra.h"
#include "celula.h"

Pedra::Pedra(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula) : 
        Personagem(totalHP, totalMP, totalSP, dano, direcao, celula) {}