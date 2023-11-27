#include <stdio.h> 
#define SIZE 10000
//策略: 用一維陣列存建築物的高度，index代表x軸。
int main(void){
    short hight[SIZE] = {0};
    int leftC, inputHight, rightC, left_most_C=10000, right_most_C=0;
    while(scanf("%d %d %d",&leftC,&inputHight,&rightC) != EOF){

        if(leftC < left_most_C) 
            left_most_C = leftC;
        if(rightC > right_most_C)
            right_most_C = rightC;
        
        for(int j=leftC ; j<rightC ; j++){
            if(inputHight > hight[j])
                hight[j] = inputHight;
        }
    }
    
    //輸出
    
    printf("%d %d",left_most_C,hight[left_most_C]);
    for(int j=left_most_C ; j<right_most_C ; j++){
        if(hight[j] != hight[j+1]){
            printf(" %d",j+1);
            printf(" %d",hight[j+1]);
        }
    }
    
    printf(" %d 0",right_most_C);

    return 0;
}
