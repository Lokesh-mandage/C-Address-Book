#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
  
    FILE *fp;

    fp = fopen("contacts.csv", "w");

    if(fp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fp, "%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }

    fclose(fp);

    printf("Contacts saved successfully.\n");
}

void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *fp;

    fp = fopen("contacts.csv", "r");

    if (fp == NULL)
    {
        printf("No saved contacts found.\n");
        addressBook->contactCount = 0;
        return;
    }

    addressBook->contactCount = 0;

    while (fscanf(fp, "%49[^,],%19[^,],%49[^\n]\n",
                  addressBook->contacts[addressBook->contactCount].name,
                  addressBook->contacts[addressBook->contactCount].phone,
                  addressBook->contacts[addressBook->contactCount].email) == 3)
    {
        addressBook->contactCount++;

        if (addressBook->contactCount >= MAX_CONTACTS)
        {
            break;
        }
    }

    fclose(fp);

    printf("Contacts loaded successfully.\n");
}