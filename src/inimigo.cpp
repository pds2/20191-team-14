#include "inimigo.h"

Inimigo::Inimigo(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula):
    Personagem(totalHP, totalMP, totalSP, dano, direcao, celula) {}

void Inimigo::scanMapa(Celula* inicio){
    for(int i = inicio->getY(); i>=0; i--){
        for(int j = 0; j < 10; j++){
            
        }
    }
}