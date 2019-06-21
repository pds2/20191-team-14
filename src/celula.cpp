#include "celula.h"
#include "personagem.h"

Celula::Celula(){
    _elemento = 'n';
    _x = _y = -1;
    _personagem = nullptr;
}

Celula::Celula(int x, int y){
    _elemento = 'n';
    _x = x;
    _y = y;
    _personagem = nullptr;
}

Celula::Celula(char elemento, int x, int y){
    _elemento = elemento;
    _x = x;
    _y = y;
    _personagem = nullptr;
}

char Celula::getElemento(){
    return _elemento;
}

void Celula::setElemento(char elemento){
    _elemento = elemento;
}

int Celula::getX(){
    return _x;
}

void Celula::setX(int x){
    _x = x;
}

int Celula::getY(){
    return _y;
}

void Celula::setY(int y){
    _y = y;
}

Personagem* Celula::getPersonagem(){
    return _personagem;
}

void Celula::setPersonagem(Personagem* personagem){
    _personagem = personagem;
}

void Celula::desalocaPersonagem(){
    if (_personagem != nullptr){
        _personagem = nullptr;
    }
}