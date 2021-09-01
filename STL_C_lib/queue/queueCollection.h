#ifndef queueCollection
#include "standardQueue.h"
#include "standardDeque.h"
void enqueueArr(queue* head,void* arr[],int n){
    for(int i=0;i<n;i++){
    	enqueue(head,arr[i]);
    }
}

void enqueueFrontArr(deque* head,void* arr[],int n){
    for(int i=0;i<n;i++){
    	enqueueFront(head,arr[i]);
    }
}

void enqueueBackArr(deque* head,void* arr[],int n){
    for(int i=0;i<n;i++){
    	enqueueBack(head,arr[i]);
    }
}
#define queueCollection
#endif
