  
bible: main.o recursiveBible.o iterativeBible.o commonFunctionBible.o 
	gcc main.o recursiveBible.o iterativeBible.o commonFunctionBible.o -o bible -g -O0
main.o: main.c recursiveBible.h iterativeBible.h  commonFunctionBible.h 
	gcc -c main.c
recursiveBible.o: recursiveBible.c commonFunctionBible.h
	gcc -c recursiveBible.c
iterativeBible.o: iterativeBible.c commonFunctionBible.h
	gcc -c iterativeBible.c
commonFunctionBible.o: commonFunctionBible.c commonFunctionBible.h
	gcc -c commonFunctionBible.c
clean:
	rm *.o bible