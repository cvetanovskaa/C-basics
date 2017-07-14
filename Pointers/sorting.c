/*
Merging two arrays of integers sorted in ascending order into a sorted array.
*/

#include <stdio.h>
#define MAX 400


void sort(int *a, int n) {
    int i,j;
    for(i=0; i<n; i++) {
        for(j=0; j<n-1; j++) {
            if(*(a+j)>*(a+j+1)) {
                int s;
                s=*(a+j);
                *(a+j)=*(a+j+1);
                *(a+j+1)=s;
            }
        }
    }
}

void merge(int *a, int *b, int *c, int n) {
int i = 0, j = 0, m = 0;
while (i < n&&j < n) {
if (*(a+i) < *(b+j))
c[m++] = a[i++];
else
c[m++] = b[j++];
}
int l;
if (i < n) {
for (l = i; l < n; l++) {
(c+m) = *(a+l);
      m++;}
}
} else {
    for (l = j; l < n; l++){
        *(c+m) = *(b+l);
    m++;}
}



int main() {
    int n;
    int a[MAX];
    int b[MAX];
    int c[MAX];
    scanf("%d", &n);
    int i;
    for(i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    sort(a, n);
    sort(b, n);
    merge(a, b, c, n);
    for(i = 0; i < 2*n; ++i) {
        printf("%d ", c[i]);
    }
    return 0;
}
