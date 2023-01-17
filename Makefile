hospital: hospital.o employee.o patient.o populateRecords.o
	gcc -o hospital hospital.o employee.o patient.o populateRecords.o

hospital.o: hospital.c
	gcc -c hospital.c

patient.o: patient.c
	gcc -c patient.c

employee.o: employee.c
	gcc -c employee.c

populateRecords.o: populateRecords.c
	gcc -c populateRecords.c

clean:
	rm -f *.o er.out