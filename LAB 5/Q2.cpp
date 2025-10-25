#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomNumber = 0;

void guessGame(int player) {
    int guess;
    cout << "Player " << player << ", enter your guess (1 to 100): ";
    cin >> guess;

    if (guess == randomNumber) {
        cout << "Player " << player << " wins! Correct number: " << randomNumber << endl;
        return;
    } else if (guess > randomNumber) {
        cout << "Too high!\n";
    } else {
        cout << "Too low!\n";
    }

    guessGame(player == 1 ? 2 : 1);
}

int main() {
    srand(time(0));
    randomNumber = rand() % 100 + 1;
    guessGame(1);
    return 0;
}
