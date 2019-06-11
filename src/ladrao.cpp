#include "ladrao.h"

Ladrao::Ladrao(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula) : 
        Personagem(totalHP, totalMP, totalSP, dano, direcao, celula) {
            _danoCritico = _dano * _BONUS_CRITICO;
        }

int Ladrao::getDanoCritico(){
    return _danoCritico;
}

void Ladrao::setDanoCritico(int danoCritico){
    _danoCritico = danoCritico;
}

bool Ladrao::ataque(Celula* alvo){
    int distancia;
    char direcaoAntiga = _direcao;

    if (_SP < _CUSTO_ATAQUE_BASICO) //Se o personagem não possui SPs o suficiente, retorna falso
        return false;

    if (alvo->getPersonagem() == nullptr) //Se não há ninguém a ser atacado, retorna falso
        return false;
    
    //Verifica se o inimigo está ao alcance do ladrão
    if (alvo->getX() > _celula->getX()){
        distancia = alvo->getX() - _celula->getX();
        _direcao = 'L';
    } else {
        distancia = _celula->getX() - alvo->getX();
        if (alvo->getX() < _celula->getX())
            _direcao = 'O';
    }

    if (alvo->getY() > _celula->getY()){
        distancia += alvo->getY() - _celula->getY();
        _direcao = 'N';
    } else {
        distancia += _celula->getY() - alvo->getY();
        if (alvo->getY() < _celula->getY())
            _direcao = 'S';
    }

    if (distancia > 0 && distancia <= _ALCANCE_ADAGA){ //Conclui o ataque se ele for válido
        if (_direcao == alvo->getPersonagem()->getDirecao){
            alvo->getPersonagem()->setHP(alvo->getPersonagem()->getHP() - _danoCritico);
        } else {
            alvo->getPersonagem()->setHP(alvo->getPersonagem()->getHP() - _dano);
        }
        _SP -= _CUSTO_ATAQUE_BASICO;
        return true;
    } else { //Retorna false e reseta direção se for inválido
        _direcao = direcaoAntiga;
        return false;
    }
}

bool Ladrao::arco(Celula* alvo, Celula** mapa){
    int distancia;
    char direcaoAntiga = _direcao;

    if (_SP < _CUSTO_ATAQUE_ARCO) //Se o personagem não possui SPs o suficiente, retorna falso
        throw std::sem_SP("SP insulficiente para skill");
        return false;

    if (alvo->getPersonagem() == nullptr) //Se não há ninguém a ser atacado, retorna falso
        throw std::sem_inimigo("Nao existe inimigos nesta celula");
        return false;

    //Verifica se o inimigo está ao alcance do arco do ladrão e se há obstáculos entre eles
    if (alvo->getX() > _celula->getX()){
        distancia = alvo->getX() - _celula->getX();

        for (int i = alvo->getX() - 1; i > _celula->getX(); i--){
            if (mapa[i][alvo->getY()].getElemento() != 'v'){ //Se obstáculo for encontrado horizontalmente, retorna false
                throw std::obstaculo("Nao pode atacar, muito longe ou obstaculo no caminho");
                return false;
            }
        }

        _direcao = 'L';
    } else {
        distancia = _celula->getX() - alvo->getX();

        for (int i = alvo->getX() + 1; i < _celula->getX(); i++){
            if (mapa[i][alvo->getY()].getElemento() != 'v'){ //Se obstáculo for encontrado horizontalmente, retorna false
                throw std::obstaculo("Nao pode atacar, muito longe ou obstaculo no caminho");
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
                throw std::obstaculo("Nao pode atacar, muito longe ou obstaculo no caminho");
                return false;
            }
        }

        _direcao = 'N';
    } else {
        distancia += _celula->getY() - alvo->getY();

        for (int i = alvo->getY() + 1; i < _celula->getY(); i++){
            if (mapa[alvo->getX()][i].getElemento() != 'v'){ //Se obstáculo for encontrado verticalmente, retorna false
                throw std::obstaculo("Nao pode atacar, muito longe ou obstaculo no caminho");
                return false;
            }
        }

        if (alvo->getY() < _celula->getY())
            _direcao = 'S';
    }

    if (distancia > 0 && distancia <= _ALCANCE_ARCO){ //Conclui o ataque se ele for válido
        alvo->getPersonagem()->setHP(alvo->getPersonagem()->getHP() - _dano);
        _SP -= _CUSTO_ATAQUE_ARCO;
        return true;
    } else { //Retorna false e reseta direção se for inválido
        _direcao = direcaoAntiga;
        throw std::alcance("Voce nao tem alcance para esse ataque");
        return false;
    }
}