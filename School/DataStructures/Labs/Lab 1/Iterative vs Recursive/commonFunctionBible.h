#ifndef COMMONFUNCTIONBIBLE_H
#define COMMONFUNCTIONBIBLE_H

int checkFileOpening(FILE*);

FILE *createOutputFilePointer(char*, FILE*);

FILE *createInputFilePointer(char*, FILE*);

void writeTime(clock_t, clock_t);

#endif