#include<stdio.h>
#include<stdlib.h>
typedef struct list{
	int data;
	struct list *next;
	
}ll;
ll *makenode(){
  ll *p=(ll*)malloc(sizeof(ll));
  p->next=0;
  printf("enter data");
  scanf("%d",&p->data);
  return p;	
}
ll *sort(ll *h){
	ll *t;
	ll *p=makenode();
	if(h==0)
	return p;
	if(h->data>p->data){
	
	p->next=h;
	//h->next=0;
	return p;
}
	t=h;
	while(t->next!=0&&p->data>t->next->data)
	   t=t->next;
	   p->next=t->next;
	   t->next=p;
        return h;

}
void display(ll *h){
	if(h==0){
	printf("\nList is empty");
}
printf("\nSorted list:");
while(h){
	printf("%d ",h->data);
	h=h->next;
}

	
	
}
int main(){
	int n,i;
	printf("enter the number of nodes");
	scanf("%d",&n);
	ll *head=0;
    for(i=0;i<n;i++){
    head=sort(head);	
	}
	display(head);
	return 0;
	
	
}
