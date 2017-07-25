#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

/*binary tree structure*/
struct bst_node
{
   int data;
   struct bst_node* left;
   struct bst_node* right;
};

/*A function to create a new node*/
struct bst_node* create_new_node(int new_data)
{
   struct bst_node *new_node = (struct bst_node*) malloc(sizeof(struct bst_node));
   new_node->data =new_data;
   new_node->left = NULL;
   new_node->right = NULL;
   return new_node;
}

/*function for inorder traversal*/
void in_order_print(struct bst_node* node)
{
    if(node == NULL)
	return;
    
    in_order_print(node->left);   //traverse the left sub tree
    printf("%d\n",node->data);    // visit the root
    in_order_print(node->right);  // traverse the right sub tree
}

/*function to search a gvien key in a given BST*/
struct bst_node* search_key(struct bst_node* node, int key)
{
    if(node == NULL || node->data == key)  //to check if key is at root
    {
	return node;
    }

    if(node->data < key)                   //if key is greater than root->data
    {
	return search_key(node->right,key);
    }
    
    return search_key(node->left,key);      //if key is less than root->data
}

/*function to insert a node in a binary search tree*/
struct bst_node* insert_node(struct bst_node* node, int key)
{
    if(node == NULL)
    {
	return create_new_node(key);
    }

    if(key < node->data)
    {
	node->left = insert_node(node->left, key);
    }
    else if(key > node->data)
    {
	node->right = insert_node(node->right, key);
    }

    return node;
}

/*function to get the minimum value node*/
struct bst_node* min_node_search(struct bst_node* node)
{
    struct bst_node* current = node;
    while(current->left != NULL)
    {
      current = current->left;
    }

    return current;
}

/*function to delete a node*/
struct bst_node* delete_node(struct bst_node* root, int key)
{
    if(root == NULL)
    {
	return root;
    }

    if(key<root->data)   //if key is smaller than root, then key lies on left 
    {
	root->left = delete_node(root->left,key);
    }
    else if(key>root->data) //if key is greater than root,then key lies on right
    {
	root->right = delete_node(root->right,key);    
    }
    else                    //key is equal to root->data
    {
	/*Node with only one child or no child*/
	if(root->right == NULL)
        {
		struct bst_node* temp = root->left;
                free(root);
		return temp;
        }
        else if(root->left == NULL)
        {
		struct bst_node* temp = root->right;
                free(root);
		return temp;
        }
	
	struct bst_node* temp = min_node_search(root->right);
	root->data = temp->data;
	root->right = delete_node(root->right,temp->data);
    }

    return root;

}

int main()
{
    struct bst_node* root = NULL;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);

    printf("Inorder traversal of the given tree \n");
    in_order_print(root);
 
    struct bst_node* min_node = min_node_search(root);
    printf("\nminimum value in tree %d\n",min_node->data);

    printf("\nDelete 20\n");
    root = delete_node(root,20);
    printf("Inorder traversal of modififed tree \n");
    in_order_print(root);

    printf("\nDelete 30\n");
    root = delete_node(root,30);
    printf("Inorder traversal of modififed tree \n");
    in_order_print(root);

    printf("\nDelete 50\n");
    root = delete_node(root,50);
    printf("Inorder traversal of modififed tree \n");
    in_order_print(root);
 
    return  0;
}
