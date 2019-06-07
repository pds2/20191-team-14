#include "mago.h"

#define _ALCANCE 3
#define _CUSTO_ATAQUE_BASICO 3

Mago::Mago(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula) : 
        Personagem(totalHP, totalMP, totalSP, dano, direcao, celula) {}

bool Mago::ataque(Celula* celula, Celula** mapa){
    int distancia;

    if (_SP < _CUSTO_ATAQUE_BASICO) //Se o personagem não possui SPs o suficiente, retorna falso
        return false;

    if (celula->getPersonagem() == nullptr) //Se não há ninguém a ser atacado, retorna falso
        return false;

    //Verifica se o inimigo está ao alcance do mago e se há obstáculos entre eles
    if (celula->getX() > _celula->getX()){
        distancia = celula->getX() - _celula->getX();

        for (int i = celula->getX() - 1; i > _celula->getX(); i--){
            if (mapa[i][celula->getY()].getElemento() != 'v'){ //Se obstáculo for encontrado horizontalmente, retorna false
                return false;
            }
        }
    } else {
        distancia = _celula->getX() - celula->getX();

        for (int i = celula->getX() + 1; i < _celula->getX(); i++){
            if (mapa[i][celula->getY()].getElemento() != 'v'){ //Se obstáculo for encontrado horizontalmente, retorna false
                return false;
            }
        }
    }

    if (celula->getY() > _celula->getY()){
        distancia += celula->getY() - _celula->getY();

        for (int i = celula->getY() - 1; i > _celula->getY(); i--){
            if (mapa[celula->getX()][i].getElemento() != 'v'){ //Se obstáculo for encontrado verticalmente, retorna false
                return false;
            }
        }
    } else {
        distancia += _celula->getY() - celula->getY();

        for (int i = celula->getY() + 1; i < _celula->getY(); i++){
            if (mapa[celula->getX()][i].getElemento() != 'v'){ //Se obstáculo for encontrado verticalmente, retorna false
                return false;
            }
        }
    }

    if (distancia > 0 && distancia <= _ALCANCE){ //Conclui o ataque se ele for válido
        celula->getPersonagem()->setHP(celula->getPersonagem()->getHP() - _dano);
        _SP -= _CUSTO_ATAQUE_BASICO;
        return true;
    } else { //Retorna false se for inválido
        return false;
    }
}