#ifndef linkedListLib

//required in-built headers
#include <stdlib.h>
#include "../DataTypes.h"


//<-----------------NODE------------------>

//Node
struct linkedlist{
    void* data;
    int length;
    struct linkedlist *next;
    struct linkedlist *end;
    int datatype;
};
typedef struct linkedlist linkedlist;


//<-------------------------------------------->


//<------------------CONSTRUCTION------------------>

//Function for Construction of LinkedList


//returns a pointer - linkedlist*
linkedlist* constructLinkedList(int datatype){

    linkedlist* head=(linkedlist*)malloc(sizeof(linkedlist));

    head->next=NULL;
    head->end=NULL;
    head->length=-1;

    if(datatype==1){
    	head->data=(void*)&dataInt;
    }else if(datatype==2){
	head->data=(void*)&dataChar; 
    }else if(datatype==3){
	head->data=(void*)&dataFloat;
    }else if(datatype==4){
	head->data=(void*)&dataString;
    }
    head->datatype=datatype;

    return head;
}


//<------------------------------------------------------->


//<----------------------------INSERTION------------------------------->



//Function for inserting element at head in linked-list
void insertAtHead(linkedlist* head,void* val){
    
    //if element to be added is first element
    if(head->length==-1){
        head->data=val;
	head->length=1;
	head->end=head;
	return;
    }

    //Initializing memory for new node
    linkedlist* newNode=(linkedlist*)malloc(sizeof(linkedlist));

    //adding Node at start(without changing the head pointer)
    newNode->data=head->data;
    newNode->next=head->next;
    head->data=val;
    head->next=newNode;
    if(head->length==1){
	    head->end=newNode;
    }

   //Increase length of linked-list
    head->length+=1;
}


//Function for inserting element at tail in linked-list
void insertAtTail(linkedlist* head,void* n){

    //if element is to be added is first Element
    if(head->length==-1){
    	head->data=n;
	head->length=1;
	head->end=head;
	return;
    }

    //initializing memory for new node
    linkedlist* newNode=(linkedlist*)malloc(sizeof(linkedlist));
    newNode->data=n;
    newNode->next=NULL;


    //attaching last node at end
    head->end->next=newNode;
    head->end=newNode;

    //increasing the length of list;
    head->length+=1;
}


//<--------------------------------------------------------------------->


//<----------------------------DELETION--------------------------------->



//Function to delete Node at the end
void deleteAtTail(linkedlist* head){

    //if linked-list is already empty
    if(head->length==-1){
    	printf("ERROR: Linked-list is empty\n");
	return;
    }

    //if linked-list has only one element
    if(head->next==NULL){
        head->length=-1;
	if(head->datatype==1){
    	    head->data=&dataInt;
	}else if(head->datatype==2){
	    head->data=&dataChar;
	}else if(head->datatype==3){
	    head->data=&dataFloat;
	}else if(head->datatype==4){
	    head->data=&dataString;
	}
	head->end=NULL;
	return;
    }

    linkedlist* todelete=head->end;
    linkedlist* prev=NULL;
    linkedlist* temp=head;
    while(temp->next!=NULL){
    	prev=temp;
	temp=temp->next;
    }
    prev->next=NULL;
    head->end=prev;

    //free the garbage memory
    free(todelete);

    //reduce size of linked-list
    head->length-=1;
}


//Function to delete Node at the head, Character type
void deleteAtHead(linkedlist* head){
    
    //if linked-list is already empty
    if(head->length==-1){
    	printf("ERROR: Linked-list is empty\n");
	return;
    }

    //if linked-list had only one element
    if(head->next==NULL){
    	head->length=-1;
	if(head->datatype==1){
    	    head->data=&dataInt;
	}else if(head->datatype==2){
	    head->data=&dataChar;
	}else if(head->datatype==3){
	    head->data=&dataFloat;
	}else if(head->datatype==4){
	    head->data=&dataString;
	}
	head->end=NULL;
	return;
    }
    
    //removing the head without deleting head pointer
    head->data=head->next->data;
    linkedlist* todelete=head->next;
    head->next=head->next->next;
    if(head->length==2){
    	head->end=head;
    }

    //free the initialized memory
    free(todelete);

    //reduce size of list
    head->length-=1;
}


//<--------------------------------------------------------------------->


//<---------------------PRINT-------------------->


//Function to print Linked-list
void printLinkedlist(linkedlist* head){
    linkedlist* temp=head;
    while(temp!=NULL){
	if(head->datatype==1){
    	    printf("%d ",*(int*)temp->data);
	}else if(head->datatype==2){
	    printf("%c ",*(char*)temp->data);
	}else if(head->datatype==3){
	    printf("%f ",*(float*)temp->data);
	}else if(head->datatype==4){
	    printf("%s ",(char*)temp->data);
	}   
	temp=temp->next;
    }
    printf("\n");
}


//<---------------------------------------------->



//Function to return length of Linked-List
int sizeLinkedlist(linkedlist* head){
    return head->length;
}

#define linkedListLib
#endif
