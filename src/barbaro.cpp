#include "barbaro.h"

Barbaro::Barbaro(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula) : 
        Personagem(totalHP, totalMP, totalSP, dano, direcao, celula) {}

bool Barbaro::ataque(Celula* celula){
    bool ataqueValido = false;

    if (celula->getPersonagem() == nullptr) //Se não há ninguém a ser atacado, retorna falso
        return false;

    //Verifica se o inimigo está em uma célula diretamente adjacente à do bárbaro
    if (celula->getX() == _celula->getX() - 1 || celula->getX() == _celula->getX() + 1){
        if (celula->getY() == _celula->getY()){
            ataqueValido = true;
        } else {
            return false;
        }
    } else if (celula->getY() == _celula->getY() - 1 || celula->getY() == _celula->getY() + 1){
        if (celula->getX() == _celula->getX()){
            ataqueValido = true;
        } else {
            return false;
        }
    } else {
        return false;
    }

    if (ataqueValido){
        celula->getPersonagem()->setHP(celula->getPersonagem()->getHP() - _dano);
        return true;
    }
}