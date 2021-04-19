#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;//self referential structure ->it is a structure which contains pointer to the structure of same type .
};
struct node *start=NULL; // Initially creating a linked list with start=NULL Start is similar to head .
struct node *CreateNode()
{
    struct node *x; // declaration of variable struct type node
    x=(struct node*)malloc(sizeof(struct node)); //Dynamically memory allocation(DMA)//malloc function will return void.
    return x;
}

struct node* Insert_at_first()
{
    struct node *NewNode,*temp;
    temp=start;  //it will store the address of  1st node.
    NewNode=CreateNode(); // Calling CreateNode() function for DMA.
    printf("Enter Data:");
    scanf("%d",&NewNode->data);// we access data members by using arrow operators
    start=NewNode ;//start will keep the address of first node of linked list
    NewNode->next=temp ;//NewNode will store the address of previous 1st node (which is stored in temp).
}

struct node* Delete_at_first()
{
    struct node *temp;
    temp=start;  //it will store the address of  1st node.
    start=start->next;
    free(temp);
    return start;
}

struct node* Insert_last_node()
{
struct node *temp2,*newNode;
temp2=start;
while(temp2->next!=NULL)
{
    temp2=temp2->next;
}
newNode=CreateNode();
printf("Enter Data:");
scanf("%d",&newNode->data);// we access data members by using arrow operators
temp2->next=newNode;
newNode->next=NULL;
}
struct node* Delete_at_last()
{
    struct node *temp2;
    temp2=start;  //it will store the address of  1st node.
    //This while loop is basically used for reaching the 2nd last node of linked list
    while(temp2->next->next!=NULL)
{
    temp2=temp2->next;
}
//temp2 will be the 2nd last node of linked list
free(temp2->next); //
temp2->next=NULL;
return start;
}
void insertat_Nth_position(int pos)
{
  struct node *prev,*newNode,*Next;
  prev=start;
  while(pos-1>0)
    {
      prev=prev->next;
      pos--;
    }
    newNode=CreateNode();
    printf("Enter Data:");
    scanf("%d",&newNode->data);// we access data members by using arrow operators
    Next=prev->next;
    prev->next=newNode;
    newNode->next=Next;

    //return temp4;
};

void Delete_at_Nth_position(int pos)
{
  struct node *prev,*Next;
  prev=start;
  // Here we are storing the address of previous Node which is to be deleted
  while(pos-1>0)
    {
      prev=prev->next;
      pos--;
    }
    Next=prev->next; // Node which is to be deleted
    prev->next=Next->next;// Here we are linking
    free(Next);// Deleting the required node provided by the user.

    //return temp4;
};

int main()
{
    struct node *p,*q,*r,*temp1,*temp3,*temp5,*temp6,*temp7;
    p=Insert_at_first(); //calling Insert_at_first() for insertion of node.
    q=Insert_at_first();
    r=Insert_at_first();
    printf("data at first node is %d\n",p->data);
    printf("data at first node is %d\n",q->data);
    printf("data at first node is %d\n",r->data);
    temp1=CreateNode();
    temp1=start;
    printf("data inserted in a linked list is :\n" );
    // Traversal of linked list is :
    //it depicts the last node of linked list
    while(temp1!=NULL)
    {
       printf(" %d ->",temp1->data) ;
       temp1=temp1->next;
    }
    printf("\n");
        Insert_last_node();
    //Elements after insertion at last in a linked list
    temp3=start;
    while(temp3!=NULL)
    {
       printf(" %d->",temp3->data);
       temp3=temp3->next;
    }
    int pos;
    printf("Enter the position: \n");
    scanf("%d",&pos);
    insertat_Nth_position(pos-1);
   // printf(" \n data at given position is %d",temp5->data);
    temp5=start;
    while(temp5!=NULL)
    {
       printf(" %d->",temp5->data);
       temp5=temp5->next;
    }
    printf("\n");
 // Deleltion of first node in a linked list
    temp6=Delete_at_last();
    while(temp6!=NULL)
    {
       printf(" %d->",temp6->data);
       temp6=temp6->next;
    }
    int pos1;
    printf("\n Enter the position to be deleted \n");
    scanf("%d",&pos1);
    Delete_at_Nth_position(pos1-1);
    temp7=start;

    while(temp7!=NULL)
    {
       printf(" %d->",temp7->data);
       temp7=temp7->next;
    }

    return 0;
}
