/*
    Guess the Number
    ----------------------
    Guess the Number is a console-based game written in C where the player tries to guess a randomly generated secret number.

    Author: [Sandra Martin Elias]
    Date: [2025/08/18]
*/

#include <stdio.h> // Standard input/output library
#include <stdlib.h>  // For rand(), srand(), and exit-related functions
#include <time.h> // For time(), used to seed the random number generator

// Function declarations
void easy();
void medium();
void hard();
void definedRange();

int main() {
    int playAgain, difficulty;

    srand(time(NULL)); // Seed the random number generator with the current time

    while(1) {
        printf("Choose the difficulty level:\n1-Easy\n2-Medium\n3-Hard\n4-Customized range\n0-Exit\n"); // Display difficulty selection menu
 
        // Validate difficulty input
        if (scanf("%i", &difficulty) != 1 ) {
            printf("Invalid input. Please enter a number between 0 and 4. Press enter to continue.\n");
            while (getchar() != '\n' && getchar() != EOF); // Clear input buffer
            continue;
        }

        switch (difficulty)  // Call the corresponding function based on difficulty
        {
        case 0:
            printf("Thank you for playing! Goodbye!\n");
            return 0;

        case 1:
            easy();
            break;

        case 2:
            medium();
            break;
        
        case 3:
            hard();
            break;

        case 4:
            definedRange();
            break;
        
        default:
            printf("Invalid input. Please enter a number between 0 and 4.\n");
            continue;
        }

        playAgain = -1;

         // Ask if the player wants to play again
        while(playAgain != 0 && playAgain != 1) {
            printf("Do you want to play again? (1 for yes, 0 for no): ");

            if (scanf("%i", &playAgain) != 1 ) {
                printf("Invalid input. Please enter 1 or 0. Press enter to continue.\n");
                while (getchar() != '\n' && getchar() != EOF); // Clear input buffer
                continue;
            }

            if (playAgain < 0 || playAgain > 1) {
                printf("Please enter 1 for yes or 0 for no.\n");
                continue;
            } else if (playAgain == 0) {
                printf("Thank you for playing! Goodbye!\n");
                return 0;
            } else {
                break;
            }
        }
    }
    return 0;
}

// Easy mode: Number between 1 and 10
// Provides basic feedback (too high/too low)
void easy() {
    int number, guess, tries;

    // Initialize variables
    tries=0;
    guess=-1;
    number = rand() % 10 + 1; // Random number between 1 and 10
    printf("Your are in EASY mode! Try to guess the number between 1 and 10!\n");

    // Loop until the correct number is guessed
    while (guess!=number) {
        while (1) {
            tries++;
            printf("Enter your guess: ");
            // Handle non-integer input
            if (scanf("%i", &guess) != 1) {
                printf("Invalid input. Please enter a number between 1 and 10. Press enter to continue.\n");
                while (getchar() != '\n' && getchar() != EOF);
                continue;
            }
            if (guess < 1 || guess > 10) {
                printf("Please enter a number between 1 and 10.\n");
                continue;
            }
            break;
        }

        // Provide hints based on the guess
        if (guess < number) {
            printf("Too low! Try a higher number.\n");
        } else if (guess > number) {
            printf("Too high! Try a lower number.\n");
        } else{
            printf("Congratulations! You've guessed the number: %i\n", number);
            printf("Number of tries: %i\n", tries);
        }
    }    
}

// Medium mode: Number between 1 and 50
// Gives hints with increasing precision
void medium() {
    int number, guess, tries;

    // Initialize variables
    tries=0;
    guess=-1;
    number = rand() % 50 + 1; // Random number between 1 and 50
    printf("You are in MEDIUM mode! Try to guess the number between 1 and 50!\n");

    // Loop until the correct number is guessed
    while (guess!=number) {
        while (1) {
            tries++;
            printf("Enter your guess: ");
            // Handle non-integer input
            if (scanf("%i", &guess) != 1) {
                printf("Invalid input. Please enter a number between 1 and 50. Press enter to continue.\n");
                while (getchar() != '\n' && getchar() != EOF);
                continue;
            }
            if (guess < 1 || guess > 50) {
                printf("Please enter a number between 1 and 50.\n");
                continue;
            }
            break;
        }

        // Provide hints based on the guess
        if (guess < (number-10)) {
            printf("Too low! Try a much higher number.\n");
        } else if (guess < number) {
            printf("Too low! Try a higher number.\n");
        } else if (guess > (number+10)) {
            printf("Too high! Try a much lower number.\n");
        } else if (guess > number) {
            printf("Too high! Try a lower number.\n");
        } else{
            printf("Congratulations! You've guessed the number: %i\n", number);
            printf("Number of tries: %i\n", tries);
        }
    }    
}

