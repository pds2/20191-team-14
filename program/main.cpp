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

#define _TURNO_BARBARO 1
#define _TURNO_LADRAO 2
#define _TURNO_GUERREIRO 3
#define _TURNO_MAGO 4
#define _TURNO_INIMIGOS 5

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
        cout << j << "   ";
        for (int i = 0; i < _LINHAS; i++){
            cout << mapa[i][j].getElemento();
        }
        cout << endl;
    }
    cout << "    ";
    for (int i = 0; i < _LINHAS; i++)
        cout << i << endl;
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

//Escreve informacoes dos personagens na tela
void escreveInformacoes(int turnoAtual, Barbaro* barbaro, Ladrao* ladrao, Guerreiro* guerreiro, Mago* mago){
    cout << "Barbaro - HP: " << barbaro->getHP() << " SP: " << barbaro->getSP() << " MP: " << barbaro->getMP();
    if (turnoAtual == _TURNO_BARBARO)
        cout << " TURNO ATUAL";
    if (!barbaro->getVivo())
        cout << " MORTO";
    cout << endl;

    cout << "Ladrao - HP: " << ladrao->getHP() << " SP: " << ladrao->getSP() << " MP: " << ladrao->getMP();
    if (turnoAtual == _TURNO_LADRAO)
        cout << " TURNO ATUAL";
    if (!ladrao->getVivo())
        cout << " MORTO";
    cout << endl;

    cout << "Guerreiro - HP: " << guerreiro->getHP() << " SP: " << guerreiro->getSP() << " MP: " << guerreiro->getMP();
    if (turnoAtual == _TURNO_GUERREIRO)
        cout << " TURNO ATUAL";
    if (!guerreiro->getVivo())
        cout << " MORTO";
    cout << endl;

    cout << "Mago - HP: " << mago->getHP() << " SP: " << mago->getSP() << " MP: " << mago->getMP();
    if (turnoAtual == _TURNO_MAGO)
        cout << " TURNO ATUAL";
    if (!mago->getVivo())
        cout << " MORTO";
    cout << endl;
}

//Fim de jogo
void gameOver(){
    cout << "Fim de jogo! Todos os personagens estão mortos..." << endl;
}

int main(){
    Celula** mapa = criaMapa();
    int opcao = 0, turnoAtual = _TURNO_BARBARO;
    bool todosMortos = false;

    Barbaro* barbaro = criaBarbaro(mapa[6][1]);
    Guerreiro* guerreiro = criaGuerreiro(mapa[7][1]);
    Ladrao* ladrao = criaLadrao(mapa[8][1]);
    Mago* mago = criaMago(mapa[9][1]);

    //Loop principal do jogo
    while (1){
        todosMortos = !barbaro->getVivo() && !guerreiro->getVivo() && !ladrao->getVivo() && !mago->getVivo();

        if (todosMortos){
            gameOver();
            break;
        }

        if (turnoAtual == _TURNO_INIMIGOS)
            turnoAtual = _TURNO_BARBARO;
        else
            turnoAtual++;

        //Se personagem atual estiver morto, pula o turno dele
        if (turnoAtual == _TURNO_BARBARO && !barbaro->getVivo()
            || turnoAtual == _TURNO_LADRAO && !ladrao->getVivo()
            || turnoAtual == _TURNO_GUERREIRO && !guerreiro->getVivo()
            || turnoAtual == _TURNO_MAGO && !mago->getVivo())
            turnoAtual++;
        
        if (turnoAtual != _TURNO_INIMIGOS){
            //Selecionado o personagem, entra no loop
            while(opcao != 4){ //Opcao = 4 finaliza o turno
                cout << endl;
                desenhaMapa(mapa);
                escreveInformacoes(turnoAtual, barbaro, ladrao, guerreiro, mago);
                cout << endl << "Escolha uma opcao:" << endl;
                cout << "1 - Ataque Basico" << endl << "2 - Habilidade" << endl << "3 - Mover" << endl << "4 - Encerrar Turno";

                cin >> opcao;
                switch (opcao){
                    case 1: // Ataque básico
                        switch (turnoAtual){
                            case _TURNO_BARBARO:
                                break;

                            case _TURNO_LADRAO:
                                break;

                            case _TURNO_GUERREIRO:
                                break;
                            
                            case _TURNO_MAGO:
                                break;
                        }
                        break;
                    case 2: //Habilidade
                        switch (turnoAtual){
                            case _TURNO_BARBARO:
                                break;

                            case _TURNO_LADRAO:
                                break;

                            case _TURNO_GUERREIRO:
                                break;
                            
                            case _TURNO_MAGO:
                                break;
                        }
                        break;
                    case 3: //Mover
                        int x, y;

                        cout << "Insira as coordenadas desejadas (uma por vez): ";
                        cin >> x >> y;

                        Celula *destino = &mapa[x][y];

                        switch (turnoAtual){
                            case _TURNO_BARBARO:
                                barbaro->getCelula()->setElemento('v');
                                if (!barbaro->movimenta(destino)){
                                    barbaro->getCelula()->setElemento('b');
                                    cout << endl << "Movimento invalido!" << endl;
                                } else {
                                    destino->setElemento('b');
                                }
                                break;

                            case _TURNO_LADRAO:
                                ladrao->getCelula()->setElemento('v');
                                if (!ladrao->movimenta(destino)){
                                    ladrao->getCelula()->setElemento('l');
                                    cout << endl << "Movimento invalido!" << endl;
                                } else {
                                    destino->setElemento('l');
                                }
                                break;

                            case _TURNO_GUERREIRO:
                                guerreiro->getCelula()->setElemento('v');
                                if (!guerreiro->movimenta(destino)){
                                    guerreiro->getCelula()->setElemento('g');
                                    cout << endl << "Movimento invalido!" << endl;
                                } else {
                                    destino->setElemento('g');
                                }
                                break;
                            
                            case _TURNO_MAGO:
                                mago->getCelula()->setElemento('v');
                                if (!mago->movimenta(destino)){
                                    mago->getCelula()->setElemento('m');
                                    cout << endl << "Movimento invalido!" << endl;
                                } else {
                                    destino->setElemento('m');
                                }
                                break;
                        }
                        break;
                    case 4: //Encerra turno
                        cout << "Encerrando turno..." << endl;
                        switch (turnoAtual){
                            case _TURNO_BARBARO:
                                barbaro->terminaTurno();
                                break;

                            case _TURNO_LADRAO:
                                ladrao->terminaTurno();
                                break;

                            case _TURNO_GUERREIRO:
                                guerreiro->terminaTurno();
                                break;
                            
                            case _TURNO_MAGO:
                                mago->terminaTurno();
                                break;
                        }
                        break;
                }
            }
        }


    }

    //Desaloca tudo
    deletaMapa(mapa);
    deletaBarbaro(barbaro);
    deletaGuerreiro(guerreiro);
    deletaLadrao(ladrao);
    deletaMago(mago);

    return 0;
}
