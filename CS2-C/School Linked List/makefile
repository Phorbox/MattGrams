studentsearch: main.o student.o
	gcc main.o student.o -o studentsearch
main.o: main.c student.h
	gcc -c main.c
student.o: student.c student.h
	gcc -c student.c
clean:
	rm *.o studentsearch
