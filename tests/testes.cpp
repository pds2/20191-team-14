#include "doctest.h"

#include "barbaro.h"
#include "celula.h"
#include "guerreiro.h"
#include "inimigodois.h"
#include "inimigoum.h"
#include "ladrao.h"
#include "mago.h"
#include "personagem.h"
#include <string>

TEST_CASE("01 - teste construtor "){
     Celula* celula; 
     CHECK_NOTHROW(Celula());
     CHECK_NOTHROW(Celula(1, 2));
     CHECK_NOTHROW(Celula('n', 1, 2));
     CHECK_NOTHROW(Personagem(100, 3, 6, 30, 'n', celula));
     CHECK_NOTHROW(Barbaro(100, 3, 6, 30, 'n', celula));
     CHECK_NOTHROW(Guerreiro(100, 3, 6, 30, 'n', celula));
     CHECK_NOTHROW(Ladrao(100, 3, 6, 30, 'n', celula));
     CHECK_NOTHROW(Mago(100, 3, 6, 30, 'n', celula));
     CHECK_NOTHROW(InimigoUm(100, 3, 6, 30, 'n', celula));
     CHECK_NOTHROW(InimigoDois(100, 3, 6, 30, 'n', celula));
}

TEST_CASE ("02 - teste retorno"){

     Celula* celula; 
     Personagem personagem = Personagem(100, 3, 6, 30, 'N', celula);
     personagem.setHP(100);
     CHECK(personagem.getHP()==100);
     Guerreiro guerreiro = Guerreiro(100, 3, 6, 30, 'N', celula);;
     guerreiro.setHP(120);
     CHECK(guerreiro.getHP()==120);
     Barbaro barbaro = Barbaro(100, 3, 6, 30, 'N', celula);;
     barbaro.setHP(100);
     CHECK(barbaro.getHP()==100);
     Ladrao ladrao = Ladrao(100, 3, 6, 30, 'N', celula);
     CHECK(ladrao.getHP()==100);
     Mago mago = Mago(100, 3, 6, 30, 'N', celula);;
     CHECK(mago.getHP()==100);
     InimigoUm inimigoum = InimigoUm(100, 3, 6, 30, 'n', celula);
     inimigoum.setHP(100);
     CHECK(inimigoum.getHP()==100);
     InimigoDois inimigodois = InimigoDois(100, 3, 6, 30, 'n', celula);
     inimigodois.setHP;
     CHECK(inimigodois.getHP()==100);
}

TEST_CASE ("03 - teste ataque"){ 
     
}

TEST_CASE ("04 - teste habilidade especial"){ 
 
}