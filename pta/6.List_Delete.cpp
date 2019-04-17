#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *deletem( struct ListNode *L, int m );
void printlist( struct ListNode *L )
{
     struct ListNode *p = L;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    int m;
    struct ListNode *L = readlist();
    scanf("%d", &m);
    L = deletem(L, m);
    printlist(L);

    return 0;
}

/* 你的代码将被嵌在这里 */

struct ListNode *readlist()
{
	int data;
	struct ListNode *last, *node, *head;
	last = head = NULL;
	while(scanf("%d", &data), data != -1)
	{
		node = (struct ListNode *)malloc(sizeof(struct ListNode));
		node->data = data, node->next = NULL;
		if(last) last->next = node;
		last = node;
		if(head && head->next == NULL) head->next = node;
		if(head == NULL) head = node, head->next = NULL;
	}
	return head;
}

struct ListNode *deletem( struct ListNode *L, int m )
{
	struct ListNode *node, *last, *trash;
	while(L && L->data == m)
	{
		trash = L;
		L = L->next;
		free(trash);
	}
	if(L) node = L->next;
	else node = NULL;
	last = L;
	while(node)
	{
		while(node && node->data == m)
		{
			trash = node;
			node = node->next;
			free(trash);
		}
		last->next = node;
		last = node;
		if(node) node = node->next;
	}
	return L;
}