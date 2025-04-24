#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node
{
	Node* root;
	Node* left;
	Node* right;
	int data;
	int depth;
};

void tree_insert(Node** root, int n);
void binary_search(Node** pRoot, Node* insertion);
void find_max_depth(Node* root, int* max);
int get_balance_factor(Node* root);
void inorder(Node* root);

int main(int argc, char* argv[])
{
	Node* root = NULL;
	tree_insert(&root, 3);
	tree_insert(&root, 10);
	tree_insert(&root, 7);
	tree_insert(&root, 9);
	tree_insert(&root, -78);
	tree_insert(&root, 17);
	tree_insert(&root, 46);
	tree_insert(&root, 45);

	inorder(root);




	return 0;
}

void tree_insert(Node** root, int n)
{
	Node* new_node = malloc(sizeof(Node));

	if (new_node != NULL)
	{
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->data = n;
		new_node->depth = 0;
	}

	binary_search(root, new_node);
}

void binary_search(Node** pRoot, Node* insertion)
{
	if (*pRoot == NULL)
	{
		*pRoot = insertion;
		return;
	}
	else
	{
		if ((*pRoot)->data > insertion->data)
		{
			insertion->depth++;
			binary_search(&((*pRoot)->left), insertion);
		}
		else if ((*pRoot)->data < insertion->data)
		{
			insertion->depth++;
			binary_search(&((*pRoot)->right), insertion);
		}
	}
	return;
}

void inorder(Node* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d  balance factor: %d\n", root->data, get_balance_factor(root));
		inorder(root->right);
	}
}

void find_max_depth(Node* root, int* max)
{
	if (root == NULL) return;

	find_max_depth(root->left, max);
	if (root->depth > *max)
	{
		*max = root->depth;
	}
	find_max_depth(root->right, max);
}

int get_balance_factor(Node* root)
{
	int right_depth;
	int left_depth;

	if (root->left == NULL && root->right == NULL) return 0;



	if (root->left == NULL)
	{
		left_depth = root->depth;
	}
	else
	{
		find_max_depth(root->left, &left_depth);
	}

	if (root->right == NULL)
	{
		right_depth = root->depth;
	}
	else
	{
		find_max_depth(root->right, &right_depth);
	}

	return right_depth - left_depth;
}