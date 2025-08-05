#include<stdio.h>
#include<stdlib.h>
struct node {
	float coeff;
	int expo;
	struct node *link;
}*head;
struct node *insert(struct node *head, float co,int ex){                 // The insertion of new nodes should maintain the sorted order of the list. 
	struct node *temp;                                                   // The polynomials can be added only when they are arranged in decreasing order of their exponents.
	struct node *newP=(struct node *)malloc(sizeof(struct node));    
	newP->coeff=co;
	newP->expo=ex;
	newP->link=NULL;
	if(head==NULL ||ex>head->expo){
		newP->link=head;
		head=newP;	
	}
	else{
		temp=head;
		while(temp->link!=NULL &&temp->link->expo>ex)
			temp=temp->link;
			newP->link=temp->link;
			temp->link=newP;	
		
	}
return head;
}
struct node *create(struct node *head){
	int n,i;
	float coeff;
	int expo;
	printf("Enter the no of terms:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\nEnter the coefficient for term %d: ",i+1);
		scanf("%f",&coeff);
		printf("\nEnter the exponent for term %d: ",i+1);
		scanf("%d",&expo);
		head=insert(head,coeff,expo);
	}
	return head;	
}

void print(struct node *head){
	if(head==NULL){
		printf("No Polynomial");	
	}
	else{
		struct node *temp=head;
		while(temp!=NULL){
			printf("(%.1fx^%d)",temp->coeff,temp->expo);
			temp=temp->link;
			if (temp!=NULL){
				printf("+");
			}
			else{
				printf("\n");
			}
		}
	}
}
void polyAdd(struct node *head1,struct node *head2){
	struct node *ptr1=head1;
	struct node *ptr2=head2;
	struct node *head3=NULL;
	while(ptr1!=NULL &&ptr2!=NULL){   
		if(ptr1->expo==ptr2->expo){
		 head3=insert(head3,ptr1->coeff+ptr2->coeff,ptr1->expo); // The coefficients of the terms with the same exponents and powers are added
		 ptr1=ptr1->link;
		 ptr2=ptr2->link;
		 
		}
		else if(ptr1->expo > ptr2->expo){
			head3=insert(head3,ptr1->coeff,ptr1->expo);
			ptr1=ptr1->link;
			
		}
		else if(ptr1->expo<ptr2->expo){
			head3=insert(head3,ptr2->coeff,ptr2->expo);
			ptr2=ptr2->link;	
		}
		
	}
	while(ptr1!=NULL){
		head3=insert(head3,ptr1->coeff,ptr1->expo); // checking for the remaining terms in  both the list polynomials, if they are found they can be inserted into the list
		ptr1=ptr1->link;	
	}
	while(ptr2!=NULL){
		head3=insert(head3,ptr2->coeff,ptr2->expo);
		ptr2=ptr2->link;
	}
	printf("Added Polynomial is: ");
	print(head3);
}
void polyMul(struct node *head1,struct node *head2){
	int res1,res2;
	struct node *ptr1=head1;
	struct node *ptr2=head2;
	struct node *head3=NULL;
	if(head1==NULL || head2==NULL)
	printf("Zero Polynomial");
	while(ptr1!=NULL){
		while(ptr2!=NULL){
		res1=ptr1->coeff*ptr2->coeff;
		res2=ptr1->expo + ptr2->expo;
		head3=insert(head3,res1,res2);	
		ptr2=ptr2->link	;
			
		}
		ptr2=head2;
		ptr1=ptr1->link;
	}
	printf("Multiplied Polynomial is: ");
	print(head3);
}

int main(){
	struct node *head1=NULL;
	struct node *head2=NULL;
	
	printf("Enter the Polynomial1\n");
	head1=create(head1);
	printf("Enter the Polynomial2\n");
	head2=create(head2);
	print(head1);
	print(head2);
	polyAdd(head1,head2);
	printf("\n");
	polyMul(head1,head2);
	return 0;
}

