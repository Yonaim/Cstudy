#include <stdio.h>
#include <stdlib.h>

typedef struct node_
{
	char *content;
	struct node_ *next;
} node;

void add_node_front(node **head, node *addnode)
{
	addnode->next = *head;
	*head = addnode;
}

int main()
{
	node *head;

	node *node1 = malloc(sizeof(node));
	node1->content = "1";
	node *node2 = malloc(sizeof(node));
	node2->content = "2";
	node *node3 = malloc(sizeof(node));
	node3->content = "3";

	add_node_front(&head, node1);
	add_node_front(&head, node2);
	add_node_front(&head, node3);

	printf("%s\n", head->content);
	printf("%s\n", head->next->content);
	printf("%s\n", head->next->next->content);
}