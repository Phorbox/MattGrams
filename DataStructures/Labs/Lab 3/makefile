  
postFixCalculator: main.o postFix.o fileIn.o  
	gcc main.o postFix.o fileIn.o  -o postFixCalculator 
main.o: main.c postFix.h fileIn.h   
	gcc -c main.c
postFix.o: postFix.c postFix.h
	gcc -c postFix.c 
fileIn.o: fileIn.c fileIn.h 
	gcc -c fileIn.c  
clean:
	rm *.o postFixCalculator