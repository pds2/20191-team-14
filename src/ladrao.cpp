#include "ladrao.h"

Ladrao::Ladrao(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula) : 
        Personagem(totalHP, totalMP, totalSP, dano, direcao, celula) {}

bool Ladrao::ataque(Celula* celula){
    bool ataqueValido = false;

    if (celula->getPersonagem() == nullptr) //Se não há ninguém a ser atacado, retorna falso
        return false;
    
    //Verifica se o inimigo está em uma célula diretamente adjacente à do guerreiro
    if (celula->getX() == _celula->getX() - ALCANCE_LADRAO || 
            celula->getX() == _celula->getX() + ALCANCE_LADRAO){
        if (celula->getY() == _celula->getY()){
            ataqueValido = true;
        } else {
            return false;
        }
    } else if (celula->getY() == _celula->getY() - ALCANCE_LADRAO || 
            celula->getY() == _celula->getY() + ALCANCE_LADRAO){
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
            celula->getPersonagem()->setHP(celula->getPersonagem()->getHP() - (_dano * CRITICO));
        }
        else{
            celula->getPersonagem()->setHP(celula->getPersonagem()->getHP() -_dano);
        }
        return true;
    }
}