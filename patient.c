

#include "string.h"
#include "stdio.h"
#include "patient.h"

// ADD DOCUMENTATION

/********************************************************************/
void printPatient(PersonRec person)

{ // gcc -o hospital hospital.c patient.c patient.h employee.c employee.h struct.h populateRecords.c populateRecords.h

    char fullname[33]; // holds the full name with size equal to max allowed
    // print the first name and the last name to a temporary string
    sprintf(fullname, "%s %s", person.firstName, person.familyName);
    // Calculate the total cost to date, how long the patient spent in hospital
    int totalCost = person.patient.dailyCost * person.patient.numDaysInHospital;

    // Print using formatting
    printf("%-33s", fullname);                                         // occupies 33 spaces
    printf("dept:%2d ", person.patient.department);                    // occupies 2 spaces
    printf("days in hospital:%2d ", person.patient.numDaysInHospital); // occupies 2 spaces
    printf("severity:%1d ", person.patient.severity);                  // occupies 1 spaces
    printf("daily cost:%3d ", person.patient.dailyCost);               // occupies 3 spaces
    printf("total cost : %3d\n", (totalCost));                         // occupies 3 spaces
}

/********************************************************************/
void printPatients(PersonRec *person, int numRecords)
{
    printf("\nPatient List: \n");
    printf("-----------------------\n");
    // iterate through all the records
    for (int i = 0; i < numRecords; i++, person++)
    { // if the person selected is of PATIENT_TYPE, print it
        if ((*person).emplyeeOrPatient == PATIENT_TYPE)
        {
            printPatient(*person);
        }
    }
    printf("-----------------------\n");
}

/********************************************************************/
void printPatientSummary(PersonRec *person, int numRecords)
{
    // for overall summary
    int totalPatients = 0;
    float costToDate = 0.0f;
    // for print by department
    int totalPatients0 = 0;
    float dailyCost0 = 0.0f;
    float costToDate0 = 0.0f;

    int totalPatients1 = 0;
    float dailyCost1 = 0.0f;
    float costToDate1 = 0.0f;

    int totalPatients2 = 0;
    float dailyCost2 = 0.0f;
    float costToDate2 = 0.0f;

    int totalPatients3 = 0;
    float dailyCost3 = 0.0f;
    float costToDate3 = 0.0f;

    int totalPatients4 = 0;
    float dailyCost4 = 0.0f;
    float costToDate4 = 0.0f;

    int totalPatients5 = 0;
    float dailyCost5 = 0.0f;
    float costToDate5 = 0.0f;

    int totalPatients6 = 0;
    float dailyCost6 = 0.0f;
    float costToDate6 = 0.0f;

    // iterate through all the records
    for (int i = 0; i < numRecords; i++, person++)
    {
        // if the person selected is of EMPLOYEE_TYPE,
        if ((*person).emplyeeOrPatient == EMPLOYEE_TYPE)
        {
            totalPatients++;                                                                 // increment total employees
            costToDate += (*person).patient.dailyCost * (*person).patient.numDaysInHospital; // add cur patient total cost to total

            // switch statement to update each department's data
            switch ((*person).patient.department)
            { // each case updates corresponding variables to values in each dept.'s summary
            case 0:
                totalPatients0++;
                dailyCost0 += (*person).patient.dailyCost;
                costToDate0 += (*person).patient.dailyCost * (*person).patient.numDaysInHospital;

                break;
            case 1:
                totalPatients1++;
                dailyCost1 += (*person).patient.dailyCost;
                costToDate1 += (*person).patient.dailyCost * (*person).patient.numDaysInHospital;

                break;
            case 2:
                totalPatients2++;
                dailyCost2 += (*person).patient.dailyCost;
                costToDate2 += (*person).patient.dailyCost * (*person).patient.numDaysInHospital;

                break;
            case 3:
                totalPatients3++;
                dailyCost3 += (*person).patient.dailyCost;
                costToDate3 += (*person).patient.dailyCost * (*person).patient.numDaysInHospital;
                break;
            case 4:
                totalPatients4++;
                dailyCost4 += (*person).patient.dailyCost;
                costToDate4 += (*person).patient.dailyCost * (*person).patient.numDaysInHospital;
                break;
            case 5:
                totalPatients5++;
                dailyCost5 += (*person).patient.dailyCost;
                costToDate5 += (*person).patient.dailyCost * (*person).patient.numDaysInHospital;
                break;
            case 6:
                totalPatients6++;
                dailyCost6 += (*person).patient.dailyCost;
                costToDate6 += (*person).patient.dailyCost * (*person).patient.numDaysInHospital;
                break;
            }
        }
    }

    // Calculates average salary
    float avgCostToDate = costToDate / totalPatients;

    printf("Patient summary:\n");
    printf("-----------------------\n");
    printf("Total number of patients:%3d ", totalPatients);               // occupies 3 spaces
    printf("cost to-date:%10.2f ", costToDate);                           // occupies 10 spaces
    printf("average cost per patient to-date: %8.2f\n\n", avgCostToDate); // occupies 8 spaces

    printf("Summary by department:\n");
    printf("-----------------------\n");
    printf("Department[0] - patients:%2d cost to-date:%7.2f daily cost: %7.2f average daily cost per patient: %7.2f\n",
           totalPatients0, costToDate0, dailyCost0, costToDate0 / totalPatients0);
    printf("Department[1] - patients:%2d cost to-date:%7.2f daily cost: %7.2f average daily cost per patient: %7.2f\n",
           totalPatients1, costToDate1, dailyCost1, costToDate1 / totalPatients1);
    printf("Department[2] - patients:%2d cost to-date:%7.2f daily cost: %7.2f average daily cost per patient: %7.2f\n",
           totalPatients2, costToDate2, dailyCost2, costToDate2 / totalPatients2);
    printf("Department[3] - patients:%2d cost to-date:%7.2f daily cost: %7.2f average daily cost per patient: %7.2f\n",
           totalPatients3, costToDate3, dailyCost3, costToDate3 / totalPatients3);
    printf("Department[4] - patients:%2d cost to-date:%7.2f daily cost: %7.2f average daily cost per patient: %7.2f\n",
           totalPatients4, costToDate4, dailyCost4, costToDate4 / totalPatients4);
    printf("Department[5] - patients:%2d cost to-date:%7.2f daily cost: %7.2f average daily cost per patient: %7.2f\n",
           totalPatients5, costToDate5, dailyCost5, costToDate5 / totalPatients5);
    printf("Department[6] - patients:%2d cost to-date:%7.2f daily cost: %7.2f average daily cost per patient: %7.2f\n",
           totalPatients6, costToDate6, dailyCost6, costToDate6 / totalPatients6);
}

/********************************************************************/
void searchPatients(PersonRec *person, int numRecords)

{

    // add code
    char familyName[15]; // max length of family name allowed
    printf("\nEnter a family name to search for : ");
    scanf("%s", familyName); // gets input from user

    printf("\nPatient List: \n");
    printf("-----------------------\n");
    // iterate through all the records
    for (int i = 0; i < numRecords; i++, person++)
    { // if the person selected is of PATIENT_TYPE, compare inputted name
        if ((*person).emplyeeOrPatient == PATIENT_TYPE)
        {
            // compares two strings character by character. If the strings are equal, print patient
            if (strcmp(familyName, (*person).familyName) == 0)
            {
                printPatient(*person);
            }
        }
    }
}
