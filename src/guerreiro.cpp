#include "guerreiro.h"


Guerreiro::Guerreiro(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula) : 
        Personagem(totalHP, totalMP, totalSP, dano, direcao, celula) {}

bool Guerreiro::ataque(Celula* alvo){
    int distancia;

    if (_SP < _CUSTO_ATAQUE_BASICO) //Se o personagem não possui SPs o suficiente, retorna falso
        return false;

    if (alvo->getPersonagem() == nullptr) //Se não há ninguém a ser atacado, retorna falso
        return false;

    //Verifica se o inimigo está ao alcance do guerreiro
    if (alvo->getX() > _celula->getX()){
        distancia = alvo->getX() - _celula->getX();
    } else {
        distancia = _celula->getX() - alvo->getX();
    }

    if (alvo->getY() > _celula->getY()){
        distancia += alvo->getY() - _celula->getY();
    } else {
        distancia += _celula->getY() - alvo->getY();
    }

    if (distancia > 0 && distancia <= _ALCANCE){ //Conclui o ataque se ele for válido
        alvo->getPersonagem()->setHP(alvo->getPersonagem()->getHP() - _dano);
        _SP -= _CUSTO_ATAQUE_BASICO;
        return true;
    } else { //Retorna false se for inválido
        return false;
    }
}