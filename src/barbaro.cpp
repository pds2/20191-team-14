#include "barbaro.h"


Barbaro::Barbaro(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula) : 
        Personagem(totalHP, totalMP, totalSP, dano, direcao, celula) {
            _danoExtra = 0;
        }

int Barbaro::getDanoExtra(){
    return _danoExtra;
}

void Barbaro::setDanoExtra(int danoExtra){
    _danoExtra = danoExtra;
}

bool Barbaro::ataque(Celula* alvo){
    int distancia;

    if (_SP < _CUSTO_ATAQUE_BASICO) //Se o personagem não possui SPs o suficiente, retorna falso
        return false;

    if (alvo->getPersonagem() == nullptr) //Se não há ninguém a ser atacado, retorna falso
        return false;

    //Verifica se o inimigo está ao alcance do bárbaro
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
        alvo->getPersonagem()->setHP(alvo->getPersonagem()->getHP() - (_dano + _danoExtra));
        _danoExtra = 0;
        _SP -= _CUSTO_ATAQUE_BASICO;
        return true;
    } else { //Retorna false se for inválido
        return false;
    }
}

bool Barbaro::berserk(){
    if (_SP < _CUSTO_BERSERK) //Se o bárbaro não possui SPs o suficiente, retorna falso
        return false;

    _SP -= _CUSTO_BERSERK;
    _danoExtra += _dano + (_dano / 2);
    return true;
}

void Barbaro::terminaTurno(){
    _SP = _totalSP;
    _MP = _totalMP;

    if (_danoExtra > 0)
        _danoExtra = 0;
}