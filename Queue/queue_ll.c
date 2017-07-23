#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

/*A linked list to store a queue entry*/
struct queue_node{
   int data;
   struct queue_node* next;
};

/*structure for queue with front and back of linked list type*/
struct queue{
   struct queue_node *front;
   struct queue_node *rear;
};


/*Function to create a new node in linked list*/
struct queue_node *create_new_node(int new_data)
{
   struct queue_node* new_node = (struct queue_node*)malloc(sizeof(struct queue_node));
   new_node->data = new_data;
   new_node->next = NULL;
   return new_node;
}	

/*function to create qempty queue*/
struct queue *create_queue()
{
  struct queue* queue = (struct queue*)malloc(sizeof(struct queue));
  queue->front = NULL;
  queue->rear = NULL;
  return queue;
}

/*function to add new data to the queue*/
void add_queue(struct queue* queue, int new_data)
{
   struct queue_node *new_node = create_new_node(new_data);
   printf("new data added to the queue is %d\n",new_data);

   // new node is both front and rear, if queue is empty
   if(queue->rear == NULL)
   {
	queue->front = queue->rear = new_node;
	return;
   }
   
  //add the new_node to the rear and modify rear
   queue->rear->next = new_node;
   queue->rear = new_node;
}

/*function to remove item from queue*/
struct queue_node* remove_queue (struct queue* queue)
{
   //check if queue is emoty
   if(queue->front == NULL)
   {
	printf("queue is empty\n");
	return NULL;
   }


   //store the node to  be removed and modify front
   struct queue_node* temp;
   temp = queue->front;
   queue->front = queue->front->next;

   //if front becomes NULL, change rear also to NULL , thus queue is empty
   if(queue->front == NULL)
	queue->rear = NULL;

   return temp;
}

void print_queue(struct queue* queue)
{
   struct queue_node* temp = queue->front;
   while(temp != NULL)
   {
	printf("%d\n",temp->data);
	temp = temp->next;
   }
}

int main()
{
  struct queue *queue = create_queue();
  add_queue(queue,1);
  add_queue(queue,2);
  add_queue(queue,3);
  add_queue(queue,4);
  add_queue(queue,5);
  add_queue(queue,6);
  printf("the items in queue are \n");
  print_queue(queue);
  struct queue_node *removed_item = remove_queue(queue);
  if(removed_item != NULL)
  {
	printf("removed item from queue is %d\n",removed_item->data);
  }

  removed_item = remove_queue(queue);
  if(removed_item != NULL)
  {
	printf("removed item from queue is %d\n",removed_item->data);
  }

  printf("the items in queue are \n");
  print_queue(queue);
 
  return 0;
}
