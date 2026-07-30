#ifndef RECORDS_H
#define RECORDS_H

#include <stdio.h>
#include <string.h>

#define MAX_PEOPLE 100
#define NAME_LEN 30
#define NUM_CURRENCIES 3
#define NUM_COINS 4

typedef struct
{
    char name[NAME_LEN];
    int totals[NUM_CURRENCIES];
    int change[NUM_CURRENCIES][NUM_COINS];
} Person;

int getCurrencyIndex(char currency[]);
void setCoins(int currencyIndex, int coins[]);
int findPersonIndex(Person people[], int count, char name[]);
void readCoinFile(Person people[], int *count);
void calculateCoins(int amount, int coins[], int counts[]);
void computeAllChanges(Person people[], int count);
void displayPersonData(Person people[], int count, char name[]);
void writeChangeCSV(Person people[], int count);
void menuLoop(Person people[], int count);

#endif