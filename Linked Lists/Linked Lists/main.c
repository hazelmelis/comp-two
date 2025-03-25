#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

void head_insert(Node** pHead, int n);

void print_list(Node* head);

Node* recRev(Node* head);

void refRev(Node** pHead);

int main(int argc, char* argv[])
{
	Node* head = NULL;

	for (int i = 1; i <= 10; i++)
	{
		head_insert(&head, i);
	}

	print_list(head);

	//head = recRev(head);
	refRev(&head);
	printf("\n");
	print_list(head);

	return 0;
}

void head_insert(Node** pHead, int n)
{
	Node* new = (Node*)malloc(sizeof(Node));
	if (new == NULL)
	{
		printf("Failed to allocate space for new node.\n");
		exit(1);
	}

	new->data = n;
	new->next = NULL;

	if (*pHead == NULL)
	{
		*pHead = new;
	}
	else
	{
		new->next = *pHead;
		*pHead = new;
	}
}

void print_list(Node* head)
{
	while (head != NULL)
	{
		printf("%d->", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

Node* recRev(Node* head)
{
	Node* newHead;
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	newHead = recRev(head->next);
	head->next->next = head;
	head->next = NULL;

	print_list(newHead);

	return newHead;
}

void refRev(Node** pHead)
{
	Node* newHead = *pHead;
	if (*pHead == NULL || (*pHead)->next == NULL)
	{
		*pHead = newHead;
		return;
	}

	refRev(&((*pHead)->next));
	(*pHead)->next->next = *pHead;
	(*pHead)->next = NULL;
}