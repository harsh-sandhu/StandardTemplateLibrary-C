#ifndef linkedListLib

//required in-built headers
#include <stdlib.h>


//<-----------------TYPES OF NODES--------------->

//Node for Integer data-type
struct NodeInt{
    int data;
    int length;
    struct NodeInt *next;
};
typedef struct NodeInt NodeInt;

//Node for Character data-type
struct NodeChar{
    char data;
    int length;
    struct NodeChar *next;
};
typedef struct NodeChar NodeChar;

//Node for Float data-type
struct NodeFloat{
    float data;
    int length;
    struct NodeFloat *next;
};
typedef struct NodeFloat NodeFloat;

//<-------------------------------------------->


//<------------------CONSTRUCTION------------------>

//Functions for Construction of LinkedList for various data-types


//returns a pointer Integer Node -- NodeInt
NodeInt* constructIntLinkedlist(){

    NodeInt* head=(NodeInt*)malloc(sizeof(NodeInt));

    head->next=NULL;
    head->data=-1;
    head->length=-1;

    return head;
}


//returns a pointer Character Node -- NodeChar
NodeChar* constructCharLinkedlist(){

    NodeChar* head=(NodeChar*)malloc(sizeof(NodeChar));

    head->next=NULL;
    head->data='\0';
    head->length=-1;

    return head;
}


//returns a pointer Float Node -- NodeFloat
NodeFloat* constructFloatLinkedlist(){

    NodeFloat* head=(NodeFloat*)malloc(sizeof(NodeFloat));

    head->next=NULL;
    head->data=-1;
    head->length=-1;

    return head;
}


//------------------------------------------------>


//<----------------------------INSERTION------------------------------->



//       ~~~INTEGER~~~



//Function for inserting element at head in linked-list, Integer-type
void insertIntAtHead(NodeInt* head,int val){
    
    //if element to be added is first element
    if(head->length==-1){
        head->data=val;
	head->length=1;
	return;
    }

    //Initializing memory for new node
    NodeInt* newNode=(NodeInt*)malloc(sizeof(NodeInt));

    //adding Node at start(without changing the head pointer)
    int tempVal=head->data;
    newNode->data=tempVal;
    newNode->next=head->next;
    head->data=val;
    head->next=newNode;

   //Increase length of linked-list
    head->length+=1;
}


//Function for inserting element at tail in linked-list, Integer-type
void insertIntAtTail(NodeInt* head,int n){

    //if element is to be added is first Element
    if(head->length==-1){
    	head->data=n;
	head->length=1;
	return;
    }

    //initializing memory for new node
    NodeInt* newNode=(NodeInt*)malloc(sizeof(NodeInt));
    newNode->data=n;
    newNode->next=NULL;

    //traversing till end of linked-list
    NodeInt* temp=head;
    while(temp->next!=NULL){
    	temp=temp->next;
    }

    //attaching last node at end
    temp->next=newNode;

    //increasing the length of list;
    head->length+=1;
}



//         ~~~CHARACTER~~~



//Function for inserting element at head in linked-list, Character-type
void insertCharAtHead(NodeChar* head,char c){
    
    //if element to be added is first element
    if(head->length==-1){
        head->data=c;
	head->length=1;
	return;
    }

    //Initializing memory for new node
    NodeChar* newNode=(NodeChar*)malloc(sizeof(NodeChar));

    //adding Node at start(without changing the head pointer)
    int tempVal=head->data;
    newNode->data=tempVal;
    newNode->next=head->next;
    head->data=c;
    head->next=newNode;

   //Increase length of linked-list
    head->length+=1;
}


//Function for inserting element at tail in linked-list, Character-type
void insertCharAtTail(NodeChar* head,char c){

    //if element is to be added is first Element
    if(head->length==-1){
    	head->data=c;
	head->length=1;
	return;
    }

    //initializing memory for new node
    NodeChar* newNode=(NodeChar*)malloc(sizeof(NodeChar));
    newNode->data=c;
    newNode->next=NULL;

    //traversing till end of linked-list
    NodeChar* temp=head;
    while(temp->next!=NULL){
    	temp=temp->next;
    }

    //attaching last node at end
    temp->next=newNode;

    //increasing the length of list;
    head->length+=1;
}


//       ~~~FLOAT~~~



//Function for inserting element at head in linked-list, Float-type
void insertFloatAtHead(NodeFloat* head,float val){
    
    //if element to be added is first element
    if(head->length==-1){
        head->data=val;
	head->length=1;
	return;
    }

    //Initializing memory for new node
    NodeFloat* newNode=(NodeFloat*)malloc(sizeof(NodeFloat));

    //adding Node at start(without changing the head pointer)
    int tempVal=head->data;
    newNode->data=tempVal;
    newNode->next=head->next;
    head->data=val;
    head->next=newNode;

   //Increase length of linked-list
    head->length+=1;
}


//Function for inserting element at tail in linked-list, Float-type
void insertFloatAtTail(NodeFloat* head,float n){

    //if element is to be added is first Element
    if(head->length==-1){
    	head->data=n;
	head->length=1;
	return;
    }

    //initializing memory for new node
    NodeFloat* newNode=(NodeFloat*)malloc(sizeof(NodeFloat));
    newNode->data=n;
    newNode->next=NULL;

    //traversing till end of linked-list
    NodeFloat* temp=head;
    while(temp->next!=NULL){
    	temp=temp->next;
    }

    //attaching last node at end
    temp->next=newNode;

    //increasing the length of list;
    head->length+=1;
}


