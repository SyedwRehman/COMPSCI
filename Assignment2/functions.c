# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include "constants.h"
# include "functions.h"


bool playWordGuessingGame(const char *randomWord)
{
    int lenAns = (int)strlen(randomWord); //length of answers used for arrays. uses an int case since strlen is an unsigned integer val
    char Answer[lenAns]; strcpy(Answer,randomWord); // array with the same length and holds the randomWord chars
    int attempts = 0; // initiallizing attempts
    char guess; // guess from the user
    char guessArr [lenAns]; // initiallizing the array for guessing correctly
    int cond = 0; // condition value for getting a correct guess
    int ALcount = 0; // variable for counting All of the Letters from the word and guess
    int pos; // position variable
    
    for (int i = 0; i < lenAns; i++) // for loop going through length of random word
    {
        guessArr[i] = '-'; // setting up the blank inputs for the guessing array
    }

    while (attempts < MAX_ATTEMPTS) // loops while the attempts are below 5
    {
        cond=3; // setting an arbritrary val above 2
        pos=-1; // setting an arbrtrary val below 0
        printf("Attempt %d:  ",attempts+1);
        scanf("%c",&guess); // puts the char for the letter into the guess var
        while (getchar() != '\n'); // eliminates any other val in the buffer
        for (int i = 0; i < lenAns; i++){ // loops through the length of the random word
            if (guess == Answer[i] && guess != guessArr[i]){ // checks if the guess char is the same as the answer and if the same letter has been guessed before
                cond =1; // sets cond var to 1 to use later
                ALcount++; // increments the Count for All of the Letters
                guessArr[i] = guess; // puts the guess in the same location for the guessArr
                pos = i; // changes the position var to the current location which is higher than or equal to 0
            }
            else if (guess == Answer[i]) // checks if guess is already inputed
            {
                cond=2; // second case condition for same input
            }
            else
            {
                continue;
            }
        }
        if(cond == 3 && pos < 0) // checks if the condition and position value has changed and if it hasn't then does the following
        {
            for (int i = 0; i < lenAns; i++)
            {
                printf("%c ",guessArr[i]); // prints the guessArr which has whatever was in it last
            }
            printf("\n");
            printf("Incorrect guess. Try again\n");
            ++attempts; // increments attempts after wrong guess
        }
        else if (cond ==2) // checks if the condition is 2 which shows an already input char or letter
        {
            printf("That is already an input\n");
        }
        else if (ALcount == lenAns && cond ==1) // checks to see if the number of correct letters is the same as the length and if the condition is 1 meaning the last input was correct
        {
            for (int i = 0; i < lenAns; i++)
            {
                printf("%c ",guessArr[i]); // prints the correct answer which is now in the guessArr
            }
            printf("\n");
            return true; // returns true since all the letters were guessed correctly
            break;
        }
        else
        {
            for (int i = 0; i < lenAns; i++) // loops through the guessArr
            {
                printf("%c ",guessArr[i]); // prints out the guessArr values for the user to see the correctly guessed inputs so far
            }
            printf("\n");
        }
    }
    return false; // returns false since the letters are not all found
}


