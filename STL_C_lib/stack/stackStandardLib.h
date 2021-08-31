#ifndef stackStandardLib

#include <stdlib.h>

//<-----------STACK NODES----------->

//Node for Integer Stack
struct stack{
    void* data;
    struct stack* next;
    int length;
    int datatype;
};
typedef struct stack stack;


//<--------------------------------->


//<--------DATATYPE CONSTANTS--------->
// 1-int
// 2-char
// 3-float
// 4-string

int dataInt=-1;
char dataChar='\0';
float dataFloat=-1;
char* dataString="";

//<----------------------------------->


//<------------------CONSTRUCTION OF STACK------------------->


//Function to construct Integer Stack 
stack* constructStack(int datatype){

    //allocate memory for queue
    stack* head=(stack*)malloc(sizeof(stack));

    //intialization of data in structure
    head->length=-1;
    head->next=NULL;
    head->datatype=datatype;

    //intialization according to datatypes
    if(datatype==1){
    	head->data=(void*)&dataInt;
    }else if(datatype==2){
	head->data=(void*)&dataChar; 
    }else if(datatype==3){
	head->data=(void*)&dataFloat;
    }else if(datatype==4){
	head->data=(void*)&dataString;
    }

}

//<------------------------------------------------------------->


//<--------------------PUSH IN THE STACK------------------------>


//Function to push into Stack
void push(stack* head,void* val){

    //if stack is empty
    if(head->length==-1){
    	head->data=val;
	head->length=1;
	return;
    }

    //Intializing memory for stack element
    stack* newNode=(stack*)malloc(sizeof(stack));
    
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


//Function to pop from Stack
void pop(stack* head){
    
    //if stack is empty
    if(head->length==-1){
    	printf("ERROR: Stack is Empty\n");
	return;
    }

    //if stack has only one element
    if(head->next==NULL){
    	if(head->datatype==1){
    	    head->data=&dataInt;
	}else if(head->datatype==2){
	    head->data=&dataChar;
	}else if(head->datatype==3){
	    head->data=&dataFloat;
	}else if(head->datatype==4){
	    head->data=&dataString;
	}
	head->length=-1;
	return;
    }

    //poping the element at top
    head->data=head->next->data;
    stack* todelete=head->next;
    head->next=head->next->next;

    //free the unusable memory
    free(todelete);

    //decrease length of stack
    head->length-=1;
        
}


//<--------------------------------------------------------->


//<-------------------TOP OF STACK------------------------->


//Function to get top element of Stack
void* top(stack* head){

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
int stackIsEmpty(stack* head){
    return head->length>0?0:1;
}


//<----------------------------------------------------------->


//<------------------SIZE OF STACK------------------------>


//Function to return size of stack
int sizeOfStack(stack* head){
     
     //if stack is empty
     if(head->length<=0){
     	return 0;
     }
     return head->length;
}


//<--------------------------------------------------------->
#define stackStandardLib
#endif
