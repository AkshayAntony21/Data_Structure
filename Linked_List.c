#include <stdio.h>
#include <stdlib.h>

void create_node();
void display();
void create_list();
void insert_begining();
void insert_middle();
void insert_end();
void delete_begining();
void delete_middle();
void delete_end();
void insert_between();
void delete_between();
void linear_search();
void sort_list();
void reverse_list();

struct node {
  int data;
  struct node *next;
};

struct node *newnode,*temp,*temp1,*temp2;
struct node *head=NULL;

int main(){
  int n,i,o;
  printf("Enter the number of elements:");
  scanf("%d",&n);

  create_list(n);

  printf("\nchoose option:\n1.Insert at begining.\n2.Insert at middle.\n3.Insert at end.\n4.Delete from begining.\n5.Delete from middle.\n");
  printf("6.Delete from end.\n7.insert in between.\n8.Delete from between\n9.Linear search\n10.Sort linked list\n11.reverse linked list");
  printf("Option:");
  scanf("%d",&o);
  switch(o){
    case 1 :insert_begining();
            break;
    case 2 :insert_middle();
            break;
    case 3 :insert_end();
            break;
    case 4 :delete_begining();
            break;  
    case 5 :delete_middle();
            break;
    case 6 :delete_end();
            break;  
    case 7 :insert_between();
            break; 
    case 8 :delete_between();
            break; 
    case 9 :linear_search();
            break; 
    case 10:sort_list();
            break; 
    case 11:reverse_list();
            break;                                                       
  }
  display();

return 0;
}
//////////////////////////////////////////////////////////////////////
//Node creation
void create_node(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter Value:");  
    scanf("%d",&newnode->data);
    newnode->next=NULL;
}

/////////////////////////////////////////////////////////////////////
//creating linked list
void create_list(int n){
  int i;
  for(i=0;i<n;i++){
    create_node();

    if(head==NULL){
      head=newnode;
      temp=head;
    }
    else{
      temp->next=newnode;
      temp=temp->next;
    }
  }
}

////////////////////////////////////////////////////////////////////
//Dispaly linked list
void display(){
 temp=head;
 while(temp!=NULL){
  printf("%d ",temp->data);
  temp=temp->next;
 }
}
///////////////////////////////////////////////////////////////////
//insert at begining
void insert_begining(){
  create_node();
  temp=newnode;
  newnode->next=head;
  head=temp;
}
//////////////////////////////////////////////////////////////////
//insert in middle
void insert_middle(){
 int c,count=0;
 temp=head;
 while(temp!=NULL){
    temp=temp->next;
    count++;
  }
 if(count%2==0)
    c=count/2;
 else
   c=((count+1)/2)-1;
 temp1=head;
 for(int i=0;i<c;i++){
  temp2=temp1;
  temp1=temp1->next;
 }
 create_node();
 newnode->next=temp1;
 temp2->next=newnode;
}
////////////////////////////////////////////////////////////////
//insert at end
void insert_end(){
  temp=head;
  while(temp->next!=NULL){
   temp=temp->next;
  }
  create_node();
  temp->next=newnode;
}
///////////////////////////////////////////////////////
////delete form begining
void delete_begining(){
  temp=head;
  head=head->next;
  free(temp);
}
//////////////////////////////////////////////////////
/////delete form middle
void delete_middle(){
  int count=0,c;
  temp=temp1=head;
  while(temp!=NULL){
    temp=temp->next;
    count++;
  }
 if(count%2==0)
    c=count/2;
 else
   c=((count+1)/2)-1;

  for(int i=0;i<c;i++){
  temp2=temp1;
  temp1=temp1->next;
  }
 temp2->next=temp1->next;
 free(temp1);
}
/////////////////////////////////////////////////////
///delete from end
void delete_end(){
  temp1=head;
  while(temp1->next!=NULL){
    temp2=temp1;
    temp1=temp1->next;
  }
  temp2->next=NULL;
  free(temp1);
}
/////////////////////////////////////////////////////
///insert in between
void insert_between(){
  int n;
  printf("Enter the positon to insert:");
  scanf("%d",&n);
  temp1=head;
  for(int i=1;i<n;i++){
  temp2=temp1;
  temp1=temp1->next;
 }
 create_node();
 newnode->next=temp1;
 temp2->next=newnode;
}
/////////////////////////////////////////////////////
//Delete from between
void delete_between(){
  int n;
  printf("Enter the positon to delete:");
  scanf("%d",&n);
  temp1=head;
  for(int i=1;i<n;i++){
  temp2=temp1;
  temp1=temp1->next;
 }
 temp2->next=temp1->next;
 free(temp1);
}
////////////////////////////////////////////////////
//Linear search
void linear_search(){
  int k,count=0;
  printf("Enter key to search:");
  scanf("%d",&k);

  temp1=head;
  while(temp1->next!=NULL){
    count++;
    if(temp1->data==k){
      printf("Key found: %d, Positon: %d",k,count);
      break;
    }
    temp1=temp1->next;
  }
}
/////////////////////////////////////////////////
//sorting
void sort_list(){

struct node *i,*j;

for(i=head;i->next!=NULL;i=i->next){
  for(j=head;j->next!=NULL;j=j->next){
    if(j->data > j->next->data){
      int tem = j->next->data;
      j->next->data = j->data;
      j->data = tem;
    }
  }
}

}
//////////////////////////////////////////////////
//reverse a list
void reverse_list(){
  struct node *current,*next,*prev;
  current=head;
  next=prev=NULL;
  while(current!=0){
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;
  }
  head=prev;
}