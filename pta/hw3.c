#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR 1e5
typedef enum { push, pop, inject, eject, end } Operation;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Element;
    PtrToNode Next, Last;
};
typedef struct DequeRecord *Deque;
struct DequeRecord {
    PtrToNode Front, Rear;
};
Deque CreateDeque();
int Push( ElementType X, Deque D );
ElementType Pop( Deque D );
int Inject( ElementType X, Deque D );
ElementType Eject( Deque D );

Operation GetOp();          /* details omitted */
void PrintDeque( Deque D ); /* details omitted */

int main()
{
    ElementType X;
    Deque D;
    int done = 0;

    D = CreateDeque();
    while (!done) {
        switch(GetOp()) {
        case push: 
            scanf("%d", &X);
            if (!Push(X, D)) printf("Memory is Full!\n");
            break;
        case pop:
            X = Pop(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case inject: 
            scanf("%d", &X);
            if (!Inject(X, D)) printf("Memory is Full!\n");
            break;
        case eject:
            X = Eject(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case end:
            PrintDeque(D);
            done = 1;
            break;
        }
    }
    return 0;
}

/* Your function will be put here */

struct DequeRecord De;
Deque CreateDeque()
{
	De.Front = (PtrToNode)malloc(sizeof(PtrToNode));
	(De.Front)->Last =(De.Front)->Next = NULL;
	De.Rear = De.Front;
	return &De;
}
int Push( ElementType X, Deque D ) // at front
{
	PtrToNode node = (PtrToNode)malloc(sizeof(PtrToNode)), nxt;
	if(node == NULL) return 0;
	node->Element = X;
	if(D->Front == D->Rear)
	{
		D->Front->Next = node;
		node->Last = D->Front;
		node->Next = NULL;
		D->Rear = node;
		return 1;
	}
	nxt = D->Front->Next;
	D->Front->Next = node;
	node->Last = D->Front;
	nxt->Last = node;
	node->Next = nxt;
	return 1;
}
ElementType Pop( Deque D ) // at front
{
	ElementType X;
	PtrToNode nxt;
	if(D->Front == D->Rear) return ERROR;
	X = D->Front->Next->Element;
	if(D->Rear == D->Front->Next)
		D->Rear = D->Front;
	nxt = D->Front->Next->Next;
	// free(D->Front->Next);
	D->Front->Next = nxt;
	if(nxt) nxt->Last = D->Front;
	return X;
}
int Inject( ElementType X, Deque D ) // at rear
{
	PtrToNode node = (PtrToNode)malloc(sizeof(PtrToNode)), lst;
	if(node == NULL) return 0;
	node->Element = X;
	node->Next = NULL;
	node->Last = D->Rear;
	D->Rear->Next = node;
	D->Rear = node;
	return 1;
}
ElementType Eject( Deque D ) // at rear
{
	ElementType X;
	PtrToNode lst;
	if(D->Front == D->Rear) return ERROR;
	D->Rear->Last->Next = NULL;
	X = D->Rear->Element;
	D->Rear = D->Rear->Last;
	// free(D->Rear->Last);
	return X;
}
Operation GetOp()  /* details omitted */
{
	char cmd[10];
	scanf("%s", cmd);
	switch(cmd[2])
	{
		case 's': return push;
		case 'p': return pop;
		case 'j': return inject;
		case 'e': return eject;
		case 'd': return end;
	}
}
void PrintDeque( Deque D )
{
	PtrToNode node;
	if(D->Front == D->Rear){printf("nmsl\n");return;}
	node = D->Front->Next;
	// printf("%x %x %x %d\n", D->Front, D->Front->Last, D->Front->Next, D->Front->Element);
	// printf("%x %x %x %d\n", D->Rear, D->Rear->Last, D->Rear->Next, D->Rear->Element);
	while(node)
	{
		printf("%d\n", node->Element);
		// printf("%x %x %x %d\n", node, node->Last, node->Next, node->Element);
		node = node->Next;
	}
	
}