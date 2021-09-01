#ifndef stackCollection
#include "stackStandardLib.h"
#include "mStacklib.h"
void pushArr(stack* head,void* arr[],int n){
    for(int i=0;i<n;i++){
    	push(head,arr[i]);
    }
}
void pushArrInMStack(mstack* head,void* arr[],int n){
    for(int i=0;i<n;i++){
    	pushMStack(head,arr[i]);
    }
}
#define stackCollection
#endif
