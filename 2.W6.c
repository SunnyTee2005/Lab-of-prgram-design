/*  devidend / divisor = quotient... remainder  */
#include <stdio.h>
#include <assert.h>
#define ARRAYSIZE 10000


int main(void){
    int inputValue;
    scanf("%d",&inputValue);

    int outputValue[ARRAYSIZE] = {0};
    assert(inputValue < 2147483647);
    int devidend, quotient = 1 , remainder;
    devidend = inputValue;

    int i;        
    for(i=0 ; quotient!=0 ; ++i){
        quotient = devidend / 2;
        remainder = devidend % 2;
        devidend = quotient;
                
        outputValue[i] = remainder;
    }

    for(int j = i-1 ; j >= 0; --j)
        printf("%d",outputValue[j]);
        
    return 0;
}