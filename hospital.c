

#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "string.h"
#include "populateRecords.h"
#include "patient.h"
#include "employee.h"
#include <ctype.h>
#include "helperFunctions.h"

#define NUM_RECORDS 20

int main(int argc, char *argv[])
{
	struct person *person = NULL;
	int numRecords = 0; // number of records to be created
	char rc = 0;

	// check the command line parameters for correct number of paramaters
	printf("Program name %s\n", argv[0]);

	if (argc == 2) // add code to get the number of records to be created
	{
		printf("The argument supplied is %s\n", argv[1]);
		numRecords = atoi(argv[1]); // sets numrecords to user input

		if (atoi(argv[1]) > 20) // if the number is wrong prompt for correct usage and quit
		{
			printf("Argument went above the maximum amount of records (20).\nInvoking the program: program_name number_of_records\nFor example: hospital 20\n");
			return -1;
		}
		if (numRecords == 0) // if input is 0
		{
			printf("Argument was 0 or not a number, No records will be created.\n");
			return 0;
		}
		printf("Number of records to create is %d\n", numRecords);
	}
	else if (argc > 2) // if user imputted more than one argument
	{
		printf("Too many arguments supplied.\n\nInvoking the program: program_name number_of_records\nFor example: hospital 20\n");
		return -1;
	}
	else // if number of records is not given then insruct the user what is required.
	{
		printf("One argument expected.\nInvoking the program: program_name number_of_records\nFor example: hospital 20\n");
		return -1;
	}

	// allocate memory to create as many persons as determined by the user
	person = (struct person *)malloc(numRecords * sizeof(struct person));
	// populate the array by invoking the function populateRecords()
	populateRecords(person, numRecords);
	// release the memory before the program terminates
	free(person);

	// add code here for menu handling
	while (1)
	{
		// Create a menu function that will allow the user to manipulate the lists.
		int userChoice = menu();

		switch (userChoice)
		{
		case 1:
			// Print all employees
			printEmployees(person, NUM_RECORDS);
			break;
		case 2:
			// Print all patients
			printPatients(person, NUM_RECORDS);
			break;
		case 3:
			// Search for all patients by Family Name
			searchPatients(person, NUM_RECORDS);
			break;
		case 4:
			// Summary of employees data
			printEmployeesSummary(person, NUM_RECORDS);
			break;
		case 5:
			// Summary of patients data
			printPatientSummary(person, NUM_RECORDS);
			break;
		case 6:
			// Size of structures (PersonRec, PatientRec, and EmployheeRec)
			printSizeOfStructures();
			break;
		case 0:
			// Quit the program
			quitProgram();
			break;
		}
	}
	return 0;
}
int menu()
{
	int userChoice;
	// options for user to select
	printf("\n(1) Print all employees\n");
	printf("(2) Print all Patients\n");
	printf("(3) Search patients by family name\n");
	printf("(4) Summary of employee data\n");
	printf("(5) Summary of patient data\n");
	printf("(6) Size of structures (PersonRec, PatientRec, and EmployeeRec)\n");
	printf("(0) Quit \n");
	printf("\n Please enter an option:\n");
	// retrieves user input
	scanf("\n %d", &userChoice);
	// checks if input is valid

	if (userChoice < 0 || userChoice > 6)
	{
		// forces user to enter valid option
		printf("\nSorry that is not a valid option. Please try again\n");
		menu();
	}
	else
	{
		return userChoice;
	}
}

int quitProgram()
{
	char userChoice;
	// gets input from user to confirm
	printf("\n Are you sure you want to quit (y/n) \n");
	scanf("\n %c", &userChoice);

	// Check for uppercase or lowercase then flag variables
	if (userChoice == 'y' || userChoice == 'Y')
	{
		exit(0); // exits program
	}
	else if (userChoice == 'n' || userChoice == 'N')
	{
		return 0;
	}
	else
	{ // non valid input
		printf("\nSorry that is not a valid option. Please try again\n");
		quitProgram();
	}
}

// This function prints the size of each struct
void printSizeOfStructures()
{
	printf("\nSize of structures:\n");
	printf("-----------------------------\n");
	printf("Size of PersonRrect = %ld bytes\n", sizeof(PersonRec));
	printf("Size of PatientRrect = %ld bytes\n", sizeof(PatientRec));
	printf("Size of EmployeeRrect = %ld bytes\n", sizeof(EmployeeRec));
	printf("-----------------------------\n\n");
}
