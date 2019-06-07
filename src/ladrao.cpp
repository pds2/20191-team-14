#include "ladrao.h"

#define _ALCANCE_ADAGA 1
#define _ALCANCE_ARCO 3

#define _CUSTO_ATAQUE_BASICO 2
#define _CUSTO_ATAQUE_ARCO 3

#define _BONUS_CRITICO 2

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

bool Ladrao::ataque(Celula* celula){
    bool ataqueValido = false;

    if (_SP < _CUSTO_ATAQUE_BASICO) //Se o personagem não possui SPs o suficiente, retorna falso
        return false;

    if (celula->getPersonagem() == nullptr) //Se não há ninguém a ser atacado, retorna falso
        return false;
    
    //Verifica se o inimigo está em uma célula diretamente adjacente à do guerreiro
    if (celula->getX() == _celula->getX() - _ALCANCE_ADAGA || 
            celula->getX() == _celula->getX() + _ALCANCE_ADAGA){
        if (celula->getY() == _celula->getY()){
            ataqueValido = true;
        } else {
            return false;
        }
    } else if (celula->getY() == _celula->getY() - _ALCANCE_ADAGA || 
            celula->getY() == _celula->getY() + _ALCANCE_ADAGA){
        if (celula->getX() == _celula->getX()){
            ataqueValido = true;
        } else {
            return false;
        }
    } else {
        return false;
    }

    //Se o ataque do ladrao é valido, ver se inimigo está de costas para dar critico
    if (ataqueValido){
        if ((celula->getX() == _celula->getX() && 
        ((celula->getY() == _celula->getY() - 1 && celula->getPersonagem()->getDirecao() == 'L') || 
        (celula->getY() == _celula->getY() + 1 && celula->getPersonagem()->getDirecao() == 'O'))) ||
        (celula->getY() == _celula->getY() && 
        ((celula->getX() == _celula->getX() - 1 && celula->getPersonagem()->getDirecao() == 'N') || 
        (celula->getX() == _celula->getX() + 1 && celula->getPersonagem()->getDirecao() == 'S')))){
            celula->getPersonagem()->setHP(celula->getPersonagem()->getHP() - (_danoCritico));
        }
        else{
            celula->getPersonagem()->setHP(celula->getPersonagem()->getHP() - _dano);
        }

        _SP -= _CUSTO_ATAQUE_BASICO;

        return true;
    }
}

bool Ladrao::arco(Celula* alvo, Celula** mapa){
    int distancia;

    if (_SP < _CUSTO_ATAQUE_ARCO) //Se o personagem não possui SPs o suficiente, retorna falso
        return false;

    if (alvo->getPersonagem() == nullptr) //Se não há ninguém a ser atacado, retorna falso
        return false;

    //Verifica se o inimigo está ao alcance do ladrão e se há obstáculos entre eles
    if (alvo->getX() > _celula->getX()){
        distancia = alvo->getX() - _celula->getX();

        for (int i = alvo->getX() - 1; i > _celula->getX(); i--){
            if (mapa[i][alvo->getY()].getElemento() != 'v'){ //Se obstáculo for encontrado horizontalmente, retorna false
                return false;
            }
        }
    } else {
        distancia = _celula->getX() - alvo->getX();

        for (int i = alvo->getX() + 1; i < _celula->getX(); i++){
            if (mapa[i][alvo->getY()].getElemento() != 'v'){ //Se obstáculo for encontrado horizontalmente, retorna false
                return false;
            }
        }
    }

    if (alvo->getY() > _celula->getY()){
        distancia += alvo->getY() - _celula->getY();

        for (int i = alvo->getY() - 1; i > _celula->getY(); i--){
            if (mapa[alvo->getX()][i].getElemento() != 'v'){ //Se obstáculo for encontrado verticalmente, retorna false
                return false;
            }
        }
    } else {
        distancia += _celula->getY() - alvo->getY();

        for (int i = alvo->getY() + 1; i < _celula->getY(); i++){
            if (mapa[alvo->getX()][i].getElemento() != 'v'){ //Se obstáculo for encontrado verticalmente, retorna false
                return false;
            }
        }
    }

    if (distancia > 0 && distancia <= _ALCANCE_ARCO){ //Conclui o ataque se ele for válido
        alvo->getPersonagem()->setHP(alvo->getPersonagem()->getHP() - _dano);
        _SP -= _CUSTO_ATAQUE_ARCO;
        return true;
    } else { //Retorna false se for inválido
        return false;
    }
}