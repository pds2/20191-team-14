/*ACEITO SUJETÕES PARA NOVOS MÉTODOS, PRINCIPALMENTE PRA APLICAR POLIMORFISMO*/

#ifndef GAME_PERSONAGEM_H
#define GAME_PERSONAGEM_H

class Personagem{
    private:
    /*Variáveis que representam atributos dos personagens*/
        int HP; //Pontos de vida
        int MP; //Pontos de movimentação
        int SP; //Pontos de Habilidade
        int dano; // Quantidade base de dano
        char direcao; //Direcao para qual está olhando (Excenssial para habilidades do assassino)

    public:
        //Construtor
        Personagem(int _HP, int _MP, int _SP, int _dano, char _direcao);

        //gets e sets dos atributos
        int getHP();
        void setHP(int _HP);

        int getMP();
        void setMP(int _MP);

        int getSP();
        void setSP(int _SP);

        int getDano();
        void setDano(int _dano);

        char getDirecao();
        void setDirecao(char _direcao);

        void movimenta(int linha,int coluna, int linDestino, int colDestino);//Mover personagem no mapa a partir dos MPs

        virtual void ataque()=0;//Todo personagem ataca,cada um de seu jeito(aplica polimorfismo)
};

#endif