#include "Matchmaking.hpp"
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {

    // Alocação dinâmica para não estourar o stack
    // (cada Matchmaking tem um array estático de 100000 Players)
    Matchmaking* hogwartsCup = new Matchmaking();

    cout << "---- Inserting Players ----" << endl;

    hogwartsCup->insert(Player(1, "Malfoy", 900, 1));
    hogwartsCup->insert(Player(2, "Luna", 1100, 2));
    hogwartsCup->insert(Player(3, "Harry", 1020, 3));
    hogwartsCup->insert(Player(4, "Hermione", 1030, 4));
    hogwartsCup->insert(Player(5, "Rony", 1000, 5));
    hogwartsCup->insert(Player(6, "Neville", 1020, 6));
    hogwartsCup->insert(Player(7, "Ginny", 1010, 7));

    hogwartsCup->printWaitingPlayers();

    cout << "---------------------------" << endl;

    cout << "---- Removing player 3 ----" << endl;

    hogwartsCup->removePlayer(3);

    hogwartsCup->printWaitingPlayers();

    cout << "---------------------------" << endl;

    cout << "---- Insertion Sort ----" << endl;

    hogwartsCup->sortByScoreInsertion();

    hogwartsCup->printWaitingPlayers();

    cout << "-------------------------" << endl;

    cout << "---- Merge Sort (empate de score: Neville e Harry) ----" << endl;
    // re-insere Harry para gerar empate de score com Neville (1020)
    hogwartsCup->insert(Player(3, "Harry", 1020, 3));
    hogwartsCup->sortByScoreMerge();
    hogwartsCup->printWaitingPlayers();
    cout << "-------------------------" << endl;
    // remove novamente para o restante dos testes
    hogwartsCup->removePlayer(3);

    cout << "--- Sucess: Group formation ---" << endl;
    cout << "--- members = 3, delta = 30 ---" << endl;

    int n;

    Player* group = hogwartsCup->formGroup(3, 30, &n);

    cout << "Group:" << endl;
    if (group != nullptr) {
        for (int i = 0; i < n; i++) {
            cout << "[" << group[i].getId() << " | " << group[i].getName() << " | " << group[i].getScore() << " | " << group[i].getTimestamp() << "]" << endl;
        }
    }
    delete[] group;

    cout << "---- Remaining Players ----" << endl;
    cout << "n = " << n << endl;
    hogwartsCup->printWaitingPlayers();

    cout << "---------------------------" << endl;

    cout << "--- Failure: Group formation ---" << endl;
    cout << "--- members = 3, delta = 50 ---" << endl;

    Player* failGroup = hogwartsCup->formGroup(3, 50, &n);

    if (failGroup == nullptr) {
        cout << "group == nullptr" << endl;
        cout << "n = " << n << endl;
    }

    cout << "---------------------------" << endl;

    cout << "---- getWaitingPlayers ----" << endl;

    int qtd;
    Player* waiting = hogwartsCup->getWaitingPlayers(&qtd);
    cout << "n = " << qtd << endl;
    if (waiting != nullptr) {
        for (int i = 0; i < qtd; i++) {
            cout << "[" << waiting[i].getId() << " | " << waiting[i].getName() << " | " << waiting[i].getScore() << " | " << waiting[i].getTimestamp() << "]" << endl;
        }
        delete[] waiting;
    } else {
        cout << "(empty)" << endl;
    }

    cout << "---------------------------" << endl;

    // Libera o primeiro Matchmaking antes de criar os de teste,
    // para não manter três arrays gigantes em memória ao mesmo tempo
    delete hogwartsCup;

    cout << endl;
    cout << "---- INSERTION vs MERGE SORT ----" << endl;

    // Tamanhos de entrada usados nos testes de desempenho
    const int N_TESTS = 4;
    int sizes[N_TESTS] = {1000, 3000, 5000, 10000};

    long long insertionTimes[N_TESTS];
    long long mergeTimes[N_TESTS];

    for (int t = 0; t < N_TESTS; t++) {
        int TEST_SIZE = sizes[t];

        Matchmaking* insertionTest = new Matchmaking();
        Matchmaking* mergeTest = new Matchmaking();

        // Usa a mesma semente para que ambos os algoritmos
        // recebam exatamente a mesma entrada (comparação justa)
        srand(42);
        for (int i = 0; i < TEST_SIZE; i++) {
            int score = rand() % TEST_SIZE;
            insertionTest->insert(Player(i, "Player", score, i));
        }
        srand(42);
        for (int i = 0; i < TEST_SIZE; i++) {
            int score = rand() % TEST_SIZE;
            mergeTest->insert(Player(i, "Player", score, i));
        }

        auto startI = high_resolution_clock::now();
        insertionTest->sortByScoreInsertion();
        auto endI = high_resolution_clock::now();
        insertionTimes[t] = duration_cast<milliseconds>(endI - startI).count();

        auto startM = high_resolution_clock::now();
        mergeTest->sortByScoreMerge();
        auto endM = high_resolution_clock::now();
        mergeTimes[t] = duration_cast<milliseconds>(endM - startM).count();

        delete insertionTest;
        delete mergeTest;
    }

    cout << "Tamanho   | Insertion (ms) | Merge (ms)" << endl;
    for (int t = 0; t < N_TESTS; t++) {
        cout << sizes[t] << "      | " << insertionTimes[t] << "             | " << mergeTimes[t] << endl;
    }

    return 0;
}
