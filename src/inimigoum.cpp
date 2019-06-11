#include "inimigoum.h"

InimigoUm::InimigoUm(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula) : 
        Inimigo(totalHP, totalMP, totalSP, dano, direcao, celula) {}

bool InimigoUm::ataque(Celula* alvo){
    int distancia;
    char direcaoAntiga = _direcao;

    if (_SP < _CUSTO_ATAQUE_BASICO) //Se o inimigo não possui SPs o suficiente, retorna falso
        return false;

    if (alvo->getPersonagem() == nullptr) //Se não há ninguém a ser atacado, retorna falso
        return false;

    //Verifica se o personagem está ao alcance do inimigo
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