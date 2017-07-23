#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

/*Double linked list Structure*/
struct node
{
  int data;
  struct node *next; // Pointer to next node in DLL
  struct node *prev; // Pointer to previous node in DLL
};

/*Add data to empty list*/
void Empty_add(struct node** head_ref, int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node*));
    struct node* temp =*head_ref;
    new_node->data = data;
    new_node->next = *head_ref;
    new_node->prev = NULL;
    if((*head_ref)!=NULL)
     {
       temp->prev = new_node;
     }
    *head_ref = new_node;
}

/*add data after a given node*/
void add_middle(struct node* prev_node, int data)
{
    if(prev_node == NULL)
    {
        printf("previous mode cannot be NULL\n");
        return;
    }

    struct node* new_node = (struct node*)malloc(sizeof(struct node*));
    new_node->data = data;

    new_node->next = prev_node->next;
    new_node->prev = prev_node;
    struct node* next_new_node;
    next_new_node = new_node->next;
    if(new_node->next!= NULL)
    {
        next_new_node->prev = new_node;
    }
}

/*print list*/
void print_list(struct node *node)
{
    struct node *last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL)
    {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }

    printf("\nTraversal in reverse direction \n");
    while (last != NULL)
    {
        printf(" %d ", last->data);
        last = last->prev;
    }
}

int main()
{
    struct node* head = NULL;

    Empty_add(&head, 7);
    Empty_add(&head, 1);
    add_middle(head->next, 8);

    printf("Created DLL is: ");
    print_list(head);
    return 0;
}
