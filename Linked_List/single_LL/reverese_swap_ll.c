#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*linked list structure*/
struct node{
    int data;
    struct node *next;
};

/*function to reverse linked list*/
static void reverse_linked_list(struct node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

/*function to swap two given nodes*/
void swap_node(struct node** head_ref, int position_1, int position_2)
{
    if(position_1 == position_2)
        return;

    struct node* current_position_1 = *head_ref;
    struct node* previous_position_1 = NULL;

    while(current_position_1 != NULL && current_position_1->data != position_1)
    {
        previous_position_1 = current_position_1;
        current_position_1 = current_position_1->next;
    }

    struct node* current_position_2 = *head_ref;
    struct node* previous_position_2 = NULL;

    while(current_position_2 != NULL && current_position_2->data != position_2 )
    {
        previous_position_2 = current_position_2;
        current_position_2 = current_position_2->next;
    }

    if(current_position_1 == NULL || current_position_2 == NULL)
        return;

    if(previous_position_1 != NULL)
    {
        previous_position_1->next = current_position_2;
    }
    else
    {
        *head_ref = current_position_2;
    }

    if(previous_position_2 != NULL)
    {
        previous_position_2->next = current_position_1;
    }
    else
    {
        *head_ref = current_position_1;
    }

    struct node *swap;
    swap = current_position_2->next;
    current_position_2->next = current_position_1->next;
    current_position_1->next = swap;
}

/*function to insert data before head*/
void insert_before_head(struct node **pointer_head, int data_to_be_inserted)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data_to_be_inserted;
    new_node->next = *pointer_head;
    *pointer_head = new_node;
}

/*function to print list*/
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf(" %d \n", node->data);
        node = node->next;
    }
}

int main()
{
    /* Start with the empty list */
    struct node* head = NULL;

    insert_before_head(&head, 7);
    insert_before_head(&head, 6);
    insert_before_head(&head, 5);
    insert_before_head(&head, 4);
    insert_before_head(&head, 3);
    insert_before_head(&head, 2);
    insert_before_head(&head, 1);

    printf("Created Linked List:\n ");
    printList(head);

    reverse_linked_list(&head);
    printf("reversed linked list: \n");
    printList(head);    

    swap_node(&head, 1, 5);
    printf("\nLinked list after swapping positions 1 and 5\n");
    printList(head);
    return 0;
}
