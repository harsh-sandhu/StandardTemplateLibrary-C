#ifndef stackStandardLib

#include <stdlib.h>

//<-----------STACK NODES----------->

//Node for Integer Stack
struct StackInt{
    int data;
    struct StackInt* next;
    int length;
};
typedef struct StackInt StackInt;


//Node for Character Stack
struct StackChar{
    char data;
    struct StackChar* next;
    int length;
};
typedef struct StackChar StackChar;


//Node for Float Stack
struct StackFloat{
    float data;
    struct StackFloat* next;
    int length;
};
typedef struct StackFloat StackFloat;

//<--------------------------------->


//<------------------CONSTRUCTION OF STACK------------------->


//Function to construct Integer Stack 
StackInt* constructIntStack(){
    StackInt* head=(StackInt*)malloc(sizeof(StackInt));
    head->data=-1;
    head->length=-1;
    head->next=NULL;
}


//Function to construct Character Stack 
StackChar* constructCharStack(){
    StackChar* head=(StackChar*)malloc(sizeof(StackChar));
    head->data='\0';
    head->length=-1;
    head->next=NULL;
}


//Function to construct Float Stack 
StackFloat* constructFloatStack(){
    StackFloat* head=(StackFloat*)malloc(sizeof(StackFloat));
    head->data=-1;
    head->length=-1;
    head->next=NULL;
}


//<---------------------------------------------------------->


//<--------------------PUSH IN THE STACK------------------------>


//Function to push into Integer Stack
void pushInIntStack(StackInt* head,int val){

    //if stack is empty
    if(head->length==-1){
    	head->data=val;
	head->length=1;
	return;
    }

    //Intializing memory for stack element
    StackInt* newNode=(StackInt*)malloc(sizeof(StackInt));
    
    //assigning at the top 
    newNode->data=head->data;
    newNode->next=head->next;
    head->next=newNode;
    head->data=val;

    //increase length of stack
    head->length+=1;
}


//Function to push into Character Stack
void pushInCharStack(StackChar* head,char val){

    //if stack is empty
    if(head->length==-1){
    	head->data=val;
	head->length=1;
	return;
    }

    //Intializing memory for stack element
    StackChar* newNode=(StackChar*)malloc(sizeof(StackChar));
    
    //assigning at the top 
    newNode->data=head->data;
    newNode->next=head->next;
    head->next=newNode;
    head->data=val;

    //increase length of stack
    head->length+=1;
}


//Function to push into Float Stack
void pushInFloatStack(StackFloat* head,float val){

    //if stack is empty
    if(head->length==-1){
    	head->data=val;
	head->length=1;
	return;
    }

    //Intializing memory for stack element
    StackFloat* newNode=(StackFloat*)malloc(sizeof(StackFloat));
    
    //assigning at the top 
    newNode->data=head->data;
    newNode->next=head->next;
    head->next=newNode;
    head->data=val;

    //increase length of stack
    head->length+=1;
}


//<-------------------------------------------------------------------->


//<----------------------POP FROM THE STACK--------------------------->



//Function to pop from Integer Stack
void popFromIntStack(StackInt* head){
    
    //if stack is empty
    if(head->length==-1){
    	printf("ERROR: Stack is Empty\n");
	return;
    }

    //if stack has only one element
    if(head->next==NULL){
    	head->data=-1;
	head->length=-1;
	return;
    }

    //poping the element at top
    head->data=head->next->data;
    StackInt* todelete=head->next;
    head->next=head->next->next;

    //free the unusable memory
    free(todelete);

    //decrease length of stack
    head->length-=1;
        
}


//Function to pop from Character Stack
void popFromCharStack(StackChar* head){
    
    //if stack is empty
    if(head->length==-1){
    	printf("ERROR: Stack is Empty\n");
	return;
    }

    //if stack has only one element
    if(head->next==NULL){
    	head->data=-1;
	head->length=-1;
	return;
    }

    //poping the element at top
    head->data=head->next->data;
    StackChar* todelete=head->next;
    head->next=head->next->next;

    //free the unusable memory
    free(todelete);

    //decrease length of stack
    head->length-=1;
        
}


//Function to pop from Float Stack
void popFromFloatStack(StackFloat* head){
    
    //if stack is empty
    if(head->length==-1){
    	printf("ERROR: Stack is Empty\n");
	return;
    }

    //if stack has only one element
    if(head->next==NULL){
    	head->data=-1;
	head->length=-1;
	return;
    }

    //poping the element at top
    head->data=head->next->data;
    StackFloat* todelete=head->next;
    head->next=head->next->next;

    //free the unusable memory
    free(todelete);

    //decrease length of stack
    head->length-=1;
        
}


//<--------------------------------------------------------->


//<-------------------TOP OF STACK------------------------->


//Function to get top element of Integer Stack
int topOfIntStack(StackInt* head){

    //if stack at empty
    if(head->length==-1){
    	printf("ERROR: Stack is Empty\n");
	exit(1);
    }

    //return top element of stack
    return head->data;

}


//Function to get top element of Character Stack
char topOfCharStack(StackChar* head){

    //if stack at empty
    if(head->length==-1){
    	printf("ERROR: Stack is Empty\n");
	exit(1);
    }

    //return top element of stack
    return head->data;

}

//Function to get top element of Float Stack
float topOfFloatStack(StackFloat* head){

    //if stack at empty
    if(head->length==-1){
    	printf("ERROR: Stack is Empty\n");
	exit(1);
    }

    //return top element of stack
    return head->data;

}


//<-------------------------------------------------------->


//<---------------------STACK IS EMPTY------------------------->


//Function which returns if stack is empty or not
int intStackIsEmpty(StackInt* head){
    return head->length>0?0:1;
}


//Function which returns if stack is empty or not
int charStackIsEmpty(StackChar* head){
    return head->length>0?0:1;
}


//Function which returns if stack is empty or not
int floatStackIsEmpty(StackFloat* head){
    return head->length>0?0:1;
}


//<----------------------------------------------------------->


//<------------------SIZE OF STACK------------------------>


//Function to return size of Integer stack
int sizeOfIntStack(StackInt* head){
     
     //if stack is empty
     if(head->length<=0){
     	return 0;
     }
     return head->length;
}


//Function to return size of Character stack
int sizeOfCharStack(StackChar* head){
     
     //if stack is empty
     if(head->length<=0){
     	return 0;
     }
     return head->length;
}


//Function to return size of Float stack
int sizeOfFloatStack(StackFloat* head){
     
     //if stack is empty
     if(head->length<=0){
     	return 0;
     }
     return head->length;
}


//<--------------------------------------------------------->
#define stackStandardLib
#endif
