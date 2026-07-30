#include "records.h"

/* This function reads the records from coins.txt
   and stores valid customer totals. */
void readCoinFile(Person people[], int *count)
{
    FILE *infile;
    int rows;
    int i;
    int amount;
    int personIndex;
    int currencyIndex;
    int lineNumber;
    int invalidFound = 0;

    char name[NAME_LEN];
    char word1[20];
    char word2[20];
    char currency[10];
    
    /* open the input file */
    infile = fopen("coins.txt", "r");

    if (infile == NULL)
    {
        printf("Error: coins.txt could not be opened.\n");
        return;
    }
    /* read the number of records */
    fscanf(infile, "%d", &rows);
    lineNumber = 2;

    for (i = 0; i < rows; i++)
    {
        fscanf(infile, "%29s %d %19s %19s %9s", name, &amount, word1, word2, currency);
        
        /* check if the amount is valid */
        if (amount < 1 || amount > 95)
        {
            if (invalidFound == 0)
            {
                printf("The data file has incorrect values.\n");
                printf("Incorrect line numbers: %d", lineNumber);
                invalidFound = 1;
            }
            else
            {
                printf(", %d", lineNumber);
            }
        }
        else
        {
            currencyIndex = getCurrencyIndex(currency);
            personIndex = findPersonIndex(people, *count, name);
            
            /* add a new customer if the name is not found */
            if (personIndex == -1)
            {
                strcpy(people[*count].name, name);

                people[*count].totals[0] = 0;
                people[*count].totals[1] = 0;
                people[*count].totals[2] = 0;

                people[*count].change[0][0] = 0;
                people[*count].change[0][1] = 0;
                people[*count].change[0][2] = 0;
                people[*count].change[0][3] = 0;

                people[*count].change[1][0] = 0;
                people[*count].change[1][1] = 0;
                people[*count].change[1][2] = 0;
                people[*count].change[1][3] = 0;

                people[*count].change[2][0] = 0;
                people[*count].change[2][1] = 0;
                people[*count].change[2][2] = 0;
                people[*count].change[2][3] = 0;

                if (currencyIndex != -1)
                {
                    people[*count].totals[currencyIndex] = amount;
                    (*count)++;
                }
            }
            else
            {
                /* if the customer already exists, add the amount */
                if (currencyIndex != -1)
                {
                    people[personIndex].totals[currencyIndex] =
                        people[personIndex].totals[currencyIndex] + amount;
                }
            }
        }

        lineNumber++;
    }

    if (invalidFound == 1)
    {
        printf("\n");
    }

    fclose(infile);
}
/* This function writes all valid customer change data to change.csv. */
void writeChangeCSV(Person people[], int count)
{
    FILE *outfile;
    int i;
    int j;
    char currencyNames[NUM_CURRENCIES][5] = {"US$", "AU$", "EUR"};

    outfile = fopen("change.csv", "w");

    if (outfile == NULL)
    {
        printf("Error: change.csv could not be opened.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        for (j = 0; j < NUM_CURRENCIES; j++)
        {
            if (people[i].totals[j] > 0)
            {
                fprintf(outfile,
                        "%s, the change for %d cents in %s is %d,%d,%d,%d\n",
                        people[i].name,
                        people[i].totals[j],
                        currencyNames[j],
                        people[i].change[j][0],
                        people[i].change[j][1],
                        people[i].change[j][2],
                        people[i].change[j][3]);
            }
        }
    }

    fclose(outfile);
    printf("change.csv has been created.\n");
}