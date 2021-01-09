#include"testMain.h"
#include"OneTimePadAPI.h"
#include<stdio.h>

int main(){

    testBuildOTPKEY();
    testFreeOTKKey();
    
    return 0;
}

int testBuildOTPKEY(){

    OTPKey** key = (OTPKey**)(malloc(sizeof(OTPKey*)*1));
    buildOTPKey("test", 5, key);

    printf("name: %s, seed = %d\n", (*key)->name, (*key)->seed );
    for(int i = 0; i < 280; i++){
        printf("Offset at %d: %d\n", i, (*key)->offset[i]);
    }

    free((*key)->name);
    free(*key);
    free(key);

    return 0;
}

int testFreeOTKKey(){
    
    OTPKey** key = (OTPKey**)(malloc(sizeof(OTPKey*)*1));
    buildOTPKey("test", 5, key);
    freeOTPKey(*key);
    free(key);

    return 0;
}