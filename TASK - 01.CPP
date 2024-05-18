/*      TASK 1
    NUMBER GUESSING GAME
Create a program that generates a random number and asks the
user to guess it. Provide feedback on whether the guess is too
high or too low until the user guesses the correct number.*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void number_guessing_game() {
    srand(time(0));
    int secret_number = rand() % 100 + 1;
    
    cout<<"*****************************************************************\n" ;
    cout << "\tWelcome to the Number Guessing Game!" << endl;
    cout << "I've picked a number between 1 and 100. Can you guess what it is?" << endl;
    
    int attempts = 0;
    int guess;
    
    while (true) {
        cout << "\nEnter your guess: ";
        cin >> guess;
        attempts++;
        
        if (guess == secret_number) {
            cout << "Congratulations! You've guessed the number " << secret_number << " correctly in " << attempts << " attempts!" << endl;
            break;
        }
        else if (guess > secret_number) {
            cout << "Too high! Try guessing a lower number." << endl;
        }
        else {
            cout << "Too low! Try guessing a higher number." << endl;
        }
    }
}

int main() {
    number_guessing_game();
    return 0;
}
