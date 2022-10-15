
#include <stdio.h>
#include <stdlib.h>

void allocate(int *a,int len){
    for (int i=0;i<len;i++){
        printf("\nEnter Element :");
        scanf("%d",(a+i));
    }
}
void display(int *a,int len){
    printf("\nSorted Elements :");
    for (int i=0;i<len;i++){
        printf("\t%d",*(a+i));
    }
}

void insertionsort(int *a,int len){
  int i, key, j;
    for (i = 1; i < len; i++) {
        key = *(a+i);
        j = i - 1;
        while (j >= 0 && *(a+j) > key) {
            *(a+j + 1) = *(a+j);
            j = j - 1;
        }
        *(a+j + 1) = key;
    }
}

void main()
{
    int *ary;
    int len;
    printf("Enter Length Of Array : ");
    scanf("%d",&len);
    ary=(int*)calloc(len,sizeof(int));
    allocate(ary,len);
    insertionsort(ary,len);
    display(ary,len);

}
