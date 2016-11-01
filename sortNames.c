#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Kjekt å prototype funksjoner
int returnNumberLines ( FILE *handledFiles );

char maxNameBuffer[40];
int maxNameLength = 40;

int main(int argc, char *argv[]) {

    //TODO - Endre dette slikt at den tar argument fra terminal når man kjører programmet
    char fileName[] = "/home/labbetuss/Desktop/prog-in-z-innlevering1/files/all.txt";

    FILE *file = fopen(fileName, "r");

    int numberOfNames = returnNumberLines(file);

    char **mDarray;
    mDarray = malloc(numberOfNames * sizeof(char *));



    //Sjekke at fopen greide å åpne filen
    if(file == NULL) {
        printf("fopen() greide ikke å åpne filen du spesifiserte - %s", fileName);
        return 1;
    }


    // En seksjon med litt testing for moro skyld
    {

        for (int count = 0; count <= numberOfNames; ++count) {
            mDarray[count] = malloc(maxNameLength * sizeof(char *));
            fgets(mDarray[count], maxNameLength, file);
        }

        /*
        while (fgets(mDarray, sizeof(buffer), file)) {
            printf("%d Lines has been read: The name is: %s", test, buffer);
            test++;
        } */
    }


    printf("%d", returnNumberLines(file));

    return 0;
}

//
int returnNumberLines ( FILE *handledFiles ) {

    char buffer[255];
    int lines = 0;

    while (fgets(buffer, sizeof(buffer), handledFiles)) {
        lines++;
    }
    rewind(handledFiles);
    return lines;
}