#include "gerarPersonagens.h"

using namespace std;

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


//Cria Inimigo 1
InimigoUm* criaInimigoUm(Celula celula){
    Celula* celulaPtr = &celula;
    InimigoUm* inimigo = new InimigoUm(_INIMIGO1_HP, _MP, _SP, _INIMIGO1_DANO, _DIRECAO_PADRAO, celulaPtr);

    celulaPtr = nullptr;

    return inimigo;
}

//Desaloca Inimigo 1
void deletaInimigoUm(InimigoUm* inimigo){
    delete inimigo;
}

//Cria Inimigo 2
InimigoDois* criaInimigoDois(Celula celula){
    Celula* celulaPtr = &celula;
    InimigoDois* inimigo = new InimigoDois(_INIMIGO1_HP, _MP, _SP, _INIMIGO1_DANO, _DIRECAO_PADRAO, celulaPtr);

    celulaPtr = nullptr;

    return inimigo;
}

//Desaloca Inimigo 2
void deletaInimigoDois(InimigoDois* inimigo){
    delete inimigo;
}

//Cria pedra
Pedra* criaPedra(Celula celula){
    Celula* celulaPtr = &celula;
    Pedra* pedra = new InimigoDois(_PEDRA_HP, 0, 0,0, _DIRECAO_PADRAO, celulaPtr);

    celulaPtr = nullptr;

    return pedra;
}

//Desaloca Pedra
void deletaPedra(Pedra* pedra){
    delete pedra;
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