#include "records.h"

/* This function shows the details of one customer. */
void displayPersonData(Person people[], int count, char name[])
{
    int personIndex;
    int i;
    int coins[NUM_COINS];
    char currencyNames[NUM_CURRENCIES][5] = {"US$", "AU$", "EUR"};

    personIndex = findPersonIndex(people, count, name);
    /* if the name does not exist, show not found */
    if (personIndex == -1)
    {
        printf("Name: %s\n", name);
        printf("Not found\n");
        return;
    }

    printf("Customer:\n");

    for (i = 0; i < NUM_CURRENCIES; i++)
    {
        if (people[personIndex].totals[i] <= 0)
        {
            continue;
        }
        /* get coin values for the current currency */
        setCoins(i, coins);

        printf("%s %d cents in %s\n",
            people[personIndex].name,
            people[personIndex].totals[i],
            currencyNames[i]);

        printf("Change:\n");

        if (people[personIndex].change[i][0] > 0)
        {
            printf("%d cents: %d\n", coins[0], people[personIndex].change[i][0]);
        }

        if (people[personIndex].change[i][1] > 0)
        {
            printf("%d cents: %d\n", coins[1], people[personIndex].change[i][1]);
        }

        if (people[personIndex].change[i][2] > 0)
        {
            printf("%d cents: %d\n", coins[2], people[personIndex].change[i][2]);
        }

        if (people[personIndex].change[i][3] > 0)
        {
            printf("%d cents: %d\n", coins[3], people[personIndex].change[i][3]);
        }

        printf("\n");
    }
}