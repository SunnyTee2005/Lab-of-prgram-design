#include <stdio.h>

int MaxCycle(int n1,int n2){
    int Maxcount=0;
    if(n1>n2){
        int temp = n2;
        n2 = n1;
        n1 = temp;
    }
    for(int i=n1;i<=n2;i++){
        int count=1;
        int n=i;
        while(n!=1){
            if(n%2!=0){
                n=3*n+1;
                count++;
            }
            else{
                n=n/2;
                count++;
            }
        }
        if(count>Maxcount)
        Maxcount=count;
    }
    return Maxcount;
}

int main(){
    int N1,N2;
    while(scanf("%d%d",&N1,&N2)!=EOF){
        if(0<N1<10000 || 0<N2<10000)
            printf("%d %d %d\n",N1,N2,MaxCycle(N1,N2));
    }
    return 0;
}