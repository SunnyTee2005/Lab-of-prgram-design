#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>

int main(){
    char c;
    int i = 0;
    bool decide = true; //Distiguish whether if it's the beginning of a sentence.
    
    while((c=getchar()) != EOF){
        if(decide && isalpha(c)){
            putchar(toupper(c));
            decide=false;
        }
        else{
            printf("%c",c);
        }

        if(c=='.' || c=='?'){
            decide=true;
        }
        else if(isdigit(c)){
            decide=false; //3.9%
        }
        i++;
    }
    return 0;
}