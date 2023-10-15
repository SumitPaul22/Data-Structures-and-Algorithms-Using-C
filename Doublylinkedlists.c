#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node*prev;
    struct node*next;
};
struct node*start= NULL;
void create_list(int d)
{
    struct node*q,*temp;
    temp = malloc(sizeof(struct node));
    temp->data = d;
    temp->next = NULL;
    if (start==NULL)
    {
        temp->prev=NULL;
        start=temp;
    }
    else
    {
        q=start;
        while(q->next!=NULL)
            q= q->next;
        q->next=temp;
        temp->prev=q;
    }
}
void add_begin(int d)
{
    struct node*temp;
    temp = malloc(sizeof(struct node));
    temp->data=d;
    temp->next=start;
    temp->prev=NULL;
    start->prev=temp;
    start=temp;
}
void add_specific(int m,int pos)
{
    struct node*temp,*q;
    temp=malloc(sizeof(struct node));
    temp->data = m;
    q=start;
    if(pos==0)
    {
        if (start == NULL)
        {
            temp->next = NULL;
            temp->prev = NULL;
            start = temp;
        }
        else
        {
            add_begin(m);
        }
        return;
    }
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    for (int i=1;i<pos;i++)
    {
        q=q->next;
        if(q==NULL)
        {
            printf("Invalid position\n");
            return;
        }
    }
    temp->next=q->next;
    temp->prev=q; 
    q->next=temp;
    if (q->next!=NULL)
        temp->next->prev = temp;
}
void del(int m)
{
    struct node*temp,*q;
    if(start==NULL)
    {
        printf("List is empty");
        printf("\n");
        return;
    }
    if(start->data==m)
    {
        temp=start;
        start=start->next;
        if(start!=NULL)
            start->prev=NULL;
        free(temp);
        printf("\n");
        return;
    }
    q=start;
    while(q->next!=NULL)
        if(q->next->data==m)
        {
            temp=q->next;
            q->next=temp->next;
            if(temp->next!=NULL)
                temp->next->prev=q;
            free(temp);
            printf("\n");
            return;
        }
        q=q->next;
    printf("Data Not Found\n");
    printf("\n");
}
void del_specific(int pos)
{
    struct node*temp,*q;
    if(start==NULL)
    {
        printf("List is empty\n");
        printf("\n");
        return;
    }
    if(pos==0)
    {
        temp=start;
        start=start->next;
        if(start!=NULL)
            start->prev=NULL;
        free(temp);
        printf("\n");
        return;
    }
    q=start;
    for (int i=1;i<pos;i++)
    {
        q=q->next;
        if(q==NULL)
        {
            printf("Invalid position\n");
            printf("\n");
            return;
        }
    }
    temp=q->next;
    q->next=temp->next;
    if(temp->next!=NULL)
        temp->next->prev=q;
    free(temp);
    printf("\n");
}
void rev()
{
    struct node*p1,*p2;
    p1=start; 
   while(p1!=NULL && p1->next!=NULL)
   {
       p2=p1->next;
       p2->prev=p2->next;
       p2->next=p1; 
       p1=p2;
       p2=p2->prev;
   }
   start=p1;
}
void display()
{
    struct node*q;
    q=start;
    while(q!=NULL)
    {
        printf("%d",q->data);
        q=q->next;
    }
   printf("\n");
}
int main() 
{
  int choice;
  int data, position;

  do{
      printf("Options:\n");
      printf("1. Create a list\n");
      printf("2. Add an element at the beginning\n");
      printf("3. Add an element at a specific position\n");
      printf("4. Delete an element with a value\n");
      printf("5. Delete an element at a specific position\n"); // new option
      printf("6. Reverse the list\n");
      printf("7. Display the list\n");
      printf("8. Exit\n"); // shifted option
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch (choice) 
      {
          case 1:
            printf("Enter the data to be inserted in the list: ");
            scanf("%d", &data);
            create_list(data);
            printf("List created successfully\n");
            printf("\n");
            break;
          case 2:
            printf("Enter the data to be inserted at the beginning: ");
            scanf("%d", &data);
            add_begin(data);
            printf("Element added at the beginning successfully\n");
            printf("\n");
            break;
          case 3:
            printf("Enter the data to be inserted at: ");
            scanf("%d", &data);
            printf("Enter the position where the data is to be inserted at: ");
            scanf("%d", &position);
            add_specific(data, position);
            printf("Element added at position %d successfully\n", position);
            printf("\n");
            break;
          case 4:
            printf("Enter the value to be deleted from the list: ");
            scanf("%d", &data);
            del(data);
            printf("Element with value %d deleted successfully\n", data);
            printf("\n");
            break;
          case 5: // new option
            printf("Enter the position of the element to be deleted from the list: ");
            scanf("%d", &position);
            del_specific(position);
            printf("Element at position %d deleted successfully\n", position);
            printf("\n");
            break; 
          case 6:
            rev();
            printf("List reversed successfully\n");
            printf("\n");
            break;
          case 7:
            display();
            break;
          case 8: // shifted option
            exit(0);
            break;
          default:
            printf("Invalid choice\n");
            break;
      }
  }while(choice!=8); // changed condition
  printf("\nExiting the program\n"); 
  return 0;
}
