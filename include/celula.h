/*O mapa é uma matriz de celulas*/
/*A variável 'elemento' representa o que tem na célula:
    b - bárbaro
    g - guerreiro
    l - ladrão
    m - mago
    1 - inimigo 1
    2 - inimigo 2
    p - pedra
    s - saída
    i - invulnerável (Parede, por exemplo)
    v - vazio
    n - null (Ainda não definido)
*/
#ifndef GAME_CELULA_H
#define GAME_CELULA_H

#include "personagem.h"

/*Quando houver um personagem na célula, ela recebe um ponteiro para esse personagem
O personagem será manipulado conforme as necessidades do jogo a partir deste ponteiro
Destruir o ponteiro quando o personagem andar para outra célula*/    

class Celula {
    private:
        char _elemento;
        int _x, _y;
        Personagem* _personagem;

    public:
        Celula();
        Celula(int x, int y);
        Celula(char elemento, int x, int y);

        //Getters e setters dos atributos
        char getElemento();
        void setElemento(char elemento);

        int getX();
        void setX(int x);

        int getY();
        void setY(int y);

        Personagem* getPersonagem();
        void setPersonagem(Personagem* personagem);

        void desalocaPersonagem(); //Função para desalocar ponteiro para personagem após ele deixar a célula
};

#endif