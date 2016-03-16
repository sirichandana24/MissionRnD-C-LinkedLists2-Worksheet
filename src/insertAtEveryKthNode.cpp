/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
struct node * insertAtEveryKthNode(struct node *head, int K) {
	struct node *temp = head, *n;
	int count = 0;
	if (head == NULL)
		return NULL;
	if (K < 1)
		return NULL;
	while (temp != NULL)
	{
		count++;
		if (count%K == 0)
		{
			n = (struct node*)malloc(sizeof(struct node));
			n->num = K;
			n->next = NULL;
			n->next = temp->next;
			temp->next = n;
			temp = temp->next;
			count = 0;
		}
		temp = temp->next;
	}
	return head;
}

