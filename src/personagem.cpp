#include "personagem.h"
#include <iostream>

Personagem::Personagem(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula){
    setTotalHP(totalHP);
    setHP(totalHP);
    setTotalMP(totalMP);
    setMP(totalMP);
    setTotalSP(totalSP);
    setSP(totalSP);
    setDano(dano);
    setDirecao(direcao);
    setCelula(celula);
    setAtordoado(0);
}

int Personagem::getHP(){
    return _HP;
}

void Personagem::setHP(int HP){
    _HP = HP;
}

int Personagem::getMP(){
    return _MP;
}

void Personagem::setMP(int MP){
    _MP = MP;
}

int Personagem::getSP(){
    return _SP;
}

void Personagem::setSP(int SP){
    _SP = SP;
}

int Personagem::getDano(){
    return _dano;
}

void Personagem::setDano(int dano){
    _dano = dano;
}

char Personagem::getDirecao(){
    return _direcao;
}

void Personagem::setDirecao(char direcao){
    _direcao = direcao;
}

Celula* Personagem::getCelula(){
    return _celula;
}

void Personagem::setCelula(Celula* celula){
    _celula = celula;
}

int Personagem::getAtordoado(){
    return _atordoado;
}

void Personagem::setAtordoado(int atordoado){
    _atordoado = atordoado;
}

bool Personagem::movimenta(Celula* destino){
    //Se a célula destino for a mesma que a célula origem, retorna false
    if (destino == _celula || destino->getElemento() != 'v')
        return false;

    int movimentosX, movimentosY;

    //Conta movimentos horizontais
    movimentosX = destino->getX() - _celula->getX();
    if (movimentosX < 0){
        movimentosX *= -1;
        _direcao = 'O';
    } else {
        _direcao = 'L';
    }

    //Conta movimentos verticais
    movimentosY = destino->getY() - _celula->getY();
    if (movimentosY < 0){
        movimentosY *= -1;
        _direcao = 'S';
    } else {
        _direcao = 'N';
    }

    //Verifica se o personagem possui MPs suficientes
    if (movimentosX + movimentosY <= _MP) {
        _MP -= movimentosX + movimentosY;
        destino->setElemento('j');
        return true; //Se o movimento é válido, retorna true
    } else {
        return false; //Se o movimento é inválido, retorna false
    }
}

void Personagem::terminaTurno(){
    _SP = _totalSP;
    _MP = _totalMP;
    
    if (_atordoado > 0)
        _atordoado--;
}