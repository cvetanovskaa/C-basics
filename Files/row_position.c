/*
For a given file "text.txt", the program will print the position of the row that contains max numbers of uppercase letters.
Max length of a row is 80 chars. If there are more than one rows with max uppercase letters, it prints the position of the first of them.

Note: Do not change functions writeToFile() and printFile().
*/

#include <stdio.h>
#include <ctype.h>

void writeToFile() {
    FILE *f = fopen("text.txt", "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    writeToFile();
    int counter=0;
    int MaxCounter=0;
    int rows=0;
    FILE *f=fopen("text.txt", "r");
    char array[80];
    int NumberofRows=1;
    int i;
    while(!feof(f)) {
    fgets(array, 80, f)!=NULL;
            for(i=0; i<strlen(array)-1; i++) {
                if(isupper(array[i])) {
                    counter++;
                }
            }
            if(counter>MaxCounter) {
                MaxCounter=counter;
                rows=NumberofRows;
            }
            NumberofRows++;

        counter=0;}

    printf("%d", rows);


}
