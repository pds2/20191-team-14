#include <stdlib>

public class Personagem {
    private:
        int HP; //Pontos de vida
        int MP; //Pontos de movimentação
        int SP; //Pontos de Habilidade
        int dano; // Quantidade base de dano
        char direcao; //Direcao para qual está olhando (Excenssial para habilidades do assassino)
        
    public:
        Personagem(int _HP, int _MP, int _SP, int _dano, char _direcao){
            setHP(_HP);
            setMP(_MP);
            setSP(_SP);
            setDano(_dano);
            setDirecao(_direcao);
        }

        int getHP(){
            return HP;
        }
        void setHP(int _HP){
            HP = _HP;
        }

        int getMP(){
            return MP;
        }
        void setMP(int _MP){
            MP = _MP;
        }

        int getSP(){
            return SP;
        }
        void setSP(int _SP){
            SP = _SP;
        }

        int getDano(){
            return dano;
        }
        void setDano(int _dano){
            dano = _dano;
        }

        char getDirecao(){
            return direcao;
        }
        void setDirecao(char _direcao){
            direcao = _direcao;
        }
}