#include<stdio.h>
#include"OneTimePadAPI.h"


OTPErrorCode buildOTPKey(char* name, unsigned int seed, OTPKey** keyPointer ){
    if(name == NULL){
        return 1;
    }

    OTPKey* newKey = (OTPKey*)(malloc(sizeof(OTPKey)*1));

    newKey->name = (char*)(malloc(sizeof(char)*(strlen(name)+1))); 
    strcpy(newKey->name, name);

    newKey->seed = seed;

    srand(seed);
    for(int i = 0; i < 280; i++){
        newKey->offset[i] = rand()%67;
    }

    return 0;
}