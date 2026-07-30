#include "records.h"

int main(void)
{
    Person people[MAX_PEOPLE];
    int count = 0;
    int i;
    int j;
    int k;
    /* set all records to empty at the start */
    for (i = 0; i < MAX_PEOPLE; i++)
    {
        people[i].name[0] = '\0';

        for (j = 0; j < NUM_CURRENCIES; j++)
        {
            people[i].totals[j] = 0;

            for (k = 0; k < NUM_COINS; k++)
            {
                people[i].change[j][k] = 0;
            }
        }
    }

    /* read file data */
    readCoinFile(people, &count);
    /* calculate change for all valid totals */
    computeAllChanges(people, count);
    /* show menu */
    menuLoop(people, count);

    return 0;
}