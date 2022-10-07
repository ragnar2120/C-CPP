#include<stdio.h>
#include <stdlib.h>
#define size 10
int x[size];
int top =-1;
void push(int a){
    if (top == size-1){
        printf("Stack Full");
    }
    else{
        x[++top]=a;
        printf("top : %d",x[top]);
    }
}
int pop(){
    int po=-1;
    if(top== -1){
        printf("Empty Stack");
    }
    else{
        po=x[top--];
    }
    return po;
}
int peek(){
    int pk=-1;
    if(top== -1){
        printf("Empty Stack");
    }
    else{
        pk=x[top];
    }
    return pk;

}
void display(){
    if(top== -1){
        printf("Empty Stack");
    }
    else{
        for(int i=0;i<=top;i++){
            printf("%d",x[i]);
        }
    }
}
/*
int main()
{
    int ch,el;
    do
    {
    printf("\nEnter Your Choice \n 1 : Push \n 2 : Pop \n 3 : Peek \n 4 : Display \n 5 : Exit\n");
    scanf("%d",&ch);
    switch(ch){
        case 1 :
        printf("Enter Element : ");
        scanf("%d",&el);
        push(el);
        break;
        case 2:
        printf("\n Removed element : %d",pop());
        break;
        case 3:
        printf("\n Value at top : %d",peek());
        break;
        case 4:
        printf("\n Stack elements are :");
        display();
        break;
        case 5:
        exit(0);
    }
    }while(ch!=5);
    return 0;
}
*/
