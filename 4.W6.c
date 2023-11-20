#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define ARRAYSIZE 1001

bool hasDuplicateCharacters(char *s) {
    // 創建一個布林陣列，用於記錄每個字符是否已經出現過
    bool charExists[128] = {false};  // 假設ASCII字符範圍在0到127之間

    // 遍歷字符串
    for (int i = 0; s[i] != '\0'; i++) {
        // 如果字符已經出現過，返回 true
        if (charExists[s[i]]) 
            return true;      

        // 標記字符已經出現
        charExists[s[i]] = true; 
    }

    // 所有字符都是獨一無二的
    return false;
    }

int main(void){
    char inPut[ARRAYSIZE];
    char check[ARRAYSIZE];
    char answer[ARRAYSIZE] = "0"; //長度為1 
    char *ptr = inPut; //指向inPut陣列的開頭
    
    gets(inPut);
    //演算法開始
    for(int i=0 ; i<strlen(inPut) ; i++)
      for(int j=1 ; j<strlen(inPut) ; j++){
        strncpy(check, &ptr[i], j);
        check[j] = '\0';
        if( hasDuplicateCharacters(check) || check[j-1] == inPut[strlen(inPut)-1]){ //我的問題: 如果"不重複字元字串"持續到inPut的最後一個字元，那最終的 strcpy(answer, check); 就不會被執行
            //比較兩組候選人的長度
            if( (strlen(answer) < strlen(check)) )
            
                strcpy(answer, check);
            break;
        }
    }

    for(int i=0 ; i<strlen(answer)-1 ; i++)
        printf("%c",answer[i]);
        
    return 0;
}