
//implementation of circular queue
#include <stdio.h>
#include <stdlib.h>
#define size 5
int x[size];
int front=-1;
int rear=-1;
void enqueue(int a){
    if (front == (rear+1)%size){
        printf("Full Queue");
    }
    else{
        if (front==-1){
            front=rear=0;
        }
        else{
            rear=(rear+1)%size;
        }
        x[rear]=a;

    }
}
int dequeue(){
    int del=-1;
    if(front== -1){
        printf("Empty Queue");
    }
    else{
        del=x[front];
        x[front]=0;
        if (front==rear){
            front=rear=-1;
        }
        else{
            front=(front+1)%size;
        }
    }
    return del;
}

void display(){
  int i=0;
  if(front==-1 && rear==-1)
  {
    printf("\n Empty Queue");
  }
  else
  {int f=front;
    while(i<size)
    { i++;
      if (x[f]==0)
      continue;
      else{
      printf("%d\t", x[f]);
      f=(f+1)%size;
    }
  }
  }
}
int main()
{
    int ch,el;
    printf("\nCircular Queue\n");
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
        default:
        printf("Invalid Choice \n" );
    }
    }while(ch!=5);
    return 0;
}
