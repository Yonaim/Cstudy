#include <stdio.h>
#include <stdlib.h>

// head 자체가 별도의 노드임 (물론 content는 없고, next 멤버만 값을 가짐)
// 연결리스트의 첫번째 노드 = head->next 

// 1. head는 정적지역변수 노드
// 2. head는 동적할당 받은 노드

typedef struct node_
{
	char *content;
	struct node_ *next;
} node;

void add_node_front(node **head, node *addnode)
{
	if ((*head)->next == NULL)
		(*head)->next = addnode;
	else
	{
		addnode->next = (*head)->next;
		(*head)->next = addnode;
	}
}

// 1. head는 정적지역변수 노드

int main()
{
	node head;

	node *node1 = malloc(sizeof(node));
	node1->content = "1";
	node *node2 = malloc(sizeof(node));
	node2->content = "2";
	node *node3 = malloc(sizeof(node));
	node3->content = "3";

	add_node_front(&head, node1);
	add_node_front(&head, node2);
	add_node_front(&head, node3);
	
	printf("%s\n", head.next->content);
	printf("%s\n", head.next->next->content);
	printf("%s\n", head.next->next->next->content);
}

// 2. head는 동적할당 받은 노드

// int main()
// {
// 	node *head;
// 	head = malloc(sizeof(node));

// 	node *node1 = malloc(sizeof(node));
// 	node1->content = "1";
// 	node *node2 = malloc(sizeof(node));
// 	node2->content = "2";
// 	node *node3 = malloc(sizeof(node));
// 	node3->content = "3";

// 	add_node_front(&head, node1);
// 	add_node_front(&head, node2);
// 	add_node_front(&head, node3);
	
// 	printf("%s\n", head->next->content);
// 	printf("%s\n", head->next->next->content);
// 	printf("%s\n", head->next->next->next->content);
// }