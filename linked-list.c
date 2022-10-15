/******************************************************************************

                      IMPLEMENTATION OF LINKED LIST

*******************************************************************************/

#include "stdio.h"
#include "stdlib.h"
struct Node {
  int data;
  struct Node * next;
};

struct Node *start =NULL;

void insert_node_front(int a){
  struct Node *n =(struct Node *)calloc(1,sizeof(struct Node));
  n->data=a;
  if(start==NULL){
    n->next=NULL;
    start=n;
  }
  else{
    n->next=start;
    start=n;
  }
}

void insert_node_rear(int a){

  struct Node *t =start;
  struct Node *n =(struct Node *)calloc(1,sizeof(struct Node));
  n->data=a;
  n->next=NULL;
  if(start==NULL){
    start=n;
  }
  else{
    while(t->next!=NULL){
      t=t->next;
    }
    t->next=n;
  }
}

int delete_node_front(){
  int del;
  struct Node *t =start;
  if (start==NULL){
    printf("No Element in Linked List \n");
  }
  else{
    del=t->data;
    if(start->next==NULL){
      start=NULL;
      free(t);
    }
    else{
    start=start->next;
    free(t);
    }
  }
  return del;
}

int delete_node_rear(){
  int del;
  struct Node *t = start;
  struct Node *p = NULL;
  if (start==NULL){
    printf("No Element in Linked List \n");
  }
  else{
    if(start->next==NULL){
      del=start->data;
      start=NULL;
      free(t);
    }
    else{
      while(t->next!=NULL){
        p=t;
        t=t->next;
      }
      del=t->data;
      p->next=NULL;
      free(t);
    }
  }
  return del;
}

void display(){
  struct Node *t = start;
  if (start==NULL){
    printf("Linked List Empty\n");
  }
  else{
    printf("Elements are :\n");

    while(t!=NULL){
      printf("%d\t", t->data);
      t=t->next;
    }
  }
}

void insert_node_at(int a,int pos){
  if (pos==0){
    insert_node_front(a);
  }
  else{
  struct Node *t =start;
  struct Node *p =NULL;
  struct Node *n =(struct Node *)calloc(1,sizeof(struct Node));
  n->data=a;
  for (int i = 0; i < pos; i++) {
    p=t;
    t=t->next;
  }
  p->next=n;
  n->next=t;
}
}

int delete_node_at(int pos){
  int del=0;
  if (pos==0){
    del=delete_node_front();
    return del;
  }
  else{
  struct Node *t =start;
  struct Node *p =NULL;
  if (start==NULL){
    printf("No Element in Linked List \n");
  }
  else{
  for (int i = 0; i < pos; i++) {
    p=t;
    t=t->next;
  }
  del=t->data;
  p->next=t->next;
  free(t);
  }
}
  return del;
}

int delete_node(int val){
  int del;
  if (start->data==val){
    del=delete_node_front();
  }
  else{
  struct Node *t =start;
  struct Node *p =NULL;
  if (start==NULL){
    printf("No Element in Linked List \n");
  }
  else{
  while(t->data!=val) {
    p=t;
    t=t->next;
  }
  del=t->data;
  p->next=t->next;
  free(t);
  return del;
  }
}
}
void search(int a){
  struct Node *t =start;
  if (start==NULL){
    printf("Linked List Empty \n");
  }
  else{
  while(t!=NULL){
    if(t->data==a){
      printf("Element present in List \n");
      break;
    }
    else{
      t=t->next;
    }
  }
  if(t==NULL){
    printf("Element not present in List\n" );
  }
}
}


int main()
{
    int ch,el,pos;
    printf("Linked List \n");
    do
    {
    printf("\nEnter Your Choice \n 1 : Insert Node From Front \n 2 : Insert Node From Rear \n 3 : Insert Node at Position \n 4 : Delete Node From Front \n 5 : Delete Node From Rear \n 6 : Delete Node at Position \n 7 : Delete Node \n 8 : Display List Elements \n 9 : Search for Element \n 10 : Exit\n");
    scanf("%d",&ch);
    switch(ch){
        case 1 :
        printf("Enter Element : ");
        scanf("%d",&el);
        insert_node_front(el);
        break;
        case 2 :
        printf("Enter Element : ");
        scanf("%d",&el);
        insert_node_rear(el);
        break;
        case 3 :
        printf("Enter Position : ");
        scanf("%d",&pos);
        printf("Enter Element : ");
        scanf("%d",&el);
        insert_node_at(el,pos);
        break;
        case 4:
        printf("\n Removed element from Front : %d",delete_node_front());
        break;
        case 5:
        printf("\n Removed element from Rear : %d",delete_node_rear());
        break;
        case 6:
        printf("Enter Position : ");
        scanf("%d",&pos);
        printf("\n Removed element from Position : %d",delete_node_at(pos));
        break;
        case 7:
        printf("Enter Element : ");
        scanf("%d",&el);
        printf("\n Removed element from Position : %d",delete_node(el));
        break;
        case 8:
        display();
        break;
        case 9:
        printf("Enter Element to Search: ");
        scanf("%d",&el);
        search(el);
        break;
        case 10:
        exit(0);
        default:
        printf("Invalid Option\n" );
    }
  }while(ch!=10);
    return 0;
}
