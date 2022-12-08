#ifndef FILEIN_H
#define FILEIN_H

int checkFileOpening(FILE *inFile);
void createOutputFilePointer(char *outputFileName, FILE *outputFile);
void createInputFilePointer(char *inputFileName, FILE *inputFile);
char *fileNameAssumption(char *name);

#endif