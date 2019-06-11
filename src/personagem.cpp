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
    setVivo(true);
    setSalvo(false);
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

bool Personagem::getVivo(){
    return _vivo;
}

void Personagem::setVivo(bool vivo){
    _vivo = vivo;
}

bool Personagem::getSalvo(){
    return _salvo;
}

void Personagem::setSalvo(bool salvo){
    _salvo = salvo;
}

bool Personagem::movimenta(Celula* destino){
    char direcaoAntiga = _direcao;

    //Se a célula destino for a mesma que a célula origem ou não estiver vazia, retorna false
    if (destino == _celula || destino->getElemento() != 'v' && destino->getElemento() != 's')
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
        if (destino->getElemento() == 's')
            _salvo = true;
        return true; //Se o movimento é válido, retorna true
    } else {
        _direcao = direcaoAntiga;
        return false; //Se o movimento é inválido, retorna false
    }
}

void Personagem::terminaTurno(){
    _SP = _totalSP;
    _MP = _totalMP;
    
    if (_atordoado > 0)
        _atordoado--;
}

void Personagem::morte(){
    _vivo = false;
}