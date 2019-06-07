#include "mago.h"

#define _ALCANCE 3

Mago::Mago(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula) : 
        Personagem(totalHP, totalMP, totalSP, dano, direcao, celula) {}

bool Mago::ataque(Celula* celula){
    int distancia = 0;

    if (celula->getPersonagem() == nullptr) //Se não há ninguém a ser atacado, retorna falso
        return false;

    //Verifica se o inimigo está ao alcance do mago
    if (celula->getX() > _celula->getX()){
        distancia += celula->getX() - _celula->getX();
    } else {
        distancia += _celula->getX() - celula->getX();
    }

    if (celula->getY() > _celula->getY()){
        distancia += celula->getY() - _celula->getY();
    } else {
        distancia += _celula->getY() - celula->getY();
    }

    if (distancia > 0 && distancia <= _ALCANCE){ //Conclui o ataque se ele for válido
        celula->getPersonagem()->setHP(celula->getPersonagem()->getHP() - _dano);
        return true;
    } else { //Retorna false se for inválido
        return false;
    }
}