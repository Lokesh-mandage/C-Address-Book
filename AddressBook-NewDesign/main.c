#include <stdio.h>
#include "contact.h"

int main()
{
    int choice;
    AddressBook A1;
    initialize(&A1);

    do
    {
        printf("\nAddressbook Menu\n");
        printf("1. Create Contact\n");
        printf("2. Search Contact\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. List all Contact\n");
        printf("6. Save Contact\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Select Create contact\n");
                createContact(&A1);
                break;

            case 2:
                printf("Select Search contact\n");
                searchContact(&A1);
                break;

            case 3:
                printf("Select Edit contact\n");
                editContact(&A1);
                break;

            case 4:
                printf("Select Delete contact\n");
                deleteContact(&A1);
                break;

            case 5:
                printf("Select List contact\n");
                listContacts(&A1);
                break;

            case 6:
                printf("Select Save contact\n");
                saveAndExit(&A1);
                break;

            case 7:
                printf("Exit application\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 7);

    return 0;
}