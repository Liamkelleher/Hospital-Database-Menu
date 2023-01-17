#include "employee.h"
#include "stdio.h"
#include <string.h>

// ADD DOCUMENTATION
//
void printEmployee(PersonRec person)

{
    char fullname[33]; // holds the full name with size equal to max allowed
    // print the first name and the last name to a temporary string
    sprintf(fullname, "%s %s", person.firstName, person.familyName);
    // Calculate the salary to date since the employee started
    float avgSalary = person.emp.yearsService * person.emp.salary;
    // Print using formatting
    printf("%-33s", fullname);                                // occupies 33 spaces
    printf("dept:%2d ", person.emp.department);               // occupies 2 spaces
    printf("salary:%9.2f ", person.emp.salary);               // occupies 9 spaces
    printf("position:%2d ", person.emp.position);             // occupies 2 spaces
    printf("years of service:%4d ", person.emp.yearsService); // occupies 4 spaces
    printf("salary to-date:%11.2f\n", avgSalary);             // occupies 11 spaces
}

void printEmployees(PersonRec *person, int numRecords)
{

    // add code
    printf("\nHospital Employees\n");
    printf("-----------------------\n");
    // iterate through all the records
    for (int i = 0; i < numRecords; i++, person++)
    { // if the person selected is of EMPLOYEE_TYPE, print it
        if ((*person).emplyeeOrPatient == EMPLOYEE_TYPE)
        {
            printEmployee(*person);
        }
    }
    printf("-----------------------\n");
}

void printEmployeesSummary(PersonRec *person, int numRecords)
{

    // Overall summary
    int totalEmployees = 1;
    float totalSalary = 0.0f;
    float avgSalary = 0.0f;

    // for print by position
    int totalEmployees0 = 0;
    float totalSalary0 = 0.0f;

    int totalEmployees1 = 0;
    float totalSalary1 = 0.0f;

    int totalEmployees2 = 0;
    float totalSalary2 = 0.0f;

    int totalEmployees3 = 0;
    float totalSalary3 = 0.0f;

    // iterate through all the records
    for (int i = 0; i < numRecords; i++, person++)
    {
        // if the person selected is of EMPLOYEE_TYPE,
        if ((*person).emplyeeOrPatient == EMPLOYEE_TYPE)
        {
            totalEmployees++;                    // increment total employees
            totalSalary += (*person).emp.salary; // add cur employee salary to total salary

            // switch statement to update each positions data
            switch ((*person).emp.position)
            { // each case updates corresponding variables to values in each position's summary
            case 0:
                totalEmployees0++;
                totalSalary0 += (*person).emp.salary;
                break;
            case 1:
                totalEmployees1++;
                totalSalary1 += (*person).emp.salary;
                break;
            case 2:
                totalEmployees2++;
                totalSalary2 += (*person).emp.salary;
                break;
            case 3:
                totalEmployees3++;
                totalSalary3 += (*person).emp.salary;
                break;
            }
        }
    }

    // Calculates average salary
    avgSalary = totalSalary / totalEmployees;

    printf("Overall summary:\n");
    printf("-----------------------\n");
    printf("Total number of employees:%3d ", totalEmployees); // occupies 3 spaces
    printf("total salary:%10.2f ", totalSalary);              // occupies 10 spaces
    printf("average salary: %8.2f\n\n", avgSalary);           // occupies 8 spaces

    printf("Summary by position:\n");
    printf("-----------------------\n");
    printf("Position[0] - employees:%2d total salary:%9.2f average salary: %8.2f\n",
           totalEmployees0, totalSalary0, totalSalary0 / totalEmployees0);
    printf("Position[1] - employees:%2d total salary:%9.2f average salary: %8.2f\n",
           totalEmployees1, totalSalary1, totalSalary1 / totalEmployees1);
    printf("Position[2] - employees:%2d total salary:%9.2f average salary: %8.2f\n",
           totalEmployees2, totalSalary2, totalSalary2 / totalEmployees2);
    printf("Position[3] - employees:%2d total salary:%9.2f average salary: %8.2f\n",
           totalEmployees3, totalSalary3, totalSalary3 / totalEmployees3);
}
