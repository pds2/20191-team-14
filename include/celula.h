/*O mapa é uma matriz de celulas*/
/*A variável 'elemento' representa o que tem na célula:
    j - jogador
    m - monstro
    p - pedra
    i - invulneralvel (Shield do Guerreiro por exemplo)
*/
#ifndef GAME_CELULA_H
#define GAME_CELULA_H

#include "guerreiro.h"
#include "mago.h"
#include "ladrao.h"
#include "barbaro.h"

/*Quando houver um personagem na célula, ela recebe um ponteiro para esse personagem
O personagem será manipulado conforme as necessidades do jogo a partir deste ponteiro
Destruir o ponteiro quando o personagem andar para outra célula*/    

class Celula{
    private:
        char elemento;
        int linha,coluna;
        Guerreiro *guerreiro;
        Mago *mago;
        Ladrao *ladrao;
        Barbaro *barbaro;
    public:
        Celula(char _elemento, int _linha, int _coluna);
        Celula(char _elemento, int _linha, int _coluna, Guerreiro *_guerreiro);
        Celula(char _elemento, int _linha, int _coluna, Mago *_mago);
        Celula(char _elemento, int _linha, int _coluna, Ladrao *_ladrao);
        Celula(char _elemento, int _linha, int _coluna, Barbaro *_barbaro);

        void setElemento(char _elemento);
        char getElemento();

        void setLinha(int _linha);
        int getLinha();

        void setColuna(int _coluna);
        int getColuna();


        void setGuerreiro(Guerreiro *_guerreiro);
        Guerreiro getGuerreiro();

        void setMago(Mago *_mago);
        Mago getMago();

        void setLadrao(Ladrao *_ladrao);
        Ladrao getLadrao();

        void setBarbaro(Barbaro *_barbaro);
        Barbaro getBarbaro();

};

#endif