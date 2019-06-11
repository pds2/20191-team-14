#include <iostream>
#include "celula.h"
#include "barbaro.h"
#include "guerreiro.h"
#include "ladrao.h"
#include "mago.h"

using namespace std;

#define _LINHAS 10
#define _COLUNAS 10

#define _SP 6
#define _MP 3
#define _DIRECAO_PADRAO 'N'

#define _BARBARO_HP 120
#define _BARBARO_DANO 30

#define _GUERREIRO_HP 145
#define _GUERREIRO_DANO 15

#define _LADRAO_HP 100
#define _LADRAO_DANO 18

#define _MAGO_HP 80
#define _MAGO_DANO 20

#define _MAPA_ELEMENTO_VAZIO 'v'
#define _MAPA_ELEMENTO_BARBARO 'b'
#define _MAPA_ELEMENTO_GUERREIRO 'g'
#define _MAPA_ELEMENTO_LADRAO 'l'
#define _MAPA_ELEMENTO_MAGO 'm'
#define _MAPA_ELEMENTO_INIMIGO_UM '1'
#define _MAPA_ELEMENTO_INIMIGO_DOIS '2'
#define _MAPA_ELEMENTO_PEDRA 'p'
#define _MAPA_ELEMENTO_SAIDA 's'
#define _MAPA_ELEMENTO_INVULNERAVEL 'i'

//Função para criar o mapa e retornar ponteiro para tal
Celula** criaMapa(){
    Celula** mapa = new Celula*[_LINHAS];

    for (int i = 0; i < _LINHAS; i++){
        mapa[i] = new Celula[_COLUNAS];
    }

    for (int i = 0; i < _LINHAS; i++){
        for (int j = 0; j < _COLUNAS; j++){
            if (i == 6 && j == 0){
                mapa[i][j] = Celula(_MAPA_ELEMENTO_BARBARO, i, j);
            } else if (i == 7 && j == 0){
                mapa[i][j] = Celula(_MAPA_ELEMENTO_GUERREIRO, i, j);
            } else if (i == 8 && j == 0){
                mapa[i][j] = Celula(_MAPA_ELEMENTO_LADRAO, i, j);
            } else if (i == 9 && j == 0){
                mapa[i][j] = Celula(_MAPA_ELEMENTO_MAGO, i, j);
            } else if (i == 4 && j == 0 || i == 5 && j == 6 || i == 7 && j == 7){
                mapa[i][j] = Celula(_MAPA_ELEMENTO_INIMIGO_UM, i, j);
            } else if (i == 2 && j == 2 || i == 0 && j == 8){
                mapa[i][j] = Celula(_MAPA_ELEMENTO_INIMIGO_DOIS, i, j);
            } else if (i == 3 && j == 3 || i == 1 && j == 6){
                mapa[i][j] = Celula(_MAPA_ELEMENTO_PEDRA, i, j);
            } else if(i == 0 && j == 9){
                mapa[i][j] = Celula(_MAPA_ELEMENTO_SAIDA, i, j);
            } else if(i == 5 && j <= 5 || i >= 8 && j == 3 || i >= 1 && i <= 3 && j == 5 || i == 3 && j >= 6 || i == 1 && j == 7){
                mapa[i][j] = Celula(_MAPA_ELEMENTO_INVULNERAVEL, i, j);
            } else {
                mapa[i][j] = Celula(_MAPA_ELEMENTO_VAZIO, i, j); 
            }
        }
    }

    return mapa;
}

//Função para desalocar memória do mapa
void deletaMapa(Celula** mapa){
    for (int i = 0; i < _LINHAS; i++)
        delete [] mapa[i];

    delete [] mapa;
}

//Função para desenhar exibição do mapa
void desenhaMapa(Celula** mapa){
    for (int j = _COLUNAS - 1; j >= 0; j--){
        for (int i = 0; i < _LINHAS; i++){
            std::cout << mapa[i][j].getElemento();
        }
        std::cout << std::endl;
    }
}

//Cria personagem do bárbaro
Barbaro* criaBarbaro(Celula celula){
    Celula* celulaPtr = &celula;
    Barbaro* barbaro = new Barbaro(_BARBARO_HP, _MP, _SP, _BARBARO_DANO, _DIRECAO_PADRAO, celulaPtr);

    celulaPtr = nullptr;

    return barbaro;
}

//Desaloca personagem do bárbaro
void deletaBarbaro(Barbaro* barbaro){
    delete barbaro;
}

//Cria personagem do guerreiro
Guerreiro* criaGuerreiro(Celula celula){
    Celula* celulaPtr = &celula;
    Guerreiro* guerreiro = new Guerreiro(_GUERREIRO_HP, _MP, _SP, _GUERREIRO_DANO, _DIRECAO_PADRAO, celulaPtr);

    celulaPtr = nullptr;

    return guerreiro;
}

//Desaloca personagem do guerreiro
void deletaGuerreiro(Guerreiro* guerreiro){
    delete guerreiro;
}

//Cria personagem do ladrão
Ladrao* criaLadrao(Celula celula){
    Celula* celulaPtr = &celula;
    Ladrao* ladrao = new Ladrao(_LADRAO_HP, _MP, _SP, _LADRAO_DANO, _DIRECAO_PADRAO, celulaPtr);

    celulaPtr = nullptr;

    return ladrao;
}

//Desaloca personagem do ladrão
void deletaLadrao(Ladrao* ladrao){
    delete ladrao;
}

//Cria personagem do mago
Mago* criaMago(Celula celula){
    Celula* celulaPtr = &celula;
    Mago* mago = new Mago(_MAGO_HP, _MP, _SP, _MAGO_DANO, _DIRECAO_PADRAO, celulaPtr);

    celulaPtr = nullptr;

    return mago;
}

//Desaloca personagem do mago
void deletaMago(Mago* mago){
    delete mago;
}

int main(){
    Celula** mapa = criaMapa();
    int opcao=0;

    Barbaro* barbaro = criaBarbaro(mapa[6][1]);
    Guerreiro* guerreiro = criaGuerreiro(mapa[7][1]);
    Ladrao* ladrao = criaLadrao(mapa[8][1]);
    Mago* mago = criaMago(mapa[9][1]);


    //Loop principal do jogo
    while (1){
        desenhaMapa(mapa);
        
        //Selecionado o personagem, ou inimigo que ataca,entra no loop
        cout << "Escolha uma opcao" << endl;
        while(opcao != 4){ //Opcao = 4 finaliza o turno
            cin >> opcao;
            switch (opcao){
                case 1: // Ataque simples
                    break;
                case 2: //Habilidade
                    break;
                case 3: //Mover
                    break;
            }
        }

        break;
    }

    //Desaloca tudo
    deletaMapa(mapa);
    deletaBarbaro(barbaro);
    deletaGuerreiro(guerreiro);
    deletaLadrao(ladrao);
    deletaMago(mago);

    return 0;
}
