// Abdullah, BSCS-13-B, 455340.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void correct_response(int array[]);
void incorrect_response(int array[]);
void generate_question(int array[], int level, int operation);
void random_multiplication(int array[], int level, int operation);

int main()
{
    int question[4] = {0}; // Stores the {rand1, rand2, user-input, answer(rand1 (op) rand2)} respectively.
    int level, operation;

    srand(time(NULL));
    printf("\nHey students. In this game you will have to get at least 8 out of 10 questions right.\nENter -1 to go back in the game...");
    while(1)
    {
        // Selection of operation. Keeps prompting until correct input.
        do{
            printf("\nOPERATION\n1. ADDITION \n2. SUBTRACTION \n3. MULTIPLICATION \n4. RANDOM\nYour choice: ");
            scanf("%d", &operation);
            if (operation == -1) return 0; // Ends game if -1 is entered.
        }while (operation > 4 || operation < 1);


        // Selection of difficulty level. Keeps promptin until correct input.
        do{
            printf("\nSELECT DIFFICULTY LEVEL\n1. BEGINNER\n2. INTERMEDIATE\n3. ADVANCED\nEnter difficulty level: ");
            scanf("%d", &level);
            if (level == -1) return 0; // Ends game if -1 is entered
        }while (level < 1 || level > 3);

        switch(level) // Switch between levels.
        {
            case 1: level = 10; break;
            case 2: level = 100; break;
            case 3: level = 1000; break;
        }
        random_multiplication(question, level, operation);
    }
    return 0;
}

// The CAI function.
void random_multiplication(int array[], int level, int operation)
{
    int success[2] = {0}; // Resets the performance every time the function is called. (stores {loses, wins})
    printf("\n------NEW GAME------ \n");

    for (int i = 0; i < 10; i++)
    {
        generate_question(array, level, operation);

        // Checks the user input value. (array[2]) with answer (array[3]).
        if (array[2] == array[3]) 
        {
            correct_response(array);
            success[1]++; // success[1] counts the wins.
        } 
        else
        {
            success[0]++; // success[0] counts the loses.
            incorrect_response(array); 
            do
            {   
                printf("? ");
                scanf("%d", &array[2]);
            }
            while (array[2] != array[3]);
        }
    }
    // Result.....
    if (success[1] / 10.0 >= 0.75)
        printf("Congratulations, you are ready to go to the next level!\n");
    else
        printf("Please ask your teacher for extra help.\n");
}

// Generates the question to be answered.
void generate_question(int array[], int level, int operation)
{
    // Generates and stores two random numbers in an array (digit count with respect to difficulty).
    array[0] = rand() % level; 
    array[1] = rand() % level;

    // Selection of operation and promting the player for questions.
    if (operation == 4) operation = array[0] % 3 + 1; // Generates a random choice of 1, 2, or 3 (array[0] is already a random number). 
    switch (operation)
    {
        case 1: array[3] = array[0] + array[1]; 
                printf("What is %d + %d ? ", array[0], array[1]); // Prints the question.
                scanf("%d", &array[2]); // Stores the user's answer in array[2]
                break;
        case 2: array[3] = array[0] - array[1];
                printf("What is %d - %d ? ", array[0], array[1]); // Prints the question.
                scanf("%d", &array[2]); // Stores the user's answer in array[2]
                break;
        case 3: array[3] = array[0] * array[1];
                printf("What is %d x %d ? ", array[0], array[1]); // Prints the question.
                scanf("%d", &array[2]); // Stores the user's answer in array[2]
                break;
    }
}

// Responds for correct answer.
void correct_response(int array[])
{
    int choice = array[0] % 4; // Random number mod 4.
    switch (choice)
    {
        case 0: printf(">Very good!\n"); break;
        case 1: printf(">Excellent!\n"); break;
        case 2: printf(">Nice work!\n"); break;
        case 3: printf(">Keep up the good work!\n"); break;
    }
}

// Responds for incorrect answer.
void incorrect_response(int array[])
{
    int choice = array[0] % 4; // random number mod 4.
    switch (choice)
    {
        case 0: printf(">No. Please try again.\n"); break;
        case 1: printf(">Wrong. Try once more.\n"); break;
        case 2: printf(">Don't give up!\n"); break;
        case 3: printf(">No. Keep trying.\n"); break;
    }
}