bool playWordGuessingGameAutomatic (const char *randomWord, char **words, int numWords, int numSuggestion)
{
    char Suggestions[numSuggestion][MAX_WORD_LENGTH]; // (NEW) suggestions 2D array to hold amount of words as numSuggestions and have a length of MAX_WORD_LENGTH
    int lenAns = (int)strlen(randomWord); //length of answers used for arrays. uses an int case since strlen is an unsigned integer val
    char Answer[lenAns]; strcpy(Answer,randomWord); // array with the same length and holds the randomWord chars
    int attempts = 0; // initiallizing attempts
    char guess; // guess from the user
    char guessArr [lenAns]; // initiallizing the array for guessing correctly
    int cond = 0; // condition value for getting a correct guess
    int ALcount = 0; // variable for counting All of the Letters from the word and guess
    int pos; // position variable 
    int correct; // (NEW) variable for correct letter for suggestions
    int total =0; // (NEW) variable for total number of sugguestions available for guess
    
    for (int i = 0; i < lenAns; i++) // for loop going through length of random word
    {
        guessArr[i] = '-'; // setting up the blank inputs for the guessing array
    }

    for (int i = 0; i < numSuggestion; i++) // (NEW) for loop going through length of random word
    {
        strcpy(Suggestions[i],"000"); // (NEW) setting up the blank inputs for the Suggestions array (Used the string "000" for a clear output when testing)
    }

    while (attempts < MAX_ATTEMPTS) // loops while the attempts are below 5
    {
        cond=3; // setting an arbritrary val above 2
        pos=-1; // setting an arbrtrary val below 0
        printf("Attempt %d:  ",attempts+1);
        scanf("%c",&guess); // puts the char for the letter into the guess var
        while (getchar() != '\n'); // eliminates any other val in the buffer
        for (int i = 0; i < lenAns; i++){ // loops through the length of the random word
            if (guess == Answer[i] && guess != guessArr[i]){ // checks if the guess char is the same as the answer and if the same letter has been guessed before
                cond =1; // sets cond var to 1 to use later
                ALcount++; // increments the Count for All of the Letters
                guessArr[i] = guess; // puts the guess in the same location for the guessArr
                pos = i; // changes the position var to the current location which is higher than or equal to 0
            }
            else if (guess == Answer[i]) // checks if guess is already inputed
            {
                cond=2; // second case condition for same input
            }
            else
            {
                continue;
            }
        }
        if(cond == 3 && pos < 0) // checks if the condition and position value has changed and if it hasn't then does the following
        {
            for (int i = 0; i < lenAns; i++) // goes through the length of the word
            {
                printf("%c ",guessArr[i]); // prints the guessArr which has whatever was in it last
            }
            printf("\n");
            printf("Incorrect guess. Try again\n");
            ++attempts; // increments attempts after wrong guess
        }
        else if (cond ==2) // checks if the condition is 2 which shows an already input char or letter
        {
            printf("That is already an input\n");
        }
        else if (ALcount == lenAns && cond ==1) // checks to see if the number of correct letters is the same as the length and if the condition is 1 meaning the last input was correct
        {
            for (int i = 0; i < lenAns; i++)
            {
                printf("%c ",guessArr[i]); // prints the correct answer which is now in the guessArr
            }
            printf("\n");
            return true; // returns true since all the letters were guessed correctly
            break;
        }
        if (attempts == (MAX_ATTEMPTS-1)) // (NEW) if on attempt 4 which would be after the fourth attempt
        {
            for (int i = 0; i < numWords; i++) // (NEW) goes through all of the words in the txt file
            {
                if ((int)strlen(words[i]) == lenAns) // (NEW) if the word has the same length as the answer continue
                {
                    int poscond =0; // (NEW) vairble to represent positive condition to allow the code to continue
                    correct =0; // (NEW) number of correct letters for suggestions is reset to 0
                    for (int j = 0; j < lenAns; j++) // (NEW) goes through the chars of the word with the same length
                    {
                        if (words[i][j] == guessArr[j]) // (NEW) if the word has the same char placement as the guess continue
                        {
                            poscond =1; // (NEW) sets positive condtition to 1 since the if condition is true
                            correct ++; // (NEW) increases the correct letter count of the suggestion (should tell you if the position is the same as the guess)
                        }
                        else
                        {
                            continue;
                        }                        
                    }
                    if (poscond == 1 && correct == ALcount) // (NEW) condition for passing the if statement in the for loop and having the same positioning as the guessArr
                    {
                        for (int q = 0; q < numSuggestion; q++) // (NEW) goes through the numSugesstion amount of length
                        {
                            if (strcmp(Suggestions[q],words[i])==0) // (NEW) compares the suggestions with the word to confirm if the same word has been entered before when looping again
                            {
                                break;
                            }
                            else if (strcmp(Suggestions[q],"000")==0) // (NEW) sees if Suggestions element has an empty or blank ("000") input
                            {
                                strcpy(Suggestions[q],words[i]); // (NEW) copies the word into the suggesstions element
                                total++; // (NEW) increases the total number of word sugguestions available
                                break;
                            }
                            else
                            {
                                continue;
                            }
                            
                        }
                    }
                    else
                    {
                        continue;
                    }
                    
                }
                else
                {
                    continue;
                }
            }
            printf("\n");
            for (int i = 0; i < lenAns; i++)  // (NEW) loops through the guessArr
            {
                printf("%c ",guessArr[i]); // (NEW) prints the last input for the guessed values
            }
            printf("\n");
            printf("The number of possible words = %d\n",total); // (NEW) prints the number of possible words available from guessed inputs
            printf("Here is up to the first %d possible words of the guessed inputs from attempt %d \n",numSuggestion, MAX_ATTEMPTS-1);
            printf("\n");
            for (int i = 0; i < numSuggestion; i++) // (NEW) loops through the numSuggestions amount of words
            {
                if (strcmp(Suggestions[i],"000")!=0) //(NEW) compares the string to see if the suggestions array has a word or a blank of "000" and selects the word options
                {
                    printf("%s\n",Suggestions[i]); // (NEW) prints the suggestions that are words and not "000"
                }
                else
                {
                    continue;
                }
            }
        }
        else
        {
            for (int i = 0; i < lenAns; i++) // loops through the guessArr
            {
                printf("%c ",guessArr[i]); // prints out the guessArr values for the user to see the correctly guessed inputs so far
            }
            printf("\n");
        }

    }
    return false; // returns false since the letters are not all found
}