#ifndef MATCHMAKING_HPP
#define MATCHMAKING_HPP
#include "Player.hpp"

const int MAX_PLAYERS = 100000;

class Matchmaking {
private:
    Player players[MAX_PLAYERS];
    int size;

    // Este método retorna verdadeiro se o jogador a "ganha" de b na fila ordenada, 
    //seja por ter menor score ou timestamp. Falso caso contrário.
    bool goesFirst(Player a, Player b);

    void mergeSort(int left, int right);
    //Esta é a função para unir duas listas ordenadas, usada no Merge Sort
    void merge(int left, int mid, int right); 

public:
    Matchmaking();
    ~Matchmaking();

    bool insert(Player player);
    bool removePlayer(int id);

    void sortByScoreInsertion();
    void sortByScoreMerge();

    Player* formGroup(int groupSize, int delta, int* n);

    Player* getWaitingPlayers(int* n);

    void printWaitingPlayers();

};

#endif