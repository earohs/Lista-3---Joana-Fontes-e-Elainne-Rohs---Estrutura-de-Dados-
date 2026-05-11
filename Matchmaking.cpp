#include "Matchmaking.hpp"
#include "Player.hpp"
#include <iostream>

using namespace std;

Matchmaking::Matchmaking() {
    size = 0;
}

Matchmaking::~Matchmaking() {
}


bool Matchmaking::goesFirst(Player a, Player b) {
    if(a.getScore() < b.getScore()) {
        return true; //sem comparar timestamps
    }
    if(a.getScore() > b.getScore()) {
        return false;
    }

    // em caso de empate
    return a.getTimestamp() < b.getTimestamp();
}
void Matchmaking::sortByScoreInsertion() {
    for(int i = 1; i < size; i++) {
        Player key = players[i];
        int j = i-1;
        while(j>=0 && goesFirst(key, players[j])) {
            players[j+1] = players[j];
            j--;
        }
        players[j+1] = key;
    }
}