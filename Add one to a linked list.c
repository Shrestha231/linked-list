#include<stdio.h>
#include<stdlib.h>
typedef struct list{
	int data;
	struct list *next;
}ll;
ll *makenode(){
	ll *p;
	p=(ll*)malloc(sizeof(ll));
	printf("enter the value of p");
	scanf("%d",&p->data);
	p->next=0;
	return p;
}
ll *newNode(int value){
	ll *p=(ll *)malloc(sizeof(ll));
	p->data=value;
	p->next=0;
	return p;
}
ll *reverse(ll *head){
	ll *curr=head;
	ll *prev=0,*next=0;
	while(curr!=0){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	
		
	}
	return prev;
}

 ll *add(ll *head){
 	head=reverse(head);
	ll *temp=head;
	int carry=1,sum,digit;
	while(temp!=0){
		sum=carry+temp->data;
		digit=sum%10;
		carry=sum/10;
		temp->data=digit;
		if(temp->next==0&&carry!=0){
			ll *new_Node=newNode(carry);
			temp->next=new_Node;
		}
		temp=temp->next;	
	}
	head=reverse(head);
	return head;
}
void printList(ll *head){
	ll *curr=head;
	while(curr!=0){
		printf("%d ",curr->data);
		curr=curr->next;
	}
}
int main(){
	int n,i;
	ll *head=0,*temp=0;
	
	printf("enter the number of digits");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		ll *new_Node=makenode();
		if(head==0){
		
		head=new_Node;
		temp=head;
	}
		else{
			temp->next=new_Node;
			temp=temp->next;
		}
	}
	printf("original list");
	printList(head);
	printf("\n");
	
	head=add(head);
	printf("After Adding 1: ");
    printList(head);
    printf("\n");

    return 0;
}
	

