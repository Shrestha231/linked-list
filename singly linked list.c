#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct node{  //self referential structure
	int data ;
	struct node *next;
}ll;
ll* makenode(){
	ll *p;
	p=(ll *)malloc(sizeof(ll *));
	p->next=0;
	printf("enter data:");
	scanf("%d ",&p->data);
	return p;
}
ll *addfirst(ll *h){
	ll *p;
	p=makenode();
	p->next=h;
	return p;
}
ll *delfirst(ll *h){
	ll *t;
   if(h==0){
   printf("\n List is empty");
   getch;
   return h;
  }
  t=h;
 h=h->next;
 printf("\nDeleting ....%d ",t->data);
 getch();
 free(t);
 return h;
}
ll *addlast(ll *h){
	ll *p,*t;
	p=makenode();
	if(h==0)
	return p;
	t=h;
	while(t->next!=0){
	t=t->next;
	t->next=p;
	return h;	
	}
}
ll *dellast(ll *h){
	ll *p,*t;
	if(h==0){
		printf("\n list is empty");
		getch();
		return h;
	}
	if(h->next==0){
		printf("delete =%d",h->data);
		getch();
		free(h);
		return 0;
	}
	t=h;
	while(t->next->next!=0){
		t=t->next;
		p=t->next;
		t->next=0;
		printf("deleting %d",p->data);
		getch();
		free(p);
		return h;
	}
}
void display(ll *h){
	if(h==0)
	printf("\nList is empty");

while(h){
	printf("\n%d",h->data);
	h=h->next;
}
getch();
}
void main(){
	ll *head=0;
	int ch;
	while(1){
		printf("\n1......Add First");
		printf("\n2......Del First");
		printf("\n3......Add last");
		printf("\n4......Del last");
		printf("\n5......Display");
		printf("\n6......Exit");
		printf("\n Enter your choice: ");
		scanf(" %d",&ch);
		switch(ch){
			case 1:head=addfirst(head);
			        break;
		    case 2:head=delfirst(head);
			        break;
			 case 3:head=addlast(head);
			        break; 
			case 4:head=dellast(head);
			        break; 		      
			case 5:display(head);
			        break;
			        
		    default:printf("thanks");
			getch();
			exit(0);			        
		}
	}
}


	
