#include "guerreiro.h"

Guerreiro::Guerreiro(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula) : 
        Personagem(totalHP, totalMP, totalSP, dano, direcao, celula) {
            _escudo = 0;
        }

void Guerreiro::setHP(int HP){
    if(_escudo > 0){
        if(HP >= _escudo)
            _HP -= (HP-_escudo);
        else
            _escudo -= HP;
    }
    else
        _HP -= HP;
}

bool Guerreiro::ataque(Celula* alvo){
    int distancia;
    char direcaoAntiga = _direcao;

    if (_SP < _CUSTO_ATAQUE_BASICO) //Se o personagem não possui SPs o suficiente, retorna falso
        return false;

    if (alvo->getPersonagem() == nullptr) //Se não há ninguém a ser atacado, retorna falso
        return false;

    //Verifica se o inimigo está ao alcance do guerreiro
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

    if (distancia > 0 && distancia <= _ALCANCE){ //Conclui o ataque se ele for válido
        alvo->getPersonagem()->setHP(alvo->getPersonagem()->getHP() - _dano);
        _SP -= _CUSTO_ATAQUE_BASICO;
        return true;
    } else { //Retorna false e reseta direção se for inválido
        _direcao = direcaoAntiga;
        return false;
    }
}

bool Guerreiro::escudo(){
    if(_SP < _CUSTO_ESCUDO) //Se não tiver SP o bastante
        throw std::sem_SP("SP insulficiente para skill");
        return false;

    if(_escudo > 0) //Se escudo já tiver sido usado, não acumular
        throw std::escudoAtivo("Escudo ja esta ativo, nao pode repeti-lo");
        return false;

    _SP -= _CUSTO_ESCUDO;
    _escudo += _BONUS_ESCUDO;
    return true;
}