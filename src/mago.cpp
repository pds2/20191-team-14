#include "mago.h"


Mago::Mago(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula) : 
        Personagem(totalHP, totalMP, totalSP, dano, direcao, celula) {}

bool Mago::ataque(Celula* alvo, Celula** mapa){
    int distancia;
    char direcaoAntiga = _direcao;

    if (_SP < _CUSTO_ATAQUE_BASICO) //Se o personagem não possui SPs o suficiente, retorna falso
        return false;

    if (alvo->getPersonagem() == nullptr) //Se não há ninguém a ser atacado, retorna falso
        return false;

    //Verifica se o inimigo está ao alcance do mago e se há obstáculos entre eles
    if (alvo->getX() > _celula->getX()){
        distancia = alvo->getX() - _celula->getX();

        for (int i = alvo->getX() - 1; i > _celula->getX(); i--){
            if (mapa[i][alvo->getY()].getElemento() != 'v'){ //Se obstáculo for encontrado horizontalmente, retorna false
                return false;
            }
        }

        _direcao = 'L';
    } else {
        distancia = _celula->getX() - alvo->getX();

        for (int i = alvo->getX() + 1; i < _celula->getX(); i++){
            if (mapa[i][alvo->getY()].getElemento() != 'v'){ //Se obstáculo for encontrado horizontalmente, retorna false
                return false;
            }
        }

        if (alvo->getX() < _celula->getX())
            _direcao = 'O';
    }

    if (alvo->getY() > _celula->getY()){
        distancia += alvo->getY() - _celula->getY();

        for (int i = alvo->getY() - 1; i > _celula->getY(); i--){
            if (mapa[alvo->getX()][i].getElemento() != 'v'){ //Se obstáculo for encontrado verticalmente, retorna false
                return false;
            }
        }

        _direcao = 'N';
    } else {
        distancia += _celula->getY() - alvo->getY();

        for (int i = alvo->getY() + 1; i < _celula->getY(); i++){
            if (mapa[alvo->getX()][i].getElemento() != 'v'){ //Se obstáculo for encontrado verticalmente, retorna false
                return false;
            }
        }

        if (alvo->getY() < _celula->getY())
            _direcao = 'S';
    }

    if (distancia > 0 && distancia <= _ALCANCE_BASICO){ //Conclui o ataque se ele for válido
        alvo->getPersonagem()->setHP(alvo->getPersonagem()->getHP() - _dano);
        _SP -= _CUSTO_ATAQUE_BASICO;
        return true;
    } else { //Retorna false e reseta direção se for inválido
        _direcao = direcaoAntiga;
        return false;
    }
}

bool Mago::stun(Celula* alvo, Celula** mapa){
    int distancia;
    char direcaoAntiga = _direcao;

    if (_SP < _CUSTO_STUN) //Se o personagem não possui SPs o suficiente, retorna falso
        return false;

    if (alvo->getPersonagem() == nullptr) //Se não há ninguém a ser atacado, retorna falso
        return false;

    //Verifica se o inimigo está ao alcance do mago e se há obstáculos entre eles
    if (alvo->getX() > _celula->getX()){
        distancia = alvo->getX() - _celula->getX();

        for (int i = alvo->getX() - 1; i > _celula->getX(); i--){
            if (mapa[i][alvo->getY()].getElemento() != 'v'){ //Se obstáculo for encontrado horizontalmente, retorna false
                return false;
            }
        }

        _direcao = 'L';
    } else {
        distancia = _celula->getX() - alvo->getX();

        for (int i = alvo->getX() + 1; i < _celula->getX(); i++){
            if (mapa[i][alvo->getY()].getElemento() != 'v'){ //Se obstáculo for encontrado horizontalmente, retorna false
                return false;
            }
        }

        if (alvo->getX() < _celula->getX())
            _direcao = 'O';
    }

    if (alvo->getY() > _celula->getY()){
        distancia += alvo->getY() - _celula->getY();

        for (int i = alvo->getY() - 1; i > _celula->getY(); i--){
            if (mapa[alvo->getX()][i].getElemento() != 'v'){ //Se obstáculo for encontrado verticalmente, retorna false
                return false;
            }
        }

        _direcao = 'N';
    } else {
        distancia += _celula->getY() - alvo->getY();

        for (int i = alvo->getY() + 1; i < _celula->getY(); i++){
            if (mapa[alvo->getX()][i].getElemento() != 'v'){ //Se obstáculo for encontrado verticalmente, retorna false
                return false;
            }
        }

        if (alvo->getY() < _celula->getY())
            _direcao = 'S';
    }

    if (distancia > 0 && distancia <= _ALCANCE_STUN){ //Conclui o ataque se ele for válido
        alvo->getPersonagem()->setAtordoado(alvo->getPersonagem()->getAtordoado() + _TURNOS_STUN);
        _SP -= _CUSTO_STUN;
        return true;
    } else { //Retorna false e reseta direção se for inválido
        _direcao = direcaoAntiga;
        return false;
    }
}