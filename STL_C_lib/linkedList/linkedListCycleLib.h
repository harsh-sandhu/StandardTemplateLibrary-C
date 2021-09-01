#ifndef linkedListCycleLib

#include "linkedListStandardLib.h"

//<----------------------- CYCLE IN LINKEDLIST ---------------------->


//Function to create cycle
void makeCycle(linkedlist* head,int n){

    //invalid input 
    if(n<1||n>=head->length){
	printf("ERROR: Cant Create Cycle\n");
	return;
    }

    int count=1;
    linkedlist* temp=head;
    linkedlist* cyclePoint=NULL;
    while(temp->next!=NULL){
	if(count==n){
	    cyclePoint=temp;
	}
	temp=temp->next;
	count++;
    }
    temp->next=cyclePoint;

}


//Function to detect Cycle- flyod Cycle detection algorithm
//return 1 if cycle is detected and 0 if linked-list has no cycle
int detectCycle(linkedlist* head){

    //initializing slow and fast pointers
    linkedlist* slow=head;
    linkedlist* fast=head;

    while(fast!=NULL&&fast->next!=NULL){
    	slow=slow->next;
	fast=fast->next->next;
	if(slow==fast){
	    return 1;
	}
    }
    return 0;
}


//Function to remove Cycle- flyod Cycle removal algorithm
void removeCycle(linkedlist* head){

    //initializing slow and fast pointer
    linkedlist* slow=head;
    linkedlist* fast=head;

    //intializing flag variable for taking record if list has cycle or not
    int flag=0;
    //previous pointer to slow pointer, for special case od circuler linked-list
    linkedlist* prevSlow=NULL;

    //Cycle detection algorithm    
    while(fast!=NULL&&fast->next!=NULL){
	prevSlow=slow;
    	slow=slow->next;
	fast=fast->next->next;

	if(slow==fast){

	    //Special case- Circular linked-list
	    if(slow==head){
	    	prevSlow->next=NULL;
		return;
	    }

	    flag=1;	    
	    fast=head;
	    break;
	}

    }
    //if cycle is detected
    if(flag==1){
    	while(slow->next!=fast->next){
	    slow=slow->next;
	    fast=fast->next;
	}
	slow->next=NULL;
    }
    //if cycle is not present
    if(flag==0){
    	printf("ERROR: No Cycle to remove\n");
    }
}

#define linkedListCycleLib
#endif
