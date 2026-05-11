# Lista-3---Joana-Fontes-e-Elainne-Rohs---Estrutura-de-Dados-
Implementação de um sistema simples de matchmaking, formando grupos de jogadores online com níveis de habilidade semelhantes.

# Descrição do projeto
Sistema simples de matchmaking para jogadores online.

Operações permitidas:
- inserir jogadores;
- remover jogadores;
- ordenar jogadores por score;
- recuperar jogadores em uma fila;
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
.\matchmaking
```

# Organização dos arquivos
- ```main.cpp```:
- ```Player.hpp```:
- ```Player.cpp```:
- ```Matchmaking.hpp```:
- ```Matchmaking.cpp```:

# Execução dos testes no main

O arquivo ```main.cpp``` possui testes para:
- inserção
- remoção
- insertion sort
- merge sort
- empate de score
- formação de grupos
- recuperação de jogadores
- comparação de desempenho entre ambos algoritmos de organização