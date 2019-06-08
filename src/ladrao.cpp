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
    bool ataqueValido = false;

    if (_SP < _CUSTO_ATAQUE_BASICO) //Se o personagem não possui SPs o suficiente, retorna falso
        return false;

    if (alvo->getPersonagem() == nullptr) //Se não há ninguém a ser atacado, retorna falso
        return false;
    
    //Verifica se o inimigo está em uma célula diretamente adjacente à do guerreiro
    if (alvo->getX() == _celula->getX() - _ALCANCE_ADAGA || 
           alvo->getX() == _celula->getX() + _ALCANCE_ADAGA){
        if (alvo->getY() == _celula->getY()){
            ataqueValido = true;
        } else {
            return false;
        }
    } else if (alvo->getY() == _celula->getY() - _ALCANCE_ADAGA || 
           alvo->getY() == _celula->getY() + _ALCANCE_ADAGA){
        if (alvo->getX() == _celula->getX()){
            ataqueValido = true;
        } else {
            return false;
        }
    } else {
        return false;
    }

    //Se o ataque do ladrao é valido, ver se inimigo está de costas para dar critico
    if (ataqueValido){
        if ((alvo->getX() == _celula->getX() && 
        ((alvo->getY() == _celula->getY() - 1 && alvo->getPersonagem()->getDirecao() == 'L') || 
        (alvo->getY() == _celula->getY() + 1 && alvo->getPersonagem()->getDirecao() == 'O'))) ||
        (alvo->getY() == _celula->getY() && 
        ((alvo->getX() == _celula->getX() - 1 && alvo->getPersonagem()->getDirecao() == 'N') || 
        (alvo->getX() == _celula->getX() + 1 && alvo->getPersonagem()->getDirecao() == 'S')))){
           alvo->getPersonagem()->setHP(alvo->getPersonagem()->getHP() - (_danoCritico));
        }
        else{
           alvo->getPersonagem()->setHP(alvo->getPersonagem()->getHP() - _dano);
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