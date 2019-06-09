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
     int *prt;
     int a = 5;
     prt = &a;
     CHECK_NOTHROW(Celula());
     CHECK_NOTHROW(Personagem(100, 3, 6, 30, "N"));

}

TEST_CASE ("02 - teste retorno"){

}

TEST_CASE (""){ 

}