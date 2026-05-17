#include "Matchmaking.hpp"
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {

    Matchmaking hogwartsCup;

    cout << "---- Inserting Players ----" << endl;

    hogwartsCup.insert(Player(1, "Malfoy", 900, 1));
    hogwartsCup.insert(Player(2, "Luna", 1100, 2));
    hogwartsCup.insert(Player(3, "Harry", 1020, 3));
    hogwartsCup.insert(Player(4, "Hermione", 1030, 4));
    hogwartsCup.insert(Player(5, "Rony", 1000, 5));
    hogwartsCup.insert(Player(6, "Neville", 1020, 6));
    hogwartsCup.insert(Player(7, "Ginny", 1010, 7));

    hogwartsCup.printWaitingPlayers();

    cout << "---------------------------" << endl;

    cout << "---- Removing player 3 ----" << endl;

    hogwartsCup.removePlayer(3);

    hogwartsCup.printWaitingPlayers();

    cout << "---------------------------" << endl;

    cout << "---- Insertion Sort ----" << endl;

    hogwartsCup.sortByScoreInsertion();

    hogwartsCup.printWaitingPlayers();

    cout << "-------------------------" << endl;

    cout << "--- Sucess: Group formation ---" << endl;
    cout << "--- members = 3, delta = 30 ---" << endl;

    int n;

    Player* group = hogwartsCup.formGroup(3, 30, &n);

    // liberando memória no main do array group
    delete[] group;

    cout << "---- Remaining Players ----" << endl;

    cout << n << endl;
    hogwartsCup.printWaitingPlayers();

    cout << "---------------------------" << endl;

    cout << "--- Failure: Group formation ---" << endl;
    cout << "--- members = 3, delta = 50 ---" << endl;


    Player* failGroup = hogwartsCup.formGroup(3, 50, &n);

    if (failGroup == nullptr) {
        cout << "group == nullptr" << endl;
        cout << "n = " << n << endl;
    }

    cout << "---------------------------" << endl;
    cout << endl;

    cout << "---- INSERTION vs MERGE SORT ----" << endl;

    Matchmaking insertionTest;
    Matchmaking mergeTest;

    int TEST_SIZE = 5000; //Número bem menor que 100000, 
    //mas dessa forma não dá segmentation fault nem precisa transformar players em array dinâmico

    for (int i = 0; i < TEST_SIZE; i++) {

        int score = rand() % TEST_SIZE;

        insertionTest.insert(Player(i, "Player", score, i));
        mergeTest.insert(Player(i, "Player", score, i));
    }

    // criando um array dinâmico ou modificando os algoritmos de ordenação para aceitarem array dinãmicos
    //Player* insertion = insertionTest.getWaitingPlayers(&n);
    //Player* merge = mergeTest.getWaitingPlayers(&n);

    auto start1 = high_resolution_clock::now();

    insertionTest.sortByScoreInsertion();

    auto end1 = high_resolution_clock::now();

    auto duration1 =
        duration_cast<milliseconds>(end1 - start1);

    auto start2 = high_resolution_clock::now();

    mergeTest.sortByScoreMerge();

    auto end2 = high_resolution_clock::now();

    auto duration2 =
        duration_cast<milliseconds>(end2 - start2);

    //delete[] merge;
    //delete[] insertion;

    cout << "Insertion Sort: "
         << duration1.count()
         << " ms" << endl;

    cout << "Merge Sort: "
         << duration2.count()
         << " ms" << endl;



    return 0;
}