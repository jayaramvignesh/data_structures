#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

/*binary tree structure*/
struct binary_tree_node
{
   int data;
   struct binary_tree_node* left;
   struct binary_tree_node* right;
};

/*function to create a new binary tree node*/
struct binary_tree_node* create_new_node(int new_data)
{
   struct binary_tree_node *new_node = (struct binary_tree_node*) malloc(sizeof(struct binary_tree_node));
    new_node->data =new_data;
    new_node->left = NULL;
    new_node->right = NULL;
}

/*function to calculate height of binary tree*/
int height_tree(struct binary_tree_node* node)
{
    if(node==NULL)
	return 0;
    else
    {   
	int left_height = height_tree(node->left);
        int right_height = height_tree(node->right);

        if(left_height>right_height)	
		return (left_height+1);
        else	
	        return (right_height+1);
 
    }
}

/*function to print nodes at a given level*/
void print_given_level(struct binary_tree_node* node, int level)
{
    if(node == NULL)
	return;

    if(level == 1)
    {
	printf("%d\n",node->data);
    }    
    else if(level > 1)
    {
	print_given_level(node->left, level-1);
        print_given_level(node->right,level-1);
    }

}

/*function to print level order traversal*/
void print_level_order(struct binary_tree_node* node)
{
    int height = height_tree(node);
    
    for(int i=1; i<=height; i++)
    {
	print_given_level(node,i);
    }

}


int main()
{
   struct binary_tree_node* new_node = create_new_node(1);
   new_node->left = create_new_node(2);
   new_node->right = create_new_node(3);
   new_node->left->left = create_new_node(4);
   new_node->left->right = create_new_node(5); 

   printf("level order traversal of binary tree is\n");
   print_level_order(new_node);

   return 0;
}
