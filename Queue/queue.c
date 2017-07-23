#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* Create_queue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0; 
    queue->rear = capacity - 1;  
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

int queue_full(struct Queue* queue)
{
    if(queue->size == queue->capacity)
    {
	printf("queue is full");
	return 1;
    }
    else
    {
	return 0;
    }
}

int queue_empty(struct Queue* queue)
{
    if(queue->size == 0)
    {
	printf("queue is empty");
	return 1;
    }
    else
    {
	return 0;
    }
}

void queue_add(struct Queue* queue, int data)
{
    if(queue_full(queue))
    {
	return ;
    }
  
    queue->rear = ((queue->rear)+1)%(queue->capacity);
    queue->array[queue->rear] = data;
    queue->size +=1;
    printf("Item added in the queue is %d\n",data);
}

int queue_remove(struct Queue* queue)
{
    int removed_item;

    if(queue_empty(queue))
    {
	return INT_MIN;
    }

    removed_item = queue->array[queue->front];
    queue->front = ((queue->front)+1)%(queue->capacity);
    queue->size -=1;
    printf("Item removed from the queue is %d\n",removed_item);
    return removed_item;
}


int queue_front(struct Queue *queue)
{
    if(queue_empty(queue))
	return INT_MIN;
    return queue->array[queue->front];
}

int queue_rear(struct Queue *queue)
{
    if(queue_empty(queue))
	return INT_MIN;
    return queue->array[queue->rear];
}

int main()
{

    struct Queue* queue = Create_queue(1000);
    queue_add(queue,10);
    queue_add(queue,20);
    queue_add(queue,30);
    queue_add(queue,40);
    queue_add(queue,50);
    
    int removed_item = queue_remove(queue);
    printf("removed item is %d\n",removed_item);

   int front_item = queue_front(queue);
   printf("front item is %d\n",front_item); 

   int rear_item = queue_rear(queue);
   printf("rear item is %d\n",rear_item); 

   return 0;
}
