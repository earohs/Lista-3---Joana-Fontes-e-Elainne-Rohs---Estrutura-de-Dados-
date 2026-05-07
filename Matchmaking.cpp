#include "Matchmaking.hpp"
#include "Player.hpp"
#include <iostream>

using namespace std;

Matchmaking::Matchmaking() {
    size = 0;
}

Matchmaking::~Matchmaking() {
}

void Matchmaking::sortByScoreInsertion(Player players[], int n) {
    for(int i=1; i<n; i++) {
        int key = players[i].getScore();
        int j = i-1;
        while(j>=0 && players[j].getScore()>key) {
            players[j+1] = players[j];
            j--;
        }
        players[j+1].getScore() = key; // não tem setter
    }
}