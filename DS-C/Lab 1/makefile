  
bible: main.o routeRecords.o
	gcc main.o commonFunctionBible.o iterativeBible.o recursiveBible.o -o bible
main.o: main.c commonFunctionBible.h iterativeBible.h recursiveBible.h
	gcc -c main.c
recursiveBible.o: recursiveBible.c commonFunctionBible.h
	gcc -c recursiveBible.c
iterativeBible.o: iterativeBible.c commonFunctionBible.h
	gcc -c iterativeBible.c
commonFunctionBible.o: commonFunctionBible.c commonFunctionBible.h
	gcc -c commonFunctionBible.c
clean:
	rm *.o bible