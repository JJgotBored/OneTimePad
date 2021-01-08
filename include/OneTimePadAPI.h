#ifndef One_Time_Pad
#define One_Time_Pad

#include<stdio.h>
#include<string.h>

typedef enum OTPErrorCode{ok, invalidName }OTPErrorCode;

typedef struct OTPKey{
    
    char* name;
    int seed;
    int offset[280];

}OTPKey;

OTPErrorCode buildOTPKey(char* name, unsigned int seed, OTPKey** keyPointer );

int freeOTPKey(OTPKey** keyPointer);

#endif
