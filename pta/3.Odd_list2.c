#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *getodd( struct ListNode **L );
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
    struct ListNode *L, *Odd;
    L = readlist();
    Odd = getodd(&L);
    printlist(Odd);
    printlist(L);

    return 0;
}

/* 你的代码将被嵌在这里 */

void insert(struct ListNode *last, struct ListNode *head, int data)
{
	struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
	node->data = data, node->next = NULL;
	if(last) last->next = node;
	last = node;
	if(head && head->next == NULL) head->next = node;
	if(head == NULL) head = node, head->next = NULL;
}

struct ListNode *readlist()
{
	int data;
	struct ListNode *last, *head;
	last = head = NULL;
	while(scanf("%d", &data), data != -1)
	{
		/*node = (struct ListNode *)malloc(sizeof(struct ListNode));
		node->data = data, node->next = NULL;
		if(last) last->next = node;
		last = node;
		if(head && head->next == NULL) head->next = node;
		if(head == NULL) head = node, head->next = NULL;*/
		insert(last, head, data);
	}
	return head;
}

struct ListNode *getodd( struct ListNode **L )
{
	struct ListNode *oddlast, *last, *node, *oddnode, *head;
	oddlast = last = oddnode = head = NULL, node = *L;
	while(node)
	{
		if(node->data & 1){
			oddnode = (struct ListNode *)malloc(sizeof(struct ListNode));
			oddnode->data = node->data, oddnode->next = NULL;
			if(oddlast) oddlast->next = oddnode;
			oddlast = oddnode;
			if(last == NULL) *L = node->next;
			if(head && head->next == NULL) head->next = oddnode; 
			if(head == NULL) head = oddnode, head->next = NULL;
		}else{
			if(last) last->next = node;
			last = node;
		}
		node = node->next;
	}
	if(last && last->next && last->next->data & 1) last->next = NULL;
	return head;
}