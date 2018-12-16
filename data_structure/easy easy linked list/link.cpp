#include <iostream>
using namespace std;
struct list{
	int val;
	list* next;
};
void PrintList(list *L){
	list* p=L;
	while(p){
		cout<<p->val;
		p=p->next;
	}
}
list *head=NULL,*temp=NULL;
void InsertList(int data){
	temp=new list;
	temp->val=data;
	if(head==NULL){
		temp->next=NULL;
		head=temp;
		return;
	}
	list* node=new list;
	list* nodelast;
	node=head;
	while(node){
		if(data<head->val){
			temp->next=head;
			head=temp;
			return;
		}
		else if(data<node->val){
			temp->next=node;
			nodelast->next=temp;
			return;
		}
		else{
			nodelast=node;
			node=node->next;
		}
	}
	temp->next=NULL;
	nodelast->next=temp;
	return;
}
int main(){
	InsertList(3);
	InsertList(9);
	InsertList(5);
	InsertList(1);
	PrintList(head);
	return 0;
} 
