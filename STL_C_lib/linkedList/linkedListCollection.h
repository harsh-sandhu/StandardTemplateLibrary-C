#ifndef linkedListCollection
#include "linkedListStandardLib.h"
#include "doublyLinkedList.h"

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

void insertArrAtTailDLL(dlinkedlist* head, void* arr[],int n){
    for(int i=0;i<n;i++){
    	insertAtTailDLL(head,arr[i]);
    }
}


void insertArrAtHeadDLL(dlinkedlist* head, void* arr[],int n){
    for(int i=0;i<n;i++){
    	insertAtHeadDLL(head,arr[i]);
    }
}
#define linkedListCollection
#endif
