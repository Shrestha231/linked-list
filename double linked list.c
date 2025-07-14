#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct list{
	int data;
	struct list *next,*prev;
}dl;
dl *makenode(){
	dl *p;
	p=(dl*)malloc(sizeof(dl*));
	p->next=p->prev=0;
	printf("enter the data :\n");
	scanf("%d",&p->data);
	return p;	
}
dl *addfirst(dl *h){
	dl *p=makenode();
	p->next=h;
	if(h!=0)
	h->prev=p;
	return p;
}
dl *delfirst(dl *h)
{
	dl *p;
	if(h==0){
		printf("\n list is empty");
		getch();
		return h;
	}
	p=h;
	h=h->next;
	if(h!=0)
	h->prev=0;
	printf("Deleting .....%d",p->data);
	getch();
	free(p);
	return h;	
}
void display(dl *h){
  if(h==0)
  printf("\n List is empty");
  
  while(h){
  
  printf("\n %d",h->data);
  h=h->next;
}

getch();
}
dl *addlast(dl *h){
	dl *p,*t;
	p=makenode();
	if(h==0)
	return p;
	t=h;
	while(t->next!=0)
	t=t->next;
	t->next=p;
	p->prev=t;
	return h;
}
dl *dellast(dl *h){
	dl *t,*p;
	if(h==0){
	
	printf("\n list is empty...");
	getch();
	return h;
}
	if(h->next==0){
	
	printf("\n deleting element=%d",h->data);
	free(h);
	return 0;
}
	t=h;
	while(t->next->next!=0)
	t=t->next;
	p=t->next;
	t->next=0;
	printf("\ndeleting......%d",p->data);
	getch();
	free(p);
	return h;
}
dl *addpos(dl *h){
	int pos,n=0,i;
	dl *p,*t;
	if(h)
	n=1;
	t=h;
	while(t->next!=0)
	{
		t=t->next;
		n++;
	}
	printf("\n enter the position where you want to join the nodes",n);
	scanf("%d",&pos);
	if(pos<1||pos>n+1)
	{
		printf("Invalid");
		getch();
		return h;
	}
	if(pos==1){
		h=addfirst(h);
		return h;
	}
	if(pos==n+1){
		h=addlast(h);
		return h;
	}
	t=h;
	for(i=2;i<pos;i++)
		t=t->next;
		p=makenode();
		p->next = t->next;

    t->next->prev = p;
	t->next = p;
     p->prev = t;
	return h;
}
dl *delpos(dl *h){
	int n=0,pos,i;
	dl *p,*t;
	if(h){
	n=1;
	t = h;
	while(t->next!=0){
		t=t->next;
		n++;	
	}
	
}
printf("\n Enter the position where you want to delete the nodes");
scanf("%d",&pos);
if(pos<1||pos>n){
	printf("Invalid");
	getch();
	return h;
}
if(pos==1)
{
	h=delfirst(h);
	return h;
}
if(pos==n){
	h=dellast(h);
	return h;
}
t=h;
for(i=2;i<pos;i++)
t=t->next;
p=t->next;
t->next=p->next;
p->next->prev=t;
printf("\ndeleting...%d",p->data);
free(p);
return h;
}

void main(){
	int ch;
	dl *head=0;
	while(1){
	printf("\n 1.Addfirst");
	printf("\n 2.Delete first");
	printf("\n 3.AddLast");
	printf("\n 4.delete Last");
	printf("\n 5.Display");
	printf("\n 6.Add position");
	printf("\n 7.Delete position");
	printf("\n 8.exit");
printf("\nEnter your choice\n");
scanf("%d",&ch);
switch(ch){
	case 1 :head=addfirst(head);
	         break;
    case 2 :head=delfirst(head);
	         break;
    case 3 :head=addlast(head);
	         break;
	case 4 :head=dellast(head);
	         break;
    case 5 :display(head);
	         break;
	case 6 :addpos(head);
	         break;
	case 7 :delpos(head);
	         break;		         
    default:printf("Thanks billlion....");
    getch();
    exit(0) ;
	         
}
}
	
}
	

