#include "records.h"
/* This function returns the index of the currency. */
int getCurrencyIndex(char currency[])
{
    if (strcmp(currency, "US$") == 0)
    {
        return 0;
    }
    else if (strcmp(currency, "AU$") == 0)
    {
        return 1;
    }
    else if (strcmp(currency, "EUR") == 0)
    {
        return 2;
    }

    return -1;
}
/* This function sets the coin values for the selected currency. */
void setCoins(int currencyIndex, int coins[])
{
    if (currencyIndex == 0)
    {
        coins[0] = 50;
        coins[1] = 25;
        coins[2] = 10;
        coins[3] = 1;
    }
    else if (currencyIndex == 1)
    {
        coins[0] = 50;
        coins[1] = 20;
        coins[2] = 10;
        coins[3] = 5;
    }
    else if (currencyIndex == 2)
    {
        coins[0] = 20;
        coins[1] = 10;
        coins[2] = 5;
        coins[3] = 1;
    }
}