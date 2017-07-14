// Efficient sorting of an array with max of 100000 elements

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void my_sort(int *x,int first,int last){
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(*(x+i)<=*(x+pivot)&&i<last)
                 i++;
             while(*(x+j)>*(x+pivot))
                 j--;
             if(i<j){
                 temp=*(x+i);
                  *(x+i)=*(x+j);
                  *(x+j)=temp;
             }
         }

         temp=*(x+pivot);
         *(x+pivot)=*(x+j);
         *(x+j)=temp;
         my_sort(x,first,j-1);
         my_sort(x,j+1,last);

    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    int *a = malloc(sizeof(int) * n);
    srand(time(NULL));
    for(i = 0; i < n; ++i) {
        a[i] = rand() % 10000;
    }


    my_sort(a,0,n);


    int sorted = 1;
    for(i = 0; i < n - 1; ++i) {
        if(a[i] > a[i + 1]) {
            sorted = 0;
            break;
        }
    }
    if(!sorted) {
        printf("NOT SORTED");
    } else {
        printf("SORTED");
    }
    free(a);
    return 0;
}
