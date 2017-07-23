#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

/*structure to represent stack*/
struct stack_node
{
   int data;
   struct stack_node* next;
};

/*function to creatre a new linked list node*/
struct stack_node* create_new_node(int new_data)
{
   struct stack_node* new_node = (struct stack_node*)malloc(sizeof(struct stack_node));
   new_node->data = new_data;
   new_node->next = NULL;
   return new_node;
}

/*function to check if stack is empty*/
int stack_empty(struct stack_node *root)
{
  if(root == NULL)
  {
    printf("Stack is empty\n");
    return 1;
  }
  else
  {
    return 0;
  }
}

/*function to push value onto the stack*/
void stack_push(struct stack_node **root, int new_data)
{
  struct stack_node* new_node = create_new_node(new_data);
  new_node->next = *root;
  *root = new_node;
  printf("%d is pushed to stack\n",new_data);
}

/*function to pop values from stack*/
int stack_pop(struct stack_node **root)
{
  if(stack_empty(*root))
  {
    return INT_MIN;
  }
 
  int removed_item;
  struct stack_node *temp = *root;
  removed_item = temp->data;
  *root = (*root)->next;
  free(temp);
 
  return removed_item;
}

/*function to get the top item of stack*/
int stack_top(struct stack_node *root)
{
  if(stack_empty(root))
  {
    return INT_MIN;
  }
 
  int top_value = root->data;
  return top_value; 
}

/*function to print stack*/
void print_stack(struct stack_node *root)
{
  if(stack_empty(root))
  {
    return;
  }
 
  struct stack_node* temp = root;
  while(temp != NULL)
  {
    printf("%d\n",temp->data);
    temp= temp->next;
  }  
}

int main()
{
  struct stack_node* root = NULL;
  int removed_item = 0;
  int top_item = 0;
  removed_item = stack_pop(&root);
  stack_push(&root,10);
  stack_push(&root,20);
  stack_push(&root,30);
  stack_push(&root,40);
  stack_push(&root,50);

  printf("Stack list is: \n");
  print_stack(root);
 
  top_item = stack_top(root);
  printf("top element %d\n",top_item);

  removed_item = stack_pop(&root);  
  printf("item removed from stack = %d\n",removed_item);
     
  removed_item = stack_pop(&root);  
  printf("item removed from stack = %d\n",removed_item);
  
  printf("Stack list is: \n");
  print_stack(root);
 
  top_item = stack_top(root);
  printf("top element %d\n",top_item);


  return 0;
}
