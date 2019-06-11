#ifndef GAME_PERSONAGEM_H
#define GAME_PERSONAGEM_H

#include "celula.h"

class Personagem {
    protected:
    /*Variáveis que representam atributos dos personagens*/
        int _totalHP; //Pontos de vida totais
        int _HP; //Pontos de vida atuais
        int _totalMP; // Pontos de movimentação totais
        int _MP; //Pontos de movimentação atuais
        int _totalSP; //Pontos de habilidade totais
        int _SP; //Pontos de habilidade atuais
        int _dano; // Quantidade base de dano
        char _direcao; //Direcao para qual está olhando (Essencial para habilidades do assassino) 
        //(N - norte, S - sul, L - leste, O - oeste)
        Celula* _celula; // Célula atual do personagem
        int _atordoado; //Quantidade de turnos em que o personagem não poderá agir se for atordoado
        bool _vivo; //Determina se o personagem está vivo
        bool _salvo; //Determina se o personagem conseguiu fugir

    public:
        //Construtor
        Personagem(int totalHP, int totalMP, int totalSP, int dano, char direcao, Celula* celula);

        //Getters e setters dos atributos
        int getTotalHP();
        void setTotalHP(int totalHP);

        int getHP();
        void setHP(int HP);

        int getTotalMP();
        void setTotalMP(int totalMP);

        int getMP();
        void setMP(int MP);

        int getTotalSP();
        void setTotalSP(int totalSP);

        int getSP();
        void setSP(int SP);

        int getDano();
        void setDano(int dano);

        char getDirecao();
        void setDirecao(char direcao);
        
        Celula* getCelula();
        void setCelula(Celula* celula);

        int getAtordoado();
        void setAtordoado(int atordoado);

        bool getVivo();
        void setVivo(bool vivo);

        bool getSalvo();
        void setSalvo(bool salvo);

        bool movimenta(Celula* destino); //Mover personagem no mapa a partir dos MPs

        virtual bool ataque(Celula* alvo); //Todo personagem ataca, cada um de seu jeito(aplica polimorfismo)
        virtual bool ataque(Celula* alvo, Celula** mapa); //Personagens com ataque à distância precisam de um
                                                            //ponteiro para o mapa para verificar obstáculos

        virtual void terminaTurno(); //Recupera SPs e MPs do personagem;pode ser sobrescrita pra permitir
                                    //alterações em outros atributos

        void morte(); //Função para determinar o personagem como morto.
};

#endif