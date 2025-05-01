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

void tree_insert(Node** pRoot, int n);
void binary_search(Node** pRoot, Node* insertion);
void find_max_depth(Node* root, int* max);
int get_balance_factor(Node* root);
void check_for_balance(Node** root);
void right_rotation(Node** root);
void left_rotation(Node** pRoot);
void double_right_rotation(Node** pRoot);
void double_left_rotation(Node** pRoot);
void adjust_depths(Node* root, int depth_change);


void inorder(Node* root);
//void preorder(Node* root);

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
	check_for_balance(&root);


	/*tree_insert(&root, 7);
	tree_insert(&root, 3);
	tree_insert(&root, 10);

	tree_insert(&root, 1);

	tree_insert(&root, 8);

	tree_insert(&root, 9);*/

	/*tree_insert(&root, 10);
	tree_insert(&root, 7);
	tree_insert(&root, 12);
	tree_insert(&root, 3);
	tree_insert(&root, 9);
	tree_insert(&root, 8);
	check_for_balance(&root);*/


	inorder(root);
	//preorder(root);



	return 0;
}

void tree_insert(Node** pRoot, int n)
{
	Node* new_node = malloc(sizeof(Node));

	if (new_node != NULL)
	{
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->data = n;
		new_node->depth = 0;
	}

	binary_search(pRoot, new_node);
}

void binary_search(Node** pRoot, Node* insertion)
{
	if (*pRoot == NULL)
	{
		*pRoot = insertion;
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
		printf("%d  balance factor: %d  depth: %d\n", root->data, get_balance_factor(root), root->depth);
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

	if (root == NULL) return -777;

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

void check_for_balance(Node** root)
{
	if (*root == NULL) return; 

	check_for_balance(&((*root)->left));
	check_for_balance(&((*root)->right));

	if (get_balance_factor(*root) >= 2)
	{
		if (get_balance_factor((*root)->right) < 0)
		{
			double_left_rotation(root);
		}
		else
		{
			left_rotation(root);
		}
	}
		
	else if (get_balance_factor(*root) <= -2)
	{
		if (get_balance_factor((*root)->left) > 0)
		{
			double_right_rotation(root);
		}
		else
		{
			right_rotation(root);
		}
	}
}

void right_rotation(Node** root)
{
	Node* new_root = (*root)->left;
	new_root->depth--;
	adjust_depths(new_root->left, -1);

	Node* new_right = *root;
	new_right->depth++;
	adjust_depths(new_right->right, 1);

	new_right->left = new_root->right;

	new_root->right = new_right;
	*root = new_root;
}

void left_rotation(Node** pRoot)
{
	Node* new_root = (*pRoot)->right;
	new_root->depth++;
	adjust_depths(new_root->right, -1);

	Node* new_left = *pRoot;
	new_left->depth++;
	adjust_depths(new_left->left, 1);

	new_left->right = new_root->left;

	new_root->left = new_left;
	*pRoot = new_root;
}

void double_right_rotation(Node** pRoot)
{
	left_rotation(&((*pRoot)->left));
	right_rotation(pRoot);
}

void double_left_rotation(Node** pRoot)
{
	right_rotation(&((*pRoot)->right));
	left_rotation(pRoot);
}

void adjust_depths(Node* root, int depth_change)
{
	if (root == NULL) return; 

	root->depth += depth_change;
	adjust_depths(root->left, depth_change);
	adjust_depths(root->right, depth_change);
}

//void preorder(Node* root)
//{
//	if (root == NULL) return;
//
//	preorder(root->left);
//	preorder(root->right);
//	printf("%d\n", root->data);
//}