#include <stdio.h>
#include <stdlib.h>
struct Node{
	double e;
	int c;
	struct Node *next;
};
struct Node *nodeReverse(struct Node *p){
	struct Node *temp,*temp2,*last=NULL,*head;
	temp=p->next;
	while(temp->next){
		temp2=temp->next;
		temp->next=last;
		last=temp;
		temp=temp2;
	}
	temp->next=last;
	head=(struct Node *)malloc(sizeof(struct Node));
	head->next=temp;
	return head;
}
struct Node *nodeFind(){
	;
}
struct Node *nodeDelete(){
	;
}
struct Node *nodeInsert(){
	;
}
struct Node *nodeRead(){
	struct Node *temp,*last,*head=NULL;
	double e;
	int n,c;
	head=(struct Node *)malloc(sizeof(struct Node));
	head->next=NULL;
	last=head;
	scanf("%d",&n);
	while(n--){
		scanf("%d%lf",&c,&e);
		temp=(struct Node *)malloc(sizeof(struct Node));
		temp->e=e;
		temp->c=c;
		last->next=temp;
		last=temp;
	}
	temp->next=NULL;
	return head;
}
void nodeFree(struct Node *p){
	;
}
void nodePrint(struct Node *p){
	struct Node *temp=p;
	temp=temp->next;
	while(temp){
		printf(" %d %.1lf",temp->c,temp->e);
		temp=temp->next;
	}
}
int main(){
	struct Node *p1;
	p1=nodeRead();
	Print(p1);
	return 0;
}
