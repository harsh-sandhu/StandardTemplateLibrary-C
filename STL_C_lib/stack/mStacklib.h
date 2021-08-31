#ifndef mStacklib

#include <stdlib.h>
#include <limits.h>

//<-----------STACK NODES----------->


//Node for MinMaxStack
struct mstack{
    void* data;
    struct mstack* next;
    void* min;
    void* max;
    int length;
    int datatype;
};
typedef struct mstack mstack;


//<--------------------------------->

//<--------DATATYPE CONSTANTS--------->
// 1-int
// 2-char
// 3-float
// XXX4-stringXXXX

int dataIntMin=INT_MIN;
char dataCharMin=CHAR_MIN;
float dataFloatMin=INT_MIN;
//XXXchar* dataStringMax=CHAR_MINXXX;

int dataIntMax=INT_MAX;
char dataCharMax=CHAR_MAX;
float dataFloatMax=INT_MAX;
//XXXchar* dataStringMax=CHAR_MAXXXX;

//<----------------------------------->


//<------------------CONSTRUCTION OF STACK------------------->


//Function to construct Stack 
mstack* constructMStack(int datatype){

    if(datatype==4){
    	printf("ERROR: String cant be used in MIN-MAX Stack\n");
	exit(0);
    }
    if(datatype>4){
    	printf("ERROR: Invalid data type\n");
	exit(0);
    }
    mstack* head=(mstack*)malloc(sizeof(mstack));
    head->datatype=datatype;

    //intialization according to datatypes
    if(datatype==1){
    	head->data=(void*)&dataInt;
	head->min=(void*)&dataIntMax;
        head->max=(void*)&dataIntMin;
    }else if(datatype==2){
	head->data=(void*)&dataChar;
        head->min=(void*)&dataCharMax;
        head->max=(void*)&dataCharMin;
    }else if(datatype==3){
	head->data=(void*)&dataFloat;
	head->min=(void*)&dataFloatMax;
        head->max=(void*)&dataFloatMin;
    }
    //else if(datatype==4){
    //	head->data=(void*)&dataString;
    //	head->min=(void*)&dataStringMax;
    //	head->max=(void*)&dataStringMin;
    //}

    head->length=-1;
    head->next=NULL;
}


//<-------------------------------------------------------->


//<--------------------PUSH IN THE STACK------------------------>


//Function to push into Stack
void pushMStack(mstack* head,void* val){

    //if stack is empty
    if(head->length==-1){
    	head->data=val;
	head->min=val;
	head->max=val;
	head->length=1;
	return;
    }

    //Intializing memory for stack element
    mstack* newNode=(mstack*)malloc(sizeof(mstack));
    
    //checking for min and max
    int valInt,headIntMin,headIntMax;
    char valChar,headCharMin,headCharMax;
    float valFloat,headFloatMin,headFloatMax;
    int flagMin=0,flagMax=0;
    if(head->datatype==1){
    	valInt=*(int*)val;
	headIntMin=*(int*)head->min;
	headIntMax=*(int*)head->max;
	if(headIntMin>valInt){
	    flagMin=1;
	}
	if(headIntMax<valInt){
	    flagMax=1;
	}
    }else if(head->datatype==2){
    	valChar=*(char*)val;
	headCharMin=*(char*)head->min;
	headCharMax=*(char*)head->max;

	if(headCharMin>valChar){
	    flagMin=1;
	}
	if(headCharMax<valChar){
	    flagMax=1;
	}
    }else if(head->datatype==2){
    	valFloat=*(float*)val;
	headFloatMin=*(float*)head->min;
	headFloatMax=*(float*)head->max;
	if(headFloatMin>valFloat){
	    flagMin=1;
	}
	if(headFloatMax<valFloat){
	    flagMax=1;
	}
    }

    void* min;
    void* max;
    if(flagMin){
    	min=val;
    }else{
    	min=head->min;
    }
    if(flagMax){
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



//Function to pop from Stack
void popMStack(mstack* head){
    
    //if stack is empty
    if(head->length==-1){
    	printf("ERROR: Stack is Empty\n");
	return;
    }

    //if stack has only one element
    if(head->next==NULL){
    	if(head->datatype==1){
    	    head->data=(void*)&dataInt;
	    head->min=(void*)&dataIntMax;
	    head->max=(void*)&dataIntMin;
    	}else if(head->datatype==2){
	    head->data=(void*)&dataChar;
            head->min=(void*)&dataCharMax;
            head->max=(void*)&dataCharMin;
    	}else if(head->datatype==3){
	    head->data=(void*)&dataFloat;
	    head->min=(void*)&dataFloatMax;
            head->max=(void*)&dataFloatMin;
    	}
	//else if(datatype==4){
	//    head->data=(void*)&dataString;
	//    head->min=(void*)&dataStringMax;
	//    head->max=(void*)&dataStringMin;
    	//}
	head->length=-1;
	return;
    }

    //poping the element at top
    head->data=head->next->data;
    head->max=head->next->max;
    head->min=head->next->min;
    mstack* todelete=head->next;
    head->next=head->next->next;

    //free the unusable memory
    free(todelete);

    //decrease length of stack
    head->length-=1;
        
}


//<--------------------------------------------------------->


//<-------------------TOP OF STACK------------------------->


//Function to get top element of Stack
void* topMStack(mstack* head){

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
void* minMStack(mstack* head){

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



//Function to get top element of Stack
void* maxMStack(mstack* head){

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
int MStackIsEmpty(mstack* head){
    return head->length>0?0:1;
}


//<----------------------------------------------------------->


//<------------------SIZE OF STACK------------------------>


//Function to return size of stack
int sizeMStack(mstack* head){
     
     //if stack is empty
     if(head->length<=0){
     	return 0;
     }
     return head->length;
}


//<--------------------------------------------------------->
#define mStacklib
#endif
