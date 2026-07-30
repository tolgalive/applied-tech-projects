#include "records.h"
/* This function calculates the number of coins for one amount. */
void calculateCoins(int amount, int coins[], int counts[])
{
    int i;

    for (i = 0; i < NUM_COINS; i++)
    {
        counts[i] = amount / coins[i];
        amount = amount % coins[i];
    }
}
/* This function calculates change for all stored customer totals. */
void computeAllChanges(Person people[], int count)
{
    int i;
    int j;
    int coins[NUM_COINS];

    for (i = 0; i < count; i++)
    {
        for (j = 0; j < NUM_CURRENCIES; j++)
        {
            if (people[i].totals[j] <= 0)
            {
                continue;
            }
            /* get the correct coin set for this currency */
            setCoins(j, coins);
            /* calculate change for the stored total */
            calculateCoins(people[i].totals[j], coins, people[i].change[j]);
        }
    }
}