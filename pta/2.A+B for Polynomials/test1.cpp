#include <stdio.h>
#include <stdlib.h>
struct Polynomial{
	double e;
	int c;
	struct Polynomial *next;
}; 
//多项式加法模拟 
int Add(struct Polynomial *p1,struct Polynomial *p2,struct Polynomial *p3){//将p1与p2相加，储存在p3中，函数返回项数 
	int len=0;
	struct Polynomial *temp1=p1->next,*temp2=p2->next,*temp3,*last;
	p3=(struct Polynomial *)malloc(sizeof(struct Polynomial));
	p3->next=NULL;
	last=p3;
	while(temp1&&temp2){
		if(temp1->c>temp2->c){
			temp3=(struct Polynomial *)malloc(sizeof(struct Polynomial));
			temp3->e=temp1->e;
			temp3->c=temp1->c;
			last->next=temp3;
			last=temp3;
			temp1=temp1->next;
			len++;
		}
		else if(temp2->c>temp1->c){
			temp3=(struct Polynomial *)malloc(sizeof(struct Polynomial));
			temp3->e=temp2->e;
			temp3->c=temp2->c;
			last->next=temp3;
			last=temp3;
			temp2=temp2->next;
			len++;
		}
		else{
			if((temp1->e+temp2->e)!=0.0){
				temp3=(struct Polynomial *)malloc(sizeof(struct Polynomial));
				temp3->e=temp2->e+temp1->e;
				temp3->c=temp2->c;
				last->next=temp3;
				last=temp3;
				len++;
			}
			temp1=temp1->next;
			temp2=temp2->next;
		}
	}
	while(temp1){
		temp3=(struct Polynomial *)malloc(sizeof(struct Polynomial));
			temp3->e=temp1->e;
			temp3->c=temp1->c;
			last->next=temp3;
			last=temp3;
			temp1=temp1->next;
			len++;
	}
	while(temp2){
		temp3=(struct Polynomial *)malloc(sizeof(struct Polynomial));
			temp3->e=temp2->e;
			temp3->c=temp2->c;
			last->next=temp3;
			last=temp3;
			temp2=temp2->next;
			len++;
	}
	temp3->next=NULL;
	return len;
}
//输入1 1 1\
 1 0 1（第一次输入表示x,第二次表示1） 
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
	struct Polynomial *p1,*p2,*p3;
	p1=Read();
	p2=Read();
	printf("%d",Add(p1,p2,p3));
	Print(p3);//这一步有问题 
	return 0;
} 
