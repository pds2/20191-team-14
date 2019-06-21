Documentação Trabalho Prático PDS II

Gabriel Nogueira Morais, 		
Igor Roiz Teixeira,
João Victor Souza Silveira 
e Thiago Camargo Medeiros.

 
1.   Introdução
 
O desenvolvimento de jogos é um dos importantes usos dos Sistemas de Informação. Em geral, os jogos são uma forma de entretenimento que sempre existiram na sociedade e, hoje, é possível criar jogos mais complexos com o uso da tecnologia.
 O objetivo deste trabalho foi criar um jogo de RPG tabuleiro, em que serão escolhidos personagens, cada um com suas habilidades, em que ocorrerão batalhas por turnos, desafios no mapa e muitas outras coisas.
 Desse modo, espera-se praticar os diversos conceitos da programação em C++ aprendidas nas aulas, como herança, encapsulamento, testes, entre outros, bem como aprimorar nosso trabalho em equipe.

  
2.   Implementação

O código foi implementado detalhadamente, com comentários e indentação, utilizando componentes modularizados e reusáveis.

Pasta Include: nesta pasta estão todos os arquivos.h do código. O arquivo personagem.h é a classe mãe que determina atributos para todos os outros “arquivos .h”, por meio de herança. Estas atribuem novos atributos característicos de cada personagem, por meio de polimorfismo.

Pasta program: inclui o main.cpp, que possui funções de criação do mapa, dos personagens e onde está implementado o loop principal do jogo. 

Pasta src: nesta pasta estão os arquivos .cpp do código. Estes determinam as execuções das funções dos arquivos .h.

Pasta tests: inclui o testes.cpp, que é o código para testes unitários de todo o programa.


 
3.   Testes

4.   Conclusão

Este trabalho foi feito utilizando todos os conteúdos abordados nas aulas da disciplina. O resultado foi dentro do esperado e conseguimos, além de criar um jogo completo e funcional, treinar habilidades de programação em C++.
A principal dificuldade do grupo foi com o tempo de entrega, o que nos impossibilitou a criação da biblioteca gráfica do trabalho, que poderia estar visualmente melhor.
 
Anexos
Listagem dos programas:
• include/
              	- barbaro.h
		- celula.h
		- guerreiro.h
		- inimigoum.h
		- inimigodois.h
		- ladrao.h
		- mago.h
		- personagem.h

 • program/
		- main.cpp
		- tester.cpp
 
• scr/
		- barbaro.cpp
		- celula.cpp
		- guerreiro.cpp
		- inimigo.cpp
		- ladrao.cpp
		- mago.cpp
		- personagem.cpp
 
• tests/
		- testes.cpp

 • third_party/
		- doctest.h

 • bin/
		- tester

 • Outros: 
		- .git / .vscode (pastas)
		- Makefile
		- README.md
		- Documentação Trabalho Prático PDSII





..
 

  