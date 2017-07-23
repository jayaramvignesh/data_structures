#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*linked list structure*/
struct node{
    int data;
    struct node* next;
};

/*add data to empty linked list*/
struct node* Empty_add(struct node* last, int data)
{
    if(last!=NULL)
    {
        printf("List is not empty\n");
        return last;
    }

    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = data;
    last = new_node;
    last->next = last;
    return last;
};

/*function to to add data before head*/
struct node* Begin_add(struct node *last, int data)
{
    if(last == NULL)
    {
        printf("list is empty\n");
        return last;
    }

    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = last->next;
    last->next = new_node;
    return last;
}

/*function to add data at end*/
struct node* End_add(struct node* last, int data)
{
    if(last == NULL)
    {
        printf("list is empty\n");
        return last;
    }

    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = last->next;
    last->next = new_node;
    last = new_node;
    return last;
};

/*function to add data ater a given position*/
struct node* add_node_position(struct node* last, int data_to_be_added , int position_data)
{
    if(last == NULL)
    {
        printf("list is empty\n");
        return last;
    }

    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node* temp_node;

    temp_node = last->next;
    do
    {
        if(temp_node->data == position_data)
        {
         new_node->data = data_to_be_added;
         new_node->next = temp_node->next;
         temp_node->next = new_node;
         if(temp_node == last)
         {
            last = new_node;
         }
         return last;
        }

        temp_node = temp_node->next;

    } while(temp_node!=last->next);

    printf("item not present in the list\n");
    return last;
};

/*function to traverse the list and print it*/
void traverse_print_list(struct node* last)
{
    if(last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *traverse_node;
    traverse_node = last->next;
    do
    {
        printf("%d\n",traverse_node->data);
        traverse_node= traverse_node->next;
    }while(traverse_node!=last->next);
}

/*function to calculate length of linked list*/
int length_linked_list(struct node* last)
{
   if(last == NULL)
    {
        printf("List is empty\n");
        return 0;
    }

    int length = 0;
    struct node *traverse_node;
    traverse_node = last->next;
    do
    {
       length++;
       traverse_node= traverse_node->next;
    }while(traverse_node!=last->next);

    return length;
}

/*function to split linked list into two*/
void split_list(struct node* last, int length)
{
    if(last == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *traverse_node;
    traverse_node = last->next;
    if((length%2) == 0)
    {
        int half_length = length/2;
        while(half_length!= 1)
        {
            traverse_node = traverse_node->next;
            half_length--;
        }
    }
    else
    {
        int half_length = (length-1)/2;
        while(half_length!= 1)
        {
            traverse_node = traverse_node->next;
            half_length--;
        }
    }

    struct node* temp_node;
    struct node* temp1_node;
    struct node *last1_node;
    struct node *last2_node;

    temp_node = traverse_node;
    temp1_node = traverse_node->next;

    temp_node->next = last->next;
    last1_node = temp_node;
    last1_node->next = last->next;
    printf("linked list 1 after split\n");
    traverse_print_list(last1_node);

    last->next = temp1_node;
    printf("linked list 2 after split\n");
    traverse_print_list(last);
}

int main()
{
    struct node* last = NULL;
    last = Empty_add(last,30);
    last = Begin_add(last,20);
    last = Begin_add(last,10);
    last = Begin_add(last,5);
    last = End_add(last,40);
    last = add_node_position(last,25,20);
    last = add_node_position(last,45,40);
    traverse_print_list(last);
    int length;
    length = length_linked_list(last);
    printf("\nlength of linked list is %d\n", length);
    split_list(last,length);
}
