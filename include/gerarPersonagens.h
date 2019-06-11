#ifndef GAME_GERAR_PERSONAGENS_H
#define GAME_GERAR_PERSONAGENS_H

#include "celula.h"
#include "barbaro.h"
#include "guerreiro.h"
#include "ladrao.h"
#include "mago.h"
#include "inimigoum.h"
#include "inimigodois.h"
#include <iostream>

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

#define _INIMIGO1_HP 85
#define _INIMIGO1_DANO 15

#define _INIMIGO2_HP 70
#define _INIMIGO2_DANO 17

#define _TURNO_BARBARO 1
#define _TURNO_LADRAO 2
#define _TURNO_GUERREIRO 3
#define _TURNO_MAGO 4
#define _TURNO_INIMIGOS 5


//Cria personagem do bárbaro
Barbaro* criaBarbaro(Celula celula);

//Desaloca personagem do bárbaro
void deletaBarbaro(Barbaro* barbaro);

//Cria personagem do guerreiro
Guerreiro* criaGuerreiro(Celula celula);

//Desaloca personagem do guerreiro
void deletaGuerreiro(Guerreiro* guerreiro);

//Cria personagem do ladrão
Ladrao* criaLadrao(Celula celula);

//Desaloca personagem do ladrão
void deletaLadrao(Ladrao* ladrao);

//Cria personagem do mago
Mago* criaMago(Celula celula);

//Desaloca personagem do mago
void deletaMago(Mago* mago);

//Cria Inimigo 1
InimigoUm* criaInimigoUm(Celula celula);

//Desaloca Inimigo 1
void deletaInimigoUm(InimigoUm* inimigo);

//Cria Inimigo 2
InimigoDois* criaInimigoDois(Celula celula);

//Desaloca Inimigo 2
void deletaInimigoDois(InimigoDois* inimigo);

//Escreve informacoes dos personagens na tela
void escreveInformacoes(int turnoAtual, Barbaro* barbaro, Ladrao* ladrao, Guerreiro* guerreiro, Mago* mago);

#endif