#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Kjekt å prototype funksjoner
int returnNumberLines (FILE *handledFiles);
void sortNames(char** ppchNames, int iCount);

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


    for (int count = 0; count < numberOfNames; ++count) {
        mDarray[count] = malloc(maxNameLength * sizeof(char *));
        fgets(mDarray[count], maxNameLength, file);
    }


    for (int count = 0; count < numberOfNames; count++) {
        printf("%d Lines has been read: The name is: %s", count, mDarray[count]);
    }

    sortNames(mDarray, numberOfNames);

    for (int count = 0; count < numberOfNames; count++) {
        printf("%d Lines has been read: The name is: %s", count, mDarray[count]);
    }

    return 0;
}

//This genius part has no comments
int returnNumberLines(FILE *handledFiles) {

    char buffer[255];
    int lines = 0;

    while (fgets(buffer, sizeof(buffer), handledFiles)) {
        lines++;
    }
    rewind(handledFiles);
    return lines;
}

//Let's hope this shit works
void sortNames(char** ppchNames, int iCount)
{
    int i,j;
    for (j = 0; j < iCount -1; j++) {
        for (i = 0; i < iCount -1; i++) {
            if (0 < strcmp(ppchNames[i], ppchNames[i +1])) {
                char* pchTemp = ppchNames[i];
                ppchNames[i] = ppchNames[i +1];
                ppchNames[i +1] = pchTemp;
            }
        }
    }
}