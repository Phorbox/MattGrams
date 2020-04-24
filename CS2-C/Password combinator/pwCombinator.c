/*
 *	Assignment 7
 *	Matthew Henderson
 *	This program lists all passwords that can meet
 *  three criteria of password length, and input characters, and numebr of input characters
 *  arg 1: Number of password options
 *  arg 2+n: Password option characters
 *  arg Last: Length of the password
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void generateLine(char*, int, char*, int);

void passwordOptionsFill(char *, int, char**);

void generateBlock(char*, int, char*, int);

int main(int argc, char *argv[])
{
    char *ptr;
    int passwordLength = strtol(*(argv+(argc-1)),&ptr,10);
    printf("Finding up to %d character long passwords",passwordLength);
    int numberOfpwOptions = strtol(*(argv+1),&ptr,10);
    printf(" with the %d following characters:",numberOfpwOptions);
    char *passwordOptions = (char *)malloc(sizeof(char) * numberOfpwOptions);
    passwordOptionsFill(passwordOptions, numberOfpwOptions, argv);
    printf("%s\n",passwordOptions);
    char *passwordOutput = (char *)malloc(sizeof(char) * passwordLength);
    generateBlock(passwordOptions, passwordLength, passwordOutput, numberOfpwOptions);
    return 0;
}

void generateLine(char *passwordOptions, int passwordLength, char *passwordOutput, int numberOfpwOptions)
{
    if (passwordLength == 0)
    {
        printf("%s\n", passwordOutput);
        return;
    }
    int optionChoice;
    for (optionChoice = 0; optionChoice < numberOfpwOptions; optionChoice++)
    {
        passwordOutput[passwordLength - 1] = *(passwordOptions + optionChoice);
        generateLine(passwordOptions, passwordLength - 1, passwordOutput, numberOfpwOptions);
    }
    return;
}

void passwordOptionsFill(char *passwordOptions, int numberOfpwOptions, char **argv)
{
    if (numberOfpwOptions > 0)
    {
        passwordOptionsFill(passwordOptions, numberOfpwOptions-1, argv);
        strncat(passwordOptions,argv[numberOfpwOptions+1],1);
    }
    return;
}

void generateBlock(char *passwordOptions, int passwordLength, char *passwordOutput, int numberOfpwOptions) {
    if (passwordLength > 0)
    {
        generateBlock(passwordOptions, passwordLength - 1, passwordOutput, numberOfpwOptions);
        generateLine(passwordOptions, passwordLength, passwordOutput, numberOfpwOptions);
    }
    return;
}