//1.Prime number comes before non-prime number.
//2.If both number are prime numbers, greater number comes before smaller number.
//3.If both number are non-prime numbers, smaller number comes before greater number.
//Remember to cosider integer digits: 0,1

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPrime(int x){
     if(x < 0) x = abs(x); //Considering negative values, so complicated...
     if((x == 0) || (x == 1)) return false;
     if((x == 2) || (x == 3)) return true;
      for(int j=2 ; j<x ; j++)
        if(x % j == 0) return false;
      return true;
}

int compare(int x,int y){
    if(isPrime(x) && isPrime(y)){
        if(x > y) return false;  // no swap
        else return true;  // swap
    }
    if(isPrime(x) && !isPrime(y)){
        return false;
    }
    if(!isPrime(x) && isPrime(y)){
        return true;
    }
    if(!isPrime(x) && !isPrime(y)){
        if(x > y) return true;
        else return false;
    }

  /*
    //Only one prime number
    if(isPrime(x) && !isPrime(y)){ //驚嘆號 (!)，表示取反。它檢查變數 y 是否不是質數。如果 y 不是質數，這個條件就會被視為真（true）。
        if(x > y) return false;
        if(y > x) return true;}
    if(!isPrime(x) && isPrime(y)){
        if(x > y) return true;
        if(y > x) return false;}
    //Two prime numbers
    if(isPrime(x) && isPrime(y)){
        if(x > y) return false;
        if(y > x) return true;}
    //Neither of two are prime number
    if(!isPrime(x) && !isPrime(x)){
        if(x > y) return true;
        if(y > x) return false;}

    if((x == -1 && y == 0) || (x==0 && y==1) || (x == -1 && y == 1)) return false; */
}

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int main(void){
    int N;
    scanf("%d",&N);
    int elements[N];
    for(int i=0 ; i<N ; i++)
        scanf("%d",&elements[i]);
    //Bubble Sort
    for(int i = 0 ; i < N; ++i)
      for(int j= 0 ; j < N - i - 1 ; ++j){
        if(compare(elements[j],elements[j+1]))
          swap(&elements[j], &elements[j+1]);
      }
    //Output
    for(int i=0 ; i<N ;i++){
        printf("%d ",elements[i]);
    }

    return 0;
}
