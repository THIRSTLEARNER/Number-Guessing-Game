#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
using namespace chrono;
int main() {

   
int time_limit = 10; // Time limit for the game in seconds
bool is_time_up = false;
int number;
int tries;
int guess;
int difficulty1;
string difficulty2;

auto start = steady_clock::now();

srand(time(0));
    
cout << "Welcome to the guessing game!" << endl;
cout << "I have a number between 1 and 1000." << endl;
cout << "you have 5 tries to guess it." << endl;

cout << "\nPlease select the difficulty level: ";
cout << "\n1. Easy (10 chances)" << endl;
cout << "2. Medium (5 chances)" << endl;
cout << "3. Hard (3 chances)" << endl;

cout << "\nEnter your choice: ";
cin >> difficulty1;
if (difficulty1 == 1){ 
    difficulty2 = "Easy";
    tries = 10;
}
else if (difficulty1 == 2){ 
    difficulty2 = "Medium";
    tries = 5;
}
else if (difficulty1 == 3){ 
    difficulty2 = "Hard";
    tries = 3;
}
cout << "Great! You have selected the " << difficulty2 << " difficulty level. "
     << "Let's start the game!" << endl;
     
     number = rand() % 100 + 1;

       
     for (int i = 1; i <= tries; i++) {
        auto elapsed = duration_cast<seconds>(steady_clock::now() - start).count();
        if (elapsed >= time_limit) {
            is_time_up = true;
            cout.flush();
            break;
        }
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess == number) {
            cout << "Congratulations! You guessed the number." << endl;
            break;
        }
        else if (guess < number) {
            cout << "Try a higher number." << endl;
        }
        else {
            cout << "Try a lower number." << endl;
        }
        if (i == tries) {
            cout << "Sorry, you have used all your chances." << endl;
            cout << "The correct number was " << number << "." << endl;
        }
        int remaining_time = time_limit - elapsed;
        cout << "Time remaining: " << remaining_time << " seconds\n";
        
        if (is_time_up) {
            cout << "\nTime's up! The correct number was " << number << ".\n";
        }
    }

           if (!is_time_up && guess != number) {
          cout << "The correct number was " << number << ".\n";
    }

    return 0;
}
// #include <iostream>
// #include <chrono>
// #include <thread>

// using namespace std;
// using namespace chrono;

// int main() {
//     int seconds = 100;

    
//     auto start = steady_clock::now();

//     // Countdown loop
//     for (int i = seconds; i > 0; --i) {
//         cout << "Time remaining: " << i << " seconds\r";
//         cout.flush();  // Ensure the output is immediately displayed

//         // Wait for one second
//         this_thread::sleep_for(chrono::seconds(1));
//     }

//     // Timer finished
//     cout << "Time's up!                " << endl;

//     return 0;
// }
