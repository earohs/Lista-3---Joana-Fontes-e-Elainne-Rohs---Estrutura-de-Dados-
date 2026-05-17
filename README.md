# Lista-3---Joana-Fontes-e-Elainne-Rohs---Estrutura-de-Dados-
Implementação de um sistema simples de matchmaking, formando grupos de jogadores online com níveis de habilidade semelhantes.

# Descrição do projeto
Sistema simples de matchmaking para jogadores online.

Operações permitidas:
- inserir jogadores;
- remover jogadores;
- ordenar jogadores por score;
- recuperação dos jogadores (gerar um array dinâmico dos jogadores em espera);
- exibir jogadores aguardando a partida.

# Instruções de compilação
Compilação realizada através do comando:
```bash
g++ main.cpp Player.cpp Matchmaking.cpp -o matchmaking
```
Ao executar esse comando, será criado um arquivo executável chamado ```matchmaking```.

# Instruções de execução
Execute o programa do arquivo ```matchmaking.exe``` usando o comando:
```bash
.\matchmaking.exe
```

# Organização dos arquivos
- ```main.cpp```: simulação do sistema de matchmaking e testes de velocidade dos algoritmos de ordenação.
- ```Player.hpp```: representa cada jogador, esperando para ser incluído em um time.
- ```Player.cpp```: métodos da classe jogador.
- ```Matchmaking.hpp```: representa o sistema de matchmaking.
- ```Matchmaking.cpp```: métodos da classe Matchmaking, declarados no arquivo anterior.

# Execução dos testes no main

O arquivo ```main.cpp``` possui testes para:
- inserção (de 7 jogadores)
- remoção (do jogador 3)
- empate de score (Harry e Neville)
- formação de grupos (casos com e sem sucesso)
- insertion sort vs merge sort: comparação de desempenho entre ambos algoritmos de organização