#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct node{  //self referential structure
	int data ;
	struct node *next;
}cl;
cl* makenode(){
	cl *p;
	p=(cl *)malloc(sizeof(cl *));
	p->next=0;
	printf("enter data:");
	scanf("%d",&p->data);
	return p;
}
cl *addfirst(cl *h){
	cl *p,*t;
	p=makenode();
	if(h==0){
		p->next=p;
		return p;
	}
	t=h;
	while(t->next!=h)
		t=t->next;
		t->next=p;
		p->next=h;
		return p;
	
}
cl *delfirst(cl *h){
	cl *t,*p;
   if(h==0){
   printf("\n List is empty");
   getch;
   return h;
  }
  if(h->next==h){
  	printf("deleting.....%d",h->data);
  	getch();
     free(h);
     return 0;
  }
  t=h;
  while(t->next!=h)
 t=t->next;
 p=h;
 h=h->next;
 t->next=h;
 printf("\nDeleting ....%d ",p->data);
 getch();
 free(p);
 return h;
}
void display(cl *h){
	cl *t;
	if(h==0)
		printf("\nList is empty");

t=h;
while(t->next!=h){
	printf("\n%d",t->data);
	t=t->next;	
}
printf("\n%d",t->data);

getch();
}
void main(){
	cl *head=0;
	int ch;
	while(1){
		printf("\n1......Add First");
		printf("\n2......Del First");
		printf("\n3......Display");
		printf("\n4......Exit");
		printf("Enter your choice");
		scanf("%d",&ch);
		switch(ch){
			case 1:head=head=addfirst(head);
			        break;
		    case 2:head=delfirst(head);
			        break;
			case 3:display(head);
			        break;
			        
		    default:printf("thanks");
			getch();
			exit(0);			        
		}
	}
}
		
