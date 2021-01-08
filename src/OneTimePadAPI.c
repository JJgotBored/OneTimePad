#include<stdio.h>
#include"OneTimePadAPI.h"

/** Function to create one time pad encryption key
 * @pre name must not be null
        seed must be unsigned int
        keyPointer must not point to anything
 * @post keyPointer will point to new OTPKey
 * @return returns OTPErrorCode indecating success or failure
**/
OTPErrorCode buildOTPKey(char* name, unsigned int seed, OTPKey** keyPointer ){
    if(name == NULL){
        return 1;
    }
    OTPKey* newKey = (OTPKey*)(malloc(sizeof(OTPKey)*1));
    
    //set name
    newKey->name = (char*)(malloc(sizeof(char)*(strlen(name)+1))); 
    strcpy(newKey->name, name);
    //set seed
    newKey->seed = seed;
    //set offset
    srand(seed);
    for(int i = 0; i < 280; i++){
        newKey->offset[i] = rand()%67;
    }

    *keyPointer = newKey;

    return 0;
}
/** Function to free one time pad encryption key
 * @pre keyPointer must not be null
 * @post keyPointer is deallocated 
 * @return returns OTPErrorCode indecating success or failure
**/
OTPErrorCode freeOTPKey(OTPKey* keyPointer){
    if(keyPointer == NULL){
        return 2;
    }
    free(keyPointer->name);
    free(keyPointer);

    return 0;
}