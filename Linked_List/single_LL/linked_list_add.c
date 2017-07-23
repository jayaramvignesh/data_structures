#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*Structure for linked list*/
struct node{
    int data;
    struct node *next;
};

/*function to add data before head*/
void insert_before_head(struct node **pointer_head, int data_to_be_inserted)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data_to_be_inserted;
    new_node->next = *pointer_head;
    *pointer_head = new_node;
}

/*function to add data after given node*/
void insert_after_node(struct node* prev_node, int new_data)
{
    if (prev_node == NULL)
    {
      printf("the given previous node cannot be NULL");
      return;
    }
 
    struct node* new_node =(struct node*) malloc(sizeof(struct node));
 
    new_node->data  = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

/*function to add data at the end*/
void insert_end(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    struct node *last = *head_ref;  

    new_node->data  = new_data;   
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }  
     
    while (last->next != NULL)
        last = last->next;
 
    last->next = new_node;
    return;    
}

/*function to print linked list*/
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d \n", node->data);
        node = node->next;
    }
}


int main()
{   
  struct node* head = NULL;
  struct node* second = NULL;
  struct node* third = NULL;
  
  head  = (struct node*)malloc(sizeof(struct node)); 
  second = (struct node*)malloc(sizeof(struct node));
  third  = (struct node*)malloc(sizeof(struct node));
 
  head->data = 1; 
  head->next = second;   
 
  second->data = 2; 
  second->next = third;  
 
  third->data = 3; 
  third->next = NULL;

  insert_before_head(&head, 10);
  insert_before_head(&head, 20);
  insert_end(&head, 40);
  insert_end(&head, 50);
  insert_after_node(second,30);
  insert_after_node(third,60);
  printf("Created Linked List:\n ");
  printList(head);

  return 0;
}
