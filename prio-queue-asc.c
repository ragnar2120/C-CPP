#include <stdio.h>
#include <stdlib.h>
#define size 10
int x[size];
int front=-1;
int rear=-1;
void enqueue(int a){
    if (rear == size-1){
        printf("Full Queue");
    }
    else{
        if (front==-1){
            front=rear=0;
        }
        else{
            rear++;
        }
        x[rear]=a;

    }
}
int dequeue(){
    int min=2147483647,pos=0;
    if(front== -1){
        printf("Empty Queue");
    }
    else{
      if (front==rear){
          min=x[front];
          front=rear=-1;
      }
      else{
      for (int i = front; i <=rear; i++) {
        if (min>x[i]){
          min=x[i];
          pos=i;
        }
      }
      for (int i = pos ; i < rear; i++){
        x[i]=x[i+1];
      }
      rear--;
    }
  }
    return min;
}

void display(){
    int i;
    if(front== -1){
        printf("Empty Queue");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d\t",x[i]);
        }
    }
}
int main()
{
    int ch,el;
    printf("Priority Queue Ascending Order\n");
    do
    {
    printf("\nEnter Your Choice \n 1 : Enqueue \n 2 : Dequeue \n 3 : Display \n 4 : Exit\n");
    scanf("%d",&ch);
    switch(ch){
        case 1 :
        printf("Enter Element : ");
        scanf("%d",&el);
        enqueue(el);
        break;
        case 2:
        printf("\n Removed element : %d",dequeue());
        break;
        case 3:
        printf("\n Queue elements are : ");
        display();
        break;
        case 4:
        exit(0);
    }
    }while(ch!=5);
    return 0;
}
