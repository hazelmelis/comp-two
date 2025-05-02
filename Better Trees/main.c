#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
	int data;
	Node* left;
	Node* right;
};

void tree_insert(Node** root, int item);
int identical_trees(Node* root1, Node* root2);

int main(int argc, char* argv[])
{
	Node* root1 = NULL;
	tree_insert(&root1, 6);
	tree_insert(&root1, 2);
	tree_insert(&root1, 1);
	tree_insert(&root1, 8);
	tree_insert(&root1, 20);

	Node* root2 = NULL;
	tree_insert(&root2, 6);
	tree_insert(&root2, 2);
	tree_insert(&root2, 8);
	tree_insert(&root2, 20);


	printf("%d\n", identical_trees(root1, root2));
}

void tree_insert(Node** root, int item)
{
	if (*root == NULL)
	{
		Node* new_node = malloc(sizeof(Node));
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->data = item;

		*root = new_node; 
	}
	else if ((*root)->data > item)
	{
		tree_insert(&((*root)->left), item);
	}
	else if ((*root)->data < item)
	{
		tree_insert(&((*root)->right), item);
	}

}

int identical_trees(Node* root1, Node* root2)
{
	if (root1 == NULL && root2 == NULL)
	{
		return 1;
	}
	else if (root1 == NULL || root2 == NULL)
	{
		return 0;
	}
	else
	{
		return (root1->data == root2->data && identical_trees(root1->left, root2->left) && identical_trees(root1->right, root2->right));
	}
}