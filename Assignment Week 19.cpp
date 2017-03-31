// Assignment Week 19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include "stdlib.h"

typedef struct 
{
	char userName[50];
	char firstName[50];
	char lastName[50];
	char displayName[50];
	char jobTitle[50];
	char dept[50];
	char officeNum[50];
	char officePhone[50];
	char mobileNum[50];
	char fax[50];
	char address[50];
	char city[50];
	char state[50];
	char zipCode[50];
	char country[50];

}contact;

int numContacts = 0;
int readFile(char *fileName);
void initialiseResults();
void printContact(contact *aContact);

contact *contacts[100];

void main()
{
	char fileName[] = "C:\\Users\\16455696\\contacts.txt";
	void initialiseResults();
	int i = 0;

	if (!readFile(fileName))
	{
		printf("File could not be opened !!\n");
	}
	
	i = 0;
	 

	
	while (contacts[i] != NULL)
	{
		printContact(contacts[i]);
		i++;
	}
}

void initialiseResults()
{
	for (int i = 0; i < 100; i++)
	{
		*(contacts + i) = NULL;
	}
}

int readFile(char *fileName)
{
	char line[300];
	char *token; 


	char delim[4] = ",";
	FILE *fptr;
	fptr = fopen(fileName, "r");
	fgets(line, 300, fptr);
	while (!feof(fptr))
	{
		fgets(line, 300, fptr);
		contacts[numContacts] = (contact *)malloc(sizeof(contact));

		token = strtok(line, delim);
		strcpy(contacts[numContacts]->userName, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->firstName, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->lastName, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->displayName, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->jobTitle, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->dept, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->officeNum, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->officePhone, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->mobileNum, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->fax, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->address, token);
		
		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->city, token);
		
		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->state, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->zipCode, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->country, token);
	
		numContacts++;

	}
	fclose(fptr);
	return 1;
}
void printContact(contact *aContact)
{

	printf("User Name: %s\nFirst Name: %s\nLast Name: %s\nDisplay Name: %s\nJob Title: %s\nDepartment: %s\nOffice Number: %s\nOffice Phone: %s\nMobile Phone: %s\nFax: %s\nAddress: %s\nCity: %s\nState: %s\nZIP Code: %s\nCountry or Region: %s\n\n\n", aContact->userName, aContact->firstName, aContact->lastName, aContact->displayName, aContact->jobTitle, aContact->dept, aContact->officeNum, aContact->officePhone, aContact->mobileNum, aContact->fax, aContact->address, aContact->city, aContact->state, aContact->zipCode, aContact->country);
}