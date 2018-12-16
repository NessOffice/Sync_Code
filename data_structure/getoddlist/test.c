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

struct ListNode *readlist(){
	int data,len = 0;
	struct ListNode *head = NULL,*node,*nodelast = NULL; 
	while(scanf("%d",&data) && data!=-1){
		len++;
		node = (struct ListNode *)malloc(sizeof(struct ListNode));
		node->data = data;
		node->next = NULL;
		if(nodelast != NULL) nodelast->next = node;
		nodelast = node;
		if(head == NULL) head = node;
		if(len == 2) head->next = node;
	}
	return head;
}

struct ListNode *getodd( struct ListNode **L ){
	int len = 0;
	struct ListNode *head = NULL,*node1,*node2,*nodelast = NULL; 
	node1 = *L;
	while(node1){
		if(node1->data % 2){
			len++;
			node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
			node2->data = node1->data;
			node2->next = NULL;
			if(nodelast != NULL) nodelast->next = node2;
			nodelast = node2;
			if(head == NULL) head = node2;
			if(len == 2) head->next = node2;
		}
		node1 = node1->next;
	}
	return head;
}
