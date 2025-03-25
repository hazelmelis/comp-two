#include <stdio.h>
#include <stdlib.h>

typedef struct treenode treeNode;

struct treenode {
	int data;
	treeNode* left;
	treeNode* right;
};

treeNode* create(int n);
void destroy(treeNode* node);
void printPreorder(treeNode* root);
void printInorder(treeNode* root);
void printPostorder(treeNode* root);

int main(int argc, char* argv[])
{
	treeNode* n1 = create(5);
	treeNode* n2 = create(80);
	treeNode* n3 = create(34); 
	treeNode* n4 = create(9);
	treeNode* n5 = create(13);
	treeNode* n6 = create(100);
	treeNode* n7 = create(90);
	treeNode* n8 = create(7);

	n1->left = n2;
	n2->right = n3;
	n2->left = n4;
	n1->right = n5;
	n5->left = n6;
	n5->right = n7;
	n3->right = n8;
	
	printPreorder(n1);
	printf("\n");
	printInorder(n1);
	printf("\n");
	printPostorder(n1);

	destroy(n1);
	destroy(n2);
	destroy(n3);
	destroy(n4);
	destroy(n5);

	return 0;
}

treeNode* create(int n)
{
	treeNode* newNode = malloc(sizeof(treeNode));
	if (newNode != NULL)
	{
		newNode->data = n;
		newNode->left = NULL;
		newNode->right = NULL;
	}

	return newNode;
}

void destroy(treeNode* node)
{
	free(node);
}

void printPreorder(treeNode* root)
{
	if (root == NULL) return;

	printf("%d ", root->data);
	printPreorder(root->left);
	printPreorder(root->right);
}

void printInorder(treeNode* root)
{
	if (root == NULL) return;

	printInorder(root->left);
	printf("%d ", root->data);
	printInorder(root->right);
}

void printPostorder(treeNode* root)
{
	if (root == NULL) return;

	printPostorder(root->left);
	printPostorder(root->right);
	printf("%d ", root->data);
}