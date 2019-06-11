#include <iostream>
#include "celula.h"
#include "barbaro.h"
#include "guerreiro.h"
#include "ladrao.h"
#include "mago.h"
#include "inimigoum.h"
#include "inimigodois.h"
#include "gerarMapa.h"
#include "gerarPersonagens.h"

using namespace std;

int main(){
    Celula** mapa = criaMapa();
    Celula* destino = nullptr; //Ponteiro para o destino de funções de personagens
    Celula* alvoInimigo = nullptr; //Ponteiro para o alvo de ataques de inimigos

    int opcao = 0, turnoAtual = _TURNO_BARBARO;
    int x, y;
    bool todosMortos = false, todosSalvos = false;

    Barbaro* barbaro = criaBarbaro(mapa[6][0]);
    Guerreiro* guerreiro = criaGuerreiro(mapa[7][0]);
    Ladrao* ladrao = criaLadrao(mapa[8][0]);
    Mago* mago = criaMago(mapa[9][0]);

    InimigoUm* inimigoA = criaInimigoUm(mapa[7][7]);
    InimigoUm* inimigoB = criaInimigoUm(mapa[5][6]);
    InimigoUm* inimigoC = criaInimigoUm(mapa[4][0]);
    InimigoDois* inimigoD = criaInimigoDois(mapa[2][2]);
    InimigoDois* inimigoE = criaInimigoDois(mapa[0][8]);

    //Loop principal do jogo
    while (1){
        todosMortos = !barbaro->getVivo() && !guerreiro->getVivo() && !ladrao->getVivo() && !mago->getVivo();
        todosSalvos = barbaro->getSalvo() && guerreiro->getSalvo() && ladrao->getSalvo() && mago->getSalvo();

        if (todosMortos){
            gameOver();
            break;
        }

        if (todosSalvos){
            vitoria();
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
        
        //Se for turno de algum dos personagens, lista escolhas
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
                        cout << "Insira as coordenadas desejadas (uma por vez): ";
                        cin >> x >> y;

                        destino = &mapa[x][y];

                        switch (turnoAtual){
                            case _TURNO_BARBARO:
                                if(!barbaro->ataque(destino))
                                    cout << endl << "Nao pode atacar essa posicao!" << endl;
                                else if (destino->getPersonagem()->getHP() <= 0){
                                    destino->getPersonagem()->morte();
                                    destino->setPersonagem(nullptr);
                                    destino->setElemento('v');
                                    cout << "Inimigo derrotado!" << endl;
                                } else {
                                    cout << "Inimigo atacado! Vida do inimigo: " << destino->getPersonagem()->getHP() << endl;
                                }
                                break;

                            case _TURNO_LADRAO:
                                if(!ladrao->ataque(destino))
                                    cout << endl << "Nao pode atacar essa posicao!" << endl;
                                else if (destino->getPersonagem()->getHP() <= 0){
                                    destino->getPersonagem()->morte();
                                    destino->setPersonagem(nullptr);
                                    destino->setElemento('v');
                                    cout << "Inimigo derrotado!" << endl;
                                } else {
                                    cout << "Inimigo atacado! Vida do inimigo: " << destino->getPersonagem()->getHP() << endl;
                                }
                                break;

                            case _TURNO_GUERREIRO:
                                if(!guerreiro->ataque(destino))
                                    cout << endl << "Nao pode atacar essa posicao!" << endl;
                                else if (destino->getPersonagem()->getHP() <= 0){
                                    destino->getPersonagem()->morte();
                                    destino->setPersonagem(nullptr);
                                    destino->setElemento('v');
                                    cout << "Inimigo derrotado!" << endl;
                                } else {
                                    cout << "Inimigo atacado! Vida do inimigo: " << destino->getPersonagem()->getHP() << endl;
                                }
                                break;
                            
                            case _TURNO_MAGO:
                                if(!mago->ataque(destino, mapa))
                                    cout << endl << "Nao pode atacar essa posicao!" << endl;
                                else if (destino->getPersonagem()->getHP() <= 0){
                                    destino->getPersonagem()->morte();
                                    destino->setPersonagem(nullptr);
                                    destino->setElemento('v');
                                    cout << "Inimigo derrotado!" << endl;
                                } else {
                                    cout << "Inimigo atacado! Vida do inimigo: " << destino->getPersonagem()->getHP() << endl;
                                }
                                break;
                        }
                        break;

                    case 2: //Habilidade
                        switch (turnoAtual){
                            case _TURNO_BARBARO:
                                if(!barbaro->berserk())
                                    cout << endl << "Nao pode usar essa habilidade!" << endl;
                                else
                                    cout << "Habilidade berserk ativada! Dano atual: " << barbaro->getDano() + barbaro->getDanoExtra() << endl;
                                break;

                            case _TURNO_LADRAO:
                                cout << "Insira as coordenadas desejadas (uma por vez): ";
                                cin >> x >> y;

                                destino = &mapa[x][y];

                                if(!ladrao->arco(destino, mapa))
                                    cout << endl << "Nao pode atacar essa posicao!" << endl;
                                else if (destino->getPersonagem()->getHP() <= 0){
                                    destino->getPersonagem()->morte();
                                    destino->setPersonagem(nullptr);
                                    destino->setElemento('v');
                                    cout << "Inimigo derrotado!" << endl;
                                } else {
                                    cout << "Inimigo atacado! Vida do inimigo: " << destino->getPersonagem()->getHP() << endl;
                                }
                                break;

                            case _TURNO_GUERREIRO:
                                if(!guerreiro->escudo())
                                    cout << endl << "Nao pode usar essa habilidade!" << endl;
                                else
                                    cout << "Escudo ativado!" << endl;
                                break;
                            
                            case _TURNO_MAGO:
                                cout << "Insira as coordenadas desejadas (uma por vez): ";
                                cin >> x >> y;

                                destino = &mapa[x][y];

                                if(!mago->stun(destino,mapa))
                                    cout << endl << "Nao pode atacar essa posicao!" << endl;
                                else
                                    cout << "Inimigo atordoado!" << endl;
                                break;
                        }
                        break;

                    case 3: //Mover
                        cout << "Insira as coordenadas desejadas (uma por vez): ";
                        cin >> x >> y;

                        destino = &mapa[x][y];

                        switch (turnoAtual){
                            case _TURNO_BARBARO:
                                if (!barbaro->movimenta(destino)){
                                    cout << endl << "Movimento invalido!" << endl;
                                } else {
                                    barbaro->getCelula()->setElemento('v');

                                    if (destino->getElemento() != 's')
                                        destino->setElemento('b');
                                }
                                break;

                            case _TURNO_LADRAO:
                                if (!ladrao->movimenta(destino)){
                                    ladrao->getCelula()->setElemento('l');
                                    cout << endl << "Movimento invalido!" << endl;
                                } else {
                                    ladrao->getCelula()->setElemento('v');

                                    if (destino->getElemento() != 's')
                                        destino->setElemento('l');
                                }
                                break;

                            case _TURNO_GUERREIRO:
                                if (!guerreiro->movimenta(destino)){
                                    guerreiro->getCelula()->setElemento('g');
                                    cout << endl << "Movimento invalido!" << endl;
                                } else {
                                    guerreiro->getCelula()->setElemento('v');

                                    if (destino->getElemento() != 's')
                                        destino->setElemento('g');
                                }
                                break;
                            
                            case _TURNO_MAGO:
                                if (!mago->movimenta(destino)){
                                    mago->getCelula()->setElemento('m');
                                    cout << endl << "Movimento invalido!" << endl;
                                } else {
                                    mago->getCelula()->setElemento('v');

                                    if (destino->getElemento() != 's')
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

            destino = nullptr; //Faz ponteiro de destino apontar para null quando não necessário por boas práticas
        } else { //Turnos dos inimigos
            alvoInimigo = inimigoA->scan(mapa);
            if (alvoInimigo != inimigoA->getCelula()){
                inimigoA->getCelula()->setElemento('1');

                if (inimigoA->ataque(alvoInimigo)){
                    if (alvoInimigo->getPersonagem()->getHP() <= 0){
                        alvoInimigo->getPersonagem()->morte();
                        alvoInimigo->setPersonagem(nullptr);
                        alvoInimigo->setElemento('v');
                    }
                }
            }

            alvoInimigo = inimigoB->scan(mapa);
            if (alvoInimigo != inimigoB->getCelula()){
                inimigoB->getCelula()->setElemento('1');

                if (inimigoB->ataque(alvoInimigo)){
                    if (alvoInimigo->getPersonagem()->getHP() <= 0){
                        alvoInimigo->getPersonagem()->morte();
                        alvoInimigo->setPersonagem(nullptr);
                        alvoInimigo->setElemento('v');
                    }
                }
            }

            alvoInimigo = inimigoC->scan(mapa);
            if (alvoInimigo != inimigoC->getCelula()){
                inimigoC->getCelula()->setElemento('1');

                if (inimigoC->ataque(alvoInimigo)){
                    if (alvoInimigo->getPersonagem()->getHP() <= 0){
                        alvoInimigo->getPersonagem()->morte();
                        alvoInimigo->setPersonagem(nullptr);
                        alvoInimigo->setElemento('v');
                    }
                }
            }

            alvoInimigo = inimigoD->scan(mapa);
            if (alvoInimigo != inimigoD->getCelula()){
                inimigoD->getCelula()->setElemento('2');

                if (inimigoD->ataque(alvoInimigo)){
                    if (alvoInimigo->getPersonagem()->getHP() <= 0){
                        alvoInimigo->getPersonagem()->morte();
                        alvoInimigo->setPersonagem(nullptr);
                        alvoInimigo->setElemento('v');
                    }
                }
            }

            alvoInimigo = inimigoE->scan(mapa);
            if (alvoInimigo != inimigoE->getCelula()){
                inimigoE->getCelula()->setElemento('2');

                if (inimigoE->ataque(alvoInimigo)){
                    if (alvoInimigo->getPersonagem()->getHP() <= 0){
                        alvoInimigo->getPersonagem()->morte();
                        alvoInimigo->setPersonagem(nullptr);
                        alvoInimigo->setElemento('v');
                    }
                }
            }

            alvoInimigo = nullptr; //Faz ponteiro para alvo apontar para null quando não necessário por boas práticas
        }
    }

    //Desaloca tudo
    deletaMapa(mapa);

    deletaBarbaro(barbaro);
    deletaGuerreiro(guerreiro);
    deletaLadrao(ladrao);
    deletaMago(mago);
    deletaInimigoUm(inimigoA);
    deletaInimigoUm(inimigoB);
    deletaInimigoUm(inimigoC);
    deletaInimigoDois(inimigoD);
    deletaInimigoDois(inimigoE);

    deletaInimigoUm(inimigoA);
    deletaInimigoUm(inimigoB);
    deletaInimigoUm(inimigoC);
    deletaInimigoDois(inimigoD);
    deletaInimigoDois(inimigoE);

    return 0;
}