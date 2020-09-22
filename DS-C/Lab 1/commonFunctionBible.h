#ifndef COMMONFUNCTIONBIBLE_H
#define COMMONFUNCTIONBIBLE_H

int checkFileOpening(FILE *inFile);

FILE *createOutputFilePointer(char *outputFileName);

FILE *createInputFilePointer(char *inputFileName);

void writeTime(clock_t start_t, clock_t end_t);

#endif