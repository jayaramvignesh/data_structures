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

    return new_node;
}

/*function for inorder traversal*/
void in_order_print(struct binary_tree_node* node)
{
    if(node == NULL)
	return;
    
    in_order_print(node->left);   //traverse the left sub tree
    printf("%d\n",node->data);    // visit the root
    in_order_print(node->right);  // traverse the right sub tree

}

/*function for preorder traversal*/
void pre_order_print(struct binary_tree_node* node)
{
    if(node == NULL)
	return;

    printf("%d\n",node->data);    //visit the root
    pre_order_print(node->left);  //traverse the left sub tree
    pre_order_print(node->right); //traverse the right sub tree

}

/*function for post order traversal*/
void post_order_print(struct binary_tree_node *node)
{
     if(node == NULL)
	return;

     post_order_print(node->left);  //traverse the left sub tree
     post_order_print(node->right); //traverse the right sub tree
     printf("%d\n",node->data);     //visit the root
	
}

int main()
{
   struct binary_tree_node* new_node = create_new_node(1);
   new_node->left = create_new_node(2);
   new_node->left->left = create_new_node(4);
   new_node->left->right = create_new_node(5); 
   new_node->right = create_new_node(3);
  // new_node->right->right = create_new_node(6); 
  // new_node->right->left = create_new_node(7);
 
  printf("\nPreorder traversal of binary tree is \n");
  pre_order_print(new_node);
 
  printf("\nInorder traversal of binary tree is \n");
  in_order_print(new_node);  
 
  printf("\nPostorder traversal of binary tree is \n");
  post_order_print(new_node);
   return 0;
}
