// Start of the code
#include <stdio.h>
#include <math.h> // math.h library used for the power function

// main function
int main()
{
   int Default_Accounts; // int variable used to store number of accounts
   float Balance; // float variable used to store the Balance of the user's account
   float Balances[Default_Accounts]; // array of floats used to store the balances of each account
   int choice = 10; // choice variable used to move through the menu. it has a placeholder of 10 instead of a random value
   float Deposit; // float variable used to store the deposit amount from the user input
   float Withdraw; // float variable used to store user input for drawing money
   float rate; // float variable used to hold the intrest rate from the user
   int years; // int variable used to hold the number of years for the future balance operation
   float FutureBalance; // float variable used to hold the future balance result
   int AccountD=0; // int variable used as the default account to move through the array of balances
   int AccountN; // int variable used as the new account the user inputs to switch to
   int pass = 0; // pass variable used to determine if conditions are met to continue through the rest of the function

   do // Do while loop does the code first and then checks for the while condition later to see if the loop should continue
   {
    do
    {
        printf("Enter the number of bank accounts being used (ex: 5 for 5 accounts):\n");
        scanf("%d",&Default_Accounts); // uses scanf to take the user's input for the number of accounts
        
        /*It should be noted that scanf when taking in an int is able to take in floats as inputs but
        ignores their decimals which allows it to be able to still keep and use the actual integer.
        This case can be seen more clearly when switching accounts with inputs like 2.99 and is not accounted for.
        String inputs however result in a value of 0 for scanf and are accounted for by the reccomended code from the TA.*/

        if (Default_Accounts <=0) // condition for if the number of accounts is negative or 0
        {
            printf("Please Enter a valid number of accounts (ex: 1 for 1 account and 2 for 2 accounts)\n");
            pass =0; // fails the exit condition as the loop depends on pass being equal to 1
        }
        else if (Default_Accounts > 10) // another condition for if the number of accounts is more than 10 
        {
            printf("Maximum number of accounts allowed is 10\n");
            pass = 0;
        }
        else
        {
            pass = 1; // satisfies the exit condition
        }
        while (getchar() != '\n'); /* Used to eliminate unwanted inputs such as strings from the input buffer
        until the getchar reaches \n. This allows scanf to read the next input properly in the next loop.
        This code was a solution reccomended by the TA to help with the string inputs*/
    } while (pass == 0); // condition stating to continue doing the loop while pass is equal to 0 and stops when pass is 1

    do
    {
        printf("\nEnter valid Bank balance for each account\n");
        for ( int i = 0; i < Default_Accounts; i++) // for loop goes through the number of iterations starting from 0 and increasing by 1 until it reaches the number of accounts
        {
            printf("Enter balance for acccount %d\n", i+1); // prints instructions asking for the balances of each account and makes the first account number equal to 1 and not 0
            scanf("%f",&Balances[i]); // takes float input for the balance and puts it into a different part of the array for each iteration and account
            if (Balances[i] <=0) // condition for if the input is negative
            {
                printf("Error: Enter proper balance\n");
                pass = 0; // fails exit condition
                break; // exits the for loop so user has to restart right away and doesn't have to input the rest of the accounts
            }
            else
            {
                pass =1; // satisfies the exit condition
            }
        }
        Balance = Balances[AccountD]; // sets the balance equal to the first balance in the array or the default balance
        while (getchar() != '\n');
    } while (pass == 0); // loop continues until pass does not equal 0
    
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

   } while (Default_Accounts > 10 || Default_Accounts <0); // loop repeats if the number of accounts is somehow more than 10 or negative which means it won't repeat if everything before has been entered correctly
   printf("Your Accounts have been entered and balances updated\n");
   printf("Operations are done on Account 1 as a default\n"); // print statement telling the user that the menu options are done based on the balance of the first account of the array
   
   do
   {
    printf("\nSelect an operation: (Ex: 1 for Deposit) \n"); //Menu of options showing the user what to input for the different operations
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. Future Balance Using Interest Rate\n");
    printf("5. Switch Account\n");
    printf("6. Display All Balances\n");
    printf("0. exit\n");
    scanf("%d", &choice); // takes in user input as a integer using scanf and stores it in the choice variable
    
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
        case 5:
            float Temp; /*Temporary float variable used to assign the current balance to the proper account and isn't needed 
            in any other function. Its also not important for this function either however 
            it is able to showcase the operations more clearly)*/
            printf("What account number do you want to switch to? enter numbers from 1 to %d\n",Default_Accounts);
            do
            {
                if (scanf("%d", &AccountN) !=1) //user input for the account they want to go into and a condition to see if the input is invalid
                {
                    printf("Invalid account number please choose an account with the range of 1 to a maximum of %d\n",Default_Accounts);
                    pass =0;
                }
                else if (AccountN < 1) // condition for account number being below 1 which is not a valid input due to the way this variable is used
                {
                    printf("Enter account number higher than 0\n");
                    pass =0;
                }
                else if (AccountN > Default_Accounts) // condition for if the account number is more than the given number of accounts by the user
                {
                    printf("Enter accounts in the range from 1 to a maximum of %d\n", Default_Accounts);
                    pass =0;
                }
                else if (AccountN <= Default_Accounts) // condition for if the number is within the range of accounts
                {
                    Temp = Balance; // Temporary variable takes in the current balance
                    Balances[AccountD] = Temp; // updates the current account or with its current balance using the temp variable
                    Balance = Balances[AccountN-1]; // updates the current balance to be the balance of the account the user inputed
                    AccountD = AccountN-1; // updates the default account or current account to be the account the user inputed
                    printf("You are now in Account #%d with a balance of $%.2f\n",AccountN,Balance);
                    pass = 1; // satisfies the exit condition
                }
                // no else condition needed due to the other conditions handeling the valid inputs
                while (getchar() != '\n'); 
            }while (pass ==0);
            break;
        case 6: //This case shows all of the balances for each account in the array
            Balances[AccountD] =Balance; // sets the current balance which may or may not be updated by the other options into the default account location in the array
            for ( int i = 0; i < Default_Accounts; i++) // goes through a for loop of all of the accounts in the array
            {
                printf("Account #%d has a Balance of: $%.2f\n",i+1,Balances[i]); // prints the balance for each account
            }
            break;
        default: // default option if the user enters a string or wrong number
            printf("Invalid option try again\n");
    }
   } while (choice !=0); // exit condition for the menu which is the first case
}// end of the main function and code


