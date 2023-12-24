#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // input n
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // implement the pattern
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}