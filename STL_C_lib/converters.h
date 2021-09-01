#ifndef converters

//integer to void pointer
void itovp(int* arr,void* ptr[],int n){
     for(int i=0;i<n;i++){
     	ptr[i]=(void*)&arr[i];
     }
}

//Character to void pointer
void ctovp(char* arr,void* ptr[],int n){
     for(int i=0;i<n;i++){
     	ptr[i]=(void*)&arr[i];
     }
}

//Float to void pointer
void ftovp(float* arr,void* ptr[],int n){
    for(int i=0;i<n;i++){
    	ptr[i]=(void*)&arr[i];
    }
}
#define converters
#endif
