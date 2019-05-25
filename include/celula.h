/*O mapa é uma matriz de celulas*/
/*A variável 'elemento' representa o que tem na célula:
    j - jogador
    m - monstro
    p - pedra
    i - invulneralvel (Shield do Guerreiro por exemplo)
*/
#ifndef GAME_CELULA_H
#define GAME_CELULA_H

class Celula{
    private:
        char elemento;
    public:
        Celula(char _elemento);
        void setElemento(char _elemento);
        char getElemento();
};

#endif