#include <stdio.h>

int getCurrency(void);
void setCoins(int currency, int coins[4]);
int getAmount(int currency);
void calculateCoins(int amount, int coins[4], int counts[4]);
void displayResult(int amount, int coins[4], int counts[4]);
char askContinue(void);

int main(void)
{
    int currency;
    int coins[4];
    int counts[4];
    int amount;
    char repeat;

    currency = getCurrency();
    setCoins(currency, coins);

    repeat = 'Y';

    while (repeat == 'Y')
    {
        amount = getAmount(currency);

        calculateCoins(amount, coins, counts);

        displayResult(amount, coins, counts);

        repeat = askContinue();
    }

    printf("Program finished.\n");
    return 0;
}

int getCurrency(void)
{
    int currency;

    printf("Select currency: 1-US, 2-AU, 3-Euro\n");
    scanf("%d", &currency);

    while (currency < 1 || currency > 3)
    {
        printf("Invalid choice. Enter 1, 2, or 3\n");
        scanf("%d", &currency);
    }

    return currency;
}

void setCoins(int currency, int coins[4])
{
    if (currency == 1)
    {
        coins[0] = 50;
        coins[1] = 25;
        coins[2] = 10;
        coins[3] = 1;
    }
    else if (currency == 2)
    {
        coins[0] = 50;
        coins[1] = 20;
        coins[2] = 10;
        coins[3] = 5;
    }
    else
    {
        coins[0] = 20;
        coins[1] = 10;
        coins[2] = 5;
        coins[3] = 1;
    }
}

int getAmount(int currency)
{
    int amount;

    printf("Enter amount (1 to 95):\n");
    scanf("%d", &amount);

    while (amount < 1 || amount > 95 || (currency == 2 && amount % 5 != 0))
    {
        if (amount < 1 || amount > 95)
        {
            printf("Amount must be between 1 and 95.\n");
        }
        else
        {
            printf("For AU, amount must be multiple of 5.\n");
        }

        printf("Enter amount again:\n");
        scanf("%d", &amount);
    }

    return amount;
}

void calculateCoins(int amount, int coins[4], int counts[4])
{
    int remaining = amount;
    int i;

    for (i = 0; i < 4; i++)
    {
        counts[i] = remaining / coins[i];
        remaining = remaining % coins[i];
    }
}

void displayResult(int amount, int coins[4], int counts[4])
{
    int i;

    printf("Amount: %d cents\n", amount);

    for (i = 0; i < 4; i++)
    {
        printf("%dc coin: %d\n", coins[i], counts[i]);
    }
}

char askContinue(void)
{
    char repeat;

    printf("Do you want to continue? (Y/N)\n");
    scanf(" %c", &repeat);

    while (repeat != 'Y' && repeat != 'N')
    {
        printf("Enter Y or N only.\n");
        scanf(" %c", &repeat);
    }

    return repeat;
}