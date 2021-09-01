#ifndef linkedListCollection
#include "linkedListStandardLib.h"
void insertArrAtTail(linkedlist* head,void* arr[],int n){
    for(int i=0;i<n;i++){
    	insertAtTail(head,arr[i]);
    }
}
void insertArrAtHead(linkedlist* head,void* arr[],int n){
    for(int i=0;i<n;i++){
    	insertAtHead(head,arr[i]);
    }
}
#define linkedListCollection
#endif
