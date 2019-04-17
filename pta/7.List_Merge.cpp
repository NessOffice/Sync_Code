#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); /*裁判实现，细节不表*/
struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2);
void printlist( struct ListNode *head )
{
     struct ListNode *p = head;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode  *list1, *list2;

    list1 = createlist();
    list2 = createlist();
    list1 = mergelists(list1, list2);
    printlist(list1);
	
    return 0;
}

/* 你的代码将被嵌在这里 */

struct ListNode *createlist()
{
	struct ListNode *head, *ptr, *last;
	last = head = NULL;
	int data;
	while(scanf("%d", &data) && data != -1)
	{
		ptr = (struct ListNode *)malloc(sizeof(struct ListNode));
		ptr->data = data;
		ptr->next = NULL;
		if(head && head->next == NULL) head->next = ptr;
		if(head == NULL) head = ptr;
		if(last) last->next = ptr;
		last = ptr;
	}
	return head;
}

struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2)
{
	struct ListNode *node, *head, *last, *ptr1, *ptr2;
	last = head = NULL;
	ptr1 = list1;
	ptr2 = list2;
	while(ptr1 || ptr2)
	{
		node = (struct ListNode *)malloc(sizeof(struct ListNode));
		int data;
		if(ptr1 && (!ptr2 || ptr1->data <= ptr2->data)){
			data = ptr1->data;
			ptr1 = ptr1->next;
		}else{
			data = ptr2->data;
			ptr2 = ptr2->next;
		}
		node->data = data;
		node->next = NULL;
		if(head == NULL) head = node;
		if(last) last->next = node;
		last = node;
	}
	return head;
}