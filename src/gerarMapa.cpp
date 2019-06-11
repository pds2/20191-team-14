#include "gerarMapa.h"

using namespace std;

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

//Fim de jogo
void gameOver(){
    cout << "Fim de jogo! Todos os personagens estão mortos..." << endl;
}

//Jogo terminado
void vitoria(){
    cout << "Todos os personagens conseguiram sair vivos! Você venceu!" << endl;
}