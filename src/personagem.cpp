#include "personagem.h"
#include <iostream>


Personagem::Personagem(int _HP, int _MP, int _SP, int _dano, char _direcao){
    setHP(_HP);
    setMP(_MP);
    setSP(_SP);
    setDano(_dano);
    setDirecao(_direcao);
}


int Personagem::getHP(){
    return HP;
}

void Personagem::setHP(int _HP){
    HP = _HP;
}


int Personagem::getMP(){
    return MP;
}

void Personagem::setMP(int _MP){
    MP = _MP;
}


int Personagem::getSP(){
    return SP;
}

void Personagem::setSP(int _SP){
    SP = _SP;
}


int Personagem::getDano(){
    return dano;
}

void Personagem::setDano(int _dano){
    dano = _dano;
}


char Personagem::getDirecao(){
    return direcao;
}

void Personagem::setDirecao(char _direcao){
    direcao = _direcao;
}