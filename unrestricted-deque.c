#include <stdio.h>
#include <stdlib.h>
#define size 10
int x[size];
int front=-1;
int rear=-1;
void enqueue_rear(int a){
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
void enqueue_front(int a){
  if (rear == size-1 && front==0){
      printf("Full Queue");
  }
  else{
    if (front==-1){
      front=rear=0;
      x[rear]=a;
    }
    else if(front==0){
      for (int i = rear ; i >= 0 ; i--) {
        x[i+1]=x[i];
      }
      x[0]=a;
      rear++;
    }
    else{
      front--;
      x[front]=a;
    }
  }
}

int dequeue_front(){

  int del=-1;
  if(front== -1){
      printf("Empty Queue");
  }
  else{
      del=x[front];
      if (front==rear){
          front=rear=-1;
      }
      else{
          front++;
      }
  }
  return del;
}

int dequeue_rear(){
  int del=-1;
  if(rear== -1){
      printf("Empty Queue");
  }
  else{
      del=x[rear];
      if (front==rear){
          front=rear=-1;
      }
      else{
          rear--;
      }
  }
  return del;


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
    do
    {
    printf("\nEnter Your Choice \n 1 : Enqueue From Front \n 2 : Enqueue From Rear \n 3 : Dequeue From Front \n 4 : Dequeue From Rear \n 5 : Display\n 6 : Exit\n");
    scanf("%d",&ch);
    switch(ch){
        case 1 :
        printf("Enter Element : ");
        scanf("%d",&el);
        enqueue_front(el);
        break;
        case 2 :
        printf("Enter Element : ");
        scanf("%d",&el);
        enqueue_rear(el);
        break;
        case 3:
        printf("\n Removed element from Front : %d",dequeue_front());
        break;
        case 4:
        printf("\n Removed element from Rear : %d",dequeue_rear());
        break;
        case 5:
        printf("\n Queue elements are : ");
        display();
        break;
        case 6:
        exit(0);
        default:
        printf("Invalid Option\n" );
    }
  }while(ch!=6);
    return 0;
}
