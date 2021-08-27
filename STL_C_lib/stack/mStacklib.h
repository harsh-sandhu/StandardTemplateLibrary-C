#ifndef stackStandardLib

#include <stdlib.h>
#include <limits.h>

//<-----------STACK NODES----------->

//Node for Integer Stack
struct MinMaxStackInt{
    int data;
    struct MinMaxStackInt* next;
    int min;
    int max;
    int length;
};
typedef struct MinMaxStackInt MinMaxStackInt;


//Node for Character Stack
struct MinMaxStackChar{
    char data;
    struct MinMaxStackChar* next;
    char min;
    char max;
    int length;
};
typedef struct MinMaxStackChar MinMaxStackChar;


//Node for Float Stack
struct MinMaxStackFloat{
    float data;
    struct MinMaxStackFloat* next;
    float min;
    float max;
    int length;
};
typedef struct MinMaxStackFloat MinMaxStackFloat;

//<--------------------------------->


//<------------------CONSTRUCTION OF STACK------------------->


//Function to construct Integer Stack 
MinMaxStackInt* constructIntMStack(){
    MinMaxStackInt* head=(MinMaxStackInt*)malloc(sizeof(MinMaxStackInt));
    head->data=-1;
    head->min=INT_MAX;
    head->max=INT_MIN;
    head->length=-1;
    head->next=NULL;
}


//Function to construct Character Stack 
MinMaxStackChar* constructCharMStack(){
    MinMaxStackChar* head=(MinMaxStackChar*)malloc(sizeof(MinMaxStackChar)); 
    head->data='\0';
    head->min=CHAR_MAX;
    head->max=CHAR_MIN;
    head->length=-1;
    head->next=NULL;
}


//Function to construct Float Stack 
MinMaxStackFloat* constructFloatMStack(){
    MinMaxStackFloat* head=(MinMaxStackFloat*)malloc(sizeof(MinMaxStackFloat));
    head->min=1000.000;
    head->max=-1000.000;
    head->data=-1;
    head->length=-1;
    head->next=NULL;
}


//<---------------------------------------------------------->


//<--------------------PUSH IN THE STACK------------------------>


//Function to push into Integer Stack
void pushInIntMStack(MinMaxStackInt* head,int val){

    //if stack is empty
    if(head->length==-1){
    	head->data=val;
	head->min=val;
	head->max=val;
	head->length=1;
	return;
    }

    //Intializing memory for stack element
    MinMaxStackInt* newNode=(MinMaxStackInt*)malloc(sizeof(MinMaxStackInt));
    
    //checking for min and max
    int min,max;
    if(head->min>val){
    	min=val;
    }else{
    	min=head->min;
    }
    if(head->max<val){
    	max=val;
    }else{
    	max=head->max;
    }

    //assigning at the top 
    newNode->data=head->data;
    newNode->min=head->min;
    newNode->max=head->max;
    newNode->next=head->next;
    head->next=newNode;
    head->data=val;
    head->min=min;
    head->max=max;

    //increase length of stack
    head->length+=1;
}


//Function to push into Character Stack
void pushInCharMStack(MinMaxStackChar* head,char val){
    
    //if stack is empty
    if(head->length==-1){
    	head->data=val;
	head->min=val;
	head->max=val;
	head->length=1;
	return;
    }

    //Intializing memory for stack element
    MinMaxStackChar* newNode=(MinMaxStackChar*)malloc(sizeof(MinMaxStackChar));
    
    //checking for min and max
    char min,max;
    if(head->min>val){
    	min=val;
    }else{
    	min=head->min;
    }
    if(head->max<val){
    	max=val;
    }else{
    	max=head->max;
    }

    //assigning at the top 
    newNode->data=head->data;
    newNode->min=head->min;
    newNode->max=head->max;
    newNode->next=head->next;
    head->next=newNode;
    head->data=val;
    head->min=min;
    head->max=max;

    //increase length of stack
    head->length+=1;
}


//Function to push into Float Stack
void pushInFloatMStack(MinMaxStackFloat* head,float val){
    
    //if stack is empty
    if(head->length==-1){
    	head->data=val;
	head->min=val;
	head->max=val;
	head->length=1;
	return;
    }

    //Intializing memory for stack element
    MinMaxStackFloat* newNode=(MinMaxStackFloat*)malloc(sizeof(MinMaxStackFloat));
    
    //checking for min and max
    float min,max;
    if(head->min>val){
    	min=val;
    }else{
    	min=head->min;
    }
    if(head->max<val){
    	max=val;
    }else{
    	max=head->max;
    }

    //assigning at the top 
    newNode->data=head->data;
    newNode->min=head->min;
    newNode->max=head->max;
    newNode->next=head->next;
    head->next=newNode;
    head->data=val;
    head->min=min;
    head->max=max;

    //increase length of stack
    head->length+=1;
}



//<-------------------------------------------------------------------->


//<----------------------POP FROM THE STACK--------------------------->



//Function to pop from Integer Stack
void popFromIntMStack(MinMaxStackInt* head){
    
    //if stack is empty
    if(head->length==-1){
    	printf("ERROR: Stack is Empty\n");
	return;
    }

    //if stack has only one element
    if(head->next==NULL){
    	head->data=-1;
	head->max=INT_MIN;
	head->min=INT_MAX;
	head->length=-1;
	return;
    }

    //poping the element at top
    head->data=head->next->data;
    head->max=head->next->max;
    head->min=head->next->min;
    MinMaxStackInt* todelete=head->next;
    head->next=head->next->next;

    //free the unusable memory
    free(todelete);

    //decrease length of stack
    head->length-=1;
        
}


