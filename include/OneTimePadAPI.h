#ifndef One_Time_Pad
#define One_Time_Pad

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef enum OTPErrorCode{ok, nullName, nullKeyPointer }OTPErrorCode;

typedef struct OTPKey{
    
    char* name;
    int seed;
    int offset[280];

}OTPKey;

OTPErrorCode buildOTPKey(char* name, unsigned int seed, OTPKey** keyPointer );

OTPErrorCode freeOTPKey(OTPKey* keyPointer);

#endif
