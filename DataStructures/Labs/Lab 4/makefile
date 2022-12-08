  
bstOperations: driver.o BST.o mattBST.o   
	gcc driver.o BST.o mattBST.o -o bstOperations 
driver.o: driver.c BST.h mattBST.h   
	gcc -c driver.c
BST.o: BST.c BST.h mattBST.h
	gcc -c BST.c  
mattBST.o: mattBST.c mattBST.h BST.h
	gcc -c mattBST.c  
clean:
	rm *.o bstOperations