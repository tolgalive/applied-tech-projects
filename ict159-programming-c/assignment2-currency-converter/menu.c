#include "records.h"

/* This function shows the menu until the user exits. */
void menuLoop(Person people[], int count)
{
    int choice;
    char name[NAME_LEN];
    int ch;

    do
    {
        printf("\n1. Enter name\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        /* check if the menu choice is valid */
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid choice.\n");

            while ((ch = getchar()) != '\n' && ch != EOF)
            {
            }

            continue;
        }

        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }

        if (choice == 1)
        {
            printf("Enter name: ");
            scanf("%29s", name);

            while ((ch = getchar()) != '\n' && ch != EOF)
            {
            }
            /* show the customer data */
            displayPersonData(people, count, name);
        }
        else if (choice == 2)
        {
            /* save the results before ending the program */
            writeChangeCSV(people, count);
            printf("Program ended.\n");
        }
        else
        {
            printf("Invalid choice.\n");
        }

    } while (choice != 2);
}