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

TEST_CASE("01 - teste construtor "){ //testa os construtores das classes
     Celula celula = Celula('j',1,2); 
     CHECK_NOTHROW(Celula());
     CHECK_NOTHROW(Celula(1, 2));
     CHECK_NOTHROW(Celula('J', 1, 2));
     CHECK_NOTHROW(Inimigo(100, 3, 6, 30, 'N', &celula));
     CHECK_NOTHROW(Personagem(100, 3, 6, 30, 'N', &celula));
     CHECK_NOTHROW(Barbaro(100, 3, 6, 30, 'N', &celula));
     CHECK_NOTHROW(Guerreiro(100, 3, 6, 30, 'N', &celula));
     CHECK_NOTHROW(Ladrao(100, 3, 6, 30, 'N', &celula));
     CHECK_NOTHROW(Mago(100, 3, 6, 30, 'N', &celula));
     CHECK_NOTHROW(InimigoUm(100, 3, 6, 30, 'N', &celula));
     CHECK_NOTHROW(InimigoDois(100, 3, 6, 30, 'N', &celula));
}

TEST_CASE ("02 - teste retorno"){
     Celula celula = Celula('j',1,2); 
     Personagem personagem = Personagem(100, 3, 6, 30, 'N', &celula);
     personagem.setHP(100);
     CHECK(personagem.getHP()==100);
     Guerreiro guerreiro = Guerreiro(100, 3, 6, 30, 'N', &celula);
     guerreiro.setHP(120);
     CHECK(guerreiro.getHP()==120);
     Barbaro barbaro = Barbaro(100, 3, 6, 30, 'N', &celula);
     barbaro.setHP(10);
     CHECK(barbaro.getHP()==10);
     Ladrao ladrao = Ladrao(100, 3, 6, 30, 'N', &celula);
     CHECK(ladrao.getHP()==100);
     Mago mago = Mago(100, 3, 6, 30, 'N', &celula);
     CHECK(mago.getHP()==100);
     Inimigo inimigo = Inimigo(100, 3, 6, 30, 'N', &celula);
     inimigo.setHP(75);
     CHECK(inimigo.getHP()==75);
     InimigoUm inimigoum = InimigoUm(100, 3, 6, 30, 'n', &celula);
     inimigoum.setHP(45);
     CHECK(inimigoum.getHP()==45);
     InimigoDois inimigodois = InimigoDois(100, 3, 6, 30, 'n', &celula);
     inimigodois.setHP(100);
     CHECK(inimigodois.getHP()==100);
}


TEST_CASE("03- mudança de direção"){
      Celula celula = Celula('j',1,2); 
     Personagem personagem = Personagem(100, 3, 6, 30, 'n', &celula);
     personagem.setDirecao('o');
     CHECK(personagem.getDirecao()=='o');
     Guerreiro guerreiro = Guerreiro(100, 3, 6, 30, 'n', &celula);
     guerreiro.setDirecao('o');
     CHECK(guerreiro.getDirecao()=='o');
     Barbaro barbaro = Barbaro(100, 3, 6, 30, 'n', &celula);
     barbaro.setDirecao('o');
     CHECK(barbaro.getDirecao()=='o');
     Ladrao ladrao = Ladrao(100, 3, 6, 30, 'n', &celula);
     CHECK(ladrao.getDirecao()=='n');
     Mago mago = Mago(100, 3, 6, 30, 'n', &celula);
     CHECK(mago.getDirecao()=='n');
     Inimigo inimigo = Inimigo(100, 3, 6, 30, 'n', &celula);
     inimigo.setDirecao('s');
     CHECK(inimigo.getDirecao()=='s');
     InimigoUm inimigoum = InimigoUm(100, 3, 6, 30, 'n', &celula);
     inimigoum.setDirecao('s');
     CHECK(inimigoum.getDirecao()=='s');
     InimigoDois inimigodois = InimigoDois(100, 3, 6, 30, 'n', &celula);
     inimigodois.setDirecao('s');
     CHECK(inimigodois.getDirecao()=='s');
}



TEST_CASE ("04 - teste validez do ataque ataque proximo"){ 
     Celula celula = Celula('j',1,2); 
     Celula alvo = Celula('i',2,2);
     Celula** mapa;
     Barbaro barbaro = Barbaro(100, 3, 6, 30, 'o', &celula);
     CHECK(barbaro.ataque(&alvo)==true);
     Guerreiro guerreiro = Guerreiro(100, 3, 6, 30, 'o', &celula);
     CHECK(guerreiro.ataque(&alvo)==true);
     Ladrao ladrao = Ladrao(100, 3, 6, 30, 'o', &celula);
     CHECK(ladrao.ataque(&alvo)==true);
     Mago mago = Mago(100, 3, 6, 30, 'o', &celula);
     CHECK(mago.ataque(&alvo, mapa)==true);
     Inimigo inimigo = Inimigo(100, 3, 6, 30, 'o', &celula);
     CHECK(inimigo.ataque(&alvo)==true);
     InimigoUm inimigoum = InimigoUm(100, 3, 6, 30, 'o', &celula);
     CHECK(inimigoum.ataque(&alvo)==true);
     InimigoDois inimigodois = InimigoDois(100, 3, 6, 30, 'o', &celula);
     CHECK(inimigodois.ataque(&alvo)==true);
}

TEST_CASE ("05 - teste ataque invalido"){ 
     Celula celula = Celula('j',1,2); 
     Celula alvo = Celula('i',2,10);
     Celula** mapa;
     Barbaro barbaro = Barbaro(100, 3, 6, 30, 'o', &celula);
     CHECK(barbaro.ataque(&alvo)==false);
     Guerreiro guerreiro = Guerreiro(100, 3, 6, 30, 'o', &celula);
     CHECK(guerreiro.ataque(&alvo)==false);
     Ladrao ladrao = Ladrao(100, 3, 6, 30, 'o', &celula);
     CHECK(ladrao.ataque(&alvo)==false);
     Mago mago = Mago(100, 3, 6, 30, 'o', &celula);
     CHECK(mago.ataque(&alvo, mapa)==false);
     Inimigo inimigo = Inimigo(100, 3, 6, 30, 'o', &celula);
     CHECK(inimigo.ataque(&alvo)==false);
     InimigoUm inimigoum = InimigoUm(100, 3, 6, 30, 'o', &celula);
     CHECK(inimigoum.ataque(&alvo)==false);
     InimigoDois inimigodois = InimigoDois(100, 3, 6, 30, 'o', &celula);
     CHECK(inimigodois.ataque(&alvo)==false);
     
}