/*
#include <stdio.h>
#include <math.h>

int main()
{
   int Default_Accounts =10;
   float Balance;
   float Balances[Default_Accounts];
   int choice = 10;
   float Deposit;
   float Withdraw;
   float rate;
   int years;
   float FutureBalance;
   int AccountD=0;
   int AccountN;
   // Pedram said not to worry about the letters that much and if you really did want to to convert the pointer value into a string find the float in there and then proceed with that as the solution

   do
   {
    printf("Enter the number of bank accounts being used (ex: 5 for 5 accounts):\n");
    scanf("%d",&Default_Accounts);
    printf("Enter valid Bank balance for each account\n");
    printf("%d\n\n",Default_Accounts);
    for ( int i = 0; i < Default_Accounts; i++)
    {
        printf("Enter balance for acccount %d\n", i+1);
        scanf("%f",&Balances[i]);
    }
    Balance = Balances[AccountD];
   } while (Default_Accounts == 0);

   printf("Your Accounts have been entered and balances updated\n");
   printf("Operations are done on Account 1 as a default\n");
   
   do
   {
    printf("\nSelect an operation:\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. Future Balance Using Interest Rate\n");
    printf("5. Switch Account\n");
    printf("6. Display All Balances\n");
    printf("0. exit\n");
    scanf("%d", &choice);
    
    switch (choice){
        case 0:
            printf("\nExiting\n");
            break;
        case 1:
            printf("Enter the Deposit amount:\n");
            scanf("%f", &Deposit);
            Balance += Deposit;
            break;
        case 2:
            printf("Enter the amount to Withdraw:\n");
            scanf("%f", &Withdraw);
            Balance -= Withdraw;
            break;
        case 3:
            printf("Your Balance is: %.2f \n", Balance);
            break;
        case 4:
            printf("Enter the interest rate as a percentage (ex: enter 5 for a rate of 5%% ):\n");
            scanf("%f",&rate);
            printf("Enter the number of years for the future balance (ex: enter 6 for 6 years of interest):\n");
            scanf("%d",&years);
            FutureBalance = Balance*(pow(1+(rate/100),years));
            printf("Your Future Balance after %d year(s) with a rate of %.2f%% will be  $%.2f\n",years,rate,FutureBalance);
            break;
        case 5:
            float Temp;
            printf("What account number do you want to switch to? enter numbers from 1 to %d\n",Default_Accounts);
            scanf("%d",&AccountN);
            // put an if statement to catch inputs that are below or over range of default accounts
            Temp = Balance;
            Balances[AccountD] = Temp;
            Balance = Balances[AccountN-1];
            AccountD = AccountN-1;
            printf("You are now in Account #%d with a balance of %.2f\n",AccountN,Balance);
            break;
        case 6:
            Balances[AccountD] =Balance;
            for ( int i = 0; i < Default_Accounts; i++)
            {
                printf("Account #%d has a Balance of: %.2f\n",i+1,Balances[i]);   
            }
            break;
        default:
            printf("Invalid option try again\n");
    }
   } while (choice !=0); 

}
*/
