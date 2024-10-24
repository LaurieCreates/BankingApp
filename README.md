# **BankingApp**
This app allows users to:
 1) Enter an initial investment amount
 2) Enter a monthly deposit amount
 3) Enter an annual interest amount (compounded)
 4) Enter the number of months for investment

A nice feature of this app is that a user does not have to enter an additional monthly deposit amount and may choose to only make an initial deposit.
The simple display will show the user's year end balance as well as display the interest earned on both the initial deposit and any recurring deposit amount entered.

This project was made in Visual Studio.

**Main Component**:
Running "AirgeadBanking.cpp" will execute the main function.

**Additional Information**: 

This is a simple program which can be expanded upon.

There are three main files containing the variables & methods used. For each file there also exists a header file with the same name (the only diffenece is the file type .h).

1) "display.cpp" - This file is for the display
2) "reportAdditionalDep.cpp" - This file contains logic for calculating and displaying recurring monthly deposits
3) "reportNoAddtionalDep.cpp" - - This contains logic for calculating and displaying when a user chooses not to add a recurring monthly deposits but invests and intitial deposit only.

**Recent Improvements**:
1) 10/24/24 - Updated display format to use setw instead of hard coded spacing.

**Areas to Improve**:

1) Adding documentation for methods
2) Expanding the program
3) Validate user input
4) No Unit tests currently

**Challenges**:
1) I found it difficult to code how to calculate the interest. I first had to do it out by hand on paper and check that it made sense. Once I got the numbers working, I wrote the pseudo code for it and then coded and checked as I went looking for a few edge cases.
2) I also found the formatting difficult. I would have liked to make a table instead, but went with what I knew how to do first to make it work.
3) I was not used to the naming conventions of using variable and member naming such as "m_balance" or "t_balance" so I had to pay careful attention to detail there.
