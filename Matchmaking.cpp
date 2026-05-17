#include "Matchmaking.hpp"
#include "Player.hpp"
#include <iostream>

using namespace std;

Matchmaking::Matchmaking() {
    size = 0;
}

Matchmaking::~Matchmaking() {
}

//
bool Matchmaking::insert(Player player) {
    if (size >= MAX_PLAYERS) return false;
    players[size] = player;
    size++;

    return true;
}

bool Matchmaking::removePlayer(int id) {
    
    int index = -1;

    for (int i = 0; i < size; i++) {
        if (players[i].getId() == id) {
            index = i;
            break;
        }
    }

    if (index == -1) return false;
    for (int i = index; i < size-1; i++) {
        players[i] = players[i+1];
    }

    size--;
    return true;
}

// Bloco Insertion Sort
bool Matchmaking::goesFirst(Player a, Player b) {
    if(a.getScore() < b.getScore()) {
        return true; //sem comparar timestamps
    }
    if(a.getScore() > b.getScore()) {
        return false;
    }

    // em caso de empate
    //(nessa simulação o timestamp nunca será o mesmo então, não usa-se <=, só <)
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

// Bloco Merge Sort
void Matchmaking::sortByScoreMerge() {
    if (size <= 1) return;
    mergeSort(0, size - 1);
}

void Matchmaking::mergeSort(int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

void Matchmaking::merge(int left, int mid, int right) {
    int sizeLeft  = mid - left + 1;
    int sizeRight = right - mid;

    Player* L = new Player[sizeLeft];
    Player* R = new Player[sizeRight];

    for (int i = 0; i < sizeLeft; i++)
        L[i] = players[left + i];
    for (int j = 0; j < sizeRight; j++)
        R[j] = players[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < sizeLeft && j < sizeRight) {
        if (goesFirst(L[i], R[j])) {
            players[k] = L[i];
            i++; k++;
        } else {
            players[k] = R[j];
            j++; k++;
        }
    }

    while (i < sizeLeft) { players[k] = L[i]; i++; k++; }
    while (j < sizeRight) { players[k] = R[j]; j++; k++; }

    delete[] L;
    delete[] R;
}

// usa-se depois de já organizada por score a lista players
Player* Matchmaking::formGroup(int groupSize, int delta, int* n) {
    *n = 0;

    if (groupSize > size) return nullptr;

    for (int min = 0; min <= size-groupSize; min++) {
        int max = min + groupSize - 1;
        int minScore = players[min].getScore();
        int maxScore = players[max].getScore();

        if (maxScore - minScore <= delta) {
            // criação do array dinâmico do grupo formado
            Player* din_group = new Player[groupSize];
            
            for (int i = 0; i < groupSize; i++) {
                din_group[i] = players[min+i];
            }

            //remoção, na lista de jogadores em espera, dos jogadores do grupo formado 
            for (int j = max + 1; j < size; j++) {
                players[j - groupSize] = players[j];
            }

            size -= groupSize;
            *n = groupSize;

            return din_group;
        }
    }
    
    return nullptr;
}

Player* Matchmaking::getWaitingPlayers(int* n) {
    *n = size;
    if (size == 0) {
        *n = 0;
        return nullptr;
    }

    Player* din_players = new Player[size];
    
    for (int i = 0; i < size; i++) {
        din_players[i] = players[i];
    }

    return din_players;
}

void Matchmaking::printWaitingPlayers() {
    cout << "Waiting Players:" <<endl;

    if (size == 0) {
        cout << "empty" << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << "[" << players[i].getId() <<"|"<< players[i].getName() <<"|"<< players[i].getScore() <<"|"<< players[i].getTimestamp() << "]" << endl; 
    }
}