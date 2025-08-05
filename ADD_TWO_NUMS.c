//ADDING TWO NUMBERS USING LINKED LIST
#include<stdio.h>
#include<stdlib.h>
struct node{
	int dig;
	struct node *link;
	}*head;
struct node *add_node(struct node *head,int val){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->dig=val;
	newnode->link=NULL;
	newnode->link=head;
	head=newnode;
	return head;	
}
struct node *createLL(struct node *head,int n){
	while(n!=0){
		head=add_node(head,n%10);
		n=n/10;
	}
	return head;
}
void print(struct node *head){
	if(head==NULL)
	printf("No Number");
	struct node *temp=head;
	while(temp->link!=NULL){
	printf("%d-->",temp->dig);
	temp=temp->link;
	}
	printf("%d",temp->dig);
}
struct node *reverse_list(struct node *head){
	struct node *next=head->link;
	head->link=NULL;
	struct node *current=head;
	while(next!=NULL){
		current=next;
		next=next->link;
		current->link=head;
		head=current;
		
	}
	
	return head;
}
struct node *push(struct node *head,int val){
	struct node *newnode=malloc(sizeof(struct node));
	newnode->dig=val;
	newnode->link=head;
	head=newnode;
	return head;
}
struct node *add(struct node *head1, struct node *head2){
if(head1->dig==0)
  return head2;
if(head2->dig==0)
  return head1;

struct node *ptr1=head1;
struct node *ptr2=head2;
struct node *head3=NULL;
int carry=0,sum=0;
while(ptr1 || ptr2){
sum=carry;
if(ptr1){
  sum+=ptr1->dig;
  ptr1 = ptr1->link;
}
if(ptr2){
sum+=ptr2->dig;
ptr2=ptr2->link;
}
carry=sum/10;
sum=sum%10;
head3=push(head3,sum);

}
if(carry)
 push(head3,carry);
return head3;
}
void backtonum(struct node *head){
	struct node *temp=head;
	printf("\nRESULT= ");
	while(temp!=NULL){
		printf("%d",temp->dig);
		temp=temp->link;
	}
	
	return;
}
int main(){
	int a,b;
	printf("Enter the two numbers:");
	scanf("%d %d",&a,&b);
	struct node *head1=NULL;
	struct node *head2=NULL;
	struct node *head3=NULL;
	printf("\nThe Linked List Representation of the first number is :\n");
	head1=createLL(head1,a);
	print(head1);
	printf("\nThe Linked List Representation of the second number is :\n");
	head2=createLL(head2,b);
	print(head2);
	head1=reverse_list(head1);
	head2=reverse_list(head2);
	printf("\nThe Reverse Lists are:\n");
	print(head1);
	printf("\n");
	print(head2);
	printf("\nThe Addition of the two numbers Linked List Representation:");
	head3=add(head1,head2);
	print(head3);
	backtonum(head3);
	
}
