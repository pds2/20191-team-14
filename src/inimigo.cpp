#include "inimigo.h"
#include "celula.h"

Inimigo::Inimigo(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula):
    Personagem(totalHP, totalMP, totalSP, dano, direcao, celula) {}

Celula* Inimigo::scan(Celula** mapa){
    bool personagemEncontrado = false;
    int i = _celula->getX() - _ALCANCE_VISAO, j, personagemX, personagemY;

    while (i <= _celula->getX() + _ALCANCE_VISAO && !personagemEncontrado){
        for (j = _celula->getY() - _ALCANCE_VISAO; j <= _celula->getY() + _ALCANCE_VISAO; j++){
            if (mapa[i][j].getPersonagem() != nullptr && mapa[i][j].getElemento() != '1' && mapa[i][j].getElemento() != '2'){
                personagemEncontrado = true;
                personagemX = i;
                personagemY = j;
                
                _celula->setElemento('v');

                if (i > _celula->getX()){
                    i -= 1;
                } else {
                    i += 1;
                }

                while (!this->movimenta(&mapa[i][j])){ //Tenta mover até encontrar a célula 
                                                      //mais próxima possível que o inimigo alcança
                    if (j > _celula->getY()){
                        j -= 1;
                    } else {
                        j += 1;
                    }
                }

                break;
            }
        }

        i++;
    }

    if (personagemEncontrado) 
        return &mapa[personagemX][personagemY]; //Se algum personagem foi encontrado e a movimentação realizada, retorna a célula do alvo
    else
        return &mapa[i][j]; //Se não se moveu, retorna a célula atual
}