//<--------------------------------------------------------------------->


//<----------------------------DELETION--------------------------------->


//          ~~~INTEGER~~~


//Function to delete Node at the end, Integer type
void deleteIntAtTail(NodeInt* head){

    //if linked-list is already empty
    if(head->length==-1){
    	printf("ERROR: Linked-list is empty\n");
	return;
    }

    //if linked-list has only one element
    if(head->next==NULL){
        head->length=-1;
	head->data=-1;
	return;
    }

    //treverse to last element while maintaing a previous pointer to current node
    NodeInt* temp=head;
    NodeInt* prev=NULL;
    while(temp->next!=NULL){
	prev=temp;
    	temp=temp->next;
    }

    //make next pointer of second-last node NULL
    prev->next=NULL;

    //free the garbage memory
    free(temp);

    //reduce size of linked-list
    head->length-=1;
}


//Function to delete Node at the head, Character type
void deleteIntAtHead(NodeInt* head){
    
    //if linked-list is already empty
    if(head->length==-1){
    	printf("ERROR: Linked-list is empty\n");
	return;
    }

    //if linked-list had only one element
    if(head->next==NULL){
    	head->length=-1;
	head->data=-1;
	return;
    }
    
    //removing the head without deleting head pointer
    NodeInt* temp=head->next;
    int tempVal=temp->data;
    temp->data=head->data;
    head->data=tempVal;
    head->next=temp->next;
    temp->next=NULL;

    //free the initialized memory
    free(temp);

    //reduce size of list
    head->length-=1;
}

//          ~~~CHARACTER~~~


//Function to delete Node at the end, Character type
void deleteCharAtTail(NodeChar* head){

    //if linked-list is already empty
    if(head->length==-1){
    	printf("ERROR: Linked-list is empty\n");
	return;
    }

    //if linked-list has only one element
    if(head->next==NULL){
        head->length=-1;
	head->data='\0';
	return;
    }

    //treverse to last element while maintaing a previous pointer to current node
    NodeChar* temp=head;
    NodeChar* prev=NULL;
    while(temp->next!=NULL){
	prev=temp;
    	temp=temp->next;
    }

    //make next pointer of second-last node NULL
    prev->next=NULL;

    //free the garbage memory
    free(temp);

    //reduce size of linked-list
    head->length-=1;
}


//Function to delete Node at the head, Character type
void deleteCharAtHead(NodeChar* head){
    
    //if linked-list is already empty
    if(head->length==-1){
    	printf("ERROR: Linked-list is empty\n");
	return;
    }

    //if linked-list had only one element
    if(head->next==NULL){
    	head->length=-1;
	head->data='\0';
	return;
    }
    
    //removing the head without deleting head pointer
    NodeChar* temp=head->next;
    char tempVal=temp->data;
    temp->data=head->data;
    head->data=tempVal;
    head->next=temp->next;
    temp->next=NULL;

    //free the initialized memory
    free(temp);

    //reduce size of list
    head->length-=1;
}


//          ~~~FLOAT~~~


//Function to delete Node at the end, Float type
void deleteFloatAtTail(NodeFloat* head){

    //if linked-list is already empty
    if(head->length==-1){
    	printf("ERROR: Linked-list is empty\n");
	return;
    }

    //if linked-list has only one element
    if(head->next==NULL){
        head->length=-1;
	head->data=-1;
	return;
    }

    //treverse to last element while maintaing a previous pointer to current node
    NodeFloat* temp=head;
    NodeFloat* prev=NULL;
    while(temp->next!=NULL){
	prev=temp;
    	temp=temp->next;
    }

    //make next pointer of second-last node NULL
    prev->next=NULL;

    //free the garbage memory
    free(temp);

    //reduce size of linked-list
    head->length-=1;
}


//Function to delete Node at the head, Float type
void deleteFloatAtHead(NodeFloat* head){
    
    //if linked-list is already empty
    if(head->length==-1){
    	printf("ERROR: Linked-list is empty\n");
	return;
    }

    //if linked-list had only one element
    if(head->next==NULL){
    	head->length=-1;
	head->data=-1;
	return;
    }
    
    //removing the head without deleting head pointer
    NodeFloat* temp=head->next;
    float tempVal=temp->data;
    temp->data=head->data;
    head->data=tempVal;
    head->next=temp->next;
    temp->next=NULL;

    //free the initialized memory
    free(temp);

    //reduce size of list
    head->length-=1;
}


//<--------------------------------------------------------------------->




//<---------------------PRINT-------------------->


//Function to print Linked-list
void printIntLinkedlist(NodeInt* head){
    NodeInt* temp=head;
    while(temp!=NULL){
    	printf("%d ",temp->data);
	temp=temp->next;
    }
    printf("\n");
}


//Function to print Linked-list
void printCharLinkedlist(NodeChar* head){
    NodeChar* temp=head;
    while(temp!=NULL){
    	printf("%c ",temp->data);
	temp=temp->next;
    }
    printf("\n");
}


//Function to print Linked-list
void printFloatLinkedlist(NodeFloat* head){
    NodeFloat* temp=head;
    while(temp!=NULL){
    	printf("%f ",temp->data);
	temp=temp->next;
    }
    printf("\n");
}

//<---------------------------------------------->



//Function to return length of Linked-List
int sizeOfLinkedlist(NodeInt* head){
    return head->length;
}

#define linkedListLib
#endif
