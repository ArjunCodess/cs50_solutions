#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for startPopulation size - DONE
    int startPopulation;
    do {
      startPopulation = get_int("Start Population Size: ");
    } while (startPopulation < 9); // least value should be 9

    // TODO: Prompt for endPopulation size - DONE
    int endPopulation;
    do {
      endPopulation = get_int("End Population Size: ");
    } while (endPopulation < startPopulation); // least value should be the start population

    // TODO: Calculate number of years until we reach threshold - DONE
    int n = 0; // where n = years it will take the population to grow from startPopulation to endPopulation

    // simple loop
    // everytime it runs it adds some population to the startPopulation variable till endPopulation is greater than startPopulation
    // and increases the value of n by 1
    while (startPopulation < endPopulation) {
        int born = startPopulation / 3;
        int die = startPopulation / 4;
        startPopulation += (born - die);
        n++;
    }

    // TODO: Print number of years - DONE
    printf("Years: %i \n", n);
}

// Original Code written by Arjun Vijay Prakash
// https://arjundev-portfolio.vercel.app/