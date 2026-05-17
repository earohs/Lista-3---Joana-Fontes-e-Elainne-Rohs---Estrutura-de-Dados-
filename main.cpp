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

    cout << "---- Removing player 2 ----" << endl;

    hogwartsCup.removePlayer(2);

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

    return 0;
}