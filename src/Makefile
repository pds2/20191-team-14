CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g -fsanitize=address
LDFLAGS = -I../include

SRC = main.cpp personagem.cpp celula.cpp gerarMapa.cpp gerarPersonagens.cpp barbaro.cpp guerreiro.cpp inimigo.cpp inimigodois.cpp inimigoum.cpp ladrao.cpp mago.cpp Pedra.cpp
OBJ = $(SRC:.cc=.o)
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)