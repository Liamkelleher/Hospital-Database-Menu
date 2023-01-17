--------------------------------------------------------
Author:
--------------------------------------------------------
Liam Kelleher
November 2022

--------------------------------------------------------
Purpose: 
--------------------------------------------------------
A program designed for manipulating records of patients and employees in a hospital. 
Using structures and unions, the program allows any user to query the data of patients or employees to obtain some summary information. 
6 options are presented to the user, of which display unique information regarding employees and patients of the hospital. See "How to use the software" for more about functionality.
- Output formatted using printf and sprint functions 
- Using string functions (e.g., strcpy(), strcmp()) 
- Pass by reference (an address) 


--------------------------------------------------------
How the software is organized (partitioned into files):
--------------------------------------------------------

File hospital.c – containing the main program (containing main(argc, argv)) and the menu functionality. The main function is given with a function to populate the array.

File patient.c will contains all functions for handling patient records (e.g., printing data of a patient record or search a patient by name).
File patient.h will contain the prototype of the patient functions.

Files employee.c and employee.h – file employee.c will contain all functions for handling employee records (e.g., printing an employee record). 
File employee.h will contain the prototype of the employee functions. 

File struct.h – a file containing the declaration of the three structures (patient, employee and person). It also contain some #define statements for different constants.

Files populateRecords.c and populateRecords.h – are used to populate the array person.


--------------------------------------------------------
Code Compilation: 
--------------------------------------------------------
Use the makefile and type "make" in terminal within project directory


--------------------------------------------------------
Execution: 
--------------------------------------------------------
./hospital X
(X is any integer greater than 0 and less than 20)


--------------------------------------------------------
How to use the software: 
--------------------------------------------------------
To start the program, refer to compilation and execution instructions above.
Once the program has begun, you will be presented with a menu consisting of 6 options plus a 0th option.
To view what each option states, type the corresponding number in the terminal when prompted.

Each option has a unique function and goes as follows:
- 1 - Prints all employees and their individual data
- 2 - Prints all patients and their individual data
- 3 - Allows to search for a patient by last name. You will be prompted again to enter a last name. (This is case sensitive)
After entry, if it is a valid name in the system, the patients with that last name will be presented.
- 4 - Summary of all employee data will be presented, overall summary as well as summary within each position.
- 5 - Summary of all Patient data will be presented, overall summary as well as summary within each department.
- 6 - will display the sized of the structures used in the amount of bytes they take up in memory. (PersonRec, PatientRec and EmployeeRec)
- 0 - entering 0 to quit will prompt the user again to confirm decision. If confirmed, program exits, else, program continues and menu is displayed again
