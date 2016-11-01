#include <stdio.h>

//Kjekt å prototype funksjoner
int returnNumberLines ( FILE *handledFiles );

int main(int argc, char *argv[]) {

    //TODO - Endre dette slikt at den tar argument fra terminal når man kjører programmet
    char fileName[] = "/home/labbetuss/Desktop/prog-in-z-innlevering1/files/all.txt";
    char buffer[255];
    FILE *file = fopen(fileName, "r");

    //Sjekke at fopen greide å åpne filen
    if(file == NULL) {
        printf("fopen() greide ikke å åpne filen du spesifiserte - %s", fileName);
        return 1;
    }


    // En seksjon med litt testing for moro skyld
    {

        int test = 0;

        //La oss prøve å printe shit ut
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("%d Lines has been read: The name is: %s", test, buffer);
            test++;
        }
    }


    printf("%d", returnNumberLines(file));

    return 0;
}

//
int returnNumberLines ( FILE *handledFiles ) {

    char buffer[255];
    int lines = 0;
    rewind(handledFiles);
    while (fgets(buffer, sizeof(buffer), handledFiles)) {
        lines++;
    }

    return lines;
}