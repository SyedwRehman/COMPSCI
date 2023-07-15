// Start of the code
#include <stdio.h>
#include <math.h> // math.h library used for the power function

// main function
int main()
{
   int Default_Accounts; // int variable used to store number of accounts
   float Balance; // float variable used to store the Balance of the user's account
   int choice = 10; // choice variable used to move through the menu. it has a placeholder of 10 instead of a random value
   float Deposit; // float variable used to store the deposit amount from the user input
   float Withdraw; // float variable used to store user input for drawing money
   float rate; // float variable used to hold the intrest rate from the user
   int years; // int variable used to hold the number of years for the future balance operation
   float FutureBalance; // float variable used to hold the future balance result
   int pass = 0; // pass variable used to determine if conditions are met to continue through the rest of the function
   

   do // Do while loop does the code first and then checks for the while condition later to see if the loop should continue
    {
        printf("Enter valid Bank balance\n");
        scanf("%f",&Balance); // uses scanf to take in the user input
        if (Balance != 0 && Balance >= 0) // if condition to make sure the balance is not 0 or below 0
        {
            printf("You may continue with a balance of $%.2f\n",Balance); // lets user know they are able to continue
        }
        else // else condition for non valid inputs
        {
            printf("Not Valid balance of $%.2f\n",Balance); // lets user know their input is not valid
        }
        
        while (getchar() != '\n'); /* Used to eliminate unwanted inputs such as strings from the input buffer
        until the getchar reaches \n. This allows scanf to read the next input properly in the next loop.
        This code was a solution recommended by the TA to help with the string inputs*/

   } while ( Balance <= 0); // condition makes the loop continue until the balance has a proper input that is more than 0
   
   do
    {
        printf("\nEnter intrest rate (ex: 1.45 for 1.45%%)\n");
        scanf("%f",&rate); // takes input for the intrest rate
        if (rate <=0) // condition for if the intrest rate is negative
        {
            printf("Enter a positive valid rate\n");
            pass = 0; // fails exit condition
        }
        else
        {
            pass = 1;
        }
        while (getchar() != '\n');
    } while (pass == 0);

   do
   {
    printf("\nSelect an operation: (Ex: 1 for Deposit) \n"); //Menu of options showing the user what to input for the different operations
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. Future Balance Using Interest Rate\n");
    printf("0. exit\n");
    scanf("%d", &choice); // takes in user input as a integer using scanf and stores it in the choice variable
    
    /*It should be noted that scanf when taking in an int is able to take in floats as inputs but
    ignores their decimals which allows it to be able to still keep and use the actual integer.
    String inputs result in a value of 0 for scanf and are accounted for by the recommended code from the TA.*/
    
    switch (choice){ // switches between all of the cases depending on the user's choice
        case 0: // This case allows the user to exit the loop
            printf("\nExiting\n");
            break; // break is used through out all of the cases to not follow through to the next case after finishing the first one
        case 1: // This case allows the user to Deposit an amount into their balance
            do
            {
                printf("Enter the Deposit amount:\n"); 
                scanf("%f", &Deposit); // takes in user's deposit amount
                if (Deposit <= 0) // condition to determine if the amount is negative or 0
                {
                    printf("Enter valid Deposit amount (ex: 100)\n");
                    pass = 0; // pass variable is updated to be 0 to show that the input is incorrect
                }
                else{
                    Balance += Deposit; // does the deposit operation
                    pass =1; // pass variable is updated to 1 to allow the function to continue out of the loop
                }
                while (getchar() != '\n'); 
            } while (pass != 1); // condition for the do while loop based on if the pass condition is equal to 1 or not
            break;
        case 2: // This case allows the user to withdraw an amount of money from their balance
            do
            {
                printf("Enter the Withdraw amount:\n");
                scanf("%f", &Withdraw); // takes in user's drawing amount
                if (Withdraw <= 0) // checks for amount below or equal to 0
                {
                    printf("Enter valid draw amount (ex: 100)\n");
                    pass = 0;
                }
                else if (Balance < Withdraw) // checks if the balance is less than the amount they want to withdraw which would result in a negative number
                {
                    printf("You are drawing more than your current balance of $%.2f\n",Balance);
                    pass = 0;
                }
                else if (Balance == Withdraw) // checks if the balance if equal to the withdraw amount
                {
                    printf("This would draw all your balance please enter a lower amount and try again\n");
                    pass =0;   
                }
                else
                {
                    Balance -= Withdraw; // does the withdrawing operation
                    pass =1; // pass condition makes it so that the loop ends
                }
                while (getchar() != '\n'); 
            } while (pass != 1); // condition for the loop to ask user for a correct input
            break;
        case 3: // This case checks the current balance
            printf("Your balance is: $%.2f \n", Balance); // shows the balance up to 2 decimal places
            break;
        case 4: // This case allows the user to determine their future balance
            do
            {
                printf("Enter the number of years for the future balance (ex: enter 6 for 6 years of interest):\n");
                scanf("%d",&years); // takes in the number of years from the user accepting whole numbers only
                if (years <= 0) // condition for if the number of years is negative or 0
                {
                    printf("Enter a valid number minimum of 1 year\n");
                    pass = 0;
                }
                else
                {
                    FutureBalance = Balance*(pow(1+(rate/100),years)); // Future balance operation using the pow or power function from the math.h library
                    printf("Your Future Balance after %d year(s) with a rate of %.2f%% will be  $%.2f\n",years,rate,FutureBalance); // prints the future balance for the user showing all of the important variables as well
                    pass =1; //satisfies the exit condition
                }
                while (getchar() != '\n'); 
            } while (pass == 0);
            break;
        default: // default option if the user enters a string or wrong number
            printf("Invalid option try again\n");
    }
   } while (choice !=0); // exit condition for the menu which is the first case
}// end of the main function and code
