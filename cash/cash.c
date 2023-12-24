#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // ask for the cents
    int cents = get_cents();

    // calculate the number of quarters
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // calculate the number of dimes
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // calculate the number of nickels
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // calculate the number of pennies
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // sum of coins
    int coins = quarters + dimes + nickels + pennies;

    // print total number of coins
    printf("%i\n", coins);
}

int get_cents(void)
{
    int n;
    do
    {
        n = get_int("Change owed: ");
    }
    while (n < 1);
    return n;
}

int calculate_quarters(int cents)
{
    int quarterValue = 25;

    // calculate the number of quarters
    int quarters = cents / quarterValue;

    return quarters;
}

int calculate_dimes(int cents)
{
    int dimeValue = 10;

    // calculate the number of dimes
    int dimes = cents / dimeValue;

    return dimes;
}

int calculate_nickels(int cents)
{
    int nickelValue = 5;

    // calculate the number of nickels
    int nickels = cents / nickelValue;

    return nickels;
}

int calculate_pennies(int cents)
{
    // calculate the number of pennies
    int pennies = cents % 5;

    return pennies;
}
