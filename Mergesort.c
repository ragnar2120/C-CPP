
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
void merge(int * a, int st,int end,int mid) {
  int i=st;
  int j=mid+1;
  int k=0;
  int *merged;
  merged=(int*)calloc(end-st+1,sizeof(int));
  while (i<=mid && j<=end) {
    if(*(a+i)<=*(a+j)){
      *(merged+k++)=*(a+i++);
      //k++,i++;
    }
    else{
      *(merged+k++)=*(a+j++);
      //k++,j++;
    }
  }
    while (i<=mid) {
      *(merged+k++)=*(a+i++);
      //k++,i++;
    }
    while (j<=end) {
      *(merged+k++)=*(a+j++);
      //k++,j++;
    }
    for (int i = 0,j=st; i < end+1; i++,j++) {
      *(a+j)=*(merged+i);
    }


}

void mergesort(int *a,int st,int end){
  if(st<end){
    int mid=st+(end-st)/2;
    mergesort(a,st,mid);
    mergesort(a,mid+1,end);
    merge(a,st,end,mid);
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
    mergesort(ary,0,len-1);
    display(ary,len);

}
