#include <stdio.h>
#include <stdlib.h>
struct Polynomial{
	double e;
	int c;
	struct Polynomial *next;
};
struct Polynomial *Reverse(struct Polynomial *p){
	struct Polynomial *temp,*temp2,*last=NULL,*head;
	temp=p->next;
	while(temp->next){
		temp2=temp->next;
		temp->next=last;
		last=temp;
		temp=temp2;
	}
	head=(struct Polynomial *)malloc(sizeof(struct Polynomial));
	head->next=temp;
	return head;
} 
struct Polynomial *Read(){
	struct Polynomial *temp,*last,*head=NULL;
	double e;
	int n,c;
	head=(struct Polynomial *)malloc(sizeof(struct Polynomial));
	head->next=NULL;
	last=head;
	scanf("%d",&n);
	while(n--){
		scanf("%d%lf",&c,&e);
		temp=(struct Polynomial *)malloc(sizeof(struct Polynomial));
		temp->e=e;
		temp->c=c;
		last->next=temp;
		last=temp;
	}
	temp->next=NULL;
	return head;
}
void Print(struct Polynomial *p){
	struct Polynomial *temp=p;
	temp=temp->next;
	while(temp){
		printf(" %d %.1lf",temp->c,temp->e);
		temp=temp->next;
	}
}
int main(){
	int len=0;
	struct Polynomial *p1,*p2,*p3;
	p1=Read();
	Print(Reverse(p1));
	return 0;
} 
