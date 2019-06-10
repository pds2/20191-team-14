#include "inimigo.h"

Inimigo::Inimigo(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula):
    Personagem(totalHP, totalMP, totalSP, dano, direcao, celula) {}

bool Inimigo::scan(Celula** mapa){
    bool personagemEncontrado = false;
    int i = _celula->getX() - _ALCANCE_VISAO;

    while (i <= _celula->getX() + _ALCANCE_VISAO && !personagemEncontrado){
        for (int j = _celula->getY() - _ALCANCE_VISAO; j <= _celula->getY() + _ALCANCE_VISAO; j++){
            if (mapa[i][j].getPersonagem() != nullptr){
                personagemEncontrado = true;
                this->movimenta();
            }
        }

        i++;
    }

    if (personagemEncontrado) //Se algum personagem foi encontrado e a movimentação realizada, retorna true
        return true;
    else //Se não, retorna false
        return false;
}