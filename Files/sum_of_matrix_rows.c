/*
It reads the elements of one matrix from text file "matrica.txt".
In the first row of the file are written the numbers of rows and columns, and then the elements of the matrix.
The program computes the sum of each row and if it's larger than 10 it writes that in the text file "izlez.txt".
*/

#include <stdio.h>

void writeToFile() {
    FILE *f = fopen("matrica.txt", "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}

void printFile() {

    FILE *f=fopen("izlez.txt","r");
    char line[100];
    while(!feof(f)) {
        fgets(line,100,f);
        if (feof(f))
            break;
        printf("%s",line);
    }
    fclose(f);
}

int main() {
    writeToFile();
    int m,n;
    FILE *f=fopen("matrica.txt", "r");
    FILE *r=fopen("izlez.txt", "w");
    int sum=0;
    fscanf(f,"%d %d", &m, &n);
    int i;

    while (!feof(f)) {
        for(i=0; i<n; i++) {
            int s;
            fscanf(f,"%d", &s);
            sum+=s;
        }
        if(sum>10) {
            fprintf(r,"%d\n", sum);
        }
        sum=0;
    }

fclose(f);
fclose(r);

printFile();
return 0;
}