//Function to pop from Character Stack
void popFromCharMStack(MinMaxStackChar* head){
    
    //if stack is empty
    if(head->length==-1){
    	printf("ERROR: Stack is Empty\n");
	return;
    }

    //if stack has only one element
    if(head->next==NULL){
    	head->data=-1;
	head->max=CHAR_MIN;
	head->min=CHAR_MAX;
	head->length=-1;
	return;
    }

    //poping the element at top
    head->data=head->next->data;
    head->max=head->next->max;
    head->min=head->next->min;
    MinMaxStackChar* todelete=head->next;
    head->next=head->next->next;

    //free the unusable memory
    free(todelete);

    //decrease length of stack
    head->length-=1;
        
}


//Function to pop from Float Stack
void popFromFloatMStack(MinMaxStackFloat* head){
    
    //if stack is empty
    if(head->length==-1){
    	printf("ERROR: Stack is Empty\n");
	return;
    }

    //if stack has only one element
    if(head->next==NULL){
    	head->data=-1;
	head->max=100000.000;
	head->min=-100000.000;
	head->length=-1;
	return;
    }

    //poping the element at top
    head->data=head->next->data;
    head->max=head->next->max;
    head->min=head->next->min;
    MinMaxStackFloat* todelete=head->next;
    head->next=head->next->next;

    //free the unusable memory
    free(todelete);

    //decrease length of stack
    head->length-=1;
        
}


//<--------------------------------------------------------->


//<-------------------TOP OF STACK------------------------->


//Function to get top element of Integer Stack
int topOfIntMStack(MinMaxStackInt* head){

    //if stack at empty
    if(head->length==-1){
    	printf("ERROR: Stack is Empty\n");
	exit(1);
    }

    //return top element of stack
    return head->data;

}


//Function to get top element of Character Stack
char topOfCharMStack(MinMaxStackChar* head){

    //if stack at empty
    if(head->length==-1){
    	printf("ERROR: Stack is Empty\n");
	exit(1);
    }

    //return top element of stack
    return head->data;

}

//Function to get top element of Float Stack
float topOfFloatMStack(MinMaxStackFloat* head){

    //if stack at empty
    if(head->length==-1){
    	printf("ERROR: Stack is Empty\n");
	exit(1);
    }

    //return top element of stack
    return head->data;

}


//<-------------------------------------------------------->


//<----------------------MIN IN STACK----------------------->

//Function to get min element of Integer Stack
int minOfIntMStack(MinMaxStackInt* head){

    //if stack at empty
    if(head->length==-1){
    	printf("ERROR: Stack is Empty\n");
	exit(1);
    }

    //return top element of stack
    return head->min;

}


//Function to get top element of Character Stack
char minOfCharMStack(MinMaxStackChar* head){

    //if stack at empty
    if(head->length==-1){
    	printf("ERROR: Stack is Empty\n");
	exit(1);
    }

    //return top element of stack
    return head->min;

}

//Function to get top element of Float Stack
float minOfFloatMStack(MinMaxStackFloat* head){

    //if stack at empty
    if(head->length==-1){
    	printf("ERROR: Stack is Empty\n");
	exit(1);
    }

    //return top element of stack
    return head->min;

}


//<---------------------------------------------------------->


//<----------------------MAX IN STACK------------------------->



//Function to get top element of Integer Stack
int maxOfIntMStack(MinMaxStackInt* head){

    //if stack at empty
    if(head->length==-1){
    	printf("ERROR: Stack is Empty\n");
	exit(1);
    }

    //return top element of stack
    return head->max;

}


//Function to get top element of Character Stack
char maxOfCharMStack(MinMaxStackChar* head){

    //if stack at empty
    if(head->length==-1){
    	printf("ERROR: Stack is Empty\n");
	exit(1);
    }

    //return top element of stack
    return head->max;

}

//Function to get top element of Float Stack
float maxOfFloatMStack(MinMaxStackFloat* head){

    //if stack at empty
    if(head->length==-1){
    	printf("ERROR: Stack is Empty\n");
	exit(1);
    }

    //return top element of stack
    return head->max;

}


//<--------------------------------------------------------->


//<---------------------STACK IS EMPTY------------------------->


//Function which returns if stack is empty or not
int intMStackIsEmpty(MinMaxStackInt* head){
    return head->length>0?0:1;
}


//Function which returns if stack is empty or not
int charMStackIsEmpty(MinMaxStackChar* head){
    return head->length>0?0:1;
}


//Function which returns if stack is empty or not
int floatMStackIsEmpty(MinMaxStackFloat* head){
    return head->length>0?0:1;
}


//<----------------------------------------------------------->


//<------------------SIZE OF STACK------------------------>


//Function to return size of Integer stack
int sizeOfIntMStack(MinMaxStackInt* head){
     
     //if stack is empty
     if(head->length<=0){
     	return 0;
     }
     return head->length;
}


//Function to return size of Character stack
int sizeOfCharMStack(MinMaxStackChar* head){
     
     //if stack is empty
     if(head->length<=0){
     	return 0;
     }
     return head->length;
}


//Function to return size of Float stack
int sizeOfFloatMStack(MinMaxStackFloat* head){
     
     //if stack is empty
     if(head->length<=0){
     	return 0;
     }
     return head->length;
}


//<--------------------------------------------------------->
#define stackStandardLib
#endif
