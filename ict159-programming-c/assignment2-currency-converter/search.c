#include "records.h"
/* This function searches for a customer name in the array. */
int findPersonIndex(Person people[], int count, char name[])
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            return i;
        }
    }

    return -1;
}