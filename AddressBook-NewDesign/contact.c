#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook)
{
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        printf("\n%s\t", addressBook->contacts[i].name);
        printf("%s\t", addressBook->contacts[i].phone);
        printf("%s", addressBook->contacts[i].email);
    }

    printf("\n------------------------------------------\n");
}

void initialize(AddressBook *addressBook)
{
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook)
{
    saveContactsToFile(addressBook);
    exit(0);

}

void createContact(AddressBook *addressBook)
{
    printf("Enter name: ");
    scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].name);

    printf("Enter phone no: ");
    scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].phone);

    printf("Enter mail id: ");
    scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].email);

    addressBook->contactCount++;

    printf("Contact created successfully.\n");
}

void searchContact(AddressBook *addressBook)
{
    char name[50];
    int found = 0;

    printf("Enter the name to search: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(name, addressBook->contacts[i].name) == 0)
        {
            printf("\nContact found:\n");
            printf("Name  : %s\n", addressBook->contacts[i].name);
            printf("Phone : %s\n", addressBook->contacts[i].phone);
            printf("Email : %s\n", addressBook->contacts[i].email);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Contact not found.\n");
    }
}

void editContact(AddressBook *addressBook)
{
    char name[50];
    int found = 0;
    int choice;

    printf("Enter the name of contact to edit: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(name, addressBook->contacts[i].name) == 0)
        {
            printf("\nContact found\n");

            printf("Current Name  : %s\n", addressBook->contacts[i].name);
            printf("Current Phone : %s\n", addressBook->contacts[i].phone);
            printf("Current Email : %s\n", addressBook->contacts[i].email);

            printf("\nWhat do you want to edit?\n");
            printf("1. Name\n");
            printf("2. Phone\n");
            printf("3. Email\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                    printf("Enter new name: ");
                    scanf(" %[^\n]", addressBook->contacts[i].name);
                    break;

                case 2:
                    printf("Enter new phone: ");
                    scanf(" %[^\n]", addressBook->contacts[i].phone);
                    break;

                case 3:
                    printf("Enter new email: ");
                    scanf(" %[^\n]", addressBook->contacts[i].email);
                    break;

                default:
                    printf("Invalid choice\n");
                    return;
            }

            printf("Contact updated successfully.\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Contact not found.\n");
    }
}

void deleteContact(AddressBook *addressBook)
{
    char name[50];
    int found = 0;

    printf("Enter the name of contact to delete: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(name, addressBook->contacts[i].name) == 0)
        {
            for (int j = i; j < addressBook->contactCount - 1; j++)
            {
                addressBook->contacts[j] = addressBook->contacts[j + 1];
            }

            addressBook->contactCount--;

            printf("Contact deleted successfully.\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Contact not found.\n");
    }
}