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
     CHECK_NOTHROW(Personagem(100, 3, 6, 30, "N", celula));
     CHECK_NOTHROW(Barbaro(100, 3, 6, 30, "N", celula));
     CHECK_NOTHROW(Guerreiro(100, 3, 6, 30, "N", celula));
     CHECK_NOTHROW(ladrao(100, 3, 6, 30, "N", celula));
     CHECK_NOTHROW(Mago(100, 3, 6, 30, "N", celula));
     CHECK_NOTHROW(inimigoum(100, 3, 6, 30, "N", celula));
     CHECK_NOTHROW(inimigodois(100, 3, 6, 30, "N", celula));
}

TEST_CASE ("02 - teste retorno"){
     Personagem personagem;
     personagem.setHP(100);
     CHECK(personagem.getHP()==100);
     Guerreiro guerreiro;
     guerreiro.setHP(100);
     CHECK(guerreiro.getHP()==100);
     Barbaro barbaro;
     barbaro.setHP(100);
     CHECK(barbaro.getHP()==100);
     Ladrao ladrao;
     CHECK(ladrao.getHP()==100);
     Mago mago;
     CHECK(mago.getHP()==100);
     InimigoUm inimigoum;
     inimigoum.setHP(100);
     CHECK(inimigoum.getHP()==100);
     InimigoDois inimigodois;
     inimigodois.setHP;
     CHECK(inimigodois.getHP()==100);
}

TEST_CASE ("03 - teste ataque"){ 
 
}

TEST_CASE ("04 - teste habilidade especial"){ 
 
}