// Hard mode: Number between 1 and 100
// More granular hints for a greater challenge
void hard() {
    int number, guess, tries;

    // Initialize variables
    tries=0;
    guess=-1;
    number = rand() % 100 + 1; // Random number between 1 and 100
    printf("You are in HARD mode! Try to guess the number between 1 and 100!\n");

    // Loop until the correct number is guessed
    while (guess!=number) {
        while (1) {
            tries++;
            printf("Enter your guess: ");
            // Handle non-integer input
            if (scanf("%i", &guess) != 1) {
                printf("Invalid input. Please enter a number between 1 and 100. Press enter to continue.\n");
                while (getchar() != '\n' && getchar() != EOF);
                continue;
            }
            if (guess < 1 || guess > 100) {
                printf("Please enter a number between 1 and 100.\n");
                continue;
            }
            break;
        }

        // Provide hints based on the guess
        if (guess < (number-20)) {
            printf("Too low! Try a much much higher number.\n");
        }else if (guess < (number-10)) {
            printf("Too low! Try a much higher number.\n");
        } else if (guess < number) {
            printf("Too low! Try a higher number.\n");
        } else if (guess > (number+20)) {
            printf("Too high! Try a much much lower number.\n");
        } else if (guess > (number+10)) {
            printf("Too high! Try a much lower number.\n");
        } else if (guess > number) {
            printf("Too high! Try a lower number.\n");
        } else{
            printf("Congratulations! You've guessed the number: %i\n", number);
            printf("Number of tries: %i\n", tries);
        }
    }    
}

// Custom range mode: User defines the min and max values
// Number is randomly selected within that range
void definedRange() {
    int number, guess, tries, minNum, maxNum;

    // Ask user for custom min and max range
    // Validate inputs and ensure max > min
    while(1) {
        printf("Enter the minimum number for the range: ");
        if (scanf("%i", &minNum) != 1) {
            printf("Invalid input. Please enter a number. Press enter to continue.\n");
            while (getchar() != '\n' && getchar() != EOF);
            continue;
        }

        printf("Enter the maximum number for the range: ");
        if (scanf("%i", &maxNum) != 1 || maxNum <= minNum) {
            printf("Invalid input. Please enter a valid range. Press enter to continue.\n");
            while (getchar() != '\n' && getchar() != EOF);
            continue;
        }

        break;
    }

    // Initialize variables
    tries=0;
    guess=-1;
    number = rand() % (maxNum - minNum + 1) + minNum; // Generate a random number in the custom range: [minNum, maxNum]
    printf("You are in CUSTOM mode! Try to guess the number between %i and %i!\n", minNum, maxNum);

    // Loop until the correct number is guessed
    while (guess!=number) {
        while (1) {
            tries++;
            printf("Enter your guess: ");
            // Handle non-integer input
            if (scanf("%i", &guess) != 1) {
                printf("Invalid input. Please enter a number between %i and %i. Press enter to continue.\n", minNum, maxNum);
                while (getchar() != '\n' && getchar() != EOF);
                continue;
            }

            if (guess < minNum || guess > maxNum) {
                printf("Please enter a number between %i and %i.\n", minNum, maxNum);
                continue;
            }
            break;
        }

        // Provide hints based on the guess
        if (guess < (number-20)) {
            printf("Too low! Try a much much higher number.\n");
        }else if (guess < (number-10)) {
            printf("Too low! Try a much higher number.\n");
        } else if (guess < number) {
            printf("Too low! Try a higher number.\n");
        } else if (guess > (number+20)) {
            printf("Too high! Try a much much lower number.\n");
        } else if (guess > (number+10)) {
            printf("Too high! Try a much lower number.\n");
        } else if (guess > number) {
            printf("Too high! Try a lower number.\n");
        } else{
            printf("Congratulations! You've guessed the number: %i\n", number);
            printf("Number of tries: %i\n", tries);
        }
    }    
}