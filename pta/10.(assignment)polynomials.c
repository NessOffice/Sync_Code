#include <stdio.h>
#include <stdlib.h>

#define PLUS 1
#define MINUS 2
#define MULTIPLY 3
#define SyntaxError 4

struct ListNode
{
	int coef, expo;//coef for coefficient, and expo for exponential
	struct ListNode *next;
};

void Welcome();
int OperatorChoose();
void PrintList(struct ListNode* head);
struct ListNode *ReadList();
struct ListNode *ListAdd(struct ListNode* h1, struct ListNode* h2, int type);
struct ListNode *FindListExpo(struct ListNode* head, int expo);
struct ListNode *ListMultiply(struct ListNode* h1, struct ListNode* h2);

int main()
{
	Welcome();
	int T;
	printf("Please enter the number of calculations:");
	scanf("%d", &T);
	while(T--)
	{
		struct ListNode *h1, *h2, *ans;
		printf("Please input the first polynomial:");
		h1 = ReadList();
		printf("Please input the sceond polynomial:");
		h2 = ReadList();
		
		int OperateType = OperatorChoose();
		switch(OperateType)
		{
			case PLUS:ans = ListAdd(h1, h2, PLUS);break;
			case MINUS:ans = ListAdd(h1, h2, MINUS);break;
			case MULTIPLY:ans = ListMultiply(h1, h2);break;
			case SyntaxError:printf("Syntax Error! Please check if your operator is +, - or *.\n");break;
		}
		if(OperateType != SyntaxError) PrintList(ans);
	}
	return 0;
}

void Welcome()
{
	printf("Hello! I'm a program designed to tickle polynomials calculation.\n");
	printf("Please input your polynomials here so that I can output the correct answer.\n");
	printf("You can enter a single integer or 0 to indicate that the input is over.\n\n");
	
	printf("Caution!Please enter the polynomial according to the exponential-descending order!\n");
	printf("Caution!You are only supposed to enter lower case x!\n");
	printf("Note: I'm not perfect for the input must be in format and x2, 3x will make error,\n");
	printf("I'm terribly sorry for any bug I make. Hopefully you can forgive me:D\n\n");

	printf("Sample Input:3x4 2x1 4\n\n");
}

int OperatorChoose()
{
	char op[10];
	printf("enter your operator(+, - or *):");
	scanf("%s", op);
	switch(op[0])
	{
		case '+':return PLUS;
		case '-':return MINUS;
		case '*':return MULTIPLY;
		default:return SyntaxError;
	}
}

void PrintList(struct ListNode* head)
{
	printf("The answer is:");
	struct ListNode *node = head;
	if(node == NULL) printf("0");
	while(node)
	{
		if(node != head && node->coef > 0) putchar('+');
		if(node->coef)
		{
			if(node->expo == 0 || (node->coef != 1 && node->coef != -1)) printf("%d", node->coef);
			if(node->expo && node->coef == -1) putchar('-');
			if(node->expo > 0) printf("x");
			if(node->expo > 1) printf("^%d", node->expo);
		}
		node = node->next;
	}
	printf("\n\n");
}

struct ListNode *ReadList()
{
	int quit = 0;
	char str[40];
	struct ListNode *last, *node, *head;
	last = head = NULL;
	while(!quit)
	{
		scanf("%s", str);
		int coef, expo, i;
		quit = 0;
		for(i = 0;str[i];i++)
			if(str[i] == 'x') break;
		if(str[i] == '\0'){
			sscanf(str, "%d", &coef);
			expo = 0, quit = 1;
		}else{
			str[i] = ' ';
			sscanf(str, "%d %d", &coef, &expo);
		}
		if(!coef) continue;
		node = (struct ListNode *)malloc(sizeof(struct ListNode));
		node->coef = coef;
		node->expo = expo;
		node->next = NULL;
		if(head == NULL) head = node;
		if(last) last->next = node;
		last = node;
	}
	return head;
}

//This function involves both add and subtract
struct ListNode *ListAdd(struct ListNode* h1, struct ListNode* h2, int type)
{
	struct ListNode *head, *node, *last;
	struct ListNode *n1, *n2;
	int coef, expo;
	
	n1 = h1, n2 = h2;
	head = last = NULL;
	while(n1 || n2)
	{
		coef = 0;
		if(n1 && (!n2 || n1->expo >= n2->expo)) expo = n1->expo;
		else expo = n2->expo;
		if(n1 && expo == n1->expo){coef += n1->coef;n1 = n1->next;}
		if(n2 && expo == n2->expo)
		{
			if(type == PLUS) coef += n2->coef;
			if(type == MINUS) coef -= n2->coef;
			n2 = n2->next;
		}

		if(!coef) continue;
		node = (struct ListNode *)malloc(sizeof(struct ListNode));
		node->coef = coef;
		node->expo = expo;
		node->next = NULL;
		if(head == NULL) head = node;
		if(last) last->next = node;
		last = node;
	}
	return head;
}

struct ListNode *FindListExpo(struct ListNode* head, int expo)
{
	struct ListNode *node = head;
	while(node->next)
	{
		if(node->next->expo < expo) return node;
		node = node->next;
	}
	return node;
}

struct ListNode *ListMultiply(struct ListNode* h1, struct ListNode* h2)
{
	struct ListNode *head, *node, *last, *temp;
	struct ListNode *n1, *n2;
	int coef, expo;

	n2 = h2;
	head = last = NULL;
	for(n2 = h2;n2;n2 = n2->next)
		for(n1 = h1;n1;n1 = n1->next)
		{
			coef = n1->coef * n2->coef;
			expo = n1->expo + n2->expo;
			node = (struct ListNode *)malloc(sizeof(struct ListNode));
			node->coef = coef;
			node->expo = expo;

			if(head == NULL || expo > head->expo) last = head;
			else last = FindListExpo(head, expo);
			if(last && last->expo == node->expo){
				last->coef += node->coef;
				if(last->coef == 0)
				{
					//I could have added a 'prev' pointer to the ListNode :D
					if(head && expo+1 > head->expo){head = last->next;free(last);}
					else{
						temp = FindListExpo(head, expo+1);
						temp->next = last->next;
						free(last);
					}
				}
			}else{
				if(last){node->next = last->next;last->next = node;}
				else{head = node;head->next = NULL;}
			}
		}
	return head;
}
